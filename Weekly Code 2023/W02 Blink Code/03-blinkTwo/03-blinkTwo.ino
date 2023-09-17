// blink 2 LEDs using a STATE variable for EACH LED.
// the state variable help us keep track of the different LEDs
// led STATEs change WITHIN loops in sync with each other
// ASYMMETRIC ON / OFF - alternating LEDs 


// led PINs
int ledPin_1= 5;
int ledPin_2= 6;

// possible led states
boolean ON = 1;
boolean OFF = 0;

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);

  // start serial
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // -----------   Pattern 1   ------------------
  
  // ***********   write the LEDs
  digitalWrite(ledPin_1, ON);  // ON  = 1 
  digitalWrite(ledPin_2, OFF);  // OFF = 0

     // print led state 
     Serial.println("  LEDs-> ON , OFF");
      
  // *********** delay - determines how long we see pattern 1
  delay ( 1000 ); 


  // -----------   Pattern 2  ------------------

  // ***********   write the LEDs
  digitalWrite(ledPin_1, OFF);  // OFF = 0
  digitalWrite(ledPin_2, ON);  // ON  = 1
  
      // print led state 
      Serial.println("  LEDs-> OFF, ON");

  // ***********  delay - determines how long we see pattern 2
  delay ( 1000 ); 

  // ***********   increment loop counter
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 

}
