
// based on Arduino --> Examples --> Servo --> Sweep

#include <Servo.h>  // use a library

Servo myservo; // create servo object 

int pos = 90;  // middle of range

void setup() {
  // put your setup code here, to run once:
  myservo.attach(10); // 10 = pin where servo is connected
}

void loop() {
  
   for (pos = 0; pos <= 180; pos += 1) {    // goes from 0 degrees to 180 degrees
    myservo.write(pos);                     // tell servo to go to position in variable 'pos'
    delay(15);                              // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);            
    delay(15);                     
  }
}
