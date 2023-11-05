// basic sonar testing
// function for averaging readings provided

#include <MedianFilter.h>
#include <Ultrasonic.h>
#include <Servo.h> 

// circuit variables
Servo continuous_360;
int servoValue;

// filter variables
MedianFilter medianValues(32, 0); // first value can be up to 255, bigger = more filter slower code
                                  // second value is a preset - i leave it zero
                                  
int filteredValues;       

//Ultra sonic sensor pin definitions
int trigpin = 12;//appoint trigger pin
int echopin = 13;//appoint echo pin

Ultrasonic ultrasonic(trigpin,echopin); // create object

// postion limits for mapping -- contextual -- you need to think a bit here
int sonarLow = 10;    // adjust both of these for your context 
int sonarHigh = 100; 

// servo postion limits for mapping
int servoLow = 0;
int servoHigh = 180;

// threshold to stop servo 
int threshold = 75;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  continuous_360.attach(4);
  ultrasonic.setTimeout(15000UL); // see examples OR https://tangiblemedia.ca/building-blocks/sonar-sensor-ultrasonic-distance-detector/
}

void loop() {

    // read your sensors - inputs
      int distanceReading = averageUltraSonic(3); // average (X) readings

    // integrate and set states
      medianValues.in(distanceReading);
      filteredValues = medianValues.out();
  
    // map 
      servoValue = map(filteredValues, sonarLow, sonarHigh, servoLow, servoHigh); //0,180 
    
      // limit the range
      if (servoValue < servoLow)  servoValue = servoLow;
      if (servoValue > servoHigh) servoValue = servoHigh;
      if (filteredValues >= threshold) servoValue = 90; // stop servo when nothing in front of sensor
    
    // take action 
      continuous_360.write(servoValue);

      // new plotter uses colon <:> for parsing !?
      Serial.print( "threshold:" ); // label, colon matters ?
      Serial.print( threshold );    // data
      Serial.print('\t');           // tab 
      Serial.print( "raw:" ); 
      Serial.print( distanceReading ); 
      Serial.print('\t');
      Serial.print( "servo POS:" ); 
      Serial.print( servoValue ); 
      Serial.print('\t');
      Serial.print( "MEDIAN:" ); 
      Serial.println(filteredValues);

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
