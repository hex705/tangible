// simple LED blink with serial messages
// state changes happen WITHIN each loop 
// serial is used to display messages in the *SERIAL MONITOR*


/* pattern



*/


// led PINs
int ledPin = 5;

// led states
boolean ON = 1;
boolean OFF = 0;

// led STATE
boolean STATE = OFF; // 0

void setup() {
  // put your setup code here, to run once:

  // set pinModes
  pinMode(ledPin, OUTPUT);

  // start serial
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  Serial.println("loop");

  
  // set led STATE variable to ON == 1 == HIGH => 5V 
  STATE = ON;

  // write led STATE
  digitalWrite(ledPin, STATE);// ON 

  // print led state 
  Serial.print("    LED ");
  Serial.println(STATE); // with print 0 = OFF, 1 = ON

  // wait 1 second
  delay(1000);


  // set led STATE variable to OFF == 0 == LOW == GND;
  STATE = OFF;

  // write led STATE
  digitalWrite(ledPin, STATE);// OFF 

  // print led state
  Serial.print("    LED ");

  Serial.println(STATE); // with print 0 = OFF, 1 = ON
  // wait 1 second
  delay(1000);
}


