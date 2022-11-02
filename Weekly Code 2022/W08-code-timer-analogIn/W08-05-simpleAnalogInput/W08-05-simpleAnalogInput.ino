// W08-05-simpleAnalogInput

// upload code and open PLOTTER

int analogPin = A0; // where is the circuit ? try A0 and A2
int analogVal; 

void setup() {
  pinMode(analogPin, INPUT );
  Serial.begin(9600);
}

void loop() {
  
  // GET READING
  analogVal  = analogRead(analogPin) ;

  // Debug reading
  Serial.println(analogVal); 
  
  
} // end loop 
