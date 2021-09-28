int buttonPIN = 10;
int state = 0;

void setup() {
  pinMode( buttonPIN, INPUT );
  Serial.begin(9600);
}
void loop() {
  state = digitalRead( buttonPIN );
  Serial.println(state);
}
