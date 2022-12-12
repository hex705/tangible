// basic sonar testing
// Median and EMA -- combined
// https://github.com/daPhoosa/MedianFilter

#include <MedianFilter.h>
#include <Ultrasonic.h>

// filter variables
MedianFilter medianValues(32, 0); // first value can be up to 255
                                  // second value is a preset - i leave it zero

//Ultra sonic sensor pin definitions
int trigpin = 12;//appoint trigger pin
int echopin = 13;//appoint echo pin

Ultrasonic ultrasonic(trigpin,echopin); // create object


// filter variables 
int   avgDistanceReading;
int   medianFilteredValue;
int   EMA         = 0;
float EMAconstant = 0.1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ultrasonic.setTimeout(15000UL); // see examples OR https://tangiblemedia.ca/building-blocks/sonar-sensor-ultrasonic-distance-detector/
}

void loop() {
  
    // get simple average of (X) distances
    avgDistanceReading = averageUltraSonic(2); // average (X) readings
    
    // get median of distances
    medianValues.in(avgDistanceReading);
    medianFilteredValue = medianValues.out();

    // get low pass -- or Exponential Moving Average
    EMA = (int)(EMAconstant*medianFilteredValue) + ((1.0-EMAconstant)*EMA);
    
    Serial.print( avgDistanceReading ); 
    Serial.print('\t');
    Serial.print(medianFilteredValue);
    Serial.print('\t');
    Serial.println(EMA);
    delay(10);
}


// this function reads the distance 'howMany' times
// it then returns the average of those readings
// 

int averageUltraSonic( int howMany ){
  long dist = 0;
  for (int i = 0; i < howMany; i++){
      dist += ultrasonic.read();
      delay(2);
  }
  return dist = (int) dist / howMany;
}
