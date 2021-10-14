
// digital input 

int buttonPin = 3;
int buttonState = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
   buttonState = digitalRead(buttonPin); 
   Serial.println( buttonState); 
 
}
