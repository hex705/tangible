
// select a favourite color -- RGB
// led BRIGHTNESS is set once in the LOOP - share your recipe in class. 

// led PINs (~)
int redLed   = 3;
int greenLed = 5;
int blueLed  = 6;

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(redLed,   OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed,  OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // *** define your own color ***
  int myRedValue   = 0;
  int myGreenValue = 0;
  int myBlueValue  = 0;

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

