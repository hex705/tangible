
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

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(redLed, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  //  *** pattern ***

  // fade red up
  //                 START              STOP         STEP = 1
  for(int brightness = 0 ; brightness <= 255; brightness+=1){ // note stop SIGN is < (less than) or equal
    analogWrite(redLed, brightness);
      Serial.print("   brightness = ");
      Serial.println(brightness);
    delay(25);
  }

  // fade red down
  //                 START              STOP         STEP = 1
  for(int brightness = 255 ; brightness >= 0; brightness-=1){  // note stop SIGN changed to > (greater than) or equal
    analogWrite(redLed, brightness);
      Serial.print("   brightness = ");
      Serial.println(brightness);
    delay(25);
  }

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}

