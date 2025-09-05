// basic sonar testing
// function for averaging readings provided

#include <Ultrasonic.h>

//Ultra sonic sensor pin definitions
int trigpin = 12;  //appoint trigger pin
int echopin = 8;  //appoint echo pin

Ultrasonic ultrasonic(trigpin,echopin); // create object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // reset 
  
}

void loop() {
    int distanceReading = ultrasonic.read(); // average (X) readings
    Serial.println( distanceReading );  
    delay(20);
}

