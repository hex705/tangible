// continuous and postional servos

#include <Servo.h> 

Servo positional_180;
Servo continuous_360;

int pos = 90;
int increment = 1; 

void setup()
{
  positional_180.attach(3);
  continuous_360.attach(4);
  Serial.begin(9600);
}

void loop()
{
  // movement from 90 to 180

  // if you need to center the servos and attach horns, 
  // use this line then comment out
  
  //pos = 90; 
  
  positional_180.write(pos);
  continuous_360.write(pos);
  delay(50); // it takes time to physically move
  pos+=increment;

  // use the following one at a time

      // 90 to 0 (right side, clockwise) 
      // if ((pos <= 0) || (pos>=91)) {increment *= -1; delay(1000); }
  
      // 90 to 180 left side, counter clockwise 
      //if ((pos >= 180) || (pos<=90)) {increment *= -1; delay(1000); }
    
      // full swing 0-180, start at 90 
      if ((pos <= 0) || (pos>=180)) {increment *= -1; delay(1000); }
  
  Serial.println(pos);

}
