// W06-05-DI-singleButton-basic
// GOAL -- read a button (digital input)
// print reading to serial monitor

// upload <start simulation>, open serial monitor,
// press left button -- look for 0,1 in monitor

int buttonPin =  2 ;   // pin declare -- where is circuit ?
boolean buttonState =  0 ; // state of button 1=pressed, 0=not

void setup() {
  pinMode(buttonPin,  INPUT ); // INPUT OR OUTPUT ?
  Serial.begin(9600);
}


void loop () {
  buttonState = digitalRead( buttonPin ); // read button
  Serial.print ( "button = " );
  Serial.println(buttonState);   // print button state        
  delay(50); // just slow it down a little
}
