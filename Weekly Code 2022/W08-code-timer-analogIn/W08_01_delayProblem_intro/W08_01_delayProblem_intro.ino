// W08_01  delay problem
// open serial monitor once code is uploaded

// need button circuit on pin 6, led on pin 13
int buttonPin = 6;  // built in
int buttonState = 0;
int ledState = 0;

int ledPin = 13;

void setup() {
  // put ;your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
  pinMode(ledPin,    OUTPUT);
}

void loop() {

  // read button every loop
  buttonState = digitalRead(buttonPin);
  Serial.print ( buttonState );

  // run once with this block commented out
  // then uncomment and run again

  // toggles the led state -- but BLOCKS loop
//      ledState = 1 - ledState;         // toggle LED
//      digitalWrite(ledPin, ledState);  // write to LED
//      printLEDState();                 // print out LED state
//      delay(1000);                     // delay 1 second for blink

 Serial.println();
}




void printLEDState() {
  // the led range is 0,1 the button is also 0,1
  // on the plotter they overlap visually
  // we can move the LED UP by adding the shift variable.
  
  int shift = 3; // move the LED above the botton on display
  // output the state to monitor
  Serial.print("\t");
  if (ledState == 1) {
    //Serial.print("\tLED HIGH\t");
    Serial.print(1 + shift);
  } else {
    //Serial.print("\tLED LOW\t");
    Serial.print(0 + shift);
  }
}
