// 4_returnASum

int value1 = 6;
int value2 = 18;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial); // wait for user to open serial monitor. 
}

void loop() {
  
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  
  int sum1 = returnASum(3, 6); 
  
  Serial.print("In loop, sum1 == ");
  Serial.println(sum1);
  Serial.println();

  int sum2 = returnASum(value1, value2);
  Serial.println(fxnSum);
  
  Serial.print("In loop, sum2 == ");
  Serial.println(sum2);
  Serial.println();

  while(1); // hault ( try uncommenting and rerun)
}

int returnASum(int val1, int val2){
  int fxnSum = val1 + val2; 
  Serial.println();
  Serial.println("In function returnASum");
  
  Serial.print("val1 = ");
  Serial.println(val1);
  
  Serial.print("val2 = ");
  Serial.println(val2);
  
  Serial.print("sum to return = ");
  Serial.println(sum);
  Serial.println();
  
  return fxnSum; // return the calculated value. 
}
