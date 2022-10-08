
// RGB blink
// each channel set ON or OFF
// write the LEDs as a group

// each RGB channel is like a single LED


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

  // first color
  // write the leds ON == 1, HIGH, 5V --- OFF = 0, LOW, Ground
  Serial.println("what color?");
  digitalWrite( rPin, ON);
  digitalWrite( gPin, ON);
  digitalWrite( bPin, OFF);

  // wait 1 second
  delay(1000);

  // second color
  // write the leds ON == 1, HIGH, 5V --- OFF = 0, LOW, Ground
  Serial.println("what color?");
  digitalWrite( rPin, OFF);
  digitalWrite( gPin, OFF);
  digitalWrite( bPin, ON);

  // wait 1 second
  delay(1000);

  // while(1);


}
