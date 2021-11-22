// tangible, steve daniels, Oct 2021

// sensor thresholding :: photocell 

int photocell = A0; // where is the circuit ? 

int currentBrightness;
int lightThreshold = 0; // reset manually in code below
int LIGHT_STATE = 0;


void setup() {
  pinMode(photocell, INPUT );
  Serial.begin(9600);
}

void loop() {
  // GET LIGHT READING
  currentBrightness  = analogRead(photocell) ;
  Serial.print(currentBrightness); 
  Serial.print('\t');
  
  // DETERMINE THRESHOLD 
  
    // use serial plotter
    // look at your sensor max and min, pick a value between that makes sense
    // change the 512 to the value you determine
  
  lightThreshold = 512; // 512 is a start point -- it will be wrong
  Serial.print(lightThreshold);
  Serial.print('\t');

  // THRESHOLD COMPARE -- is light above or below threshold
  if (currentBrightness < lightThreshold) {
    LIGHT_STATE = 0; 
    Serial.print("dark");
  } else {
    LIGHT_STATE = 1;
    Serial.print("light"); 
  }
  
  Serial.print('\t');
  Serial.print(LIGHT_STATE); 
  Serial.println();
} // end loop 
