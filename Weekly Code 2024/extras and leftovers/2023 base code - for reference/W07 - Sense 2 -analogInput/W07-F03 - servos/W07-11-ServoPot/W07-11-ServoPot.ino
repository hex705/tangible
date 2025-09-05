// 180 servo controlled by pot

#include <Servo.h> // use a library

Servo myservo; // cool variable type!
int pos = 0;
int potPIN = A1;  // where is the potentiometer?

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  pinMode( potPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  int pos = analogRead(potPIN); 

  Serial.print(pos);   // raw number
  Serial.print("\t");  // tab

  pos = map(pos, 0, 1023, 0, 180); // scale the input
  Serial.println(pos); // input value mapped to angle
  myservo.write(pos);  // value as Angle
  delay(15);

}

