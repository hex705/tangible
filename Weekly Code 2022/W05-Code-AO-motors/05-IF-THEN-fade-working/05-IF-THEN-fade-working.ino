// this example is completed version of 
// W05/ 03-IF-then-fade-class


// RGB FADE with IF..THEN (NOT FOR loop)

// each channel has a STATE (eg. rBrightness) and an increment (eg. rStep) value
// brightnesses are written, incremented and then CHECKED -- if they fall out
// of range the direction of INCREMENT (Step) is reversed.


// led PINs
int rPin = 3;
int gPin = 5;
int bPin = 6;

// led Brightness states
int rBrightness, gBrightness=255, bBrightness;

// step variables
int rStep = 5;
int bStep = 1;
int gStep = -5;


void setup() {
  // put your setup code here, to run once:

  // set pinModes
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  // start serial
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.println("loop");

  // write to LEDS
  analogWrite( rPin, rBrightness);
  analogWrite( gPin, gBrightness); 
  analogWrite( bPin, bBrightness);

  // serial out the brightness values
  printBrightnesses(); // fxn below

  // change value to write
  rBrightness = rBrightness + rStep;
  gBrightness = gBrightness + gStep;
  bBrightness = bBrightness + bStep;
         
  // check value ranges
  if ( rBrightness <=0 || rBrightness >= 255) {
    rStep = -rStep;
  }

  if ( gBrightness <=0 || gBrightness >= 255) {
    gStep = -gStep;
  }

  if ( bBrightness <=0 || bBrightness >= 255) {
    bStep = -bStep;  
  }

  // oops but cool -- comment bBrightness above -- note in this g-brightness controls blue
  //      if ( gBrightness <=0 || gBrightness >= 255) {
  //        bStep = -bStep;  
  //      }

  delay(30);
}


// its a function -- we will look at these in W07 -- but if you can write them in JS
// you should be able to write them here

void printBrightnesses(){

  Serial.print(bBrightness);
  Serial.print('\t'); //tab between values - for plotter and columns
  Serial.print(rBrightness);
  Serial.print('\t'); //tab between values - for plotter and columns
  Serial.print(gBrightness);
  Serial.println();  // only one println

}
