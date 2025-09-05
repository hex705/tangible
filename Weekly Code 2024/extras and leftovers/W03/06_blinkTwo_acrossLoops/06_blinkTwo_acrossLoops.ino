
// blink 2 LEDs using a STATE variable for EACH LED.
// led STATE changes ACROSS loops
// SYMMETRIC on OFF - alternating LEDs 

/* pattern

        LOOP-1  LOOP-2  LOOP-3  LOOP-4
LED_1     ON     OFF      ON     OFF
LED_2     OFF    ON       OFF    ON

*/

// led PINs
int ledPin_1= 5;
int ledPin_2= 6;

// led states
boolean ON = 1;
boolean OFF = 0;

// led STATEs
boolean STATE_1 = ON;   
boolean STATE_2 = OFF;  // STARTS OFF

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // ***********   change led STATEs  *****************

  // change led STATE with IF..THEN
  // explicit we can see the state
  if (STATE_1 == ON){
    STATE_1=OFF;
  } else {
    STATE_1=ON;
  }

  // change led_2 STATE_2 with logic (toggle)  
  // same outcome as above, less code -- may be harder to read ? YMMV    
  STATE_2 = 1 - STATE_2; // can you see why state will go 0,1,0,1... as the arduino loops?

  // ***********   write the LEDs  *****************
  Serial.print("   Condition Changed\t");
  digitalWrite(ledPin_1, STATE_1);
  digitalWrite(ledPin_2, STATE_2);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("LED_1-> ");
   Serial.print(STATE_1 );
    Serial.print("\t LED_2-> "); // NOTE ::  \t = tab
     Serial.println(STATE_2); // println adds end of line and new line

  // ***********   determine the delay - they blink at same time   *****************
  if (STATE_1 == ON) {
    // if led_1 is on, led_1 ON, led_2 OFF time 
    delay(2000);
  } else {
    // led_1 is off, led_1 OFF time, led_2 ON time
    delay(2500);
  }

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 
}
