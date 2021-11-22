// 0_baseCode

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial); // wait for user to open serial monitor. 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  while(1); // halut ( try uncommenting and rerun)
}
