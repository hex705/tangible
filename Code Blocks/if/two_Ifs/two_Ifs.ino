// if ... else exploration
// steve daniels
// tangible, Oct 2020

// button pressed = red
// button released = cyan
// all leds have 1k resistors

// led variables
int rPin = 3;
int gPin = 6;
int bPin = 9;

// button variables
int buttonPin = 2;
int buttonState = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode ( rPin, OUTPUT );
  pinMode ( gPin, OUTPUT );
  pinMode ( bPin, OUTPUT );

  pinMode (buttonPin, INPUT );
}

void loop() {

  buttonState = digitalRead ( buttonPin );

  if ( buttonState == 1 ) {
    digitalWrite ( rPin , 1 ); // red on 
    digitalWrite ( gPin, 0  );
    digitalWrite ( bPin, 0  );
  } 

  if (buttonState == 0 ) {
    digitalWrite ( rPin, 0   ); // red off
    analogWrite  ( gPin, 127 );  // half on  range = 0- 255
    analogWrite  ( bPin, 127 ); // half on blue
  } // end if 
 

} // end loop 
