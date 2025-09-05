// W06_03_potAndPhoto

// upload code and open PLOTTER

int photoPin = A0; // where is the circuit ? try A0 and A1
int photoVal; 

int potPin = A1; // where is the circuit ? try A0 and A1
int potVal;

void setup() {
  pinMode(photoPin, INPUT );
  pinMode(potPin, INPUT );

  Serial.begin(9600);
}

void loop() {
  
  // GET READING
  photoVal  = analogRead(photoPin) ;
  potVal    = analogRead(potPin) ;

  // Debug reading
  Serial.print("photoVal:"); // : means label for plotter
  Serial.print(photoVal); 
  Serial.print("\t");
  Serial.print("potVal:"); 
  Serial.println(potVal); 
  
} // end loop 
