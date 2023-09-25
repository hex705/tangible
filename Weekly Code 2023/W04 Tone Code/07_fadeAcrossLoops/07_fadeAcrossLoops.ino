
// cross fade RGB across loops. 
// we use a variable called colorStepCounter to hold the brightness state.
// we adjust the colorStepCounter by an increment each loop.
// we limit the colorStepCounter to 255 at the top and 0 at the bottom of the 'stairs'

// led PINs (~)
int redLed   = 3;
int greenLed = 5;
int blueLed  = 6;

// color channel Variables
int redValue   = 0;
int greenValue = 0;
int blueValue  = 0;

// utility variables 
int loopCounter = 0; 

int colorStepCounter = 0;
int colorIncrement = 1;

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

  // *** define the color ***
  redValue   = colorStepCounter;
  greenValue = 0; // not used in example
  blueValue  = 255 - colorStepCounter;

  // call FXN to set color
  setRGB (redValue, greenValue, blueValue);

  // call FXN to print color
  printRGB();

  // color step counter
  colorStepCounter += colorIncrement;

  // if at top of stairs, change direction to negative
  if (colorStepCounter > 255) {
    colorStepCounter = 255;
    colorIncrement = -1; 
  }

  if ( colorStepCounter < 0 ) {
    colorStepCounter = 0;
    colorIncrement = 1;
  }


  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

  delay(25);

}

// FXN to set the RGB value of LED -- colors passed to function.
void setRGB (int setRed, int setGreen, int setBlue){
  //  *** set color ***
  analogWrite(redLed,   setRed );
  analogWrite(greenLed, setGreen );
  analogWrite(blueLed,  setBlue );
}

// FXN to print the colors selected by user above. 
void printRGB (){
  // *** print color ***
  Serial.print("\t red, green, blue =\t" );
    Serial.print(redValue);
  Serial.print(",\t");
    Serial.print(greenValue);
  Serial.print(",\t");
    Serial.print(blueValue);

    if ( colorIncrement > 0) {
       Serial.println("\tCounter going up.\n");  
    } else {
       Serial.println("\tCounter going back down.\n");
    }
}

