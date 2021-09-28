// digital input
// sample code for a single button

// https://tangiblemedia.ca/explore/digital-inputs/

int buttonPIN = 12;
int state = 0;

void setup() {
  pinMode( buttonPIN, INPUT );
  Serial.begin(9600);
}

void loop() {
  state = digitalRead( buttonPIN ); 
  Serial.println(state);
}
