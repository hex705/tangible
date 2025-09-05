// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI Peripheral device
// Refer to the "Wire Peripheral Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
}

byte x = 0;

void loop()
{
  wireSend(1); //on
  delay(3000);
  wireSend(3); //off
  delay(3000);
  wireSend(2);
  delay(3000);

}

void wireSend(int theValue){

  Wire.beginTransmission(4); // transmit to device #4
  Wire.write(theValue);              // sends one byte  
  Wire.endTransmission();    // stop transmitting 
  Serial.println(theValue);
}