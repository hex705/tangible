// W08-08-tonesAndTimers
// pot controls tone that pulses -- on/off for timed periiod

int potPin = A0;
int potPosition = 0;

int speakerPin = 12; // where is the circuit?

//// postion limits for mapping
int potLow = 0;    // adjust both of these for your context 
int potHigh = 1023; 

// tone variables
int toneLow  = 50;     // tune to your desired frequency range
int toneHigh = 1500;

int toneToPlay;  // which tone
boolean playNote = 0;
boolean PRESSED = 1;

// button Variables -- for mute function! 
int buttonPin = 6;
int buttonState = 0;
int lastButtonState = 0;
boolean isPlaying = 1;

// timer variables
unsigned long currentTime = 0;
unsigned long toneInterval = 500; // try the long and short
unsigned long toneStart = 0;

void setup() {

  pinMode(potPin, INPUT);
  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  // READ sensors
  potPosition = analogRead(potPin);
  buttonState = digitalRead(buttonPin);

  // timer for tone change
  currentTime = millis();
    
  // timer for note pulses
  if ( currentTime - toneStart  > toneInterval ) {
     playNote = !playNote; // toggle note on/off
     
     // integrate sensor states
     toneToPlay = map(potPosition, potLow, potHigh, toneLow, toneHigh); 
      
     toneStart += toneInterval; // reset timer
  }

  // look for button press
  if ( buttonState == PRESSED && lastButtonState == !PRESSED) {
    // raising edge ! 
    isPlaying = !isPlaying; // toggle mute
  }

  // try uncommenting the map function for tone here -- what changes? 
  // integrate sensor states
    // toneToPlay = map(potPosition, potLow, potHigh, toneLow, toneHigh); 

      
  // take action
  Serial.print(potPosition); 
  Serial.print('\t');
  Serial.print(toneToPlay); 
  Serial.print('\t');

  //take action
  if ( playNote && isPlaying){
    tone(speakerPin, toneToPlay);
  } else {
    noTone(speakerPin);
  }
 
  Serial.println();
  lastButtonState = buttonState;
  
} // end loop 
