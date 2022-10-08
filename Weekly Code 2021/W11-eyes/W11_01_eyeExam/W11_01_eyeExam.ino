
// bot Eye Exam 
// use a flash light to see if they dialate 
// (or at least throw bigger values)

int leftEye = A5  ; // pin -- note the A prefix! 
int rightEye= A4  ; // pin
int leftEyeValue, rightEyeValue; 

void setup() {
  
  // pinmodes for eyes (technically not needed on analog input, but good habit)
  pinMode(leftEye,  INPUT );
  pinMode(rightEye, INPUT );
  
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  // what is the number range of analog INPUT?
  leftEyeValue  = analogRead(leftEye);
  rightEyeValue = analogRead(rightEye);

  Serial.print( leftEyeValue );
  Serial.print( "\t" ); // a tab
  Serial.println( rightEyeValue );
  
}
