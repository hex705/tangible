// blink 3 LEDs in three (3) different patterns
// led STATEs change ACROSS loops


// led PINs - check connections!
int redPin = 3;
int greenPin = 5;
int bluePin = 6;

// possible LED states
boolean ON = 1;
boolean OFF = 0;

// color channel Variables
int redValue   = 1;
int blueValue  = 0; // what happens if these are both 1? 

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // -----------   Alternating Pattern, across loops   ------------------

  // ***********   write the LEDs  *****************
  Serial.print("   Pattern:: \t");
   Serial.print(redValue);
    Serial.print("\t");
     Serial.println(blueValue);

  digitalWrite(redPin, redValue);
  digitalWrite(bluePin, blueValue);
 

  // ***********   determine the delay - they blink at same time   *****************
  delay(1000);

  // ***********   TOGGLE the digital state of a value   *****************  
  redValue = 1 - redValue;  // can you see why this alternates 0,1,0,1,0,1 ... ?
  blueValue = 1 - blueValue;

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 
}
