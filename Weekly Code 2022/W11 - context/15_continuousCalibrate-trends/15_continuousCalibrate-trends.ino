// calibrating a sensor
// finding max, min, range of readings
// setting thresholds

// this example explores continuous calibration with sound

// sensor (photoCell) variables
int lightSensorPin = A0;
int brightness = 0; // used in setup 
int avgBrightnessReading = 0; // used in loop
int lastBrightness = 0;

// calibration variables
int maxBrightness = 0;     // initialize very small
int minBrightness = 2000;  // initialize very big
int brightnessRange = 0;
int brightnessThreshold = 0;
float thresholdAmount = 0.5; // 0.0 - 1.0, percent of range

int crossedThreshold = 0;


// sound varibles
int speakerPin = 6;

// tone variables
boolean playNote = 0;
int toneToPlay;        // which tone
int alarmTone = 50;

int toneLow  = 50;     // tune to your desired frequency range
int toneHigh = 1500;


// timer variables
unsigned long currentTime = 0;
unsigned long toneInterval = 50; // try the long and short
unsigned long toneStart = 0;

// raisng or falling ? 
boolean TREND = 0;
boolean INCREASING = 1;
boolean DECREASING = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightSensorPin, INPUT);


  Serial.println("setup complete");
}

void loop() {

  // *******  get simple average of (X) distances
  avgBrightnessReading = averageBrightness(2); // average (X) readings

  // *******  calibrate with new reading
  calibrate(avgBrightnessReading);

  // ******* check <finalValue> against <brightnessThreshold>
  crossedThreshold = checkThreshold(avgBrightnessReading);

  // *******  NEW NEW NEW **********
  // check for sensor trent ... rasing or falling?
  if ( lastBrightness > avgBrightnessReading) TREND = DECREASING;
  if ( lastBrightness < avgBrightnessReading) TREND = INCREASING;

  // ******* determine action

  // check relation to threshold
  switch ( crossedThreshold ) {
    case (0):
      // below threshold here
      Serial.println("below");

      // below threshold we will sound an alarm  < IF still going down !>

      if ( TREND == DECREASING) {
        // you are below threshold and still going down
   
          // timer for tone change -- see W08-08-tones and timers
          currentTime = millis();
            
          // timer for note pulses
          if ( currentTime - toneStart  > toneInterval ) {
             playNote = !playNote; // toggle note on/off
             toneToPlay =  alarmTone;  // set tone         
             toneStart += toneInterval; // reset timer
          }
      } else {
        // below threshold and coming up   
        toneToPlay =  alarmTone;  
      }
      break;

    case (1):
      // above threshold code here
      Serial.println("above");
      if ( TREND = INCREASING) {
        playNote = true;
        toneToPlay = map(avgBrightnessReading, minBrightness, maxBrightness, toneHigh-500, toneLow); 
      } else {
        playNote = true;
        toneToPlay = map(avgBrightnessReading, minBrightness, maxBrightness, toneLow, toneHigh);
      }
     
      break;
  }

  // take action

  // generate sound 
  //take action
  if ( playNote ){
    tone(speakerPin, toneToPlay);
  } else {
    noTone(speakerPin);
  }

  printReadings(avgBrightnessReading);

  // write in diary -- see lightning mcqueen w07
  lastBrightness = avgBrightnessReading;
  delay(10);
}

void printReadings(int newReading) {
  Serial.print( newReading );
  Serial.print('\t');
  Serial.print( brightnessThreshold);
  Serial.print('\t');
  Serial.print( maxBrightness);
  Serial.print('\t');
  Serial.println( minBrightness);
}
