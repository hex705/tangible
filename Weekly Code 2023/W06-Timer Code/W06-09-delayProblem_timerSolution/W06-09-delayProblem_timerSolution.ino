// W06-09-delayProblem_timerSolution
// open serial PLOTTER once code is uploaded

// need button circuit on pin 2, led on pin 11
int buttonPin = 2;
int buttonState = 0;

// led variables
int ledPin = 11;
int ledState = 0;

// timer variables
unsigned long timeNow = 0;
unsigned long ledBlink_Interval = 250;
unsigned long ledBlink_Start = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // next line is for testing only - NOT in production
  while (!Serial); // have to open the serial MONITOR or PLOTTER to get past this line 
  pinMode(buttonPin, INPUT);
  pinMode(ledPin,    OUTPUT);
}

void loop() {

  // open PLOTTER to see what is happening

  // read the button
  buttonState = digitalRead( buttonPin );
  Serial.print ("button = ");
  Serial.print ( buttonState );
  Serial.print ('\t');


  //***** delay solution *****
    ledState = 1 - ledState;         // toggle LED
    digitalWrite(ledPin, ledState);  // write to LED
    printLEDState();                 // print out LED state
  
    delay(1000);                     // delay 1 second for blink
  // ***** delay solution *****


//    // ***** timer solution *****
    //   timeNow = millis();
   
    //   // NOTE::  timeNow - ledBlink_Start == elapsed time
    //   if ( timeNow - ledBlink_Start  > ledBlink_Interval ) {
    //      ledState = 1 - ledState;             // toggle LED
    //      ledBlink_Start += ledBlink_Interval; // reset timer
    //   }
   
    //  digitalWrite(ledPin, ledState); // write to LED
    //  printLEDState();                // print out LED state
//    // ***** end timer solution *****
  
  Serial.println();
}



void printLEDState() {
  //int shift = 0; // move the LED above the botton on display
  // output the state to monitor
  if (ledState == 1) {
    Serial.print("LED HIGH\t");
    //Serial.print(1 + shift);
  } else {
    Serial.print("LED LOW\t");
    //Serial.print(0 + shift);
  }
}
