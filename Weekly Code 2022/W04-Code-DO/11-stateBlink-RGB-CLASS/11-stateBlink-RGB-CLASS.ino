
// state blink
// set STATES using 0,1 notation
// write the LEDs


// led PINs
int rPin = 3;
int gPin = 5;
int bPin = 6;

// led states
boolean ON = 1;
boolean OFF = 0;


void setup() {
  // put your setup code here, to run once:

  // set pinModes
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  // start serial
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.println("loop");

  // write the leds ON == 1, HIGH, 5V --- OFF = 0, LOW, Ground
  Serial.println("what color");
  digitalWrite( rPin, ON);
  digitalWrite( gPin, OFF);
  digitalWrite( bPin, OFF);
  // wait 1 second
  delay(1000);

  // write the leds ON == 1, HIGH, 5V --- OFF = 0, LOW, Ground
  Serial.println("other color");
  digitalWrite( rPin, OF);
  digitalWrite( gPin, ON);
  digitalWrite( bPin, ON);
  // wait 1 second
  delay(1000);

}
