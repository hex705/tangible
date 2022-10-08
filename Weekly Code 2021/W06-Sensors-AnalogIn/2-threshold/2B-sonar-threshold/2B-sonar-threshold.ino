// File :: sonar-threshold
// tangible, steve daniels 
// created 2019
// updated Oct 2021

// sonar threshold example


#include <Ultrasonic.h>

//Ultra sonic sensor pin definitions
int trigpin = 12;//appoint trigger pin
int echopin = 13;//appoint echo pin

Ultrasonic ultrasonic(trigpin,echopin); // create object

int currentDistance; 
int distanceThreshold = 0; 
int DISTANCE_STATE = 0; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
   // GET DISTANCE READING
   int currentDistance = averageUltraSonic(5);   // average (X) readings
   Serial.print( currentDistance ); 
   Serial.print('\t'); 
    
   // DETERMINE THRESHOLD 
  
    // use serial plotter
    // look at your sensor max and min, pick a value between that makes sense
    // change the 30 to the value you determine
  
   distanceThreshold = 30; // 30 is a start point -- it will be wrong
   Serial.print(distanceThreshold);
   Serial.print('\t');

  // THRESHOLD COMPARE -- is light above or below threshold
  if (currentDistance < distanceThreshold) {
    DISTANCE_STATE = 1; 
    Serial.print("near"); // like grover on seasame street
  } else {
    DISTANCE_STATE = 0;
    Serial.print("far"); 
  }
  
  Serial.print('\t');
  Serial.print(DISTANCE_STATE); 
  Serial.println();

}


// this function reads the distance 'howMany' times
// it then returns the average of those readings

int averageUltraSonic( int howMany ){
  long dist = 0;
  for (int i = 0; i < howMany; i++){
      dist += ultrasonic.read();
  }
  return dist = (int) dist / howMany;
}
