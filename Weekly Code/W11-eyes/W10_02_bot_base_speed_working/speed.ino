
//setSpeed(150, 75); // remember this is in loop 

void setSpeed(int left, int right){
  //  using analog write,
  //  set each wheel speed independently
  
  analogWrite( leftSpeedPin,  left  );
  analogWrite( rightSpeedPin, right ); 
  
} // end set speed


void setSpeed(int theSpeed){
    // set both wheels with one speed parameter
    // call one function from another
    setSpeed( theSpeed, theSpeed);
    
} // end setSpeed


void forward(int leftSpeed, int rightSpeed){
  // set both wheel speeds, then call direction (fwd)
  setSpeed (leftSpeed, rightSpeed);
  forward();
} // forward speed


void backward(int leftSpeed, int rightSpeed){
  // set the wheel speeds, then call direction (bwd)
  setSpeed (leftSpeed, rightSpeed);
  backward();
} // backward speed
