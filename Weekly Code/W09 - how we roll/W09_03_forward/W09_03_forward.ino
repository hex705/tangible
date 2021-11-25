// W09_03_forward

const int green  = ? ; // change the '?' to pin numbers
const int blue   = ? ; //
const int red    = ? ; // if a wheel goes backward,
const int yellow = ? ; // flip the pin numbers for that wheel.

void setup() {
  // motor wire pinModes
  pinMode ( green,  OUTPUT );  // output because we are sending a signal out
  pinMode ( blue,   OUTPUT ); 
  pinMode ( red,    OUTPUT );  
  pinMode ( yellow, OUTPUT );
}

void loop() {
  // move bot forward
   digitalWrite( green,  1 ); // HIGH
   digitalWrite( blue,   0 ); // LOW
   digitalWrite( red,    1 ); // HIGH
   digitalWrite( yellow, 0 ); // LOW
   delay( 1000 );

  // move bot in reverse 

  
}
