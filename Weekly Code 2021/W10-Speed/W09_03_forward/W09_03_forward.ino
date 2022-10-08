// W09_03_forward

const int green  = 4 ; // change the '?' to pin numbers
const int blue   = 5 ; //
const int red    = 9 ; // if a wheel goes backward,
const int yellow = 8 ; // flip the pin numbers for that wheel.

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
   digitalWrite( green,  0 ); // HIGH
   digitalWrite( blue,   1 ); // LOW
   digitalWrite( red,    0 ); // HIGH
   digitalWrite( yellow, 1 ); // LOW
   delay( 1000 );

   // stop 
   digitalWrite( green,  1 ); // HIGH
   digitalWrite( blue,   1 ); // LOW
   digitalWrite( red,    0 ); // HIGH
   digitalWrite( yellow, 0 ); // LOW
   delay( 1000 );

   // left 
   digitalWrite( green,  1 ); // HIGH
   digitalWrite( blue,   1 ); // LOW
   digitalWrite( red,    1 ); // HIGH
   digitalWrite( yellow, 0 ); // LOW
   delay( 1000 );
  

  
}
