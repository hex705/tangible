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
  // get POT value
  int pos = analogRead(potPIN); 
  Serial.print(pos);   // raw number
  Serial.print("\t");  // tab

  // map the sensor to servos - output to plotter
  pos = map(pos, 0, 1023, 0, 180); // scale the input to servo out
     Serial.print(180); // force plotter to scale  
     Serial.print("\t"); // for plotter use - scale
  Serial.println(pos); // input value mapped to angle

  // write to both servos !
  positional_180.write(pos); // mapped value as Angle
  continuous_360.write(pos);
  
  delay(15); // slow down a bit for plotter - could wrap it all in a timer
}
