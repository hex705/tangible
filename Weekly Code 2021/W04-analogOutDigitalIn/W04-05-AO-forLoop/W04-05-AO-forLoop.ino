//Analog Output example -- for loop 

int ledPIN = 6;
int state = 0;


void setup() {
  pinMode( ledPIN, OUTPUT );
}

void loop() {

  //  analogWrite( ledPIN, state );
  //  state++;
  //  delay(50);

  for (int brightness = 0; brightness < 255; brightness++ ) {
    analogWrite( ledPIN , brightness ); // pin, state
    delay(10);
  }

}
