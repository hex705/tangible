
// see also
// https://docs.arduino.cc/built-in-examples/control-structures/SwitchCase/
// https://forum.arduino.cc/t/demonstration-code-for-several-things-at-the-same-time/217158


// includes for libraries


// all the variables you need
// just keep adding them as you add to your code


// state variables
int CURRENT_STATE = 0;  // W02 - today
const int STATE1 = 1; // name it based on your wheel spin
int STATE2 = 2;

float sensorIsAFloat = 0.0; // W07
boolean ON = 1; // W02



void setup() {
  // put your setup code here, to run once:


    // *****  pinModes -- set up circuits   --> W02 - today

    // *****  initialize sensors as needed  --> sensor dependant, W07, W08

    // *****  attach servos if used --> W07


}

void loop() {
  // put your main code here, to run repeatedly:

  // now = millis(); // for timers if used  --> W03

  // 1) *****   read sensors -- get new data  *****
    
        // can be done directly here 
        //   or
        // with function calls

        // buttons (W03), photocells and pots (W06), accellerometer (W07), sonar (W08) 
    

  // 2) *****   integrate sensor data   *****
    
        // -- filtering  / simple averaging --> W08
        // -- edge detect -- W04
        // -- threshold   -- W08
        // -- mapping  -- W07, Artifact_09

        // limit sensor output as needed
            // if (sensor >= 255)  sensor = 255;
            // if (sensor <= 0) sensor = 0;    

  
  // 3) *****   determine the CURRENT_STATE   *****
   
  //  for react you need to decide when to change between states  
  //  probably one or many if statements ... W03,W04 others

    // ******   STATE1 to STATE2 -- based on sensors -- its a reaction   *****

      // // this could be edge (W04) or threshold (W08) or simple if W03, W04)
          // if ( sensor above threshold ) {
          //   CURRENT_STATE = STATE2;  // set curent to activated state
          //   // timerStart == now;    // if you want to stay in 


    // ******   STATE2 back to STATE1 -- could be a timer or more sensors   *****

      // ****** if more senors -- this is basic -- could be much more

      // this could be edge (W04) or threshold (W08) or simple if (W04)
          // if (CURRENT_STATE == STATE2) && (sensor belowThreshold) {
          //     CURRENT_STATE = STATE1;  // back to beginning
          // }

      // // or

      // ****** if timer driven   *****

          // if (CURRENT_STATE == STATE2) {
          //   //if timer expires - it started in line 43 -- when change to STATE2 was triggered
          //   if (now- start > interval) { 
          //     CURRENT_STATE = STATE1;
          //     // last step of timer, moving startTime forward is usually here -- but we put it in line 43 above
          //   }
          // } 

  // 4) *****   choose behaviour -- display or present STATE   *****
   // // https://docs.arduino.cc/built-in-examples/control-structures/SwitchCase/
   // // https://docs.arduino.cc/language-reference/en/structure/control-structure/switchCase/
    
    switch ( CURRENT_STATE ) { // W08

      case STATE1:  // use better name for STATE1

          // actions for STATE1
          // -- set leds     -- W02
          // -- play a sound -- W04
          // -- move servos  -- W07
          // -- etc

          // myServo.write(90);  // (W07) what would servo do ? 
          // digitalWrite(myLed, 1);   // (W03)

          // if (muteButtonState == notPressed) tone(speakerPin, note); // W04
        
      break;

      case STATE2: // use better name for STATE2
          // analogWrite(otherLed, 100); // W05
          // actions for STATE1
          // -- set leds     -- W02
          // -- play a sound -- W04
          // -- move servos  -- W08
          // -- etc
        
      break;

      case label3:
          // statements
          break;

      case label4: {
          // ADVANCED - if you declare a variable inside a case 
          // you need to wrap that case block in { }
          break;
      }

      default:
          // statements
      break;
    } // end of switch .. case



  `

// custom functions down here
// could put them in a tab .... 
