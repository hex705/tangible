// tangible 
// steve daniels, Oct 2021

// basic analogRead with photocell circuit

int sensorPin = A0;
int state = 0;

void setup() {
  pinMode(sensorPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  state = analogRead( sensorPin ); 
  Serial.println(state); 
  delay(50); 
}
