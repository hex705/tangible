
int blueLED  = 5 ; // connect PIN 5 to singel LED or BLUE pin of RGB LED

void setup() {
  // put your setup code here, to run once:
  pinMode ( blueLED , OUTPUT) ; 
}

void loop() {
  
 // blue
 // digitalWrite( pin, state); 
  digitalWrite ( blueLED , HIGH ) ;   // turn LED on 
  delay ( 1000 ) ;  // wait a bit == 1 second 
  digitalWrite ( blueLED, LOW ) ;  // turn LED off  
  delay  (1000 ) ; // wait a bit 

}
