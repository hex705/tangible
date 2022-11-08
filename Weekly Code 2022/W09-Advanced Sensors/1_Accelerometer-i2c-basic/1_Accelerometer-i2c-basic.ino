// Simplified example -- see video for details.
// This example shows the 3 axis acceleration.
#include "LIS3DHTR.h"
#include <Wire.h>
LIS3DHTR<TwoWire> LIS; //IIC
#define WIRE Wire

void setup() {
    Serial.begin(115200);
    while (!Serial) {};
    
    LIS.begin(WIRE, 0x19); //IIC init
    delay(100); // give it a moment to start
    
    LIS.setFullScaleRange(LIS3DHTR_RANGE_2G); //sensitivity
    LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ); // data rate
    LIS.setHighSolution(true); //High solution enable
}
void loop() {
    if (!LIS) {
        Serial.println("LIS3DHTR didn't connect.");
        while (1);
        return;
    }
    //3 axis
    Serial.print("x:"); Serial.print(LIS.getAccelerationX()); Serial.print("  ");
    Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
    Serial.print("z:"); Serial.println(LIS.getAccelerationZ());

    delay(50);
}
