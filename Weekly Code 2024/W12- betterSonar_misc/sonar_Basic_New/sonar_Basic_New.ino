// basic sonar testing
// function for averaging readings provided

#include <Ultrasonic.h>
#include <MedianFilter.h>

//Ultra sonic sensor pin definitions
int trigpin = 12;  // trigger pin - yellow
int echopin = 13;  // echo pin

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
int STATE;

// timer to keep active state alive despite errors from sensor
unsigned long activeStart;
unsigned long activeInterval = 1000;  // keep as small as possible

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
  ultrasonic.setTimeout(17000UL);  // this is in Micro Seconds (1000 micro to 1 milli) 18cm / 1000
  timeoutDistance = 303;

  Serial.begin(115200);            // reset
  pinMode(6, OUTPUT);
}


void loop() {

  now = millis();

  // every 60 mS get a new reading ...
  if (now - startTime > senseInterval) {
    distanceReading = ultrasonic.read();  // just do a straight read -- the average was misleading
  
    // store limit data when nothing is happening -- result = limit as baseline
    if (( distanceReading == timeoutDistance) and (STATE == STANDBY)){
      DATA = INCLUDE; 
    } 

    // if the readinis not a time out
    if (distanceReading != timeoutDistance) {  // this if..then removes timeout noise 
      STATE = ACTIVE;
      activeStart = now;
      DATA = INCLUDE;
    } 


  // error spike -- timeout while reading
  if ((distanceReading == timeoutDistance) and (STATE == ACTIVE)){
      // this is an error spike
      DATA = EXCLUDE;
  }

   if (DATA == INCLUDE){
    ema = emaValue * distanceReading + (1.0 - emaValue) * distanceReading;
    medianValues.in(distanceReading);  // ema can replace distancereading if desired -- its a double filter
    filteredValues = medianValues.out();

    DATA = EXCLUDE;
   }
    printStuff();
    startTime += senseInterval;  // reset 60mS timer for readings
  }                              // end timer


  // need an activate keep alive timer before timeout and go back to waiting
  if ((now - activeStart) > activeInterval) {
    STATE = STANDBY;
  }

  // take action ... this is very basic
  // thresholds should be much better now (yippy, sheepish grin)
  switch (STATE) {

    case STANDBY:
      noTone(10);         // no sound
      analogWrite(6, 0);  // no light
      break;

    case ACTIVE:
      int freq = map(filteredValues, 0, timeoutDistance, 100, 2000);
      tone(10, freq);
      int brightness = map(filteredValues, 0, timeoutDistance, 255, 0);
      analogWrite(6, brightness);
      break;
  }

}  // end loop

void printStuff() {
  Serial.print( distanceReading);  //1
  Serial.print( "\t");
  //Serial.print("ema:");
  Serial.print(ema);               //2
  Serial.print("\t");
  Serial.print(filteredValues);    //3
  Serial.print("\t");
  Serial.print(STATE*-20);         //4
  Serial.print("\t");
  Serial.print(DATA);              //5
  Serial.print("\t");
  Serial.print(0);                 //6
  Serial.print("\t");
  Serial.println(timeoutDistance); //7
}
