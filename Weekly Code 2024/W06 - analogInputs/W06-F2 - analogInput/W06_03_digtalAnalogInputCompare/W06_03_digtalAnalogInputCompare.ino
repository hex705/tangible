// W06_02_digitalAnalogInputCompare

// upload code and open PLOTTER

int analogPin = A0; // where is the circuit ? try A0 and A1
int analogVal; 

int digitalPin = 8;  // where is the button?
int digitalVal = 0;
int digitalMultiplier = 250; // this is just so you can see it (0-1 will be too small to see on plotter)


void setup() {
  pinMode(analogPin, INPUT );
  pinMode(digitalPin, INPUT );
  Serial.begin(9600);
}

void loop() {
  
  // GET READING
  analogVal  = analogRead(analogPin) ;
  digitalVal = digitalRead(digitalPin);

  // Debug reading
  Serial.print(analogVal); 
  Serial.print("\t");
  Serial.println(digitalVal * digitalMultiplier);
  
  
} // end loop 
