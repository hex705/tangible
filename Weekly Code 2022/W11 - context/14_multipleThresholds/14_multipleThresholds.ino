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
int brightnessLowThreshold = 0;
int brightnessHighThreshold = 0;

// threshold levels
float lowThresholdAmount = 0.25; // 0.0 - 1.0, percent of range
float highThresholdAmount = 0.80; 

int thresholdZone = 2;


// sound varibles
int speakerPin = 6;

// tone variables
boolean playNote = 0;
int toneToPlay;        // which tone
int alarmTone = 20;

int toneLow  = 50;     // tune to your desired frequency range
int toneHigh = 1500;


// timer variables
unsigned long currentTime = 0;
unsigned long toneInterval = 200; // try the long and short
unsigned long toneStart = 0;



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
  thresholdZone = checkThreshold(avgBrightnessReading);


  // ******* determine action

  // check relation to threshold
  switch ( thresholdZone ) {
    case (0):
      // below low -- too close == scared == out of my space man
      Serial.println("below");

      // below threshold we will sound an alarm
      
      // timer for tone change -- see W08-08-tones and timers
          currentTime = millis();
            
          // timer for note pulses
          if ( currentTime - toneStart  > toneInterval ) {
             playNote = !playNote; // toggle note on/off
             toneToPlay =  alarmTone;  // set tone         
             toneStart += toneInterval; // reset timer
          }
      break;

    case (1):
      // above high threshold -- lonely come care for me
      Serial.println("above");
      playNote = true;
      toneToPlay = map(avgBrightnessReading, minBrightness, maxBrightness, toneLow, toneHigh); 
      break;

    case(2):
      // middle - happy / indifferent
      playNote = 0; // turn off sounds
      
    default:
       // none of the above
       playNote = 0; // turn off sounds
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
  delay(10);
}

void printReadings(int newReading) {
  Serial.print( newReading );
  Serial.print('\t');
  Serial.print( brightnessLowThreshold);
  Serial.print('\t');
  Serial.print( brightnessHighThreshold);
  Serial.print('\t');
  Serial.print( maxBrightness);
  Serial.print('\t');
  Serial.println( minBrightness);
}
