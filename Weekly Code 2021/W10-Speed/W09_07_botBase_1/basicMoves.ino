void forward() {
  // move bot forward
   digitalWrite( green, 1 ); // HIGH
   digitalWrite( blue,  0 ); // LOW
   
   digitalWrite( red,    1 ); // HIGH
   digitalWrite( yellow, 0 ); // LOW
} 

void backward(){
 // move bot backward
   digitalWrite( green,  0 ); 
   digitalWrite( blue,   1 ); 
   
   digitalWrite( red,    0 ); 
   digitalWrite( yellow, 1 ); 
}
 
void stop() {
   // stop
   digitalWrite( green,  0 ); 
   digitalWrite( blue,   0 ); 
   
   digitalWrite( red,    0 ); 
   digitalWrite( yellow, 0 ); 
}

void left(){


}

void right(){
  
}
