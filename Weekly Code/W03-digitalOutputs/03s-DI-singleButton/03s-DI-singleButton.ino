// 03s-DI-singleButton
// GOAL -- read a button (digital input)
// send that reading over serial

int buttonPin_1 = 10;  // pin declare
int buttonState_1 = 0; // state of button

void setup() {
  pinMode(buttonPin_1, INPUT);// INPUT OR OUTPUT ?
  Serial.begin(9600);
}

void loop () {
  buttonState_1 = digitalRead(buttonPin_1);// read button

  Serial.println(buttonState_1); // print button state
}
