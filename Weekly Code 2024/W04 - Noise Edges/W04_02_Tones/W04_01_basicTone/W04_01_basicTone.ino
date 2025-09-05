// generate a simple tone 


// speaker variables -- // https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
int speakerPin = 12;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(speakerPin, 440, 200); //pin, tone, duration

  delay(1000);

}
