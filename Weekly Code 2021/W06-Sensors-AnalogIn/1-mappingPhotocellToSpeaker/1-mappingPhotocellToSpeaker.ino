// tangible, steve daniels, Oct 2021

// mapping photocell to speaker


int photocell = A0; // where is the circuit ? 
int currentBrightness;


// brighness limits for mapping 
int brightnessLow = 0;    // adjust both of these for your context 
int brightnessHigh = 1023; 


int speakerPin = 4; // where is the circuit?

// frequency limits for mapping
int speakerLow = 50;     // tune to your desired frequency range
int speakerHigh = 1500;


void setup() {
  pinMode(photocell, INPUT );
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  // GET LIGHT READING
  currentBrightness  = analogRead(photocell) ;

  Serial.print(currentBrightness); 
  Serial.print('\t');
  
  Serial.print(brightnessLow); 
  Serial.print('\t');

  Serial.print(brightnessHigh); 
  Serial.print('\t');

  int frequency = map(currentBrightness,brightnessLow,brightnessHigh,speakerLow,speakerHigh);

  tone(speakerPin, frequency);

  // uncomment below once you have your sensor limits sorted above. 
  Serial.print(frequency);
  
  Serial.println();
  
} // end loop 
