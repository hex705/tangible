// W04-03-DI-DO-button to LED 

// map button presses to LED with IF statement

int buttonPin_1 =   10 ; // pin declare -- where is circuit ?
int buttonState_1 =  0 ; // state of button 1=pressed, 0=not

int ledPin_1 = 5;

void setup() {
  
  pinMode(buttonPin_1,  INPUT ); // INPUT OR OUTPUT ?
  pinMode(ledPin_1, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop () {
  
  buttonState_1 = digitalRead( buttonPin_1  ); // read button
  
  if ( buttonState_1 == 1 ) {  
     // do stuff when true == if pressed do stuff 
     digitalWrite( ledPin_1, 1 );   
  } else {
     digitalWrite( ledPin_1, 0 );  
  }
  

  Serial.println(buttonState_1);   // print button state
}
