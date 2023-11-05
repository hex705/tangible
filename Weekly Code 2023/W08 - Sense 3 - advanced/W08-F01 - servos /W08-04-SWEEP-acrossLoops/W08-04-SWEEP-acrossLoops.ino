// continuous and postional servos

#include <Servo.h> 

Servo positional_180;
Servo continuous_360;

// servo postion variables
int pos = 85;
int increment = 1; 

// movement timer variables
unsigned long movementInterval=50;
unsigned long moveStart;
unsigned long timeNow;

void setup()
{
  positional_180.attach(3);
  continuous_360.attach(4);
  Serial.begin(9600);
}

void loop()
{

  timeNow = millis();

  // only change *pos* when timer expires -- it takes time to physically move 
  if (( moveStart - timeNow) > movementInterval){
    pos+=increment;  // increment position once per timer
    moveStart+=movementInterval;
  }

  // full swing 0-180, start at 90 
  if ((pos <= 0) || (pos>=180)) {increment *= -1;  }
  
// take action - every loop 
  positional_180.write(pos);
  continuous_360.write(pos);
  Serial.println(pos);


}
