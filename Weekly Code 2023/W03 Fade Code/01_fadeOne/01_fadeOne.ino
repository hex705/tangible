
// RGB fade, RED only 
// led STATEs change WITHIN loops
// each fade is within a FOR..NEXT loop


// led PINs
int redLed = 3;

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
  for(int brightness = 0 ; brightness <= 255; brightness+=1){ 

    analogWrite(redLed, brightness);     // STATE + BRIGHTNESS
      Serial.print("   brightness = ");
      Serial.println(brightness);
    delay(25);
    
  }

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}

