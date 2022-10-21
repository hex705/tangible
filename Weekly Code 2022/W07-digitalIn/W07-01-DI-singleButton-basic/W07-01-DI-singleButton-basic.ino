// W07-01-DI-singleButton
// GOAL -- read a button (digital input)
// send that reading over serial

// upload <start simulation>, open serial monitor,
// press left button -- look for 0,1 in monitor

int buttonPin =  4 ;   // pin declare -- where is circuit ?
boolean buttonState =  0 ; // state of button 1=pressed, 0=not


void setup() {
  pinMode(buttonPin,  INPUT ); // INPUT OR OUTPUT ?
  Serial.begin(9600);
}

void loop () {
  
  buttonState = digitalRead( buttonPin ); // read button

  Serial.println(buttonState);   // print button state        

}
