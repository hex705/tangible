//04s-IO-buttonToLed
// solution (one of many)

/* add an IF statement to link INPUT to OUTPUT.  You will need to add the OUTPUT circuit to breadboard and include with code.*/


int buttonPin_1 = 10;
int buttonState_1 = 0;
int ledPin = 5; // add an LED pin definition here


void setup() {
  pinMode(buttonPin_1, INPUT);
  pinMode(ledPin, OUTPUT); // add an LED pinmode here

  Serial.begin(9600);
}

void loop() {
  buttonState_1 = digitalRead(buttonPin_1);
  Serial.println(buttonState_1);

  /* add if statement below https://www.arduino.cc/reference/en/language/structure/control-structure/if/
  */

  if (buttonState_1 == 1) {
    digitalWrite(ledPin, 1);
  } else {
    digitalWrite(ledPin, 0);
  }

}
