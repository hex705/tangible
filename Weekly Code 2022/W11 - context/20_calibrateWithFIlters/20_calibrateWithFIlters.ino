// calibrating a sensor
// finding max, min, range of readings
// setting thresholds


#include <MedianFilter.h>

// Median filter variables
MedianFilter medianValues(32, 0); // first value can be up to 255
// second value is a preset - i leave it zero
// EMA filter variables
int   medianFilteredValue;
int   EMA         = 0;
float EMAconstant = 0.1;

int finalValue; // variable to hold final filtered outcomes

// calibration variables
int maxBrightness = 0;     // initialize very small
int minBrightness = 2000;  // initialize very big
int brightnessRange = 0;
int brightnessThreshold = 0;
float thresholdAmount = 0.5; // 0.0 - 1.0, percent of range

// sensor (photoCell) variables
int lightSensorPin = A0;
int avgBrightnessReading;
int brightness = 0;
int lastBrightness = 0;

int crossedThreshold = 0;

// indicator variables
int ledPin = 13; // built in led
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);


  // enter calibration mode
  unsigned long start = millis();

  digitalWrite(ledPin, 1); // turn LED on to indicate calibration mode
  Serial.println("calibrating sensor");

  do {
    brightness = analogRead(lightSensorPin);
    calibrate(brightness);
    printReadings(brightness);
    delay(10);
    //printCalibrationIndicator();
  } while (millis() - start < 5000); // calibrate for 5 seconds

  digitalWrite(ledPin, 0); // led OFF, calibration complete
  // calibration complete

  Serial.println("setup complete");

}

void loop() {

  // *******  get simple average of (X) distances
  avgBrightnessReading = averageBrightness(2); // average (X) readings

 
  // *******  filter readings -- as needed
  // get median of distances
  medianValues.in(avgBrightnessReading);
  medianFilteredValue = medianValues.out();

  // get low pass -- or Exponential Moving Average
  EMA = (int)(EMAconstant * medianFilteredValue) + ((1.0 - EMAconstant) * EMA);

  // *******  decide which value you want to use
  // can be avgBrightnessReading OR medianFilteredValue OR EMA
  finalValue = avgBrightnessReading;


  // ******* check <finalValue> against <brightnessThreshold>

  crossedThreshold = checkThreshold(finalValue);

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

  // write to speaker


  printReadings(finalValue);
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
