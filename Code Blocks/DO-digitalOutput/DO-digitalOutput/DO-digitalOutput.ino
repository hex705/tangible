// Digital Output
// controlling a single LED with a Digital Output

int ledPin  = 8 ; // connect PIN 5 to BLUE pin of RGB LED

void setup() {

  pinMode ( ledPin , OUTPUT) ; // set direction 
}

void loop() {

  digitalWrite ( ledPin , HIGH ) ;   // turn LED on 
  delay ( 1000 ) ;  // wait a bit == 1 second 
  digitalWrite ( ledPin, LOW ) ;  // turn LED off  
  delay  (1000 ) ; // wait a bit 

}
