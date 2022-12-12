// this function reads the distance 'howMany' times
// it then returns the average of those readings


int averageBrightness( int howMany ){
  long dist = 0;
  for (int i = 0; i < howMany; i++){
      dist += analogRead(lightSensorPin);
      delay(2);
  }
  return dist = (int) dist / howMany;
}
