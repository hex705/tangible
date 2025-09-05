int buttonPin = 4;
int buttonState = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println(digitalRead(buttonPin));
}
