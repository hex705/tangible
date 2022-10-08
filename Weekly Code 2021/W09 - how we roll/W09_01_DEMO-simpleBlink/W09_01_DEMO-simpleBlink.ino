// demo simple blink 

int blue = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(blue, 1);
  delay(1000);

  digitalWrite(blue, 0);
  delay(1000);
  
}
