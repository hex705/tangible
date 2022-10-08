
// W05:: Motion
// 'BLink' a transistor -- turning motors ON and OFF

int TIP_PIN = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(TIP_PIN, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TIP_PIN, 1);
  delay(1000);
  digitalWrite(TIP_PIN, 0);
  delay(1000); 
}
