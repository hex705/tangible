// File :: 1-sonarTest
// tangible 
// steve daniels 
// created Aug 2019
// updated Oct 2021

// see below for original
//https://www.arduinolibraries.info/libraries/ultrasonic


/*
 * print each single sonar reading as it comes in. 
 * 
 */

#include <Ultrasonic.h>

//Ultra sonic sensor pin definitions
int trigpin = 12;//appoint trigger pin
int echopin = 13;//appoint echo pin

Ultrasonic ultrasonic(trigpin,echopin); // create object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

    int distanceReading = ultrasonic.read(); // default single reading
    Serial.println( distanceReading );  
    delay(10);
}
