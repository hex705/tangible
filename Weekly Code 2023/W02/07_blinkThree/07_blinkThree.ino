
// blink 3 LEDs in sequence
// led STATEs changes WITHIN loops
// change happens every 1000ms (1 sec)

/* pattern -- across loops

        LOOP-1  LOOP-2  LOOP-3   LOOP-4  LOOP-5  LOOP-6 

LED_1     ON     OFF      OFF     ON     OFF      OFF  
LED_2     OFF    ON       OFF     OFF    ON       OFF  
LED_3     OFF    OFF      ON      OFF    OFF      ON

*/

/* pattern - within loops 

        LOOP-1  LOOP-2  LOOP-3  LOOP-4  LOOP-5  LOOP-6 ...

Sequence_1
LED_1     ON     ON      ON      ON      ON      ON  
LED_2     OFF    OFF     OFF     OFF     OFF     OFF  
LED_3     OFF    OFF     OFF     OFF     OFF     OFF

Sequence_2
LED_1     OFF    OFF     OFF     OFF     OFF     OFF  
LED_2     ON     ON      ON      ON      ON      ON  
LED_3     OFF    OFF     OFF     OFF     OFF     OFF

Sequence_3
LED_1     OFF    OFF     OFF     OFF     OFF     OFF  
LED_2     OFF    OFF     OFF     OFF     OFF     OFF 
LED_3     ON     ON      ON      ON      ON      ON
*/

// led PINs
int ledPin_1= 5;
int ledPin_2= 6;
int ledPin_3= 7;

// led states
boolean ON = 1;
boolean OFF = 0;

// led STATEs - declare but don't set yet
boolean STATE_1, STATE_2, STATE_3; 

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // ***********   Sequence_1 :: set led STATEs  *****************
  STATE_1 = ON;
  STATE_2 = OFF;
  STATE_3 = OFF;
  
  // ***********   write the LEDs  *****************
  Serial.print("   Sequence 1\t");
  digitalWrite(ledPin_1, STATE_1);
  digitalWrite(ledPin_2, STATE_2);
  digitalWrite(ledPin_3, STATE_3);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("leds-> ");
   Serial.print(STATE_1 );
    Serial.print("\t"); // NOTE ::  \t = tab
     Serial.print(STATE_2); 
      Serial.print("\t");  // NOTE ::  \t = tab
       Serial.println(STATE_3); // println adds end of line and new line

  // ***********   determine the delay - they blink at same time   *****************
  delay(2000);

    // ***********   Sequence_2 :: set led STATEs  *****************
  STATE_1 = OFF;
  STATE_2 = ON;
  STATE_3 = OFF;
  
  // ***********   write the LEDs  *****************
  Serial.print("   Sequence 2\t");
  digitalWrite(ledPin_1, STATE_1);
  digitalWrite(ledPin_2, STATE_2);
  digitalWrite(ledPin_3, STATE_3);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("leds-> ");
   Serial.print(STATE_1 );
    Serial.print("\t"); // NOTE ::  \t = tab
     Serial.print(STATE_2); 
      Serial.print("\t");  // NOTE ::  \t = tab
       Serial.println(STATE_3); // println adds end of line and new line

  // ***********   determine the delay - they blink at same time   *****************
  delay(2000);

    // ***********   Sequence_3 :: set led STATEs  *****************
  STATE_1 = OFF;
  STATE_2 = OFF;
  STATE_3 = ON;
  
  // ***********   write the LEDs  *****************
  Serial.print("   Sequence 3\t");
  digitalWrite(ledPin_1, STATE_1);
  digitalWrite(ledPin_2, STATE_2);
  digitalWrite(ledPin_3, STATE_3);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("leds-> ");
   Serial.print(STATE_1 );
    Serial.print("\t"); // NOTE ::  \t = tab
     Serial.print(STATE_2); 
      Serial.print("\t");  // NOTE ::  \t = tab
       Serial.println(STATE_3); // println adds end of line and new line

  // ***********   determine the delay - they blink at same time   *****************
  delay(2000);

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 
}
