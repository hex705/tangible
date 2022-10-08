// W11_11
// simple timer 

unsigned long eventInterval = 1000;
unsigned long startTime = 0;
unsigned long currentTime = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  // get the current time and store it in a variable 
   currentTime = millis();

   Serial.println( currentTime );
   
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
