// W04_11-DI-singleButton-EDGE - only capture first press
//
// GOAL -- read only FIRST presses -- ignore button held down.
// send that state over serial

// button variables
int buttonPin =  4 ;   // pin declare -- where is circuit ?
boolean currentButtonState =  0 ; // state of button 1=pressed, 0=not

// led variables 
int rLED = 5;
boolean rLEDState = 0;

// compare variables
boolean IS_PRESSED = 1; 
boolean NOT_PRESSED = 0;

// diary variables   ===========    new !
boolean lastButtonState = 0;


void setup() {
  pinMode(buttonPin, INPUT); // INPUT OR OUTPUT ?
  pinMode(rLED, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("setup complete \n\n");
  Serial.println("awaiting button press ...");
}

void loop (){
  // (1) get current reading
  currentButtonState = digitalRead( buttonPin ); // read button

  // (2) compare -- look for RAISING edge [0 1]
  // if the button IS pressed AND (&&) lastTime was NOT pressed   
  if ((lastButtonState == NOT_PRESSED) && (currentButtonState == IS_PRESSED)) { 
     Serial.println("raising edge - toggle led");
     
     rLEDState = !rLEDState; // toggle the led state  
     Serial.print("led is " );
     Serial.println(rLEDState);
  } 
 
  digitalWrite(rLED, rLEDState);

  // (3) Dear Diary .. store this loop's reading for later
  lastButtonState = currentButtonState; // save this reading for next loop

  delay(5); // simple debounce 
}
