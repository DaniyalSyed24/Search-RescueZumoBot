# Search and Rescue Zumo Bot

## Project Overview
For this project, I had to use a Pololu Zumo 32U4 robot to perform a simulated search and rescue operation.

The scenario motivating this assignment is that the robot is trying to find/rescue people trapped on a building floor which is filled with smoke. The robot moves along a series of corridors where people might be discovered. Once the robot has found a person, it signals back. (white floor, with black tape for the corridor walls)

Three control modes were implemented in this project.

### Mode 1: Manual        <ins></ins>
The zumo bot can be driven down the corridor by a user using a GUI. The GUI consists of simple commands such as go forward, backwards, turn left, turn right and stop.

### Mode 2: Semi-Autonomous
In this mode the zumo bot can keep between the lines by using the line sensors. When the zumo bot encounters a corner, it stops and returns to manual control. The user tells it to turn left, right or turn back. After the turn, the zumo reactivates its autonomous behaviour and continues down the corridor.

### Mode 3: Fully-Autonomous
In this final mode, the Zumo bot is fully autonomous and makes all decisions itself without andy user intervention.

## Installation

To set up the project, there are a number of applications and libraries that need to be downloaded and installed first.

* Arduino IDE: https://www.arduino.cc/en/software
  * file --> preferences --> at the bottom, add "https://files.pololu.com/arduino/package_pololu_index.json" in the Additional boards managers URLs.
  * tools --> boards --> boards manager and look for "Pololu a-star boards" and install it.
* Processing: https://processing.org/download

## Usage

To use the application, follow the following steps:
* Download the project as a zip folder & open the file of the mode you want to run (mode 1, mode 2 or mode 3).
* Connect the Zumo bot to you computer and go to tools --> boards --> Pololu a-star boards and select Pololu a-star 32U4.
* Go to tools --> port and connect to the port on which the Zumo bot is connected.
* Finally, click on the run arrow and wait for the code to be uploaded to the Zumo.

Mode 1 and 2 can be controlled through the Serial Monitor in Arduino IDE or from from the GUI in Processing.

To use the GUI, go to the GUI folder and run the two .pde files. Remember, in order for Processing to work, you must close Arduino IDE before running it!

## Controls

### Mode 1:
* Turn left ('q')
* turn right ('d')
* go forwards ('z')
* reverse ('s')
<br/>

* sound the buzzer('x')
* 
<br/>

* partially turn left ('4')
* partially turn right ('6')
* partially go forwards ('8')
* partially reverse ('5')

### Mode 2:
* Turn left when in a corner ('l')
* Turn right when in a corner ('r')
* Turn 180 when in a corner ('t')

# References

* https://pololu.github.io/zumo-32u4-arduino-library/index.html
* http://arduino.cc/en/Reference/HomePage






