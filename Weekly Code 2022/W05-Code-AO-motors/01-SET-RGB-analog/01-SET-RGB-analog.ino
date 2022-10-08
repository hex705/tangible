
// RGB color SET -- one fixed color using analogWrite
// each channel STATE from 0-255
// write the LEDs as a group

// each RGB channel is like a single LED


// led PINs
int rPin = 3;
int gPin = 5;
int bPin = 6;


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


  // select a color by mixing 
  // each channel can be 0-255
  Serial.println("what color?");
  analogWrite( rPin, 0);     // 200
  analogWrite( gPin, 127);   //  40
  analogWrite( bPin, 255);   //   0
  
  // wait 1 second
  delay(1000);

  // add another color ? 

  // while(1);


}
