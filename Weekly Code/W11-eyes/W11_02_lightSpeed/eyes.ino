void readEyes() {
  // what is the number range of analog INPUT?
  leftEyeValue  = analogRead(leftEye) /4  ; // divide by 4 so they acn be used with motors 
  rightEyeValue = analogRead(rightEye) /4 ;

    // keep eye values in range of motors speeds (0-255) - redundant ? 
    if ( leftEyeValue > 255 ) leftEyeValue  = 255;
    if ( rightEyeValue > 255) rightEyeValue = 255;

    if ( leftEyeValue  <= 0 ) leftEyeValue  = 0;
    if ( rightEyeValue <= 0 ) rightEyeValue = 0;

  averageEyes = ( leftEyeValue + rightEyeValue) / 2;
}


void printEyes() {

  Serial.print( leftEyeValue );
  Serial.print( "\t" ); // a tab
  Serial.print( rightEyeValue );
  Serial.print( "\t" ); // a tab
  Serial.println ( lightThreshold );
}

// note this funtion start with int 
// int is the type of variable that this function returns

int checkBrightnessThreshold() {
  int brightnessNow;
  
  // determine if its bright or dark (I am using only right eye -- you could average)
  if (rightEyeValue > lightThreshold) {
    // its bright!
    brightnessNow = 1;
    Serial.print( "its bright, currentBrightness = " );
    Serial.println( brightnessNow );
  } else {
    // its dark
    brightnessNow = 0;
    Serial.print( "its dark, currentBrightness = " );
    Serial.println( brightnessNow );
  }
  return brightnessNow;
}
