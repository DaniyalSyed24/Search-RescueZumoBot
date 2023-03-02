import processing.serial.*;
import g4p_controls.*;

Serial connexion;;

int bgcol = 15;

public void setup() {
  String portName = Serial.list()[2];
  connexion = new Serial(this, portName, 9600);
  size(1000, 400);
  createGUI();
}

public void draw() {
  background(200, 200, 200);
  
  stroke(0);
  strokeWeight(3);
  //line(10, 150, 250, 150); // draw a line from (50,50) to (350,350)

}
