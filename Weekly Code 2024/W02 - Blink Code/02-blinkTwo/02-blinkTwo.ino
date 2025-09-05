// blink 2 LEDs 
// Pattern 1 - uses the boolean variables On, OFF that we define
// Pattern 2 - uses more typical 1 = ON and 0 = OFF syntax

// led PINs - where are the circuits? 
int ledPin_1= 5;
int ledPin_2= 6;

// possible LED states
boolean ON = 1;
boolean OFF = 0;


void setup() {
  // put your setup code here, to run once:
  // set pinModes
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
}

void loop() {

  // -----------   Pattern 1   ------------------
  
  // ***********   write the LEDs
  digitalWrite(ledPin_1, ON);   // ON  = 1 
  digitalWrite(ledPin_2, OFF);  // OFF = 0

  // *********** delay - determines how long we see pattern 1
  delay ( 1000 ); 


  // -----------   Pattern 2  ------------------

  // ***********   write the LEDs
  digitalWrite(ledPin_1, 0);  // OFF = 0
  digitalWrite(ledPin_2, 1);   // ON  = 1

  // ***********  delay - determines how long we see pattern 2
  delay ( 1000 ); 

}
