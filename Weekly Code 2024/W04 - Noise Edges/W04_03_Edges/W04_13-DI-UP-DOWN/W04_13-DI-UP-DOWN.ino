// W04-13-DI-UP-DOWN


// GOAL -- detect both edges while reading a button
// change sound freq. and led blink rate
// send that state over serial

// button variables 
// 3 buttons, 3 currentState, 3 lastState

int upPin = 3 ;   // pin declare -- where is circuit ?
boolean upState = 0 ; // state of button 1=pressed, 0=not
boolean lastUpState = 0; // remember what happened last time

int downPin = 4 ;   // pin declare -- where is circuit ?
boolean downState = 0 ; // state of button 1=pressed, 0=not
boolean lastDownState = 0; // remember what happened last time

int mutePin = 2;
boolean muteState = 0;
boolean lastMuteState = 0;
boolean isPlaying = true;

// led variables
int LED = 5;      //  start on red
int LEDState = 0; // now going to be analog


// compare variables
boolean IS_PRESSED = 1;
boolean NOT_PRESSED = 0;

// speaker variables -- // https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
int speakerPin = 12;
int frequency = 200;
int frequencyStep = 20;

// led blink rate -- a timer ... oh my!
unsigned long timeNow = 0;
unsigned long ledBlink_Interval = 250;
unsigned long ledBlink_Start = 0;

unsigned long intervalStep = 50; 


void setup() {
  // buttons
  pinMode(upPin, INPUT);   // INPUT OR OUTPUT ?
  pinMode(downPin, INPUT);
  pinMode(mutePin, INPUT);

  // led
  pinMode(LED, OUTPUT);

  // messaging 
  Serial.begin(9600);
  Serial.println(__FILE__);
  Serial.println("setup complete \n\n");
  Serial.println("press buttons for up / down or MUTE");
}

void loop () {

  timeNow = millis();

  upState   = digitalRead( upPin   ); // read button
  downState = digitalRead( downPin ); // read button
  muteState = digitalRead( mutePin ); // read button

  // check for raising edge (just Pressed) UP button
  // if the button IS pressed AND (&&) lastTime was NOT pressed
  if ((upState == IS_PRESSED) && (lastUpState == NOT_PRESSED)) {
    Serial.print("\n UP   - raising edge! ");
    ledBlink_Interval -= intervalStep ; // blink faster
    frequency += frequencyStep;
  }

  // check for raising edge (just pressed) DOWN button
  // if the button IS pressed AND (&&) lastTime was NOT pressed
  if ((downState == IS_PRESSED) && (lastDownState == NOT_PRESSED)) {
    Serial.print("\n DOWN - raising edge! ");
    ledBlink_Interval += intervalStep; // blink slower
    frequency -= frequencyStep;
  }

  // show state of system

    Serial.print("Led blink = "); 
    Serial.print(ledBlink_Interval);
    Serial.print("\tfrequency = ");
    Serial.println(frequency);

  // check for MUTE raising edge
  // if the button IS pressed AND (&&) lastTime was NOT pressed
  if ((muteState == IS_PRESSED) && (lastMuteState == NOT_PRESSED)) {

    Serial.print("\n Toggle Mute");
    isPlaying = !isPlaying;

    Serial.print(" Mute = " );
    Serial.println(isPlaying);

  }

     
  // limit blink rate
  if (ledBlink_Interval <= 50)   { ledBlink_Interval = 50; }
  if (ledBlink_Interval >= 1000) { ledBlink_Interval = 1000; }

  if (timeNow-ledBlink_Start>ledBlink_Interval){
    LEDState = 1 - LEDState;
    ledBlink_Start+=ledBlink_Interval;
  }

  digitalWrite(LED,LEDState);

  // limit the frequency range
  if (frequency >= 1000) frequency = 1000;
  if (frequency <= 0 )  frequency = 0;  

  
  if ( isPlaying == 1) {
    tone(speakerPin, frequency);
  } else
  {
    noTone(speakerPin);
  }

  // write in your diary
  lastUpState   = upState; // save this reading for next loop
  lastDownState = downState;
  lastMuteState = muteState;
  
  delay(5); // simple debounce - we will discuss in class.

}
