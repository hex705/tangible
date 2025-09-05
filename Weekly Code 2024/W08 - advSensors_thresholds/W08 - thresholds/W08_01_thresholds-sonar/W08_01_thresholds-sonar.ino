// sensor thresholding :: sonar

// sonar on pins 12 and 13
// servo on pin 4

#include <MedianFilter.h>
#include <Ultrasonic.h>
#include <Servo.h> 

// circuit variables
Servo continuous_360;
int servoValue;
int servoPin = 4;

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
int threshold = 90;  // test in context!
int DISTANCE_STATE = 0;

//https://www.youtube.com/watch?v=E9IuXEwpU7U
int NEAR = 0;
int FAR = 1; 

void setup() {

  Serial.begin(9600);
  continuous_360.attach(servoPin);
  ultrasonic.setTimeout(15000UL); // see examples OR https://tangiblemedia.ca/building-blocks/sonar-sensor-ultrasonic-distance-detector/
  Serial.println(__FILE__);
}

void loop() {

  // read your sensors - inputs
    int distanceReading = averageUltraSonic(3); // average (X) readings
      Serial.print(distanceReading); // value 1 in plotter
      Serial.print("\t");

  // integrate and set states
    medianValues.in(distanceReading);
    filteredValues = medianValues.out();
      Serial.print(filteredValues);  // value 2 in plotter
      Serial.print("\t");
  
  // map 
    servoValue = map(filteredValues, sonarLow, sonarHigh, servoLow, servoHigh); //0,180 
    
  // limit the range
    if (servoValue < servoLow)  servoValue = servoLow;
    if (servoValue > servoHigh) servoValue = servoHigh;
    
  // take action 
    Serial.print(servoValue);   // value 3 in plotter
    Serial.print("\t");

  // DETERMINE THRESHOLD

    // use serial plotter
    // look at your sensor max and min, pick a value between that makes sense
    // change the 90 to the value you determine

  threshold = 20; // 90 is a start point -- it will be wrong - find yours
    Serial.print(threshold);   // value 4 in plotter
    Serial.print('\t');

  // THRESHOLD COMPARE -- distance is NEAR (below threshold) of FAR ( above threshold)
  if (servoValue < threshold) {
    DISTANCE_STATE = NEAR;
    Serial.print("near");   // value 5 in plotter
    tone(10,440);
    continuous_360.write(0); // spin one way fast
  } else {
    DISTANCE_STATE = FAR;
    Serial.print("far");   // value 5 in plotter
    noTone(10);
    continuous_360.write(90); // stop
  }

  Serial.print('\t');
  Serial.print(DISTANCE_STATE*50); //  // value 6 in plotter
  Serial.println();

} // end loop

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


