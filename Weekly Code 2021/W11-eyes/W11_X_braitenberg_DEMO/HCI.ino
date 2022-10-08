void waitForButtonPress(){

    do {
        digitalWrite( ledPin, 1);
        delay(40);
        digitalWrite( ledPin, 0);
        delay(40);
    } while ( digitalRead (buttonPin) == 0  ); 

}
