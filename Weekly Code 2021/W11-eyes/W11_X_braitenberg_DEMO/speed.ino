
void setSpeed(int theSpeed){
    // set both wheels with one speed parameter
    // all one function from another
    
} // end setSpeed

void setSpeed(int left, int right){
  right = right - 4; // 4 is the offset I needed to make speed(255,255) go straight
                     // i adjusted right because it was faster (my bot naturally turns left).  
  if(right < 0) right = 0;
  //  using analog write,
  //  set each wheel speed independantly
     analogWrite( leftSpeedPin, left);
     analogWrite(rightSpeedPin, right);
} // end set speed


void backward(int leftSpeed, int rightSpeed){
  // set the wheel speeds, then call direction (bwd)

   
} // backward with speed


void forward(int leftSpeed, int rightSpeed){
  // set both wheel speeds, then call direction (fwd)
   setSpeed(leftSpeed, rightSpeed);
   forward();
} // forward with speed
