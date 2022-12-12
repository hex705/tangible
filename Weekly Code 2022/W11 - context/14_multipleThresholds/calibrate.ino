

void calibrate(int newValue){
  if(newValue > maxBrightness)  maxBrightness = newValue;    
  if(newValue < minBrightness)  minBrightness = newValue; 
  brightnessRange = maxBrightness-minBrightness;
  brightnessLowThreshold = minBrightness + (brightnessRange*lowThresholdAmount);
  brightnessHighThreshold = minBrightness + (brightnessRange*highThresholdAmount);
}


int checkThreshold(int theValue){
  if (theValue < brightnessLowThreshold) return 0;  // below threshold
  if (theValue > brightnessHighThreshold) return 1;  // above threshold 
  if( theValue > brightnessLowThreshold && theValue < brightnessHighThreshold) return 2; // in between
}
