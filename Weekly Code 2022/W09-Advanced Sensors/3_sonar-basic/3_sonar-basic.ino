// basic sonar testing
// function for averaging readings provided

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

    int distanceReading = averageUltraSonic(5); // average (X) readings
    Serial.println( distanceReading );  
    delay(10);
}


// this function reads the distance 'howMany' times
// it then returns the average of those readings
// 

int averageUltraSonic( int howMany ){
  long dist = 0;
  for (int i = 0; i < howMany; i++){
      dist += ultrasonic.read();
  }
  return dist = (int) dist / howMany;
}
