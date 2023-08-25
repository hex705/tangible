// blink LED across loops (not within loops)
// A STATE variable is used to maintain LED condition across loops
// This example has equal on/off time.
// Serial is used to show pattern -- open serial monitor once uploaded.

/* pattern
        LOOP-1  LOOP-2  LOOP-3  LOOP-4
LED_1     ON     OFF      ON     OFF
   ms    1000   1000     1000   1000
*/

// led PINs
int ledPin = 5;

// led states
boolean ON = 1;
boolean OFF = 0;

// led STATE
boolean STATE = OFF; // 0


void setup() {
  // put your setup code here, to run once:

  // set pinModes
  pinMode(ledPin, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");

  /* toggle STATE -- TWO ways try them both !
     below are IF..THEN and logic toggles - comment one to use the other
     use them one at a time
     what happens if you use both methods each loop?
  */

  /* change led STATE with IF..THEN  */
  if (STATE == ON) {  // compare with two equals ==
    STATE = OFF;      // set a value with one =
  } else {  // was off, turn it on
    STATE = ON;
  }

    /* alt method -- comment IF..THEN above, 
      uncomment below to change led STATE with logic toggle  
    */
    // STATE = 1 - STATE;  // can you see why state will go 0,1,0,1... as the arduino loops?

  // write LED state 
  digitalWrite(ledPin, STATE);
  
  // print led state
  Serial.print("  LED ");
  Serial.println(STATE); // with print 0 = OFF, 1 = ON

  // single delay time
  delay(1000);

}
