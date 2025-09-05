// W03-07-buttons change blink duration

// left button reduce blink time (increase rate)
// middle button increases blink time (slows rate)
// right button resets to 1 sec

// led variables
int ledPin = 5;
int ledState = 0;

// button PIN variables
int lessButtonPin =  2 ;   // pin declare -- where is circuit ?
int moreButtonPin =  3 ;   // pin declare -- where is circuit ?
int resetButtonPin = 4 ;   // pin declare -- where is circuit ?

// button states
boolean lessButtonState =  0 ; // state of button 1=pressed, 0=not
boolean moreButtonState =  0 ; // state of button 1=pressed, 0=not
boolean resetButtonState = 0 ; // state of button 1=pressed, 0=not

// timer variables
unsigned long timeNow = 0;
unsigned long ledBlink_Interval = 1000;
unsigned long ledBlink_Start = 0;

unsigned long intervalStep = 50; //



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // next line is for testing only - NOT in production
  while (!Serial); // have to open the serial MONITOR or PLOTTER to get past this line 

  pinMode(lessButtonPin,  INPUT ); // INPUT OR OUTPUT ?
  pinMode(moreButtonPin,  INPUT ); // INPUT OR OUTPUT ?
  pinMode(resetButtonPin, INPUT ); // INPUT OR OUTPUT ?
  pinMode(ledPin, OUTPUT);
}

void loop() {

    // listen :: read sensors
  lessButtonState  = digitalRead( lessButtonPin ); // read button
  moreButtonState  = digitalRead( moreButtonPin ); // read button
  resetButtonState = digitalRead( resetButtonPin ); // read button

  if ( lessButtonState == 1 )  ledBlink_Interval -= intervalStep ;
  if ( moreButtonState == 1 )  ledBlink_Interval += intervalStep;
  if ( resetButtonState == 1 ) ledBlink_Interval =  1000;

  if (ledBlink_Interval > 2000) ledBlink_Interval = 2000;
  if (ledBlink_Interval < 100 ) ledBlink_Interval = 100;

//    // ***** timer solution *****
     timeNow = millis();
   
      // NOTE::  timeNow - ledBlink_Start == elapsed time
      if ( timeNow - ledBlink_Start  > ledBlink_Interval ) {
         ledState = 1 - ledState;             // toggle LED
         ledBlink_Start += ledBlink_Interval; // reset timer
      }
   
     digitalWrite(ledPin, ledState); // write to LED
     printLEDState();                // print out LED stat
// ***** end timer solution *****

   // feedback to screen
  Serial.print ( "buttons:: " );
  Serial.print(lessButtonState);   // print button state  
    Serial.print(" ");   // space    
    Serial.print(moreButtonState);   // print button state     
      Serial.print(" ");     
      Serial.print(resetButtonState);   // print button state
        Serial.print("\t\t ledBlinkInterval::  ");     
        Serial.println(ledBlink_Interval);   // print button state

  delay(50); // we will get rid of this delay in W04!
}



void printLEDState() {
  //int shift = 0; // move the LED above the botton on display
  // output the state to monitor
  if (ledState == 1) {
    Serial.print("LED:: HIGH\t");
    //Serial.print(1 + shift);
  } else {
    Serial.print("LED:: LOW\t");
    //Serial.print(0 + shift);
  }
}
