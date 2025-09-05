
// RGB fade, RED only up and down
// led STATEs change ACROSS loops


// led PINs
int redLed = 9;

// fade variables
int brightness, STEP=5;

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

  //  *** patterns ***

  // fade red up and down

  // increment the brightness
  brightness += STEP;

  // print out brightness
    Serial.print("   brightness = ");
    Serial.println(brightness);

  // limit brightness
  if ( brightness >= 255) {
    brightness = 255;
    STEP = -5; 
  } 
  if (brightness <= 0){
    brightness=0;
    STEP = 5; 
  }

  // write LED
   analogWrite(redLed, brightness);

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}

