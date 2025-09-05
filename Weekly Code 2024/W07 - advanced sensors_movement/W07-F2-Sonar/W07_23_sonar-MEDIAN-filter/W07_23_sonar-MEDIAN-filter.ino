// basic sonar testing
// function for averaging readings provided

#include <MedianFilter.h>
#include <Ultrasonic.h>

// filter variables
MedianFilter medianValues(32, 0); // first value can be up to 255
                                  // second value is a preset - i leave it zero

//Ultra sonic sensor pin definitions
int trigpin = 12;//appoint trigger pin
int echopin = 13;//appoint echo pin

Ultrasonic ultrasonic(trigpin,echopin); // create object

int filteredValues;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ultrasonic.setTimeout(15000UL); // see examples OR https://tangiblemedia.ca/building-blocks/sonar-sensor-ultrasonic-distance-detector/
}

void loop() {

    int distanceReading = averageUltraSonic(2); // average (X) readings
    medianValues.in(distanceReading);
    filteredValues = medianValues.out();
    
    Serial.print( distanceReading ); 
    Serial.print('\t');
    Serial.println(filteredValues);
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
