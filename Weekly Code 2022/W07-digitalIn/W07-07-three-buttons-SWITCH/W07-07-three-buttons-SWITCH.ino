// W07-06- threeButtons

// read 3 buttons independently -- first press only
// act on button states in combination


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
int lastAllButtons = 0;

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

  B1State = digitalRead( B1Pin ); // read button
  B2State = digitalRead( B2Pin ); // read button
  B3State = digitalRead( B3Pin ); // read button

  // check B1 
      // pressed (raising edge) 
      // if the button IS pressed AND (&&) lastTime was NOT pressed
      if ((B1State == IS_PRESSED) && (lastB1State == NOT_PRESSED)) {
        Serial.print("\n B1 pressed");
        allButtons += 100;
      }
      
      // released (falling edge) 
      if ((B1State == NOT_PRESSED) && (lastB1State == IS_PRESSED)) {
        Serial.print("\n\t\t B1 released");
        allButtons -= 100;
      }

  //check B2
      // pressed (raising edge) 
      // if the button IS pressed AND (&&) lastTime was NOT pressed
      if ((B2State == IS_PRESSED) && (lastB2State == NOT_PRESSED)) {
        Serial.print("\n B2 pressed");
        allButtons += 10;
      } 
      // released (falling edge) 
      if ((B2State == NOT_PRESSED) && (lastB2State == IS_PRESSED)) {
        Serial.print("\n\t\t B2 released");
        allButtons -= 10;
      }

  // check B3 
      // pressed (raising edge) 
      // if the button IS pressed AND (&&) lastTime was NOT pressed
      if ((B3State == IS_PRESSED) && (lastB3State == NOT_PRESSED)) {
        Serial.print("\n B3 pressed");
        allButtons += 1;
      }
      // released (falling edge) 
      if ((B3State == NOT_PRESSED) && (lastB3State == IS_PRESSED)) {
        Serial.print("\n\t\t B3 released");
        allButtons -= 1;
      }
      

   // did VALUE of all buttons change?
   if (allButtons != lastAllButtons){    

       // take action
       // switch...case
       switch (allButtons) {
        
          case 000: // none pressed
            // default do nothing
            break;
    
          case 1:   //001 -- only right pressed
            Serial.println("\n\t 001 -- cyan, freq = 300");
            ledsOff();
            analogWrite(gLED, 100);
            analogWrite(bLED, 50);
            analogWrite(rLED, 20);
            tone(speakerPin, 300);
            break;
    
          case 10: // 010 -- only middle pressed
            Serial.println("\n\t add something here");
            break;
       
          case 11: //011 -- middle and right pressed 
            Serial.println("\n\t 001 -- purple, freq = 500");
            ledsOff();
            analogWrite(bLED,30);
            analogWrite(rLED,40);
            tone(speakerPin, 500);
            break;
            
          case 100: //100 -- only middle pressed
            Serial.println("\n\t add something here");
            break;
    
          // there are 2 more cases -- what are they? 
          
          
          case 111:  // 111 all pressed
            Serial.println("\n\t 111 - everything off"); 
            ledsOff();
            noTone(speakerPin);
            break;
            
          default:
            break;
           
       } // end switch
   } // end if all buttons changed   


  // write in your diary
  lastB1State = B1State; 
  lastB2State = B2State;
  lastB3State = B3State;
  lastAllButtons = allButtons;
  
  delay(100); // play with this
              // smaller == harder to hit combinations 
              // bigger == less responsive

}

void ledsOff(){
  analogWrite(rLED, 0);
  analogWrite(gLED, 0);
  analogWrite(bLED, 0);
}
