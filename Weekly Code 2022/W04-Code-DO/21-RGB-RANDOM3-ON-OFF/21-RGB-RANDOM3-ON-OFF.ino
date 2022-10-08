
// randomly select a color 
// select random number (LOTTERY) from 0-100
// split the number line ( 0-100) into thirds
// decide which third you are in -- assign a color
// one color per loop.


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

 long lottery = random (0,100);
 Serial.println(lottery);

 if ( lottery <= 33 ) {
 
     // write the leds 
     Serial.println("purple");
     digitalWrite( rPin, ON);
     digitalWrite( gPin, OFF);
     digitalWrite( bPin, ON);
     // wait 1 second
     delay(1000);
 }

 
 if ( lottery >= 66){

     // write the leds 
     Serial.println("cyan");
     digitalWrite( rPin, OFF);
     digitalWrite( gPin, ON);
     digitalWrite( bPin, ON);
     // wait 1 second
     delay(1000);
 }
 
 
 if (lottery <= 65 && lottery >= 34) {
     // write the leds 
     Serial.println("lime ?? ");
     digitalWrite( rPin, ON);
     digitalWrite( gPin, ON);
     digitalWrite( bPin, OFF);
     // wait 1 second
     delay(1000);
 }


}
