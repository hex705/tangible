// W03-04-DI_DO_buttons_to_RGB
// GOAL -- control LED with a button 
// print reading to serial monitor

// upload <start simulation>, open serial monitor,
// press left button -- look for 0,1 in monitor

// button PIN variables
int rButtonPin =  2 ;   // pin declare -- where is circuit ?
int gButtonPin =  3 ;   // pin declare -- where is circuit ?
int bButtonPin =  4 ;   // pin declare -- where is circuit ?

// button states
boolean rButtonState =  0 ; // state of button 1=pressed, 0=not
boolean gButtonState =  0 ; // state of button 1=pressed, 0=not
boolean bButtonState =  0 ; // state of button 1=pressed, 0=not

// led variables
int rLedPin = 5; // where are the LEDs?
int gLedPin = 6; // where are the LEDs?
int bLedPin = 7; // where are the LEDs?

void setup() {
  pinMode(rButtonPin,  INPUT ); // INPUT OR OUTPUT ?
  pinMode(gButtonPin,  INPUT ); // INPUT OR OUTPUT ?
  pinMode(bButtonPin,  INPUT ); // INPUT OR OUTPUT ?

  pinMode (rLedPin, OUTPUT);
  pinMode (gLedPin, OUTPUT);
  pinMode (bLedPin, OUTPUT);

  Serial.begin(9600);
}


void loop () {
  // listen :: read sensors
  rButtonState = digitalRead( rButtonPin ); // read button
  gButtonState = digitalRead( gButtonPin ); // read button
  bButtonState = digitalRead( bButtonPin ); // read button

  // take action and provide feedback
  if ( rButtonState == 1){
    digitalWrite(rLedPin, 1);
  } else {
    digitalWrite(rLedPin, 0);
  }

  if ( gButtonState == 1){
    digitalWrite(gLedPin, 1);
  } else {
    digitalWrite(gLedPin, 0);
  }

  if ( bButtonState == 1){
    digitalWrite(bLedPin, 1);
  } else {
    digitalWrite(bLedPin, 0);
  }

  // feedback to screen
  Serial.print ( "buttons = " );
  Serial.print(rButtonState);   // print button state  
    Serial.print(" ");   // space    
    Serial.print(gButtonState);   // print button state     
      Serial.print("\t");   // tab    
      Serial.println(bButtonState);   // print button state     

  delay(50); // just slow it down a little
}
