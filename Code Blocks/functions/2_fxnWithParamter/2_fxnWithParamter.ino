// 2_void function with parameter

int theNumber = 6;   // change the number and rerun

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial); // wait for user to open serial monitor. 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  printAnInt(theNumber); 
  printAnInt(9);
  // printAnInt(); // will cause error because printAnInt needs you to send an int
  while(1); // hault ( try uncommenting and rerun)
}

void printAnInt( int integerToPrint ){ // theIntegerToPrint
  Serial.print("In printAnInt(int). \nThe integer to print is :: ");
  Serial.println(integerToPrint);
}
