// W03_03b_variations
// GOAL -- control LED with a button 
// print reading to serial monitor

// tw ostrategies are included.  the first uses if..else

// upload <start simulation>, open serial monitor,
// press left button -- look for 0,1 in monitor

// button variables
int buttonPin =  2 ;   // pin declare -- where is circuit ?
boolean buttonState =  0 ; // state of button 1=pressed, 0=not

// led varaiables
int ledPin = 5;
int ledState;

void setup() {
  pinMode(buttonPin,  INPUT ); // INPUT OR OUTPUT ?
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop () {
  // listen :: read sensors
  buttonState = digitalRead( buttonPin ); // read button


// *****  strategy 1 ********
  // take action and provide feedback

  // if ( buttonState == 1){
  //   digitalWrite(ledPin, 1);
  // } else {
  //   digitalWrite(ledPin, 0);
  // }

// *****  strategy 2 ********
  // less flexible but effective - directly map button to LED
  // comment out strategy 1 THEN uncomment next line to test/use
   digitalWrite(ledPin, buttonState);


  // feedback to screen
  Serial.print ( "button = " );
  Serial.println(buttonState);   // print button state     

  delay(50); // just slow it down a little
}
