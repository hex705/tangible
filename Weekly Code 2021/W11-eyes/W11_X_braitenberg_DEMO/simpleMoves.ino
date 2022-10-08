
void right(){
    //right
  digitalWrite (blue, LOW);    // 0
  digitalWrite (green, HIGH);  // 1
  digitalWrite (red, LOW);     // 0
  digitalWrite (yellow, LOW);  // 1
}


void left() {
    //left
  digitalWrite (blue, LOW);    // 0
  digitalWrite (green, LOW);  // 1
  digitalWrite (red, LOW);     // 0
  digitalWrite (yellow, HIGH);  // 1
    
}// end left


void stop() {
    //stop
    // what does stop code look like ?
  digitalWrite (blue, LOW);    // 0
  digitalWrite (green, LOW);  // 1
  digitalWrite (red, LOW);     // 0
  digitalWrite (yellow, LOW);  // 1
     
} // end stop


void forward(){
  digitalWrite(ledPin, 1);
 // forward -- coppy your forward code to here!
  digitalWrite (blue, LOW);    // 0
  digitalWrite (green, HIGH);  // 1
  digitalWrite (red, LOW);     // 0
  digitalWrite (yellow, HIGH);  // 1
 
} // end forward


void backward() {
    digitalWrite(ledPin, 0);
    // copy your backward code to here
  digitalWrite (blue, HIGH);    // 0
  digitalWrite (green, LOW);  // 1
  digitalWrite (red, HIGH);    // 0
  digitalWrite (yellow, LOW);  // 1
    
} // end backward
