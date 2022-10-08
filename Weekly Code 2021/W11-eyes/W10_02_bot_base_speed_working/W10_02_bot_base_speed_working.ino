 // W10_02
 // GOAL::  perform a routine AFTER button press
  
// set up variables for each motor wire
// the number identifies to which PIN we connected
// the motor control wire.

const int green  = 4 ; // where is the circuit ?
const int blue   = 5 ; // where is the circuit?
const int yellow = 8 ; // where is the circuit?
const int red    = 9 ;

int buttonPin =   2 ;  // switched from 
int ledPin    =   3 ;  // last week?

 int leftSpeedPin  =  6;
 int rightSpeedPin =  11;

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

   forward();  
   setSpeed(95, 150); // 150 , 85 
   delay(2000);

  // steve add the reverse direction back in 
   forward( 150, 95) ; 
   delay(2000); 

   
   backward(85,150);
   //delay(2500);    
 
}
