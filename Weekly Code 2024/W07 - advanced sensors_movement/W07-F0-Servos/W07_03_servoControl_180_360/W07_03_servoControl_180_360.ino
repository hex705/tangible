// continuous and postional servos

#include <Servo.h> 

Servo positional_180;
Servo continuous_360;

int postionalPin = 3;
int continuousPin = 4;

int pos = 90;
int potPIN = A1;  // where is the potentiometer?

void setup()
{
  positional_180.attach(postionalPin);
  continuous_360.attach(continuousPin);
  pinMode( potPIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int pos = analogRead(potPIN); 

  Serial.print(pos);   // raw number
  Serial.print("\t");  // tab

  pos = map(pos, 0, 1023, 0, 180); // scale the input
  Serial.println(pos); // input value mapped to angle
 
  positional_180.write(pos); // value as Angle
  continuous_360.write(pos); // value as speed and direction
  
  delay(15);
}
