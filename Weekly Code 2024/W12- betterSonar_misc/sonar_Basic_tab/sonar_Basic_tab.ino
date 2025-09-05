// basic sonar testing
// function for averaging readings provided

#include <Ultrasonic.h>
#include <MedianFilter.h>

//Ultra sonic sensor pin definitions
int trigpin = 11;  // trigger pin - yellow
int echopin = 12;  // echo pin

Ultrasonic ultrasonic(trigpin, echopin);  // create object

// make a timer for how often to read (60mS = 16 reads / second)
unsigned long now;
unsigned long senseInterval = 60;  // max rate -- there is a hardware limit ... don't change
unsigned long startTime;

// circuits 
int speakerPin = 10;

// distance and filters 
int distanceReading;  // sonar raw

// some filters to see what they do ...
int ema;
float emaValue = 0.05;

MedianFilter medianValues(16, 0);
int filteredValues;


// some constant to track what is happening

// overall states ::  active == see someone, STANDBY - nothing detected for a while
const int ACTIVE = 1;
const int STANDBY = 0;
int SONAR_STATE;

// timer to keep active state alive despite errors from sensor
unsigned long activeStart;
unsigned long activeInterval = 200;  // keep as small as possible 1000

// state variables to track when to add data to filters and when to exclude
// it is sort of a prefilter ... 
const int EXCLUDE = 0;
const int INCLUDE = 1;
int DATA = EXCLUDE;


//https://github.com/ErickSimoes/Ultrasonic/blob/master/README.md

/* cool table for filtering 

ultrasonic           
timeout                                
setting (uS)   ...  ...    timeoutConstant  
                                        
10000       ...        ...      178      
11000       ...        ...      196    <-**** used in example   
12000       ...        ...      214       
13000       ...        ...      232      
14000       ...        ...      250  
15000       ...        ...      268       
16000       ...        ...      285      
17000       ...        ...      303       

   ....   limit of sensor out here .... add 18 for every 1000uS (1mS) in timout 
*/

int timeoutDistance;


void setup() {
  // match to table above 
  ultrasonic.setTimeout(11000UL);  // this is in Micro Seconds (1000 micro to 1 milli) 18cm / 1000
  timeoutDistance = 196;//11000 - 196

  Serial.begin(115200);            // reset
  pinMode(6, OUTPUT);
}


void loop() {

  now = millis();

  readSonar();

  // need an activate keep alive timer before timeout and go back to waiting
  if ((now - activeStart) > activeInterval) {
    SONAR_STATE = STANDBY;
  }

  // take action ... this is very basic
  // thresholds should be much better now (yippy, sheepish grin)
  switch (SONAR_STATE) {
    case STANDBY:
      noTone(10);         // no sound
      analogWrite(6, 0);  // no light
      break;

    case ACTIVE:
      int freq = map(filteredValues, 0, timeoutDistance, 100, 1500);
      tone(10, freq);
      int brightness = map(filteredValues, 0, timeoutDistance, 255, 0);
      analogWrite(6, brightness);
      break;
  }

}  // end loop


// called from readSonar - line 32
void printStuff() {
 // if ((STATE==ACTIVE) and (distanceReading != timeoutDistance)){
  Serial.print( distanceReading);  //1 = raw
  Serial.print( "\t");
 // }
  //Serial.print("ema:");
  Serial.print(ema);               //2
  Serial.print("\t");
  Serial.print(filteredValues);    //3
  Serial.print("\t");
  Serial.print(SONAR_STATE*-20);         //4
  Serial.print("\t");
  Serial.print(DATA*20);              //5
  Serial.print("\t");
  Serial.print(0);                 //6
  Serial.print("\t");
  Serial.println(timeoutDistance); //7
}