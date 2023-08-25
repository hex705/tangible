
// RGB fade, TWO colors at a time 
// led STATEs change WITHIN loops
// each fade is within a FOR..NEXT loop


/* state pattern - within loops 

LOOP-1                        LOOP-2                        LOOP-3 ...

Sequence_1 (FOR..loop)        Sequence_1                    Sequence_1
  redLed    fade up             redLed    fade up             redLed    fade up     
  blueLed   fadeDown            blueLed   fadeDown            blueLed   fadeDown
  ms        255*25              ms        255*25              ms        255*25
   
Sequence_2                    Sequence_2                    Sequence_2
  greenLed  fade up             greenLed  fade up             greenLed  fade up
  redLed    fadeDown            redLed    fadeDown            redLed    fadeDown
  ms        255*25   

Sequence_3                    Sequence_3                    Sequence_3
  blueLed   fade up             blueLed   fade up             blueLed   fade up 
  greenLed  fadeDown            greenLed  fadeDown            greenLed  fadeDown
  ms        255*25              ms        255*25              ms        255*25 
   
*/

// led PINs
int redLed = 9;
int greenLed = 10;
int blueLed = 11;


// led STATEs - decalre but don't set yet
int STATE_1, STATE_2, STATE_3; 

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  //  *** sequences ***
  
  // cross fade red up, blue down
  Serial.println("   red up, blue down -- 255 steps");
  for(int brightness = 0 ; brightness < 255; brightness ++){
    analogWrite(redLed, brightness);
    analogWrite(blueLed, 255 - brightness);
    delay(25);
  }

  // cross fade green up, red down
  Serial.println("   green up and red down -- 255 steps");
  for(int brightness = 0 ; brightness < 255; brightness ++){
    analogWrite(greenLed, brightness);
    analogWrite(redLed, 255 - brightness);
    delay(25);
  }

  // cross fade blue up, green down
  Serial.println("   blue up, green down -- 255 steps");
  for(int brightness = 0 ; brightness < 255; brightness ++){
    analogWrite(blueLed, brightness);
    analogWrite(greenLed, 255 - brightness);
    delay(25);
  }

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}


// **************   function:: set leds   *********************
// function that sets 3 LEDs to state (ON/OFF)
// function also debugs the states

void setLeds(int state1, int state2, int state3){

  // ***********   write the LEDs  *****************
  Serial.print("   New sequence - ");
  digitalWrite(redLed, state1);
  digitalWrite(greenLed, state2);
  digitalWrite(blueLed, state3);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("led states ->\t");
   Serial.print(state1 );
    Serial.print("\t"); // NOTE ::  \t = tab
     Serial.print(state2); 
      Serial.print("\t");  // NOTE ::  \t = tab
       Serial.println(state3); // println adds end of line and new line

}
