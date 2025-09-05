// blink 3 LEDs 
// Pattern 1 - uses the boolean variables On, OFF that we define
// Pattern 2 - uses more typical 1 = ON and 0 = OFF syntax

// led PINs
int ledPin_1= 5;
int ledPin_2= 6;
int ledPin_3= 7;

// possible LED states
boolean ON = 1;
boolean OFF = 0;

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // -----------   Pattern 1   ------------------

      // ***********   write the LEDs  *****************
      digitalWrite(ledPin_1, ON);
      digitalWrite(ledPin_2, OFF);
      digitalWrite(ledPin_3, OFF);

      // ***********   determine the delay - they blink at same time   *****************
      delay(1000);


  // -----------   Pattern 2   ------------------
  
      // ***********   write the LEDs  *****************
      digitalWrite(ledPin_1, OFF);
      digitalWrite(ledPin_2, 1); // use 1 = ON
      digitalWrite(ledPin_3, OFF);

      // ***********   determine the delay - they blink at same time   *****************
      delay(1000);

  // -----------   Pattern 3   ------------------

      // ***********   write the LEDs  *****************

      digitalWrite(ledPin_1, 0); // 0==OFF
      digitalWrite(ledPin_2, 0);
      digitalWrite(ledPin_3, 1); // 1==ON

      // ***********   determine the delay - they blink at same time   *****************
      delay(1000);

}
