// W08-07-2In3Out

// in this code we map two analog inputs to 3 ouputs

// inputs are a photocell and a POTentiometer
// outputs are sound and 2 kinds of servo 


#include <Servo.h> 

// circuit variables
Servo positional_180;
Servo continuous_360;

int photocell = A2; // where is the circuit ? 
int currentBrightness;

int potPin = A0;
int currentPosition = 0;

int speakerPin = 12; // where is the circuit?

// brighness limits for mapping 
int brightnessLow = 0;    // adjust both of these for your context 
int brightnessHigh = 1023; 

// postion limits for mapping
int potLow = 0;    // adjust both of these for your context 
int potHigh = 1023; 

// frequency limits for mapping
int speakerLow = 50;     // tune to your desired frequency range
int speakerHigh = 1500;

// servo postion limits for mapping
int servoLow = 0;
int servoHigh = 180;


void setup() {
  
  pinMode(photocell, INPUT );
  pinMode(potPin, INPUT);
  
  pinMode(speakerPin, OUTPUT);
  
  positional_180.attach(3);
  continuous_360.attach(4);
  Serial.begin(9600);
  
}

void loop() {
  
  // READ sensors
  currentBrightness = analogRead(photocell);
  currentPosition   = analogRead(potPin);

  // display
  Serial.print(currentBrightness); 
  Serial.print('\t');
  
  Serial.print(currentPosition); 
  Serial.print('\t');

  // map - integrate sensors
  int frequency = map(currentBrightness,brightnessLow,brightnessHigh,speakerLow,speakerHigh);
  int servoValue = map(currentPosition, potLow, potHigh, servoLow, servoHigh); //0,180 

  //take action
  tone(speakerPin, frequency);
  positional_180.write(servoValue);
  continuous_360.write(servoValue);

  // uncomment below once you have your sensor limits sorted above. 
  Serial.print(frequency);
  Serial.print('\t');
  Serial.print(servoValue);
  
  Serial.println();
  
} // end loop 
