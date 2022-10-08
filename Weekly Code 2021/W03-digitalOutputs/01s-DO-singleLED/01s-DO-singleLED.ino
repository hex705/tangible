//01s-DO-singleLED
//SOLUTION  - blink a single LED on our breadboard

int ledPin  = 5 ; // where is your circuit ? 
int ledPin_2 = 6 ;

void setup() {

  pinMode ( ledPin , OUTPUT) ; // set direction of current flow 
  pinMode ( ledPin_2, OUTPUT);
}


void loop() {

  digitalWrite ( ledPin , HIGH ) ;   // turn LED on 
  digitalWrite ( ledPin_2, 1 );
  delay ( 1000 ) ;      // wait a bit == 1 second 

  digitalWrite ( ledPin, LOW ) ;  // turn LED off
  digitalWrite ( ledPin_2, 0 );  
  delay  (1000 ) ;       // wait a bit 

}
