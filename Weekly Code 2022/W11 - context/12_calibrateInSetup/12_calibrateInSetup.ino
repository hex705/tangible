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

// indicator variables
int ledPin = 13; // built in led


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);  //give time to open plotter - remove for crit
  delay(1000);
  
  pinMode(lightSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);


  // enter calibration mode -- only happens at reset / startup
  unsigned long start = millis();

  digitalWrite(ledPin, 1); // turn LED on to indicate calibration mode
  Serial.println("calibrating sensor");

  do {
    brightness = averageBrightness(2);
    calibrate(brightness);
    printReadings(brightness);
    delay(10);
  } while (millis() - start < 5000); // calibrate for 5 seconds

  digitalWrite(ledPin, 0); // led OFF, calibration complete
  // calibration complete

  Serial.println("setup complete");

}

void loop() {

  // *******  get simple average of (X) distances
  avgBrightnessReading = averageBrightness(2); // average (X) readings

  // ******* check <finalValue> against <brightnessThreshold>
  crossedThreshold = checkThreshold(avgBrightnessReading);


  // determine action

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
