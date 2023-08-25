// simple LED blink 
// state changes happen within each loop 

/* pattern

        LOOP-1            LOOP-1          LOOP-2            LOOP-2         
   
LED_1     ON              ON             ON                OFF
duration  1000
Led_1     OFF             OFF
duration  1000 
*/

// led PINs
int ledPin = 5;

// led states
boolean ON = 1;
boolean OFF = 0;


void setup() {
  // put your setup code here, to run once:
  
  // set pinModes
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // write ledPin to ON ( HIGH, 1, 5V);
  digitalWrite(ledPin, ON);// ON == 1 == HIGH ==> 5V 
  // wait 1 second
  delay(1000);
  
  // write ledPin to OFF (LOW, 0, GND);
  digitalWrite(ledPin, OFF);// OFF == 0 == LOW ==> 0V(GND) 
  // wait 1 second
  delay(1000);
}
