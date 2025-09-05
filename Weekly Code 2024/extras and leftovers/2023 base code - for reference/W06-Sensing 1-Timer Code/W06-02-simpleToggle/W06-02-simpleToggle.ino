// toggle with serial 
// state changes happens ACROSS loops

// led PINs
int ledPin = 11;

// led states
ledState = 0;

void setup() {
  // set pinModes
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // toggle the LED
  ledState = 1-ledState; // toggle 
  digitalWrite(ledPin, ledState); // write state  
  delay(1000);  // wait 1 second

}
