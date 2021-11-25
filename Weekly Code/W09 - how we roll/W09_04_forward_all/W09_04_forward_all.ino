// W09_04_forward_all

const int green  = 4 ; // where is the circuit ?
const int blue   = 5 ; // where is the circuit?
const int yellow = 8 ; // where is the circuit?
const int red    = 9 ;

void setup() {
  // put your setup code here, to run once:
  pinMode ( green,  OUTPUT ) ;  // output because we are sending a signal out
  pinMode ( blue, OUTPUT ); // output because we are sending a signal out
  pinMode ( red,  OUTPUT ) ;  // output because we are sending a signal out
  pinMode ( yellow, OUTPUT );

}

void loop() {
  // put your main code here, to run repeatedly:

   digitalWrite( green, 1 ); // HIGH
   digitalWrite( blue, 0  ); // LOW
   
   digitalWrite( red,  1   ); // HIGH
   digitalWrite( yellow, 0 ); // LOW
   delay( 1000 );

   // now add code to switch the the flow in the circuit
   digitalWrite( green , 0 ) ; 
   digitalWrite( blue ,  1 ) ; 
   
   digitalWrite( red ,    0 ) ; 
   digitalWrite( yellow , 1 ) ; 
   delay(1000);

  
}
