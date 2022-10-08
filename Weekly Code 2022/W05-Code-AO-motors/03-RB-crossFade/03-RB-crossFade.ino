
// RGB cross fade 
// 
// two RGB channels are controlled WITHIN a single FOR .. LOOP
// https://www.arduino.cc/reference/en/language/structure/control-structure/for/


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
     analogWrite( bPin, 255-brightness);
     delay(20);
     Serial.println(brightness);
  }

  // can you write a loop that fades down?
}
