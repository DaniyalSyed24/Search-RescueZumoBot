/* =========================================================
 * ====                   WARNING                        ===
 * =========================================================
 * The code in this tab has been generated from the GUI form
 * designer and care should be taken when editing this file.
 * Only add/edit code inside the event handlers i.e. only
 * use lines between the matching comment tags. e.g.

 void myBtnEvents(GButton button) { //_CODE_:button1:12356:
     // It is safe to enter your event code here  
 } //_CODE_:button1:12356:
 
 * Do not rename this tab!
 * =========================================================
 */


// Variable declarations
GTextArea textArea; 
GTextField textField; 

GButton stopButton; // stop the Zumo
GButton leftButton; // turn left
GButton rightButton; // turn right
GButton forwardButton; // move forward
GButton reverseButton; // move back
GButton buzzerButton; // object detected

GButton leftButtonSmall; // turn left
GButton rightButtonSmall; // turn right
GButton forwardButtonSmall; // move forward
GButton reverseButtonSmall; // move back

GButton cornerLeftButton;
GButton cornerRightButton;
GButton cornerTButton;


public void textarea1_change1(GTextArea source, GEvent event) {
}

public void textfield1_change1(GTextField source, GEvent event) { // Instructions plane
  String inputs = textField.getText();
  char instruction = inputs.charAt(inputs.length() - 1);
  textArea.appendText("\n Sent "+ instruction +" to Zumo");
  connexion.write(instruction);
}

public void stopZumo(GButton source, GEvent event) { // Button to stop the Zumo
  connexion.write("e");
}

public void turnLeft(GButton source, GEvent event) {
  connexion.write("q");
  textArea.appendText("\n Turn Left");
}

public void turnRight(GButton source, GEvent event) {
  connexion.write("d");
  textArea.appendText("\n Turn Right");
}

public void moveForward(GButton source, GEvent event) {
  connexion.write("z");
  textArea.appendText("\n Move Forward");
}

public void reverseZumo(GButton source, GEvent event) {
  connexion.write("s");
  textArea.appendText("\n Move Backwards");
}

public void soundBuzzer(GButton source, GEvent event) {
  connexion.write("x");
  textArea.appendText("\n Object Detected!");
}



public void turnLeftSmall(GButton source, GEvent event) {
  connexion.write("4");
  textArea.appendText("\n Turn Left S");
}

public void turnRightSmall(GButton source, GEvent event) {
  connexion.write("6");
  textArea.appendText("\n Turn Right S");
}

public void moveForwardSmall(GButton source, GEvent event) {
  connexion.write("8");
  textArea.appendText("\n Move Forward S");
}

public void reverseZumoSmall(GButton source, GEvent event) {
  connexion.write("5");
  textArea.appendText("\n Move Backwards S");
}

public void turn90Left(GButton source, GEvent event) {
  connexion.write("l");
  textArea.appendText("\n Turn 90 degrees left");
}

public void turn90Right(GButton source, GEvent event) {
  connexion.write("r");
  textArea.appendText("\n Turn 90 degrees Right");
}

public void turn180(GButton source, GEvent event) {
  connexion.write("t");
  textArea.appendText("\n Turn 180 degrees");
}


// Create the GUI controls.  
 public void createGUI() {
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  G4P.setCursor(ARROW);
  surface.setTitle("Zumo Controls");
  
  //GPanel panel = new GPanel(this, 10, 10, 300, 350);
  
  background(255); // set the background color to white
  
  stroke(0); // set the stroke color to black
  strokeWeight(2); // set the thickness of the stroke to 2 pixels
  
  line(50, 50, 200, 200); // draw a line from (50,50) to (350,350)


  createInstructionsTextArea();
  createTextField1();
  createStopButton();
  createLeftButton();
  createRightButton();
  createForwardButton();
  createBackButton();
  createBuzzerButton();
  
  createLeftButtonSmall();
  createRightButtonSmall();
  createForwardButtonSmall();
  createBackButtonSmall();
  
  createCornerLeftButton();
  createCornerRightButton();
  createCornerTButton();
}

private void createInstructionsTextArea() {
  textArea = new GTextArea(this, 700, 50, 198, 250, G4P.SCROLLBARS_VERTICAL_ONLY| G4P.SCROLLBARS_AUTOHIDE);
  textArea.setText("Instructions");
  //textarea.setLocalColorScheme(GCScheme.PURPLE_SCHEME);
  textArea.setLocalColorScheme(GCScheme.GREEN_SCHEME);
  textArea.setOpaque(true);
  textArea.addEventHandler(this, "textarea1_change1");
}

