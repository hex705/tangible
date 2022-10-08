
// blink LEDs by setting state
// set STATES using 0,1 notation
// write the LEDs

// each RGB cahnnel is like a single LED


// led PINs
int rPin = 3;
int gPin = 5;
int bPin = 6;

// led states
boolean rSTATE = 0;
boolean gSTATE = 0;
boolean bSTATE = 0;


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

 // set STATEs
 Serial.println("set STATES");
 rSTATE = 1;
 gSTATE = 0;
 bSTATE = 1;

 // write the leds
 Serial.println("write leds");
 digitalWrite( rPin, rSTATE);
 digitalWrite( gPin, gSTATE);
 digitalWrite( bPin, bSTATE);

 //delay(1000);

}
