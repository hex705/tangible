
// blink LED using SINGLE STATE variable
// led STATE changes ACROSS loops not within loops
// This example has equal on/off time.  


// led PINs
int ledPin = 5;

// led STATE
boolean STATE = 0;


void setup() {
  // put your setup code here, to run once:
  
  // set pinModes
  pinMode(ledPin, OUTPUT);
}

void loop() {
 // put your main code here, to run repeatedly:
 
 // toggle STATE
 STATE = 1 - STATE; // can you see why state will go 0,1,0,1... as the arduino loops?

 // write LED
 digitalWrite( ledPin, STATE);
 delay(1000);

}
