#include <Servo.h>  // use a library
Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3); // pin where 180 servo is connected
}

void loop() {
  // put your main code here, to run repeatedly:

  // first time centre the servo with this code then attach horn
  myservo.write(90);

}


// once horn is attached, lets sweep the servo with code. 


//  for (CURRENT_COUNT=START; END; STEP) {
//    myservo.write(CURRENT_COUNT);
//    delay(20);
//  }
  
//  for (pos = 0; pos <= 180; pos += 10) {
//    myservo.write(pos);
//    delay(20);
//  }
//
//  for (pos = 180; pos >= 0; pos -= 10) {    
//    myservo.write(pos);
//    delay(20);
//  }


//}
