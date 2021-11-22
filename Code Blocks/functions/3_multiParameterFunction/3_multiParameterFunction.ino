// 3_multiParameterFunction

int myInt = 6;
float myFloat = 5.4;
String myString = "Birds are feathered"; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial); // wait for user to open serial monitor. 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  printThemAll(3,7.8,"It works!");
  printThemAll(myInt, myFloat, myString); // call void basicFunction
  while(1); // hault ( try uncommenting and rerun)
}

void printThemAll(int incomingInt, float incomingFloat, String incomingString){
  Serial.println("In function printThemAll");
  Serial.println(incomingInt);
  Serial.println(incomingFloat);
  Serial.println(incomingString);
  Serial.println();
}
