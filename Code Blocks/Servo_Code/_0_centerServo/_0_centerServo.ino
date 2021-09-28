#include <Servo.h>  // use a library

Servo myservo; // instantiate 

int pos = 90 ;  // middle of range

void setup() {
  // put your setup code here, to run once:
  myservo.attach(10); // 10 = pin where servo is connected
}

void loop() {
  
  // put your main code here, to run repeatedly:
  myservo.write( pos ) ; // (pos)ition of servo (0-180)
 
}
