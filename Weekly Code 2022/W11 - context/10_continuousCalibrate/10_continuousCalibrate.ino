// calibrating a sensor
// finding max, min, range of readings
// setting thresholds

// this example explores calibration in setup 

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


  // ******* determine action

  // check relation to threshold
  switch ( crossedThreshold ) {
    case (0):
      // below threshold here
      Serial.println("below");
      break;

    case (1):
      // above threshold code here
      Serial.println("above");
      break;
  }

  // take action

  printReadings(avgBrightnessReading);
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
