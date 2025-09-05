
int blueLED  = 5 ;  // connect PIN 5 to BLUE pin of RGB LED
int redLED   = 10 ; // connect PIN 10 to RED pin of RGB LED

void setup() { 
  // put your setup code here, to run once:
  pinMode ( blueLED , OUTPUT) ;   
  pinMode ( redLED  , OUTPUT) ; 
}

void loop() { 
  // put your main code here, to run repeatedly:

  //  blue
  digitalWrite ( blueLED , HIGH ) ;   // turn LED on 
  delay ( 1000 ) ;  // wait a bit == 1 second 
  digitalWrite ( blueLED, LOW ) ;  // turn LED off  
  delay  (1000 ) ; // wait a bit 

  //  red
  digitalWrite ( redLED , HIGH ) ; 
  delay ( 1000 ) ;  // wait a bit == 1 second 
  digitalWrite ( redLED, LOW ) ;  // turn LED off  
  delay  (1000 ) ; // wait a bit 
}
