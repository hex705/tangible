// digitalWrite -- with arduino pins connected to
// anode and cathode

int RED = 3;
int GREEN = 6;
int BLUE = 9; // CA = common anode (white)

int LED_ON  = 0;  // use human words for your circuit outcome
int LED_OFF = 1; 

void setup() {

  pinMode( RED,   OUTPUT);
  pinMode( GREEN, OUTPUT);
  pinMode( BLUE,  OUTPUT);

}

void loop() {
  
//  // all off 
//  digitalWrite( RED,   LED_OFF); // high == OFF 
//  digitalWrite( GREEN, LED_OFF); // high == OFF 
//  digitalWrite( BLUE , LED_OFF); // high == OFF 
//  delay(1000);
//
//  digitalWrite( RED,   LED_ON);  // LOW == ON 
//  digitalWrite( GREEN, LED_OFF); // high == OFF 
//  digitalWrite( BLUE , LED_OFF); // high == OFF
//  delay(1000); 
//
//  digitalWrite( GREEN, LED_ON);  // LOW == ON
//  digitalWrite( RED,   LED_OFF); // high == OFF 
//  digitalWrite( BLUE , LED_ON);  // high == OFF  
//  delay(1000); 
//
//  digitalWrite( BLUE,  LED_ON);  // LOW == ON
//  digitalWrite( RED,   LED_OFF); // high == OFF 
//  digitalWrite( GREEN, LED_OFF); // high == OFF   
//  delay(1000); 

  analogWrite( RED,   0      ); // 0-255 0 == bright
  analogWrite( GREEN, 127    ); // 0-255
  analogWrite( BLUE , 255    ); // 0-255 255 == off (dim)  
  delay(1000);
  
  
  
}
