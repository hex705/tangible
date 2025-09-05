
 // switch case with a button 
 // // https://docs.arduino.cc/language-reference/en/structure/control-structure/switchCase/


// variables and constant for the switch LABELS
const int ONE = 1;
const int TWO = 2;  // const says TWO will ALWAYS be 2, not needed but you will see it in online examples

// bunch of variables for a button
int buttonPin = 2; // where is it?
int buttonState = 0; // current state PRESSED or NOT
int lastButtonState=0;  // we will edge detect (W04)
int buttonCount = 0; // now many presses?


// some comparators
boolean PRESSED = 1;
boolean NOT_PRESSED = 0;

int STATE = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // check your baud
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // 1) *****   read sensors -- get new data  *****
    buttonState = digitalRead(buttonPin);


  // 2) *****   integrate sensor data if needed   *****
    // find edges -- we will increment count on raising edge
    if ( (buttonState == PRESSED) && (lastButtonState == NOT_PRESSED) ) {
      buttonCount = buttonCount + 1; // buttonCount ++; // would also work
    }

  // 3) *****   determine the CURRENT_STATE   *****
    // in this simple example this is a bit excessive
    // you may/will need to do more work here
    STATE = buttonCount; 

  // debug
  Serial.print("presses = ");
  Serial.print(STATE);
  Serial.print("::\t"); // tab 
  
  // 4) *****   choose behaviour -- display or present STATE   *****
  switch (STATE)  {
            case 0:  // an int
              Serial.println("count is 0");
              // other stuff
              break;
            case ONE:  // ONE is a variable of type int
              Serial.println("count is ONE");
              // other stuff
              break;
            case TWO:  // TWO is a constant (#define creates an int)
              displayStateTwo();  // fxn call
              break;  
            default:  // none of the above
              Serial.print("no match!, count = ");
              Serial.println(STATE); // could use buttonCount
              break;
          } // end switch

            
  // 5) *****   write in diary for edges and thresholds, advance counters etc - W04   *****
  if (buttonCount >= 4) buttonCount = 0;
  lastButtonState = buttonState;

}

void displayStateTwo(){
  // other stuff
  Serial.println("count is TWO (2)");
}
