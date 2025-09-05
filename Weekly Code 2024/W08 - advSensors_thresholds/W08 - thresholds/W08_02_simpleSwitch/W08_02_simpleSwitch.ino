 // basic switch case
 // //https://docs.arduino.cc/language-reference/en/structure/control-structure/switchCase/


// a counting variable -- we will use it in the switch..case
int count = 0;

// constant for the switch LABELS
const int ONE = 1;  // switch labels must be constant - they are not allowed to change
const int TWO = 2;  // const says TWO will ALWAYS be 2, not needed but you will see it in online examples


void setup() {
  // put your setup code here, to run once:
  // no electronics for this one
  Serial.begin(9600); // check your baud
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // 1) *****   read sensors -- get new data  *****
    count = count + 1;

// debug
  Serial.print("count = ");
  Serial.print(count);
  Serial.print("::\t"); // tab 

  // 2) *****   integrate sensor data if needed   *****
    // not required

  // 3) *****   determine the CURRENT_STATE   *****
    // not required
  
  // 4) *****   choose behaviour -- display or present STATE   *****
  switch (count)  {
            case 0:  // an int
              Serial.println("count is 0");
              break;
            case ONE:  // ONE is a variable of type int
              Serial.println("count is ONE");
              break;
            case TWO:  // TWO is a constant (#define creates an int)
              Serial.println("count is TWO");
              break;  
            default:  // none of the above
              Serial.print("no match!, count = ");
              Serial.println(count);
              break;
          } // end switch

            
  // 5) *****   write in diary for edges and thresholds, advance counters etc - W04   *****
  if (count >= 4) { 
    count = -1;  // try -1 and 0
    Serial.println(); // aesthetics - put one space between the loops
  }

  delay(1000); // so we can this happen 

}
