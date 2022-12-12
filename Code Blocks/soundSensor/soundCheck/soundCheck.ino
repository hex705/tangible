// adjust the microphone 
// upload code, open serial plotter

// adjust trimmer POT -- it can take A LOT of turns
// On these boards:
// COUNTER CLOCKWISE should INCREASE the reading
// CLOCKWISE should REDUCE the reading

// you want an analog read of about 512 in a quiet room
// this should just turn off the red LED beside the pot
// the digital LED goes on when a threshold level sound is detected 


int sensorPin = A3;
int sensorValue = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue, DEC); 
  delay(10);
}
