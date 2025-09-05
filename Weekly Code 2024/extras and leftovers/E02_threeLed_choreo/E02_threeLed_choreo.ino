
// blink 3 LEDs in sequence
// led STATEs changes WITHIN loops
// change happens every 1000ms (1 sec)


// speaker pin
int speaker = 12;

// led PINs
int ledPin_1= nine; // change code, move wire from 3 to 9!
int ledPin_2= 5;
int ledPin_3= 6;

// led possible states
boolean ON = 1;
boolean OFF = 0;

// led current STATEs - declare but don't set yet
boolean STATE_1, STATE_2, STATE_3; 

// utility variables 
int loopCounter = 0; 
int sequenceCounter = 1;

// duration variables 
int beat = 500;

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  Serial.print("  sequence ");
  Serial.println(sequenceCounter);

  //  *** sequences ***
  if (sequenceCounter==1){
      // could have other code here too

      // pattern 1
      setLedsDigital(OFF,OFF,OFF); // reset - start all off 
      setLedsDigital(ON, ON, ON); 
      tone(speaker,75,300);
      delay(beat*2);

      // pattern 2
      setLedsDigital(ON,OFF,ON);
      tone(speaker,75,200);
      delay(beat);

      // pattern 3
      setLedsDigital(OFF, ON, OFF);
      tone(speaker,60,200);
      delay(beat);

      // pattern 4
      setLedsDigital(ON,OFF,ON);
      tone(speaker,75,200);
      delay(beat);

      // pattern 5
      setLedsDigital(OFF,OFF,OFF);
      delay(beat);

      // pattern 6
      setLedsDigital(ON,OFF,ON);
       tone(speaker,75,200);
      delay(beat);

      //pattern 7
      setLedsDigital(OFF, ON, OFF);
       tone(speaker,60,200);
      delay(beat);

      //pattern 8
      setLedsDigital(ON,ON,OFF);
      tone(speaker,50,400);
      delay(beat*2);
  }

  if (sequenceCounter==2){
      // pattern 1
      noTone(speaker);
      setLedsAnalog(0,0,0);
      delay(beat*2);

      // pattern 2
      setLedsAnalog(200,100,0);
      tone(speaker,400);
      delay(beat*3);

      // pattern 3
      tone(speaker,600);
      setLedsAnalog(0,200,100);
      delay(beat*3);

         // pattern 3
      tone(speaker,800);
      setLedsAnalog(80,0,100);
      delay(beat*3);
  }

  if (sequenceCounter==3){
      noTone(speaker);
      setLedsDigital(OFF, OFF, OFF);
      delay(2000);
  }


    // ***********   increment sequence counter    *****************
  sequenceCounter++;
  if (sequenceCounter > 3) sequenceCounter = 1; // constrain to 3 sequences                                      

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 
}


void setLedsDigital(int state1, int state2, int state3){

  // ***********   write the LEDs  *****************
 // Serial.print("   New sequence - ");
 // Serial.print(sequenceCounter);   // ** new
  digitalWrite(ledPin_1, state1);
  digitalWrite(ledPin_2, state2);
  digitalWrite(ledPin_3, state3);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("\tled states ->\t");
   Serial.print(state1 );
    Serial.print("\t"); // NOTE ::  \t = tab
     Serial.print(state2); 
      Serial.print("\t");  // NOTE ::  \t = tab
       Serial.println(state3); // println adds end of line and new line

}


void setLedsAnalog(int state1, int state2, int state3){

  // ***********   write the LEDs  *****************
 // Serial.print("   New sequence - ");
 // Serial.print(sequenceCounter);   // ** new
  analogWrite(ledPin_1, state1);
  analogWrite(ledPin_2, state2);
  analogWrite(ledPin_3, state3);
 
  // ***********   print LED states side by side  *****************    
  Serial.print("\tled states ->\t");
   Serial.print(state1 );
    Serial.print("\t"); // NOTE ::  \t = tab
     Serial.print(state2); 
      Serial.print("\t");  // NOTE ::  \t = tab
       Serial.println(state3); // println adds end of line and new line

}
