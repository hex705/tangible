// generate a simple tone 
// https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

// speaker variable
int speakerPin = 12;

// size of tone steps
int stepSize = 50; 

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

  // FOR..NEXT within loop stair climb.
  // how many ways can you reconfigure this loop for same effect?

  for (int stepCount = 0 ; stepCount < 8; stepCount++){

    Serial.print("  tone ");
    Serial.print(stepCount);

    int freq = 300 + (stepCount * stepSize);  // 50 == step size (delared above)
    tone( speakerPin, freq );

    Serial.print("\tfreq "); 
    Serial.println(freq);

    delay(500); // duration of each tone

    // pause between notes? try uncommenting following two lines
      // noTone(speakerPin);
      // delay(50);
  }

  // silent pause between ascents
  noTone(speakerPin);
  delay(1000);

  //increment loop counter
  loopCounter++;

}
