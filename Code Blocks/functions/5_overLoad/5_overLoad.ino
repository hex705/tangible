// 5_overload a function

int mySpeed = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial); // wait for user to open serial monitor. 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  setSpeed(100, 230);
  setSpeed(mySpeed);
  while(1); // hault ( try uncommenting and rerun)
}

void setSpeed(int theSpeed){
  Serial.print("In setSpeed, single parameter -- (int theSpeed)\nPassing ");
  Serial.print(theSpeed);
  Serial.print(" to both motors via "); 
  Serial.println("setSpeed, two parameters.\n");
  Serial.println(); 
  
  setSpeed(theSpeed, theSpeed);
}

void setSpeed(int leftSpeed, int rightSpeed){
  Serial.println("In setSpeed with two parameters -- (int leftSpeed, int rightSpeed)");
  
  Serial.print("Setting left speed to :: ");
  Serial.println(leftSpeed);

  Serial.print("Setting right speed to :: ");
  Serial.println(rightSpeed);
  Serial.println();
  Serial.println();

}
