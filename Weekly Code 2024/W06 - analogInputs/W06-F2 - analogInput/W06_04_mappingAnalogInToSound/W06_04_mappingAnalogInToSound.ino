// W06_04_mappingAnalogInToSound
// mapping photocell to speaker

// analog input variables
int photocell = A1; // where is the circuit ? 
int currentBrightness;

// brighness limits for mapping 
int brightnessLow = 0;    // adjust both of these for your context 
int brightnessHigh = 1024; 

// speaker variables
int speakerPin = 12; // where is the circuit?

// frequency limits for mapping
int speakerLow = 50;     // tune to your desired frequency range
int speakerHigh = 1000;


void setup() {
  pinMode(photocell, INPUT );
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  // GET LIGHT READING
  currentBrightness  = analogRead(photocell) ;

    Serial.print("currentBrightness:"); // in osx the colon  :  is everything here, it makes it a plotter label?  ? why arduino, why? 
    Serial.print(currentBrightness); 
    Serial.print('\t');

    Serial.print("brightnessLow:");
    Serial.print(brightnessLow); 
    Serial.print('\t');

    Serial.print("brightnessHigh:"); 
    Serial.print(brightnessHigh); 
    Serial.print('\t');

   int frequency = map(currentBrightness,brightnessLow,brightnessHigh,speakerLow,speakerHigh);
    // if (frequency < 50) frequency = 50; // if you get undesired silence in dark....

  tone(speakerPin, frequency);

  // uncomment below once you have your sensor limits sorted above. 
  Serial.print("frequency:");
  Serial.print(frequency);
  
  Serial.println();
  
} // end loop 
