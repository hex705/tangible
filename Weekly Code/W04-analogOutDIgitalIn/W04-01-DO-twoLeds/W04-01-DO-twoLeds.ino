//W04-01-DO-twoLeds-solution

int ledPin_1  = 5 ;     // connect PIN 5 to BLUE pin of RGB LED
int ledPin_2  = 6 ;       // add second ledPin here

void setup() {
  pinMode ( ledPin_1 , OUTPUT); // set direction
  pinMode ( ledPin_2 , OUTPUT); // add pinmode for led 2 here
}

void loop() {

  digitalWrite ( ledPin_1 , HIGH );  // turn LEDs on
  digitalWrite ( ledPin_2 , 0 );  // add second LED here
  delay ( 1000 );       // wait a bit == 1 second

  digitalWrite ( ledPin_1, LOW );    // turn LEDs off
  digitalWrite ( ledPin_2, 1 );   // add second LED here
  delay  (1000 ) ;           // wait a bit


}
