// light can be dim -- must be just above robot to work well-ish
// plastic fins need ?tape? to help turn -- the bur catches.
// photcells about 2 cm beyond edge of bot works well.

// motor variables
// digital outs

int blue = 5;
int green = 4;
int red = 9;
int yellow = 8;

int leftSpeedPin =   6;
int rightSpeedPin = 11;

int movementOffset = 70; // blue bot ?? -- 70 ? 
                              //pink bot -- 65 is ok, 70 is  

                            // for green bot, 70 is a little too wandery but 
                            // does sort of interesting things
                            // 65 is almost there 
// variables
int currentLeftSpeed=0;
int currentRightSpeed=0;

// Analog Input Pins
int leftEye = A5;
int rightEye = A4;

int leftEyeValue, rightEyeValue;

int ledPin = 3;
int buttonPin = 2;


void setup() {
  
  // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("W06_X_braitenberg");
    
    //direction controls
    pinMode (blue,   OUTPUT);
    pinMode (green,  OUTPUT);
    pinMode (red,    OUTPUT);
    pinMode (yellow, OUTPUT);

    // speed controls
    pinMode(leftSpeedPin, OUTPUT);
    pinMode(rightSpeedPin, OUTPUT);
    // HCI
    pinMode(buttonPin, INPUT);
    pinMode(ledPin,    OUTPUT);

    pinMode (leftEye,  INPUT);
    pinMode (rightEye, INPUT);

    waitForButtonPress(); //moved to a function (HCI tab)
      
    stop(); // reserved word, we are going to try and override it
}

void loop() {

    leftEyeValue  = analogRead(leftEye )/4 + movementOffset;
    rightEyeValue = analogRead(rightEye)/4 + movementOffset;
    
   // LIMIT THE READING VALUES -- this is a real world hack
  //  if ( leftEyeValue  > 175 ) leftEyeValue  = 255;// interesting in this room
   if ( leftEyeValue  > 155)leftEyeValue  = 255; // this is a hack of sorts
   if ( rightEyeValue > 155) rightEyeValue = 255;  // the limit adjusts for carpet!  175

   //if ( leftEyeValue  <95 )leftEyeValue  = 255; // this is a hack of sorts
//   if ( rightEyeValue > 95) rightEyeValue = 255;
    
   if ( leftEyeValue  <= 71) leftEyeValue  = 0;  // another hack -- environment fix // 70
   if ( rightEyeValue <= 71 ) rightEyeValue = 0;
   
   printEyes();  // serial output for people
     
     
   // less speed when super bright - vehicle 3,4
//         if (( leftEyeValue >= 100) &&  ( leftEyeValue <= 115)){
//              leftEyeValue = 10;
//         }
//         if (( rightEyeValue >= 100) && leftEyeValue <= 115){ // was 160
//               rightEyeValue = 10;
//         }

 
 
   // forward(rightEyeValue, leftEyeValue );    // cross over, aggressive
   forward(leftEyeValue,  rightEyeValue); // straight, run away

  
    
}
