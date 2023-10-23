// W08_01  delay problem
// open serial monitor once code is uploaded

// need button circuit on pin 2, led on pin 11
int buttonPin = 2;  
int buttonState = 0;

// led vars 
int ledPin = 11;
int ledState = 0;

void setup() {

  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
  pinMode(ledPin,    OUTPUT);
}

void loop() {

  // read button every loop
  buttonState = digitalRead(buttonPin);
  Serial.print ( "button = " );
  Serial.print ( buttonState );

  // run once with this block commented out
  // then uncomment and run again

  // toggles the led state -- but BLOCKS loop
          //  ledState = 1 - ledState;         // toggle LED
          //  digitalWrite(ledPin, ledState);  // write to LED
          //  Serial.print("\t");              // print out LED state
          //  Serial.print ( "LED = " );
          //  Serial.print ( ledState );              
          //  delay(1000);                     // delay 1 second for blink

 Serial.println();
}

