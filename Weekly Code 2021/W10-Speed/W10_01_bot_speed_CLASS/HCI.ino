void HCI_waitForButtonPress(){

 do{
      
      // what does this block do ?
        digitalWrite(ledPin, 1);
        delay(50);
        digitalWrite(ledPin, 0);
        delay(50);
      //
     } while( digitalRead( buttonPin ) == 0 ); // while NOT pressed, DO (loop)

   digitalWrite(ledPin, 1);  // turn LED on and leave it
  
   
}
