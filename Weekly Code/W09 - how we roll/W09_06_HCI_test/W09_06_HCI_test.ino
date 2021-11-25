// W09_07_HCI_test
// button and LED only, no motors

int buttonPin =   2 ;  // circuits are where?
int ledPin    =   3 ;

void setup() {
  // put your setup code here, to run once:
    pinMode(buttonPin, INPUT  );  // directions?
    pinMode(ledPin,    OUTPUT );

     do{
      // what does this block do ?
        digitalWrite(ledPin, 1);
        delay(50);
        digitalWrite(ledPin, 0);
        delay(50);
      //
     } while( digitalRead( buttonPin ) == 0 ); // while NOT pressed, DO (loop)
}

void loop() {
  digitalWrite(ledPin, 1);  // turn LED on and leave it
}
