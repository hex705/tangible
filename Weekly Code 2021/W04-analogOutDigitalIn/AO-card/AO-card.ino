//Analog Output example -- card

int ledPIN = 6;
int state = 0;


void setup() {
  pinMode( ledPIN, OUTPUT );
}

void loop() {

    analogWrite( ledPIN, state );
    state++;
    delay(50);

}
