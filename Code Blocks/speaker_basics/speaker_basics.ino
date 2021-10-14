/*

  tangible
  steve daniels, Oct 2021

  simple tone generator to test a speaker (on pin 8) 

*/


int speakerPin = 8;
int noteDuration = 25;

void setup() {
  /*  while(1); is a simple way to force your arduino to stop
   *  this line says:
   *    - while true repeat the stuff in the braces {}   
   *  Since we put 1 in the parenthesis () -- it is always true
   *  Since we put nothing in the braces -- it does nothing; forever.
   *  
   *  uncomment this line and upload to stop your speaker.
   *  comment it out and upload when you want to make noise.
   *  (or just remove and replace the wire from pin 8)
   */
   
   // while(1){};// this is a hack that causes your code to stop at this line
}

void loop() {

  for (int frequency = 100; frequency <= 1200; frequency += 100) {
    tone(speakerPin, frequency); // create tone  
    delay(noteDuration);         // feel the tone wash over you
    noTone(speakerPin);          // stop the tone. 
  }

}
