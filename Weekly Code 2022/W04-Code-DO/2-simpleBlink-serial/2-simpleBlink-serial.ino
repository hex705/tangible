
// simple LED blink with serial messages
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

  // start serial
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  Serial.println("loop");

  // set ledPIN HIGH - LED ON
  Serial.println("ON");
  digitalWrite(ledPin, ON);// ON == 1 == HIGH ==> 5V 
  // wait 1 second
  delay(1000);

  // set ledPIN LOW -- LED OFF
  Serial.println("OFF");
  digitalWrite(ledPin, OFF);// OFF == 0 == LOW ==> 0V(GND) 
  // wait 1 second
  delay(1000);
}
