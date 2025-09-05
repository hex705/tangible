// generate a simple tone staircase
// https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

/*

  -- this example was originally W04_02_toneStairCase
  --  connect AN LED rather tahna speaker to pin 12 -- you will see weird behaviour
  -- this hints at how tone and PWM relate -- see links

  // https://docs.arduino.cc/learn/microcontrollers/analog-output/
  // https://www.arduino.cc/reference/tr/language/functions/advanced-io/tone/

*/

// speaker variable
int speakerPin = 12;

// size of tone steps
int stepSize = 1; //50

// counters
int loopCounter = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  Serial.print("\nloop "); // \n = inside quotes == newline
  Serial.println(loopCounter);

  // FOR..NEXT stair climb - similar to LED fade.
  // how many ways can you reconfigure this loop for same effect?

  for (int stepCount = 0 ; stepCount < 8; stepCount++){

    Serial.print("  tone ");
    Serial.print(stepCount);

    int freq = 15 + (stepCount * stepSize);  // 50 == step size (delared above)
    tone( speakerPin, freq );

    Serial.print("\tfreq "); 
    Serial.println(freq);

    delay(500); // duration of each tone, within for..loop
    // pause between notes? try uncommenting following two lines
      noTone(speakerPin);
      delay(200);
  }

  // silent pause between ascents
  noTone(speakerPin);
  delay(1000);

  //increment loop counter
  loopCounter++;

}
