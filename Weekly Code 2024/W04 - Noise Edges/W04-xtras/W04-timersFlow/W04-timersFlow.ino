
void setup() {
  // put your setup code here, to run once:

}

void loop() {

  // every loop is fast

     // all the time stuff

  // occasional stuff, done fast
  if ( now - startTime > interval){
    // occasional thing
     startTime += interval; // timer forward
  }

}
