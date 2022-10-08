// RGB with functions
// steve daniels -- tangible, Oct 2020

// accompanying video
// https://tangiblemedia.ca/code-blocks/functions/

 
// this demo based in part on 
// https://www.youtube.com/watch?v=5Qi93MjlqzE&t=256s 

// variables for pins (they are social distancing) 
// note -- these pins have the tilde ~
// i am using 1K resistors on each led

int rPin = 3;
int gPin = 5;
int bPin = 6;

// preset colors - 3 int array
int YELLOW [ ] = {200,127,0}; // yellow

void setup() {
  // put your setup code here, to run once:
  pinMode (rPin, OUTPUT);
  pinMode (gPin, OUTPUT);
  pinMode (bPin, OUTPUT);
}

void loop() {
  
  setRGB ( 75 , 200, 100 ) ;  // sort of cyan /  lime-y
  delay (1000);
  
  setRGB ( 200, 0, 175) ;    // sort of PINK 
  delay (1000);

  setRGB ( YELLOW );
  delay(1000); 

}

void setRGB ( int theColor [ ] ) {
  setRGB ( theColor[0], theColor[1], theColor[2] ) ; 
} // end setRGB -- array 


void setRGB ( int rAmount, int gAmount, int bAmount ) {
  analogWrite( rPin, rAmount);
  analogWrite( gPin, gAmount);
  analogWrite( bPin, bAmount); 
} // end setRGB - int
