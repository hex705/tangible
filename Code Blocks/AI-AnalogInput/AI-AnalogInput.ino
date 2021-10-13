// tangible 
// steve daniels, Oct 2021

// basic analogRead with photocell circuit

int photocell = A0;
int brightness = 0; 

void setup() {
  // put your setup code here, to run once:
   pinMode(photocell, INPUT);
   Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  brightness = analogRead(photocell); 

  Serial.println(brightness); 

  delay(10); // slow it down a little 
  
}
