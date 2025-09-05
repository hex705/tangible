// blink LED across loops (not within loops)
// A STATE variable is used to maintain LED condition across loops
// This example has un-equal or A-SYMMETRIC on/off time.
// Serial is used to show pattern -- open serial monitor once uploaded.

/* pattern
        LOOP-1  LOOP-2  LOOP-3  LOOP-4
LED_1     ON     OFF      ON     OFF
   ms    1000    500     1000    500
*/


// led PINs
int ledPin = 5;

// led states
boolean ON = 1;
boolean OFF = 0;

// led STATEs
boolean STATE = OFF; // 0
int onTime = 1000;
int offTime = 500;
int delayTime;

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

  /* change led STATE with IF..THEN  */
  if (STATE == ON) {  // compare with two equals ==
    STATE = OFF;      // set a value with one =
    delayTime = offTime;
  } else {  // was off, turn it on
    STATE = ON;
    delayTime = onTime;
  }

  // write LED state
  digitalWrite(ledPin, STATE);

  // print led state
  Serial.print("  LED ");  // no ln !
  Serial.println(STATE);         // now the ln !

  // delay 
  delay(delayTime);

  
}
