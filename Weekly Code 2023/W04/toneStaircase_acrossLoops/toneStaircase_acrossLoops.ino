// generate a simple tone 
// https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

// speaker variable
int speakerPin = 12;

// size of tone steps
int stepSize = 50; 

// counters
int loopCounter = 0;
int stepCount = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  Serial.print("\nloop "); // \n = inside quotes == newline
  Serial.println(loopCounter);

    Serial.print("  tone "); // \n = inside quotes == newline
    Serial.print(stepCount);

    // calculate the freqency (tone) for THIS loop / stepCount
    int freq = 300 + (stepCount*stepSize);
    tone( speakerPin, freq, 500);

    // print out the frequency
    Serial.print("\tfreq ");
    Serial.println(freq);

    // duration of each tone
    delay(500); 

    // pause between notes? try uncommenting following two lines
      // noTone(speakerPin);
      // delay(50);


  // silent pause
  // compare with toneStaircase.ino -- this FALLS BETWEEN TONES NOW !!! 
  noTone(speakerPin);
  //delay(1000);

  //increment and limit stepCount
  stepCount++;
  if ( stepCount >= 8 ) { 
    stepCount=0;
    // add noTone AND delay here for silence BETWEEN sets
      // noTone(speakerPin);
      // delay(1000);
  }

  //increment loop counter
  loopCounter++;
 
}
