#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;

char action;
int speed = 100;


void setup()
{
  Serial.begin(9600);
  ledYellow(1);
}

void loop()
{
  if (Serial.available() > 0)
  {
    action = Serial.read();

    switch (action)
    {
      case 'x': // object found, sound buzzer
        Serial.write('Object Detected');
        buzzer.playFrequency(800, 300, 15);
        delay(300);  // pause for 100 ms
        buzzer.playFrequency(500, 400, 15);
        break;
      case 'z': // go forwards
        ledYellow(0);
        ledRed(0);
        ledGreen(1);
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(speed);
        
        break;
      case 's': // reverse
        ledYellow(0);
        ledRed(1);
        ledGreen(0);
        motors.setLeftSpeed(-speed);
        motors.setRightSpeed(-speed);
        break;
      case 'q': // turn left
        motors.setLeftSpeed(-speed);
        motors.setRightSpeed(speed);
        break;
      case 'd': // turn right
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(-speed);
        break;

      case '8': // go forwards in small steps
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(speed);
        delay(50);
        motors.setLeftSpeed(0);
        motors.setRightSpeed(0);
        break;
      case '5': // reverse in small steps
        motors.setLeftSpeed(-speed);
        motors.setRightSpeed(-speed);
        delay(50);
        motors.setLeftSpeed(0);
        motors.setRightSpeed(0);
        break;
      case '4': // turn left in small steps
        motors.setLeftSpeed(-speed);
        motors.setRightSpeed(speed);
        delay(50);
        motors.setLeftSpeed(0);
        motors.setRightSpeed(0);
        break;
      case '6': // turn right in small steps
        motors.setLeftSpeed(speed);
        motors.setRightSpeed(-speed);
        delay(50);
        motors.setLeftSpeed(0);
        motors.setRightSpeed(0);
        break;
      
      default:
        motors.setLeftSpeed(0);
        motors.setRightSpeed(0);
        ledYellow(1);
    }
  }
}