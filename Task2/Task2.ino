#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Buzzer buzzer;

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];


char action;
int speed = 100;
int MAX = 500; //300
int MIN = 260;
int cornerMAX = 200; //100


void setup() {
  Serial.begin(9600);
  lineSensors.initThreeSensors();
  proxSensors.initThreeSensors();
}

// function for aut mode (keep between the lines)
void autoMode(){
  motors.setLeftSpeed(speed);
  motors.setRightSpeed(speed);

  if (lineSensorValues[0] > MAX) { // wall left --> adjust to the right
    // Serial.println("Left Wall");
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    delay(100);

    motors.setLeftSpeed(100);
    motors.setRightSpeed(-100);
    delay(100);
  }

  if (lineSensorValues[2] > MAX) { // wall right --> adjust to the left
    // Serial.println("Right Wall");
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    delay(100);

    motors.setLeftSpeed(-100);
    motors.setRightSpeed(100);
    delay(100);
  }
}

// function for manual mode (turn when in corners)
void manualMode(){
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);

  if (Serial.available() > 0){
    action = Serial.read();

    switch (action){
      case 'l': // Turn Left
        motors.setLeftSpeed(-speed);
        motors.setRightSpeed(speed);
        delay(1000);
        break;
      case 'r': // Turn Right
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(-speed);
        delay(1000);
        break;
      case 't': // Turn back
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(-speed);
        delay(1700);
        break;
    }
  }
}

void loop() {
  proxSensors.read();
  int leftSensor = proxSensors.countsLeftWithLeftLeds();
  int centerLeftSensor = proxSensors.countsFrontWithLeftLeds();
  int centerRightSensor = proxSensors.countsFrontWithRightLeds();
  int rightSensor = proxSensors.countsRightWithRightLeds();

  // Sample line sensors every 100 milliseconds
  static uint16_t lastSampleTime = 0;
  if ((uint16_t)(millis() - lastSampleTime) >= 100){
    lastSampleTime = millis();
    lineSensors.read(lineSensorValues);
  }

  // flags
  static bool inCorner = false;
  static bool leftObject = false;
  static bool rightObject = false; 
  static bool objectDetected = false;

  if ((lineSensorValues[0] > MAX && lineSensorValues[1] > cornerMAX || lineSensorValues[2] > MAX && lineSensorValues[1] > cornerMAX) || // line sensors
      (leftSensor > 4.5 || rightSensor > 4.5 || (centerLeftSensor > 4.5 && centerRightSensor > 4.5 && leftSensor > 4.5 && rightSensor > 4.5))) { // proximity sensors

    if (lineSensorValues[0] > MAX && lineSensorValues[1] > cornerMAX || lineSensorValues[2] > MAX && lineSensorValues[1] > cornerMAX) { // line sensor code block
      if (!inCorner){ // print the message only once
        Serial.println("In Corner");
      }
      inCorner = true;
    }

  if (leftSensor > 4.5 || rightSensor > 4.5 || (centerLeftSensor > 4.5 && centerRightSensor > 4.5 && leftSensor > 4.5 && rightSensor > 4.5)) { // prox sensors code block
    if (leftSensor > 4.5) {
      if (!leftObject) { // check flag
        Serial.println("Object Detected on Left");
      }
      motors.setSpeeds(-100, 100); // turn left towards the object
      leftObject = true;
    }
    if (rightSensor > 4.5) {
      if (!rightObject) {
        Serial.println("Object Detected on Right");
      }
      motors.setSpeeds(100, -100); // turn right towards the object
      rightObject = true;
    }
    if (centerLeftSensor > 5.5 && centerRightSensor > 5.5 && leftSensor > 4.5 && rightSensor > 4.5) {
      if (!objectDetected) { // check flag
        Serial.println("Object Detected in Front"); // detect object and make a sound
      }
      buzzer.playFrequency(500, 400, 10);
      motors.setSpeeds(0,0);
      objectDetected = true;
    }
    delay(100);
  }
  manualMode();

  } else {
    inCorner = false;
    objectDetected = false;
    rightObject = false;
    leftObject = false;
    autoMode();
  }


/* ---------- Attempted doorway code ---------- */ 

  // const unsigned long DOORWAY_DURATION = 2000; // 2 second in milliseconds
  // static unsigned long doorwayStartTime = 0;

  // if (lineSensorValues[0] < MIN && lineSensorValues[1] < cornerMAX) { // Check if zumo is in a doorway
  //   if (doorwayStartTime == 0) { // If entering the doorway, start the timer
  //     doorwayStartTime = millis();
  //   }
  //   // Serial.println("POTENTIAL DOORWAY");
  //   if (millis() - doorwayStartTime >= DOORWAY_DURATION) { // If more than 2 second has passed since entering the doorway, sound the buzzer
  //     Serial.println("THIS IS A DOORWAY");
  //     buzzer.playFrequency(500, 400, 10);

  //     motors.setLeftSpeed(0);
  //     motors.setRightSpeed(0);
  //     manualMode();
  //   }
    
  // } else {
  //   doorwayStartTime = 0; // Reset the timer if not in the doorway
  // }




}

