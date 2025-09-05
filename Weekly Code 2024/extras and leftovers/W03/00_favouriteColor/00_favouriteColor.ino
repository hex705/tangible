
// RGB fade, single (RED) led only 
// led BRIGHTNESS changes WITHIN loops
// each fade is within a FOR..NEXT loop


/* state pattern - within loops 

LOOP-1                        LOOP-2                        LOOP-3 ...

Sequence_1 (FOR..loop)        Sequence_1                    Sequence_1
  redLed    fade up             redLed    fade up             redLed    fade up     
  ms        255*25              ms        255*25              ms        255*25
   
*/

// led PINs
int redLed = 9;
int greenLed = 10;
int blueLed = 11;

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

  // *** define color ***
  int myRedValue   = 20;
  int myGreenValue = 20;
  int myBlueValue  = 20;

  // *** print color ***
  Serial.print("red   =\t" );
    Serial.println(myRedValue);
  Serial.print("green =\t");
    Serial.println(myGreenValue);
  Serial.print("blue  =\t");
    Serial.println(myBlueValue);

  //  *** set color ***
  analogWrite(redLed, myRedValue);
  analogWrite(greenLed, myGreenValue);
  analogWrite(blueLed, myBlueValue);

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

  while(1); // trick to stop you code from looping

}

