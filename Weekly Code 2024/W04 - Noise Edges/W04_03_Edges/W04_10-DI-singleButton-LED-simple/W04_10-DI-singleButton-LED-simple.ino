// W04-10-DI-singleButton-LED-simple
//
// GOAL -- read a button (digital input) - have LED follow button state using if..then
// send that state over serial

// we did this in WEEK 03 too!

// button variables
int buttonPin =  4 ;   // pin declare -- where is circuit ?
boolean buttonState =  0 ; // state of button 1=pressed, 0=not

// led variables 
int rLED = 5;          // led we will control 
boolean rLEDState = 0; // starting state of the led 

// compare variables
boolean IS_PRESSED = 1; 
boolean NOT_PRESSED = 0; 

void setup() {
  pinMode(buttonPin, INPUT); // INPUT OR OUTPUT ?
  pinMode(rLED, OUTPUT); // why OUTPUT
  
  Serial.begin(9600);
  Serial.println(__FILE__);
  Serial.println("Setup complete");
}

void loop (){

  buttonState = digitalRead( buttonPin ); // read button
       
  // if button IS pressed, say so 
  if (buttonState == IS_PRESSED) {
      Serial.println("button pressed");
      rLEDState = 1;
      
  } else 
  {
      Serial.println("off");
      rLEDState = 0;
  }

  digitalWrite(rLED, rLEDState);
}
