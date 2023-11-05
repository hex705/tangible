// continuous and postional servos

#include <Servo.h> 

Servo positional_180;
Servo continuous_360;

int pos = 90;
int potPIN = A1;  // where is the potentiometer?

void setup()
{
  positional_180.attach(3);
  continuous_360.attach(4);
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
 
  positional_180.write(pos);// value as Angle
  continuous_360.write(pos);
  
  delay(15);
}
