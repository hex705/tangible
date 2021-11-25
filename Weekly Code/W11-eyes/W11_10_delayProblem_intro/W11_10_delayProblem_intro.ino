// W11_10  delay problem 
// open serial monitor once code is uploaded

// need button circuit on pin 2, led on pin 3 
int buttonPin = 2;
int buttonState= 0;

int ledPin = 3;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
   pinMode(buttonPin, INPUT);
   pinMode(ledPin,    OUTPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin); 
  Serial.println ( buttonState );

// run once with this block commented out 
// then uncomment and run again

  digitalWrite( ledPin, 1);
  Serial.println ( "LED HIGH" );
  delay(1000);
  digitalWrite( ledPin,0);
  Serial.println ( "LED LOW" );
  delay(1000); 
  
  
}
