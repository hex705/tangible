// Simplified example -- see video for details.
// This example shows the 3 axis acceleration.
#include "LIS3DHTR.h"
#include <Wire.h>
LIS3DHTR<TwoWire> LIS; //IIC
#define WIRE Wire

#include <Servo.h> 

float xValRaw, yValRaw, zValRaw;
int   xVal,yVal,zVal;

// servo variables
Servo positional_180;
int servoValue;

// postion limits for mapping -- contextual -- you need to think a bit here
int accel_xLow = -1000;    // adjust both of these for your context 
int accel_xHigh = 1000; 

// servo postion limits for mapping
int servoLow = 0;
int servoHigh = 180;

void setup() {
    Serial.begin(115200); // NOTE !!!!!!! - change your plotter/monitor
    while (!Serial) {};

    // accel setup 
    LIS.begin(WIRE, 0x19); //I2C init --0x19 for Uno
    delay(100); // give it a moment to start
    
    LIS.setFullScaleRange(LIS3DHTR_RANGE_2G); //sensitivity
    LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ); // data rate
    LIS.setHighSolution(true); //High solution enable

    if (!LIS) {
        Serial.println("LIS3DHTR didn't connect.");
        while (1);
        return;
    }

    // servo variables
    positional_180.attach(3);
    
}
void loop() {
    
    //read sensor
      xValRaw = LIS.getAccelerationX();
      yValRaw = LIS.getAccelerationY();
      zValRaw = LIS.getAccelerationZ();

    //integrate readings

      // sensor returns floats, map needs ints...
      // convert raw (-1.0 -> 1.0) to range of -1000 -> 1000, make answer an int
      xVal = xValRaw * 1000.0;
      yVal = yValRaw * 1000.0;
      zVal = zValRaw * 1000.0;
  
      // map the int sensor reading
      servoValue = map(xVal, accel_xLow, accel_xHigh, servoLow, servoHigh); //0,180 
      
      // limit the range
      if (servoValue < servoLow)  servoValue = servoLow;
      if (servoValue > servoHigh) servoValue = servoHigh;
      //  if (filteredValues >= 105) servoValue = 90; // stop servo when nothing in front of sensor

    // take action
      positional_180.write(servoValue);
      Serial.print(servoValue); Serial.print('\t');
//      Serial.print(xValRaw);    Serial.print('\t');
//      Serial.print(yValRaw);    Serial.print('\t');
//      Serial.print(zValRaw);    Serial.print('\t');
      Serial.print(xVal);       Serial.print('\t');
      Serial.print(yVal);       Serial.print('\t');
      Serial.println(zVal);
  
    delay(10);
}
