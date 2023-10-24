// simple LED blink with serial messages
// state changes happen WITHIN each loop 
// serial is used to display messages in the *SERIAL MONITOR*

// led PINs
int ledPin = 11;

// led states
boolean ON = 1;
boolean OFF = 0;

// utility variables 
int loopCounter = 0; 

void setup() {
// set pinModes
  pinMode(ledPin, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__); // print file name 
}

void loop() {
  
  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // write ledPIN HIGH - LED ON
  digitalWrite(ledPin, ON);    // ON == 1 == HIGH ==> 5V 
  Serial.println("  LED ON");  // print led state 
  delay(1000);                 // wait 1 second

  // write ledPIN LOW -- LED OFF
  digitalWrite(ledPin, OFF);// OFF == 0 == LOW ==> 0V(GND) 
  Serial.println("  LED OFF");  // print led state
  delay(1000);  // wait 1 second

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}


