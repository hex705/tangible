int ledPin = 2;
int lightPin = A0;

int lightState = 0;

// calibration variables
int maxBrightness = 0;     // initialize very small
int minBrightness = 2000;  // initialize very big
int brightnessRange = 0;
int brightnessThreshold = 20;
float thresholdAmount = 0.5; // 0.0 - 1.0, percent of range

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(lightPin, INPUT);
  Serial.begin(9600); 

  digitalWrite(ledPin,1);
}

void loop() {
  // put your main code here, to run repeatedly:
   lightState = analogRead(lightPin);
   calibrate(lightState);
   printReadings(lightState);

}

void printReadings(int newReading) {
  Serial.print( "newReading:" ); // NEW!! -- the colon will make it a label in plotter!
  Serial.print( newReading );
  Serial.print('\t');

  Serial.print( "maxBrightness:");
  Serial.print( maxBrightness);
  Serial.print('\t');

  Serial.print( "minBrightness:");
  Serial.println( minBrightness);
}

void calibrate(int newValue){
  if(newValue > maxBrightness)  maxBrightness = newValue;    
  if(newValue < minBrightness)  minBrightness = newValue; 
  brightnessRange = maxBrightness-minBrightness;
  brightnessThreshold = minBrightness + (brightnessRange*thresholdAmount);
}

