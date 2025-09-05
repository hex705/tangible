// generate a staircase of tones with silence between each climb
// use timers for the silence AND for the staircase!

// https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

/* 

This example shows both the power of timers, but also reveals how they require very structured code.
Using timers for both the stairs and the silence 
adds some logic to the code that otherwise gets hidden with delays.

Within the loop, there are two(2) STATES - one for SILENCE, one for PLAYing notes.  

STATE = PLAY, play 8 notes ascending in frequency, each note for 500mS (1/2 sec)
STATE = SILENT, silence for 1 sec

In PLAY state,
  -- overall, this block plays 8 notes in a row, each of higher frequency
  -- notes are played one at a time
  -- the timer controls length of note and which one is played
  -- when the timer expires (end of each note):
        -- a new note is calculated, and played
        -- and the note counter (position along staircase of 8) is incremented by 1
        -- timer start is moved forward
        -- check to see if this counter = 8, ie we are at top of stairs - ahve played last note
              YES at top?
                -- turn off speaker
                -- change STATE to SILENT
                -- reset stepCount - put us back to bottom of stars for next climb
              NO, not at top - continue with PLAY timer

In SILENT state (at end of loop), 
  -- the timer simply checks for the one second of silence to expire. 
  -- changes STATE to PLAY mode.

  */

// speaker variable
int speakerPin = 12;

// size of tone steps
int stepSize = 50; 

// counters
int noteCount = 0; // not this was in the for..loop in delay example
int loopCounter = 0;

// timer variables
unsigned long now;
unsigned long interval=500; // note duration
unsigned long startTime;

unsigned long silentInterval=1000; // duration of silence

// state variables
int SILENCE = 0;
int PLAY = 1;

int STATE=PLAY; // start by playing notes


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  now = millis();

  // do stuff every loop here
  Serial.print("loop "); // \n = inside quotes == newline
  Serial.println(loopCounter);
  
  // do timer stuff with all the code below ... 
  // if we are playing, use this timer to climb stairs
  if (STATE == PLAY){
    // note timer
    if ( now-startTime >= interval) {

      Serial.print("  tone ");
      Serial.print(noteCount);

      int freq = 300 + (noteCount * stepSize);  // 50 == step size (delared above), 300 lowest note
      tone( speakerPin, freq );

      Serial.print("\tfreq "); 
      Serial.println(freq);

      startTime += interval; // move timer forward for next note 
      noteCount+=1;  //increment step count - and limit it to 8

        // what to do at top of stairs (ie 8th note has played) ?
        if(noteCount>8){ 
            // silent pause between ascents
            noTone(speakerPin);
            noteCount=0; // once done at top of stairs, jump to bottom.
            STATE = SILENCE;
        } // end if top of staircase

    } // end of note timer
  } // end of STATE == PLAY


  // timer check - time for a new note?
  if (STATE == SILENCE) {

    // timer for silence between ascents
    if ( now-startTime >= silentInterval) {
      STATE = PLAY; // silence ends, change to playing notes
      startTime += silentInterval; // move timer forward for first note
    } // end of SILENT timer

  } // end of STAE == SILENT


  //increment loop counter
  loopCounter++;

}
