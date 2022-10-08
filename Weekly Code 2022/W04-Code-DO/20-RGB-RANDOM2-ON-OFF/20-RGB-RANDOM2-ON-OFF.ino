// has random
// state blink
// led STATE changes across loops not within loops


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

  // pick random value from 0-100
  long lottery = random (0, 100);
  Serial.println(lottery);

  // select a boundary value
  int boundary = 50; // change this and see what happens

  // deterine if boundary is BELOW the boundary
  if ( lottery <= boundary ) {

    // write the leds -- pick a different color
    Serial.println("purple");
    digitalWrite( rPin, ON);
    digitalWrite( gPin, OFF);
    digitalWrite( bPin, ON);
    // wait 1 second
    delay(1000);
  }


  // deterine if boundary is ABOVE the boundary
  if ( lottery >= boundary + 1) {

    // write the leds -- pick a different color
    Serial.println("cyan");
    digitalWrite( rPin, OFF);
    digitalWrite( gPin, ON);
    digitalWrite( bPin, ON);
    // wait 1 second
    delay(1000);
  }


}
