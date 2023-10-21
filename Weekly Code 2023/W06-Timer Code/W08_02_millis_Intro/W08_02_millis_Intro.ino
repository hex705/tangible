// W08_02_millis_Intro
// millis intro - simple timer 

// timer variables 
unsigned long eventInterval = 1000; // try shorter and longer intervals
unsigned long startTime = 0;
unsigned long currentTime = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  
  // get the current time and store it in a variable 
  currentTime = millis();

  // debug that variable 
  Serial.println( currentTime );

  // run with block below commented an uncommented    
    //   if ( currentTime - startTime  >= eventInterval ) { // eventInterval = 1000
    //       Serial.print("\t time for an event :: ");  
    //       Serial.println(currentTime);
    //       startTime += eventInterval;
    //   } // end if 
       
}


void printTimes(){
        Serial.print( currentTime );
        Serial.print("\t");
        Serial.print( startTime );
        Serial.print("\t");
        Serial.print(currentTime-startTime); 
        Serial.print("\t");
        Serial.print(eventInterval);    
        Serial.println();
}
