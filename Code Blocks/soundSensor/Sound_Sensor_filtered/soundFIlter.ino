
float filterData( int newTestValue ) {

  // centre the values around zero -- this makes some math easier in long run
  // the depends on getting really good average at start
  int difference = newTestValue - midPoint;

  // sounds deflects up and down -- make it all postiive
  int absDifference = abs(difference);

  // overall sound cause small reading changes
  // sensor is bouncy but overall stable (it varies by 1 or 2, but does not throw giant spikes)
  // so we want to get rid of all that tiny background variation
  // we will pre filter this so tiny changes just become zeros
  // then amplify the larger variations and track them

  if (absDifference < noiseReduction) { // mine is 2 
    newTestValue = 0;
  } else {
    newTestValue = absDifference;
  }

  // we get here with a zero OR a change of interest
  // these diffences may still only be 3 or 4 above background
  // which is small given the sensor range is potentially 0-1023
  // scale up these changes of interest with a multiplier
  // zero's -- uninteresting changes -- stay zero

  newTestValue *= soundScaler;

  /* EXPONENTIAL MOVING AVERAGE
     Now we apply an exponential moving average
     A what ? -- https://hackaday.com/2019/09/06/sensor-filters-for-coders/
     variable weightEMA_1 is a sliding scale from 0 to 1 (like a teeter-totter)
     EMA_1  = (some proportion of the newTestValue) + ( some proportion of the MOVING AVERAGE)
     If EMA_1 is close to ZERO (0) -- then OLD readings are more important than NEW ones
     IF EMA_1 is close to ONE  (1) -- then NEW readings are more important than OLD ones
     weightEMA_1 is defined above setup in main tab -- try different values
  */

  EMA_1 = weightEMA_1 * newTestValue + (1.0 - weightEMA_1) * EMA_1;

  // subtract above from current reading to enhance brief spikes in volume.
  highPass = (newTestValue - EMA_1);
  // keep it all positive
  highPass = abs(highPass);

  //loudnessDetect[1] = highPass;  // save the EMA filteed values
  currentLoudness = highPass;

  if ( currentLoudness >= lastLoudness) { // got an upswing
    peak = currentLoudness;
  }

  peakHold = peak;  // store the recent peak loudness
  if (peak > maxPeak) maxPeak = peak; // store the loudest sound you have heard since starting


  // dubug and plotting
  // printout the various values
  Serial.print(currentLoudness);
  Serial.print('\t');
  Serial.print(peakHold);
  Serial.print('\t');
  //Serial.print(maxPeak); // uncomment if you want to see loudest sound (graph will loose resolution
  //Serial.print('\t');
  Serial.println( );

  // store the currentLoudness for use in next loop
  lastLoudness = currentLoudness;

  return currentLoudness; // send the filteredLoudness back to fxn call
}




// this is called once from setup
void getAverage(int howMany)
{
  long runningTotal=0;
  
  for (int i = 0; i < howMany; i ++){  
      runningTotal += analogRead(sensorAnalogPin);
      delay(1);  
  } // end for
  
  midPoint = runningTotal / howMany;
  Serial.println(); 
}
