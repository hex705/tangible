// toggle with serial 
// state changes happens ACROSS loops
// serial is used to display messages in the *SERIAL MONITOR*

// led PINs
int ledPin = 5;

// led states
int ledState = 0;

// utility variables 
int loopCounter = 0; 


void setup() {
  // set pinModes
  pinMode(ledPin, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // LED - take action  
  ledState = 1-ledState; // toggle state
  digitalWrite(ledPin, ledState); // write state  
   Serial.print("  LED = "); // print state
   Serial.println(ledState); // print state
  delay(1000);  // wait 1 second

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 
  
}
