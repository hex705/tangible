// W07-05-DI-UP-DOWN

/*
 * 
 * 
 *   NOTE TONE (speaker) conflicts with (messes up) PWM (~) On pin 11 and 3
 *   
 *   if you want to use red led 
 *   need to move RED LED WIRE to pin 6 !!!
 * 
 *   this code uses pin 10 ( green led) 
 *   
 *   
 */

// GOAL -- detect both edges while reading a button
// send that state over serial

// button variables
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
int LED = 10;
int LEDState = 0; // now going to be analog

// compare variables
boolean IS_PRESSED = 1;
boolean NOT_PRESSED = 0;

// speaker variables -- // https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
int speakerPin = 12;
int frequency = 200;
int frequencyStep = 20;

// brightness variables
int brightness = 50;
int brightnessStep = 5;


void setup() {
  pinMode(upPin, INPUT);   // INPUT OR OUTPUT ?
  pinMode(downPin, INPUT);
  pinMode(mutePin, INPUT);

  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("setup complete \n\n");
  Serial.println("press buttons for up / down or MUTE");
}

void loop () {

  upState   = digitalRead( upPin   ); // read button
  downState = digitalRead( downPin ); // read button
  muteState = digitalRead( mutePin ); // read button

  // check for UP raising edge
  // if the button IS pressed AND (&&) lastTime was NOT pressed
  if ((upState == IS_PRESSED) && (lastUpState == NOT_PRESSED)) {

    Serial.print("\n UP   rasing edge ");

    brightness += brightnessStep;
    frequency += frequencyStep;

    Serial.print("brightness = "); 
    Serial.print(brightness);
    Serial.print("\tfrequency = ");
    Serial.println(frequency);

  }

  // check for DOWN raising edge
  // if the button IS pressed AND (&&) lastTime was NOT pressed
  if ((downState == IS_PRESSED) && (lastDownState == NOT_PRESSED)) {

    Serial.print("\n DOWN raising edge ");

    brightness -= brightnessStep;
    frequency -= frequencyStep;

    Serial.print("brightness = "); 
    Serial.print(brightness);
    Serial.print("\tfrequency = ");
    Serial.println(frequency);
  }

  // check for MUTE raising edge
  // if the button IS pressed AND (&&) lastTime was NOT pressed
  if ((muteState == IS_PRESSED) && (lastMuteState == NOT_PRESSED)) {

    Serial.print("\n Toggle Mute");
    isPlaying = !isPlaying;

    Serial.print(" Mute = " );
    Serial.println(isPlaying);
  }

  // limit the ranges

  if ( brightness <= 0) brightness = 0 ;
  if ( brightness > 255) brightness = 255;

  if (frequency >= 1000) frequency = 1000;
  if (frequency <= 0 )  frequency = 0;  


  // take action
  analogWrite(LED, brightness);
  
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
