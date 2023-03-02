#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
Zumo32U4Buzzer buzzer;
Zumo32U4ProximitySensors proxSensors;

// number of line sensors and an array to hold their values
#define NUM_SENSORS 5 
uint16_t lineSensorValues[NUM_SENSORS];

//variables
int speed = 100;
int MAX = 500;
int cornerMAX = 200;
// int MIN = 100;


void setup() {
  lineSensors.initThreeSensors();
  proxSensors.initThreeSensors();
}

void loop() {

  // Sample the line sensors every 100 milliseconds
  static uint16_t lastSampleTime = 0;
  if ((uint16_t)(millis() - lastSampleTime) >= 100)
  {
    lastSampleTime = millis();
    lineSensors.read(lineSensorValues);
  }

  motors.setLeftSpeed(speed);
  motors.setRightSpeed(speed);

  
  if (lineSensorValues[0] > MAX && lineSensorValues[1] > MAX) { // Check if left and front sensor detect wall --> turn right
    // Stop the robot
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    // Serial.println("Right Corner");
    delay(300);

    // Turn right
    motors.setLeftSpeed(100);
    motors.setRightSpeed(-100);
    delay(500); // Adjust to turn more or less
  }
  else if (lineSensorValues[2] > MAX && lineSensorValues[1] > MAX) { // Check if right and front sensor detect wall --> turn left
    // Stop the robot
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    // Serial.println("Left Corner");
    delay(300);

    // Turn left
    motors.setLeftSpeed(-100);
    motors.setRightSpeed(100);
    delay(500); // Adjust to turn more or less
  }
  else if (lineSensorValues[0] > MAX) { // wall left --> adjust to the right
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    delay(100);

    motors.setLeftSpeed(100);
    motors.setRightSpeed(-100);
    delay(100);
  }
  else if (lineSensorValues[2] > MAX) { // wall right --> adjust to the left
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    delay(100);

    motors.setLeftSpeed(-100);
    motors.setRightSpeed(100);
    delay(100);
  }
  else if (lineSensorValues[2] > cornerMAX && lineSensorValues[1] > cornerMAX && lineSensorValues[0] > cornerMAX) { // Check if ALL sensors detect wall --> turn 180
    // Stop the robot
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    // Serial.println("T Corner");
    delay(300);

    motors.setLeftSpeed(-100);
    motors.setRightSpeed(100);
    delay(2000); // Adjust to turn more or less
  }

  proxSensors.read();
  int leftSensor = proxSensors.countsLeftWithLeftLeds();
  int centerLeftSensor = proxSensors.countsFrontWithLeftLeds();
  int centerRightSensor = proxSensors.countsFrontWithRightLeds();
  int rightSensor = proxSensors.countsRightWithRightLeds();

  // object flags 
  static bool leftObject = false;
  static bool rightObject = false; 
  static bool objectDetected = false;

  if (leftSensor > 4.5 && centerLeftSensor > 4.5 || rightSensor > 4.5 && centerRightSensor > 4.5 || (centerLeftSensor > 4.5 && centerRightSensor > 4.5 && leftSensor > 4.5 && rightSensor > 4.5)) {
    if (leftSensor > 4.5 && centerLeftSensor > 4.5) { // object on the left, turn right
      if (!leftObject) { // check flag
        Serial.println("Object Detected on Left");
      }
      motors.setSpeeds(50, -50); // turn right
      delay(50);
      motors.setSpeeds(50, 50);
      delay(50);
      leftObject = true; // set flag to true
    }
    if (rightSensor > 4.5 && centerRightSensor > 4.5) { // object on the right, turn left
      if (!rightObject) { // check flag
        Serial.println("Object Detected on Right");
      }
      motors.setSpeeds(-50, 50); // turn left
      delay(50);
      motors.setSpeeds(50, 50);
      delay(50);
      rightObject = true;
    }
    if (centerLeftSensor > 5.5 && centerRightSensor > 5.5 && leftSensor > 4.5 && rightSensor > 4.5) { // object in the front
      if (!objectDetected) { // check flag
        Serial.println("Object Detected in Front");
      }
      // buzzer.playFrequency(500, 400, 10);
      motors.setSpeeds(0,0);
      objectDetected = true;
    }
    delay(100);
  }else{
    objectDetected = false;
    rightObject = false;
    leftObject = false;
  }
}



  // if (lineSensorValues[0] < MIN) { // Check if no left wall
  //   // Stop the robot
  //   motors.setLeftSpeed(0);
  //   motors.setRightSpeed(0);
  //   Serial.println("No LEFT wall");
  //   delay(300);

  //   // Turn left
  //   motors.setLeftSpeed(-100);
  //   motors.setRightSpeed(100);
  //   delay(500); // Adjust to turn more or less
  // }

