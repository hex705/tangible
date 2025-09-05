void calibrate(int newValue){
  if(newValue > maxBrightness)  maxBrightness = newValue;    
  if(newValue < minBrightness)  minBrightness = newValue; 
  brightnessRange = maxBrightness-minBrightness;
  brightnessThreshold = minBrightness + (brightnessRange*thresholdAmount);
}


int checkThreshold(int theValue){
  if (theValue > brightnessThreshold) return 1;  // above threshold 
  if (theValue < brightnessThreshold) return 0;  // below threshold
}
