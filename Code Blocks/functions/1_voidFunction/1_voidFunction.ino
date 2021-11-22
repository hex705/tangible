// 1_basic void function

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial); // wait for user to open serial monitor. 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  basicFunction(); // call void basicFunction
  while(1); // hault ( try uncommenting and rerun)
}

void basicFunction(){
  Serial.println("basic void function");
}
