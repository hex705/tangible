/*
  select a favourite color -- RGB

  Uses functions to clean up our code. 
   -- led BRIGHTNESS is set using the FXN::  setRGB(int r,int g,int b); 
   -- printing the chosen color uses  FXN::  printRGB(); 
   
  Use your recipe from:: example 04_favouriteColor.ino 
  and then try others.  

  Share your favorite in class.
*/


// led PINs (~)
int redLed = 3;
int greenLed = 5;
int blueLed = 6;

// color channel Variables
int myRedValue = 0;
int myGreenValue = 0;
int myBlueValue = 0;

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

  // *** define your own color ***
  myRedValue = 10;
  myGreenValue = 20;
  myBlueValue = 30;

  // call FXN to set color
  setRGB(myRedValue, myGreenValue, myBlueValue);

  // call FXN to print color
  printRGB();

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++;

  while (1);  // trick to stop you code from looping
}

// FXN to set the RGB value of LED -- colors passed to function.
void setRGB(int setRed, int setGreen, int setBlue) {
  //  *** set color ***
  analogWrite(redLed, setRed);
  analogWrite(greenLed, setGreen);
  analogWrite(blueLed, setBlue);
}

// FXN to print the colors selected by user above.
void printRGB() {
  // *** print color ***
  Serial.print("red   =\t");
  Serial.println(myRedValue);
  Serial.print("green =\t");
  Serial.println(myGreenValue);
  Serial.print("blue  =\t");
  Serial.println(myBlueValue);
}
