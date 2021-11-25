// W11_11 delayProblem_timerSolution
// open serial monitor once code is uploaded

// need button circuit on pin 2, led on pin 3
int buttonPin = 2;
int buttonState = 0;

int ledPin = 3;
int ledState = 0;

unsigned long timeNow = 0;
unsigned long ledBlink_Interval = 1000;
unsigned long ledBlink_Start = 0;
unsigned long ledBlink_End = ledBlink_Interval;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial); 
  pinMode(buttonPin, INPUT);
  pinMode(ledPin,    OUTPUT);
}

void loop() {

  buttonState = digitalRead( buttonPin );
  Serial.print ( buttonState );
  Serial.print ('\t');

  // ***** delay solution *****
  ledState = 1 - ledState;         // toggle LED
  digitalWrite(ledPin, ledState);  // write to LED
  printLEDState();                 // print out LED state

  delay(1000);                     // delay 1 second for blink 

//   // ***** timer solution *****
//   timeNow = millis();
//  
//   if ( timeNow > ledBlink_End ) {
//    
//      // same as above
//      ledState = 1 - ledState;        // toggle LED
//      digitalWrite(ledPin, ledState); // write to LED
//      printLEDState();              // print out LED state
//      
//      ledBlink_End   += ledBlink_Interval;
//   }

   //printLEDState(); // for plotter, if used comment out fxn call in timer
   Serial.println();
}



void printLEDState(){
     int shift = 3; // move the LED above the botton on display
    // output the state to monitor
    if (ledState == 1) {
      //Serial.print("\tLED HIGH\t");
      Serial.print(1+shift);
    } else {
      //Serial.print("\tLED LOW\t");
      Serial.print(0+shift);
    }
}
