 // W11_02
 // GOAL:: light controls speed 
  
// set up variables for each motor wire
// the number identifies to which PIN we connected
// the motor control wire.

const int green  = 4 ; // where is the circuit ?
const int blue   = 5 ; // where is the circuit?
const int yellow = 8 ; // where is the circuit?
const int red    = 9 ;

int buttonPin =   2 ;  // switched from 
int ledPin    =   3 ;  // last week?

 int leftSpeedPin  =  6 ;
 int rightSpeedPin =  11;

 int leftEye = A5  ; // pin -- note the A prefix!
 int rightEye = A4  ; // pin
 int leftEyeValue, rightEyeValue, averageEyes, lightThreshold;
 int offset = 30; // 30 in dark 
 
void setup() {
  
  // set up pinModes for the wires
  pinMode (blue,   OUTPUT);
  pinMode (green,  OUTPUT);
  pinMode (red,    OUTPUT);
  pinMode (yellow, OUTPUT);

  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);

  pinMode(buttonPin, INPUT  );  
  pinMode(ledPin,    OUTPUT );

  // Start Serial
  Serial.begin(9600);
  Serial.println(__FILE__);
  Serial.println("bot is stading by");


  // comment out line below if you don't have button setup on pin 2
  HCI_waitForButtonPress();  
   
}

void loop() {
// put your main code here, to run repeatedly:
  readEyes();
  printEyes();

  leftEyeValue += offset;
  rightEyeValue += offset;
  
     // keep eye values in range of motors speeds (0-255) - redundant ? 
    if ( leftEyeValue > 200 ) leftEyeValue  = 240;
    if ( rightEyeValue > 200) rightEyeValue = 240;

    if ( leftEyeValue  <= 90 ) leftEyeValue  = 90;
    if ( rightEyeValue <= 90 ) rightEyeValue = 90;

  
  forward( leftEyeValue , rightEyeValue ); // away from light
  //forward( rightEyeValue , leftEyeValue ); // away from light
}
