// basic sonar testing - filters 
// exponential moving average (EMA), or low pass filter
// https://www.norwegiancreations.com/2015/10/tutorial-potentiometers-with-arduino-and-filtering/


#include <Ultrasonic.h>

//Ultra sonic sensor pin definitions
int trigpin = 12;//appoint trigger pin
int echopin = 13;//appoint echo pin
Ultrasonic ultrasonic(trigpin,echopin); // create object

// filter variables 
// exponential moving average 
int   EMAValue    = 0;
float EMAConstant = 0.1; // teetertotter fulcrum


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ultrasonic.setTimeout(15000UL); // see examples OR https://tangiblemedia.ca/building-blocks/sonar-sensor-ultrasonic-distance-detector/
}

void loop() {
  
    int distanceReading = averageUltraSonic(2); // average (X) readings
    //calculate the EMA
    EMAValue = (int)(EMAConstant*distanceReading) + ((1.0-EMAConstant)*EMAValue);

    Serial.print("raw:" );

    Serial.print(distanceReading); 
    Serial.print("  ");
    Serial.print("EMAs:" );
    Serial.println(EMAValue);
    delay(10);
    
}


// this function reads the distance 'howMany' times
// it then returns the average of those readings

int averageUltraSonic( int howMany ){
  long dist = 0;
  for (int i = 0; i < howMany; i++){
      dist += ultrasonic.read();
      delay(2);
  }
  return dist = (int) dist / howMany;
}
