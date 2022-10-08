// W10_04_botBase_1

const int green  = 4 ; // where is the circuit ?
const int blue   = 5 ; // where is the circuit?
const int yellow = 8 ; // where is the circuit?
const int red    = 9 ;

int buttonPin =   2 ;  // circuits are where?
int ledPin    =   3 ;

void setup() {
  // put your setup code here, to run once:
  pinMode ( green,  OUTPUT );   // output because we are sending a signal out
  pinMode ( blue,   OUTPUT );   // output because we are sending a signal out
  pinMode ( red,    OUTPUT );   // output because we are sending a signal out
  pinMode ( yellow, OUTPUT );   // output because we are sending a signal out

  pinMode(buttonPin, INPUT  );
  pinMode(ledPin,    OUTPUT );

  // comment out line below if you don't have button setup on pin 2
  waitForButtonPress(); // in HCI tab

}

void loop() {

  forward();
  delay(2000);

  backward();
  delay(2000);

  //  stop();
  //  delay(1000);

}
