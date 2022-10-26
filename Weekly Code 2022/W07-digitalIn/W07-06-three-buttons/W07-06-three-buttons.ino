// W07-06- threeButtons

// read 3 buttons independently -- first press only
// act on button states in combination

/*
 * 
 *   NOTE TONE (speaker) conflicts with (messes up) PWM (~) On pin 11 and 3
 *   
 *   if you want to use red led 
 *   need to move RED LED WIRE to pin 6 !!!
 * 
 *   this code uses pin 10 (green led) 
 *   
 */


// button variables
int B1Pin = 4 ;   // pin declare -- where is circuit ?
boolean B1State = 0 ; // state of button 1=pressed, 0=not
boolean lastB1State = 0; // remember what happened last time

int B2Pin = 3 ;   // pin declare -- where is circuit ?
boolean B2State = 0 ; // state of button 1=pressed, 0=not
boolean lastB2State = 0; // remember what happened last time

int B3Pin = 2 ;   // pin declare -- where is circuit ?
boolean B3State = 0 ; // state of button 1=pressed, 0=not
boolean lastB3State = 0; // remember what happened last time


// led variables
int rLED = 6;
int rLEDState = 0; // now going to be analog

int gLED = 10;
int gLEDState = 0; // now going to be analog

int bLED = 9;
int bLEDState = 0; // now going to be analog

int allButtons = 0; // hold all the buttons together
int lastAllButtons =0;

// compare variables
boolean IS_PRESSED  = 1;
boolean NOT_PRESSED = 0;

// speaker variables -- // https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
int speakerPin = 12;
int frequency = 200;
int frequencyStep = 20;

// brightness variables
int brightness = 50;
int brightnessStep = 5;


void setup() {
  
  pinMode(B1Pin, INPUT);   // INPUT OR OUTPUT ?
  pinMode(B2Pin, INPUT);
  pinMode(B3Pin, INPUT);

  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);

  Serial.begin(9600);
  Serial.println("\n\nsetup complete");
  Serial.println("press any button to begin");
}

void loop () {

  // read all the buttons 
  B1State = digitalRead( B1Pin ); // read button
  B2State = digitalRead( B2Pin ); // read button
  B3State = digitalRead( B3Pin ); // read button

  // find raising and falling edges of all buttons
  // check B1 
      // pressed (raising edge) 
      // if the button IS pressed AND (&&) lastTime was NOT pressed
      if ((B1State == IS_PRESSED) && (lastB1State == NOT_PRESSED)) {
        Serial.print("\n B1 PRESSED");
        allButtons += 100;
      }
      
      // released (falling edge) 
      if ((B1State == NOT_PRESSED) && (lastB1State == IS_PRESSED)) {
        Serial.print("\n B1 released");
        allButtons -= 100;
      }

  //check B2
      // pressed (raising edge) 
      // if the button IS pressed AND (&&) lastTime was NOT pressed
      if ((B2State == IS_PRESSED) && (lastB2State == NOT_PRESSED)) {
        Serial.print("\n B2 PRESSED");
        allButtons += 10;
      } 
      // released (falling edge) 
      if ((B2State == NOT_PRESSED) && (lastB2State == IS_PRESSED)) {
        Serial.print("\n B2 released");
        allButtons -= 10;
      }

  // check B3 
      // pressed (raising edge) 
      // if the button IS pressed AND (&&) lastTime was NOT pressed
      if ((B3State == IS_PRESSED) && (lastB3State == NOT_PRESSED)) {
        Serial.print("\n B3 PRESSED");
        allButtons += 1;
      }
      // released (falling edge) 
      if ((B3State == NOT_PRESSED) && (lastB3State == IS_PRESSED)) {
        Serial.print("\n B3 released");
        allButtons -= 1;
      }
      
    // did VALUE of allButtons change?
       if (allButtons != lastAllButtons){
           Serial.print("\t");
           Serial.print(B1State);
           Serial.print("\t");
           Serial.print(B2State);
           Serial.print("\t");
           Serial.print(B3State);
           
           Serial.print( "\t all buttons ==> ");
           Serial.println(allButtons);
       } // end if button change


  // write in your diary
    lastB1State = B1State; 
    lastB2State = B2State;
    lastB3State = B3State;
    lastAllButtons = allButtons;
  
  delay(30); // if this gets smaller -- then its harder to hit combinations

}

void ledsOff(){
  analogWrite(rLED, 0);
  analogWrite(gLED, 0);
  analogWrite(bLED, 0);
}
