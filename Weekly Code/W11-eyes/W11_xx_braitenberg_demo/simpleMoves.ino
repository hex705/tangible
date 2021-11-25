void forward(){
    digitalWrite(ledPin, 1);
 // forward
   digitalWrite( green, 1 ); // HIGH
   digitalWrite( blue,  0 ); // LOW
   
   digitalWrite( red,    1 ); // HIGH
   digitalWrite( yellow, 0 ); // LOW 
    
} // end forward


void backward() {
    digitalWrite(ledPin, 0);
    //backward
   digitalWrite( green,  0 ); 
   digitalWrite( blue,   1 ); 
   
   digitalWrite( red,    0 ); 
   digitalWrite( yellow, 1 );  
   
} // end backward

void stop() {
    //stop
     digitalWrite(blue,    0 );  // HIGH or 1
     digitalWrite(green,   0 );  // LOW or 0 
     digitalWrite(red,     0 );  // HIGH or 1
     digitalWrite(yellow,  0 );  // LOW or 0

} // end stop



void right(int howLong){
    //right
     digitalWrite(blue,    1 );  // HIGH or 1
     digitalWrite(green,   0 );  // LOW or 0 
     digitalWrite(red,     0 );  // HIGH or 1
     digitalWrite(yellow,  0 );  // LOW or 0 

     delay( howLong );
   
} // end right


void left(int howLong) {
    
    //left
     digitalWrite(blue,    0 );  // HIGH or 1
     digitalWrite(green,   0 );  // LOW or 0 
     digitalWrite(red,     1 );  // HIGH or 1
     digitalWrite(yellow,  0 );  // LOW or 0 

     delay( howLong );
  
}// end left
