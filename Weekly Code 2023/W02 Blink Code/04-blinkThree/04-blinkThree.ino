// blink 3 LEDs in three (3) different patterns
// led STATEs changes WITHIN loops

// led PINs
int ledPin_1= 5;
int ledPin_2= 6;
int ledPin_3= 7;

// possible LED states
boolean ON = 1;
boolean OFF = 0;

// utility variables 
int loopCounter = 0; 

void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("loop ");
  Serial.println(loopCounter);

  // -----------   Pattern 1   ------------------

  // ***********   write the LEDs  *****************
  Serial.print("   Pattern 1\t");
  digitalWrite(ledPin_1, ON);
  digitalWrite(ledPin_2, OFF);
  digitalWrite(ledPin_3, OFF);
 
  // ***********   print LED states side by side  *****************    
  Serial.println("  LEDs-> ON,  OFF, OFF ");
   
  // ***********   determine the delay - they blink at same time   *****************
  delay(1000);


  // -----------   Pattern 2   ------------------
  
  // ***********   write the LEDs  *****************
  Serial.print("   Pattern 2\t");
  digitalWrite(ledPin_1, OFF);
  digitalWrite(ledPin_2, ON);
  digitalWrite(ledPin_3, OFF);
 
  // ***********   print LED states side by side  *****************    
  Serial.println("  LEDs-> OFF, ON,  OFF ");

  // ***********   determine the delay - they blink at same time   *****************
  delay(1000);


  // -----------   Pattern 3   ------------------

  // ***********   write the LEDs  *****************
  Serial.print("   Pattern 3\t");
  digitalWrite(ledPin_1, OFF);
  digitalWrite(ledPin_2, OFF);
  digitalWrite(ledPin_3, ON);
 
  // ***********   print LED states side by side  *****************    
  Serial.println("  LEDs-> OFF, OFF, ON ");
  
  // ***********   determine the delay - they blink at same time   *****************
  delay(1000);

  // ***********   increment loop counter    *****************
  // loopCounter is just a way to clearly see how the code is flowing
  // you don't *NEED* it in your programs
  loopCounter++; 
}
