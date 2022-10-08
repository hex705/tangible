
// RGB FADE
// single RGB channel is FADED with a FOR... loop
// https://www.arduino.cc/reference/en/language/structure/control-structure/for/

// note -- the WHOLE FADE happens inside a single loop

// each RGB channel is like a single LED


// led PINs
int rPin = 3;
int gPin = 5;
int bPin = 6;

// led states



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

  for (int brightness = 0; brightness <= 255; brightness ++) {
     analogWrite( rPin, brightness);  
     delay(10);
     Serial.println(brightness);
  }
}
