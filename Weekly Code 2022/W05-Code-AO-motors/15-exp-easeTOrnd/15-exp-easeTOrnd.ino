// LED chases random brightness
// an example of easing with hardware -- it could be greatly refined
// brightness in this example changes in a way that is not linear

// its ok if this does not make sense -- its just an experiment. 

// here is a software example https://processing.org/examples/easing.html
// most of you covered this in a difference context in comp arts

// led PINs
int rPin = 3;

// led Brightness states
float rBrightness;

// targets
int rTarget;

// easings 
float rEasing = 0.01;

void setup() {
  // put your setup code here, to run once:

  // set pinModes
  pinMode(rPin, OUTPUT);

  // start serial
  Serial.begin(9600);
  
  rTarget = random(0,30);  // seed

}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.println("loop");
  
  float rDx = rTarget-rBrightness;
  rBrightness += rDx * rEasing;

  int ledValue = (int) rBrightness;
  
  // write to LEDS
  analogWrite( rPin, ledValue);
  
  // plot whats happening 
  // plotter colors -- target is blue -- current brightness is red. 
  Serial.print(rTarget);
  Serial.print('\t'); //tab between values - for plotter and columns
  Serial.print(rBrightness);
  Serial.print('\t'); 
     Serial.print(ledValue);
  Serial.println();  // only one println

    rTarget = random(0,30);
  }
  delay(10);
}
