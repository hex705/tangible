
//simple LED blink 
// state changes happen within each loop 

// led PINs
int ledPin = 5;

// led states
boolean ON = 1;
boolean OFF = 0;


void setup() {
  // put your setup code here, to run once:
  
  // set pinModes
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // set ledPIN HIGH - LED ON
  digitalWrite(ledPin, ON);// ON == 1 == HIGH ==> 5V 
  // wait 1 second
  delay(1000);
  
  // set ledPIN LOW -- LED OFF
  digitalWrite(ledPin, OFF);// OFF == 0 == LOW ==> 0V(GND) 
  // wait 1 second
  delay(1000);
}
