void readSonar() {

  // every 60 mS get a new reading ...
  if (now - startTime > senseInterval) {
    distanceReading = ultrasonic.read();  // just do a straight read -- the average was misleading

    // store limit data when nothing is happening -- result = limit as 'baseline' - top of plotter
    if ((distanceReading == timeoutDistance) and (SONAR_STATE == STANDBY)) {
      DATA = INCLUDE;
    }

    // active zone reading -- we got one!
    if (distanceReading != timeoutDistance) {  // this if..then removes timeout noise
      SONAR_STATE = ACTIVE;
      activeStart = now;
      DATA = INCLUDE;
    }

    // error spike -- timeout while reading
    if ((distanceReading == timeoutDistance) and (SONAR_STATE == ACTIVE)) {
      // this is an error spike
      DATA = EXCLUDE;
    }

    // once we know what to do with current data point, do it.
    if (DATA == INCLUDE) {
      ema = emaValue * distanceReading + (1.0 - emaValue) * ema;
      medianValues.in(distanceReading);  // ema can replace distancereading if desired -- its a double filter
      filteredValues = medianValues.out();

      DATA = EXCLUDE;
    }

    printStuff();
    startTime += senseInterval;  // reset 60mS timer for readings
  
  }// end timer
}