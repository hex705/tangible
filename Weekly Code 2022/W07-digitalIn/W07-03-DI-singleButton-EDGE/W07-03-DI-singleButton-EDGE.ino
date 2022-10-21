// W07-03-DI- EDGE - only capture first press
//
// GOAL -- read only FIRST presses -- ignore button held down.
// send that state over serial

// button variables
int buttonPin =  4 ;   // pin declare -- where is circuit ?
boolean currentButtonState =  0 ; // state of button 1=pressed, 0=not

// led variables 
int rLED = 11;
boolean rLEDState = 0;

// compare variables
boolean IS_PRESSED = 1; 
boolean NOT_PRESSED = 0;

// diary variables
boolean lastButtonState = 0;


void setup() {
  pinMode(buttonPin, INPUT); // INPUT OR OUTPUT ?
  pinMode(rLED, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("setup complete \n\n");
  Serial.println("awaiting button press ...");
}

void loop (){
  
  currentButtonState = digitalRead( buttonPin ); // read button

  // raising edge
  // if the button IS pressed AND (&&) lastTime was NOT pressed   
  if ((currentButtonState == IS_PRESSED) && (lastButtonState == NOT_PRESSED)) { 
     
     Serial.println("raising edge - toggle led");
     
     rLEDState = !rLEDState; // toggle the led state  
     Serial.print("led is " );
     Serial.println(rLEDState);

  } 

 
  digitalWrite(rLED, rLEDState);

  lastButtonState = currentButtonState; // save this reading for next loop

  delay(5); // simple debounce - we will discuss in class. 
}
