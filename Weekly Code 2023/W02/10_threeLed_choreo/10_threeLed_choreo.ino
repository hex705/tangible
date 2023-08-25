
// blink 3 LEDs in sequence
// led STATEs changes WITHIN loops
// change happens every 1000ms (1 sec)

/* pattern -- across loops

        LOOP-1  LOOP-2  LOOP-3   LOOP-4  LOOP-5  LOOP-6 

LED_1     ON     OFF      OFF     ON     OFF      OFF  
LED_2     OFF    ON       OFF     OFF    ON       OFF  
LED_3     OFF    OFF      ON      OFF    OFF      ON

*/

/* state pattern - within loops 

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
int ledPin_1= 5;  // 5
int ledPin_2= 6; // 6
int ledPin_3= 7; // 7

// led states
boolean ON = 1;
boolean OFF = 0;

// led STATEs - decalre but don't set yet
boolean STATE_1, STATE_2, STATE_3; 

// utility variables 
int loopCounter = 0; 
int sequenceCounter = 1;

// duration variables 
int beat = 500;

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

  Serial.print("  sequence ");
  Serial.println(sequenceCounter);

  //  *** sequences ***
  if (sequenceCounter==1){
      // could have other code here too
      setLeds(OFF,OFF,OFF);

      setLeds(ON, ON, ON); 
      delay(beat*3);
      setLeds(ON,OFF,ON);
      delay(beat);
      setLeds(OFF, ON, OFF);
      delay(beat);
      setLeds(ON,OFF,ON);
      delay(beat);

      setLeds(OFF,OFF,OFF);
      delay(beat);
      setLeds(ON,OFF,ON);
      delay(beat);
      setLeds(OFF, ON, OFF);
      delay(beat);
      setLeds(ON,OFF,ON);
      delay(beat);
  }

  if (sequenceCounter==2){
      setLeds(OFF,OFF,OFF);
      delay(beat*2);
      setLeds(ON,ON,OFF);
      delay(beat*3);
      setLeds(OFF,ON,ON);
      delay(beat*3);
      setLeds(OFF, OFF, OFF);
      delay(beat);
       setLeds(ON,ON,ON);
      delay(beat*4);
  }

  if (sequenceCounter==3){
      setLeds(OFF, OFF, OFF);
      delay(2000);
  }


    // ***********   increment sequence counter    *****************
  sequenceCounter++;
  if (sequenceCounter > 3) sequenceCounter = 1; // constrain to 3 sequences                                      

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 
}

void setLeds(int state1, int state2, int state3){

  // ***********   write the LEDs  *****************
 // Serial.print("   New sequence - ");
 // Serial.print(sequenceCounter);   // ** new
  digitalWrite(ledPin_1, state1);
  digitalWrite(ledPin_2, state2);
  digitalWrite(ledPin_3, state3);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("\tled states ->\t");
   Serial.print(state1 );
    Serial.print("\t"); // NOTE ::  \t = tab
     Serial.print(state2); 
      Serial.print("\t");  // NOTE ::  \t = tab
       Serial.println(state3); // println adds end of line and new line

}
