// W04-12-DI-singleButton-RAISING-FALLING 
// GOAL -- detect both edges while reading a button  
// send that state over serial


// button variables
int buttonPin = 4 ;   // pin declare RIGHT button -- where is circuit ?
boolean buttonState =  0 ; // state of button 1=pressed, 0=not

// led variables 
int     LED = 7;   // blue of RGB
boolean LEDState = 0;

// compare variables
boolean IS_PRESSED  = 1; // we want to know when pressed
boolean NOT_PRESSED = 0; 

// speaker variables -- // https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
int speakerPin = 12;
int raisingFrequency = 800;
int fallingFrequency = 400;

// diary variables
boolean lastButtonState = 0;
int counter=0; 

void setup() {
  pinMode(buttonPin, INPUT); // INPUT OR OUTPUT ?
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("setup complete \n\n");
  Serial.println("awaiting button press ...");
}

void loop (){
  // (1) get current reading
  buttonState = digitalRead( buttonPin ); // read button

  // (2) compare -- look for raising edge [ 0 1 ] 
  // if the button IS pressed AND (&&) lastTime was NOT pressed   
  if ((lastButtonState == NOT_PRESSED) && (buttonState == IS_PRESSED)) { 
     
     Serial.print("\n raising edge - toggle led");
     
     LEDState = !LEDState; // toggle the led state 
     Serial.print(" led is " );
     Serial.println(LEDState);

     tone(speakerPin, raisingFrequency);
     
  } 

  // (2) compare -- look for falling edge [ 1 0 ]
  // if button is NOT (!=) pressed AND (&&) lastTime it WAS (==) pressed   
  if ( (lastButtonState == IS_PRESSED) && (buttonState == NOT_PRESSED)) { 
     
     Serial.print(" falling edge");

     counter++; 
     Serial.print(" count ");
     Serial.println(counter);

     tone(speakerPin, fallingFrequency);
    
  } 

  // take action
  digitalWrite(LED, LEDState);
  
  // (3) write in your diary - store this loops reading for later
  lastButtonState = buttonState; // save current reading for next loop
                                 // save      today      for tomorrow

  delay(15); // simple debounce - we will discuss in class
             // added a little time (10mS) to hear tone
  noTone(speakerPin);
}
