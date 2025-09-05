// generate a simple tone -- using a timer instead of delay


// speaker variables -- // https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
int speakerPin = 12;

// timer variables
unsigned long now;
unsigned long interval=1000;
unsigned long startTime;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(__FILE__);
}

void loop() {

  now = millis();

  // timer check
  if ( now-startTime >= interval){
   tone(speakerPin, 440, 200); //pin, tone, duration
   startTime += interval; 
  } 

}
