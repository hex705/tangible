// blink 2 LEDs using a STATE variable for EACH LED.
// led STATEs change WITHIN loops in sync with each other
// ASYMMETRIC ON / OFF - alternating LEDs 


/* pattern

        LOOP-1            LOOP-1          LOOP-2            LOOP-2         
        SEQUENCE-1       SEQUENCE-2     SEQUENCE-1       SEQUENCE-2
LED_1     ON               OFF               ON                OFF
LED_2     OFF              ON                OFF               ON
   ms     500              1000              500              1000
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

}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);
  // +++++++++++++++++++++++  SEQUENCE 1  +++++++++++++++++++++
  // set led states for SEQUENCE 1
  // LED_1 ON, led_2 OFF
  STATE_1 = ON;             // can you see why state will go 0,1,0,1... as the arduino loops?
  STATE_2 = OFF;

  // ***********   write the LEDs
  digitalWrite(ledPin_1, STATE_1);
  digitalWrite(ledPin_2, STATE_2);

  // ***********   print sequence LED states side by side       
  Serial.println("   SEQUENCE 1\t");
   Serial.print("\tLED_1 ");
    Serial.println(STATE_1 );
     Serial.print("\tLED_2 "); // NOTE ::  \t = tab
      Serial.println(STATE_2); // println adds end of line and new line

  // ***********   SEQUENCE-1 delay
  delay ( 500 ); 

 // +++++++++++++++++++++++  SEQUENCE 2  +++++++++++++++++++++
 // set led states for SEQUENCE 2
 // LED_1 ON, led_2 OFF
  STATE_1 = OFF;             // can you see why state will go 0,1,0,1... as the arduino loops?
  STATE_2 = ON;

  // ***********   write the LEDs
  digitalWrite(ledPin_1, STATE_1);
  digitalWrite(ledPin_2, STATE_2);

  // ***********  print LED states side by side         
  Serial.println("   SEQUENCE 2\t");
   Serial.print("\tLED_1 ");
    Serial.println(STATE_1 );
     Serial.print("\tLED_2 "); // NOTE ::  \t = tab
      Serial.println(STATE_2); // println adds end of line and new line

  // ***********   SEQUENCE-2 delay
  delay ( 1000 ); 

  // ***********   increment loop counter
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}
