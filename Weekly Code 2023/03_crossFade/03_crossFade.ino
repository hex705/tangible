
// RGB cross fade, two LED channels
// led BRIGHTNESS changes WITHIN loops
// each fade is within a FOR..NEXT loop


// led PINs
int redLed = 3;
int greenLed = 5;
int blueLed = 6;

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

  //  *** pattern 1 ***

  Serial.println("   cross:  red up, blue down ");
  //                 START              STOP         STEP = 1
  for(int brightness = 0 ; brightness <= 255; brightness+=1){ // note stop SIGN is < (less than) or equal
    analogWrite(redLed, brightness);
    analogWrite(blueLed, 255-brightness);
    delay(25);
  }

  //  *** pattern 2 ***

  Serial.println("   cross:  blue up, red down ");
  //                 START              STOP         STEP = 1
  for(int brightness = 255 ; brightness >= 0; brightness-=1){  // note stop SIGN changed to > (greater than) or equal
    analogWrite(redLed, brightness);
    analogWrite(blueLed, 255-brightness);
    delay(25);
  }

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}

