// W03-02-DI-singleButton-basic
// GOAL -- read a button (digital input)
// print reading to serial monitor

// upload <start simulation>, open serial monitor,
// press left button -- look for 0,1 in monitor

int buttonPin =  2 ;   // pin declare -- where is circuit ?
boolean buttonState =  0 ; // state of button 1=pressed, 0=not

int speakerPin = 12;

void setup() {
  pinMode(buttonPin,  INPUT ); // Why INPUT or OUTPUT ?
  Serial.begin(9600);
}


void loop () {
  buttonState = digitalRead( buttonPin ); // read button
  Serial.print( "button = " );
  Serial.println(buttonState);    // print button state  

  if (buttonState == 1 ) {
    tone(speakerPin,1000);
  }    else {
    noTone(speakerPin);
  }

  delay(50); // just slow it down a little
}


