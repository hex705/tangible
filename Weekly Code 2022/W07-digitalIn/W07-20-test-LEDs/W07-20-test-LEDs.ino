// W07-20-test-LEDs
// make sure LED is ready for class
/* pattern:
 *  
 *  red   on/off digital blink -- 500mS on/off
 *  green on/off digital blink -- 250mS on/off
 *  blue  on/off digital blink -- 100mS on/off
 *  
 *  red   analog fade -- 0-100
 *  green analog fade -- 0-150
 *  blue  analog fade -- 0-200
 *  
 *  led goes off breifly at end of each fade. 
 */


int rPin =  11 ;   // pin declare -- where is circuit ?
int gPin =  10 ;   // pin declare -- where is circuit ?
int bPin =   9 ;   // pin declare -- where is circuit ?

void setup() {
  pinMode(rPin,  OUTPUT ); // INPUT OR OUTPUT ?
  pinMode(gPin,  OUTPUT ); // INPUT OR OUTPUT ?
  pinMode(bPin,  OUTPUT ); // INPUT OR OUTPUT ?
  
}

void loop () {
  blinkLED(rPin, 2, 500);
  blinkLED(gPin, 4, 250);
  blinkLED(bPin, 10,100);

  fadeLED(rPin, 0, 100);
  fadeLED(gPin, 0, 150);
  fadeLED(bPin, 0, 200);

  delay(1000);
}


// functions
void blinkLED( int whichOne, int howMany, int howLong){
  for(int i = 0; i < howMany; i++){
    digitalWrite(whichOne, 1);
    delay(howLong);
    digitalWrite(whichOne, 0);
    delay(howLong);
  }
}

void fadeLED( int whichOne, int start, int end){
  for (int i = start; i < end; i+=3){
    analogWrite(whichOne, i);
    delay(50);
  }
  analogWrite(whichOne, 0); // turn whichOne off 
  delay(250); // give eye a moment to adjust
}
