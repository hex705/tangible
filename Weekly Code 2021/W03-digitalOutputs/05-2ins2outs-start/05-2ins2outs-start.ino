//05-2in2outs

// stretch goal -- can we get 2 ins and outs?

int buttonPin_1 = 11;
int buttonState_1 = 0;
int ledPin = 5; // add an LED pin definition here

// duplicate the declarations - add second button and led
// create state var for second button


void setup() {
  pinMode(buttonPin_1, INPUT);
  pinMode(ledPin, OUTPUT);

  // add pinModes for new button and led

  Serial.begin(9600);
}

// next page -- continues!


void loop() {
  buttonState_1 = digitalRead(buttonPin_1);
  Serial.println(buttonState_1);

  // duplicate above -- read new button, store it, print it


  // extend if..then below to include 2 buttons

  /*
    https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/
    https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalor/
    https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/
  */
  
  /* if (condition1) && (condition2) {
      // do something when true
      } else {
      // do something when false
      }
  */


  if (buttonState_1 == 1) {
    digitalWrite(ledPin, 1);
  } else {
    digitalWrite(ledPin, 0);
  }
  
}
