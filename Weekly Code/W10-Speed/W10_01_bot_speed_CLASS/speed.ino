
//setSpeed(150, 75); // remember this is in loop 

void setSpeed(int left, int right){
  //  using analog write,
  //  set each wheel speed independently
  
  analogWrite( leftSpeedPin,  left  ); // left moto
  analogWrite( ??? , ??? ); // right motor
  
} // end set speed


void setSpeed(int theSpeed){
    // set both wheels with one speed parameter
    // call one function from another
    setSpeed( theSpeed, theSpeed);
    
} // end setSpeed


void forward(int leftSpeed, int rightSpeed){
  // set both wheel speeds, then call direction (fwd)
      // put a speed call here
      // put a direction call here 
} // forward speed


void backward(int leftSpeed, int rightSpeed){
  // set the wheel speeds, then call direction (bwd)
      // put a speed call here
      // put a direction call here 
} // backward speed
