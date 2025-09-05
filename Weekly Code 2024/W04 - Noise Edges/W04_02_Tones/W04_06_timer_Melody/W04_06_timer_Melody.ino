/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Tone


  This is a mod of Tom's original code, used to explore using timers to play a song.  It makes use of arrays and timers.
  The original is a bit sneaky as it used the 3rd parameter of tone() -- which is a timer.  Then
  embedded this inside a for..loop with a delay to create the needed rests between notes.

  I decided to run with two states -- one for notes, one for rests, each with its own timer.  
  
  This meant making a rests[] array to hold length of rests in order.  
  
  When a timer expires it sets up the alternate state, which follows.

  So, the NOTES timer sets up the next REST when it expires, and the REST timer sets up the next note.

  A single timer version could be imagined where the melody and duration arrays are extended to include notes AND rests.

*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// rests in the melody:
int rests[] = {
  75, 37, 37, 75, 75, 75, 75, 75
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int speakerPin = 12;

// timer variables
unsigned long now;
unsigned long noteDuration=0; // note duration
unsigned long startTime;

unsigned long restDuration= 0; // duration of silence

int thisNote = 0; // a counter to move us through the notes.
 
// state variables
int REST = 0;
int NOTE = 1;

int STATE; // start by playing notes

void setup() {

  // iterate over the notes of the melody:
  Serial.begin(9600);
  Serial.print("start ");

  // start playing first note  - timers trigger AT END of events, so need an initial event
  STATE=NOTE;
  noteDuration = 1000 / noteDurations[thisNote];
  tone(speakerPin, melody[thisNote]);

}

void loop() {

  now = millis();

  // each note is played, followed by a REST ... so at end of note, queue a REST
  if (STATE == NOTE) {

    if (now-startTime >= noteDuration) {
      // once a note ends, the action is to start a delay. 
      restDuration = rests[thisNote];
      STATE = REST;

      startTime = startTime + noteDuration;  // this is delay start time 
      noTone(speakerPin);
    } // end PLAY timer
  } // end STATE == PLAY a note

  // to distinguish the notes, set a minimum time between them
  // rest begins after a note .. when it expires, the next note must be queued
  if (STATE == REST) {
    if (now-startTime >= restDuration){
      // rest is done ... set up next note 
      thisNote++;

      noteDuration = 1000 / noteDurations[thisNote];
      tone(speakerPin, melody[thisNote]);
      STATE = NOTE;
      startTime += restDuration;

      // check for end of song
        if (thisNote >= 8) {
          Serial.println(" fin");
          noTone(speakerPin);
          while(1);
        } // end if 

      Serial.print(".");

    } // end REST timer  
  } // end STATE == REST

} // end loop 