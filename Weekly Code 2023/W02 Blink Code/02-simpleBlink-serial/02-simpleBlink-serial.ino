// simple LED blink with serial messages
// state changes happen within each loop 
// serial is used to display messages in the *SERIAL MONITOR*



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
  Serial.println(__FILE__); // print file name 
}

void loop() {
  
      // put your main code here, to run repeatedly:
      Serial.println("loop");

  // write ledPIN HIGH - LED ON
  digitalWrite(ledPin, ON);// ON == 1 == HIGH ==> 5V 

      // print led state 
      Serial.println("  LED ON");

  // wait 1 second
  delay(1000);

  // write ledPIN LOW -- LED OFF
  digitalWrite(ledPin, OFF);// OFF == 0 == LOW ==> 0V(GND) 

      // print led state 
      Serial.println("  LED OFF");
    
  // wait 1 second
  delay(1000);
}


