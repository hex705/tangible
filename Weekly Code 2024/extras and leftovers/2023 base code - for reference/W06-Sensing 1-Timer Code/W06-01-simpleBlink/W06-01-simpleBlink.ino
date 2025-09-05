// simple LED blink 
// state changes happen WITHIN each loop 

// led PINs
int ledPin = 11;

// led states
boolean ON = 1;
boolean OFF = 0;


void setup() {
// set pinModes
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // write ledPin to ON ( HIGH, 1, 5V);
  digitalWrite(ledPin, ON);// ON == 1 == HIGH, [electrical 5V] 
  // wait 1 second
  delay(1000);
  
  // write ledPin to OFF (LOW, 0, GND);
  digitalWrite(ledPin, OFF);// OFF == 0 == LOW, [electrical 0V(GND)] 
  // wait 1 second
  delay(1000);
}
