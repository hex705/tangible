// W09_06_in_out

// lets use words to connect a BUTTON to an LED

// INPUTs let us receive signals from the physical world
// and USE them in our media based projects

// create a variable to hold the arduino PINs we connected to

int buttonPin =   2  ; // where is the circuit?
int ledPin    =   3  ; // where is the circuit?

//  create a variable to hold the STATE of the input.
//  this one is digital so it can ONLY be a 0 or 1 (LOW or HIGH)

int STATE; // name of variable.

void setup() {
  // put your setup code here, to run once:
  // set your pinModes
  pinMode ( buttonPin, INPUT   );  // set this
  pinMode ( ledPin,    OUTPUT  );
  
  // Lets set up a Serial connection so we can see what the Arduino sees
 Serial.begin(9600);
  // Lets include a startup message
 Serial.println(__FILE__); // note __FILE__ is a built in thing -- no quotes.
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //  we want to know the state of our DIGTAL INPUT
  //  so we need to execute a digitaRead
 
  //  store the result in the STATE variable you CREATED
  //  at top of your code

  STATE = digitalRead( buttonPin );
   
  // OUTPUT, write the state to your LED
  digitalWrite (  ledPin    ,   STATE     ); // (whichPin, value)

  //  use Serial to print out the STATE of the circuit. 
  Serial.println( STATE );

  delay(100);
}
