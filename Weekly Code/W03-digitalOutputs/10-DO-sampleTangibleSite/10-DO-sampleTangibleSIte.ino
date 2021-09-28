int ledPin  = 5 ; // built in

void setup() {

  pinMode ( ledPin , OUTPUT) ; // set direction
}

void loop() {

  digitalWrite ( ledPin , 1 ) ;   // turn LED on
  delay ( 1000 ) ;  // wait a bit == 1 second

  digitalWrite ( ledPin, 0 ) ;  // turn LED off  
  delay ( 1000 ) ; // wait a bit
}
