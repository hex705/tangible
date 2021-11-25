// W09_02_DEMO-blinkTwo

const int blue = 5 ; // where is the circuit?
const int green = 4 ; // where is the circuit ? 

void setup() {
  // put your setup code here, to run once:
  pinMode ( blue, OUTPUT ) ;  // output because we are sending a signal out
  pinMode ( green,  OUTPUT ); // output because we are sending a signal out
}

void loop() {
  // put your main code here, to run repeatedly:

   digitalWrite( blue  , HIGH ) ; 
   digitalWrite( green , LOW) ; 
   delay(2000);

   // now add code to switch the the flow in the circuit

   digitalWrite( blue , LOW ) ; 
   digitalWrite( green, HIGH) ; 
   delay(2000);

  
}
