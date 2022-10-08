
// blink LED using SINGLE STATE variable
// led STATE changes ACROSS loops not within loops
// This example has equal on/off time.  

// led PINs
int ledPin = 5;

// led STATEs
boolean STATE = 0;


void setup() {
  // put your setup code here, to run once:
  
  // set pinModes
  pinMode(ledPin, OUTPUT);

  // start serial
  Serial.begin(9600);
}

void loop() {

 // put your main code here, to run repeatedly: 
 Serial.println("loop");

 // toggle STATE
 Serial.println("toggle");
 STATE = 1 - STATE; // can you see why state will go 0,1,0,1... as the arduino loops?

 // write the LED 
 digitalWrite( ledPin, STATE);
 delay(1000);

 
}
