//  W05:: Motion
// 'FADE' a transistor -- accelerate a motor

int TIP_PIN = 3;

int ACCELERATION = 2; // how fast to accelerate -- try different values
int FASTEST = 255;    // limit of analogWrite
int START_SPEED = 25; // every motor needs some power to turn on
                      // below this level no motion

void setup() {
  // put your setup code here, to run once:
  pinMode(TIP_PIN, OUTPUT);
}

void loop() {
  
  // accellerate -- for loop counts up
  for (int motorSpeed = START_SPEED; motorSpeed<= FASTEST; motorSpeed+=ACCELERATION ) {
    analogWrite( TIP_PIN , motorSpeed ); // pin, state 
    delay(100);  // acceleration can be adjusted here too 
  }


  // slow down
  // compare for loop structure -- this one counts down
  for (int motorSpeed = FASTEST; motorSpeed >= START_SPEED; motorSpeed-=ACCELERATION ) {
    analogWrite( TIP_PIN , motorSpeed ); // pin, state 
    delay(100);  // acceleration can be adjusted here too 
  }

  
}
