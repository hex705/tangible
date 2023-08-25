
// RGB fade, ONE color at a time 
// led STATEs change WITHIN loops
// each fade is within a FOR..NEXT loop


/* state pattern - within loops 

LOOP-1                        LOOP-2                        LOOP-3 ...

Sequence_1 (FOR..loop)        Sequence_1                    Sequence_1
  redLed    fade up             redLed    fade up             redLed    fade up     
  ms        255*25              ms        255*25              ms        255*25
   
Sequence_2 (FOR..loop)        Sequence_2                    Sequence_2
  redLed    fade down           redLed    fade down           redLed    fade down     
  ms        255*25              ms        255*25              ms        255*25

Sequence_3                    Sequence_3                    Sequence_3
  greenLed  fade up             greenLed  fade up             greenLed  fade up
  ms        255*25                ms        255*25            ms        255*25   

Sequence_4                    Sequence_4                    Sequence_4 
  greenLed  fadeDown            greenLed  fadeDown            greenLed  fadeDown
  ms        255*25              ms        255*25              ms        255*25 

Sequence_5                    Sequence_5                    Sequence_5
  blueLed   fade up             blueLed   fade up             blueLed   fade up 
  ms        255*25              ms        255*25              ms        255*25 

Sequence_6                    Sequence_6                    Sequence_6
  blueLed   fade down ALT       blueLed   fade down ALT       blueLed   fade down ALT
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
  
  // fade red up
  Serial.println("   red up -- 255 steps");
  for(int brightness = 0 ; brightness < 255; brightness ++){
    analogWrite(redLed, brightness);
    delay(25);
  }

  // fade red down
  Serial.println("   red down -- 255 steps");
  for(int brightness = 255 ; brightness > 0; brightness --){
    analogWrite(redLed, brightness);
    delay(25);
  }

  // fade green up
  Serial.println("   green up -- 255 steps");
  for(int brightness = 0 ; brightness < 255; brightness ++){
    analogWrite(greenLed, brightness);
    delay(25);
  }

  // fade green down
  Serial.println("   green down -- 255 steps");
  for(int brightness = 255 ; brightness > 0; brightness --){
    analogWrite(greenLed, brightness);
    delay(25);
  }
  
  // fade blue up
  Serial.println("   blue up -- 255 steps");
  for(int brightness = 0 ; brightness < 255; brightness ++){
    analogWrite(blueLed, brightness);
    delay(25);
  }

  // fade blue down  --    **** NOTE ALT METHOD *****
  Serial.println("   blue down -- 255 steps");
  for(int brightness = 0 ; brightness < 255; brightness ++){
    analogWrite(blueLed, 255 - brightness);
    delay(25);
  }
  
  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}

