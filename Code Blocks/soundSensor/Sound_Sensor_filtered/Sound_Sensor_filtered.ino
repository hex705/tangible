// update daniels 2020

// based in part on
// www.elegoo.com
// 2018.10.24
 
/*
  LED1 should be lit, showing power. LED2 (bedine the blue POT) indicates sound input, and the sensitivity is adjusted by potentiometer.
  There is a tiny screw on the blue potentiometer block that you can use for adjustment. Turning that
  clockwise lowers the potentiometer value, while counter-clockwise raises the potentiometer value.
  Use the potentiometer to adjust the Sound Sensor sensitivity. Turn the potentiometer
  several rotations until you see the LED2 extinguish (or just faintly blink). 
  This might be slightly greater than 500, if you are also watching Serial Monitor (inital adjustment)
*/

// where is the soundSensor connected        
int  sensorAnalogPin = A3;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor


// filtering variables -- there are lots here as we do a lot
// of signal processing
int   midPoint; // get us started variable -- probably a better way to do this .. but well its end of term. 
int   noiseReduction = 2; 
float weightEMA_1 = 0.9; // range 0 to 1 :: 0.6 is fast strong in my setup - set soundFilter Tab for more info
int   soundScaler = 25; // range 1 to 50ish -- really just for visualizing data -- makes it all feel dramatic (try 1 if you like)

float EMA_1, highPass;
float peak, maxPeak, peakHold;
float currentLoudness, lastLoudness, filteredLoudness;
float loudnessThreshold = 3;

void setup()
{
  Serial.begin(115200); // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(A3, INPUT);
  getAverage(100);
}

void loop()
{
 
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue 
  filteredLoudness = filterData(analogValue);
  
  // once you have a filtered number, do something with it.
  // you will ahve to look at the size of filterdLoudness 
  // and decide what to do in your project
   
  if ( filteredLoudness > loudnessThreshold ){
    // do cool stuff here
  }
  
  delay(2); // legacy pause -- probs intitially to limit data to serial -- delete?
}