private void createTextField1() {
  textField = new GTextField(this, 135, 300, 150, 30, G4P.SCROLLBARS_NONE);
  textField.setText("");
  textField.setLocalColorScheme(GCScheme.RED_SCHEME);
  textField.setOpaque(true);
  textField.addEventHandler(this, "textfield1_change1");
}

private void createStopButton() {
  stopButton = new GButton(this, 20, 302, 90, 30);
  stopButton.setTextAlign(GAlign.CENTER, GAlign.CENTER);
  stopButton.setText("Stop Zumo");
  stopButton.setTextBold();
  stopButton.setLocalColorScheme(GCScheme.RED_SCHEME);
  stopButton.addEventHandler(this, "stopZumo");
}

private void createLeftButton() {
  leftButton = new GButton(this, 10, 70, 80, 30);
  leftButton.setText("Left");
  leftButton.setTextBold();
  leftButton.addEventHandler(this, "turnLeft");
}

private void createRightButton() {
  rightButton = new GButton(this, 130, 70, 80, 30);
  rightButton.setText("Right");
  rightButton.setTextBold();
  rightButton.addEventHandler(this, "turnRight");
}

private void createForwardButton() {
  forwardButton = new GButton(this, 70, 30, 80, 30);
  forwardButton.setText("Forward");
  forwardButton.setTextBold();
  forwardButton.addEventHandler(this, "moveForward");
}

private void createBackButton() {
  reverseButton = new GButton(this, 70, 110, 80, 30);
  reverseButton.setText("Back");
  reverseButton.setTextBold();
  reverseButton.addEventHandler(this, "reverseZumo");
}

private void createBuzzerButton() {
  buzzerButton = new GButton(this, 230, 40, 60, 30);
  buzzerButton.setText("Buzzer");
  buzzerButton.setTextBold();
  buzzerButton.setLocalColorScheme(GCScheme.RED_SCHEME);
  buzzerButton.addEventHandler(this, "soundBuzzer");
}

private void createLeftButtonSmall() {
  leftButtonSmall = new GButton(this, 10, 200, 80, 30);
  leftButtonSmall.setText("Left Small");
  leftButtonSmall.setTextBold();
  leftButtonSmall.addEventHandler(this, "turnLeftSmall");
}

private void createRightButtonSmall() {
  rightButtonSmall = new GButton(this, 130, 200, 80, 30);
  rightButtonSmall.setText("Right Small");
  rightButtonSmall.setTextBold();
  rightButtonSmall.addEventHandler(this, "turnRightSmall");
}

private void createForwardButtonSmall() {
  forwardButtonSmall = new GButton(this, 70, 160, 80, 30);
  forwardButtonSmall.setText("Forward S.");
  forwardButtonSmall.setTextBold();
  forwardButtonSmall.addEventHandler(this, "moveForwardSmall");
}

private void createBackButtonSmall() {
  reverseButtonSmall = new GButton(this, 70, 240, 80, 30);
  reverseButtonSmall.setText("Back Small");
  reverseButtonSmall.setTextBold();
  reverseButtonSmall.addEventHandler(this, "reverseZumoSmall");
}

private void createCornerLeftButton(){
  cornerLeftButton = new GButton(this, 350, 40, 70, 70);
  cornerLeftButton.setLocalColorScheme(GCScheme.GREEN_SCHEME);
  cornerLeftButton.setText("Turn 90 Left");
  cornerLeftButton.setTextBold();
  cornerLeftButton.addEventHandler(this, "turn90Left");
}

private void createCornerRightButton(){
  cornerRightButton = new GButton(this, 450, 40, 70, 70);
  cornerRightButton.setLocalColorScheme(GCScheme.GREEN_SCHEME);
  cornerRightButton.setText("Turn 90 Right");
  cornerRightButton.setTextBold();
  cornerRightButton.addEventHandler(this, "turn90Right");
}

private void createCornerTButton(){
  cornerTButton = new GButton(this, 550, 40, 70, 70);
  cornerTButton.setLocalColorScheme(GCScheme.GREEN_SCHEME);
  cornerTButton.setText("Turn 180");
  cornerTButton.setTextBold();
  cornerTButton.addEventHandler(this, "turn180");
}
  
  
  
  
  
