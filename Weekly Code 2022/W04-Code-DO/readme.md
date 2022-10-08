# tangible code samples
## W04 - digital outputs

### 1-simpleBlink

-- functionally identical to the example file from Arduino -- this code blinks an LED using *delay(x);*

### 2-simpleBlink-serial

-- as above with serial messages.
-- open the serial port to see how loop / on and off relate in time.

### 3-stateBlink

This example blinks the LED ACROSS loops.

A variable is used for the *state* of the LED. This variable is *toggled* each time through loop with the line :
````
STATE = 1 - STATE;
````

### 4-stateBlink-serial

-- as above with serial
-- open the serial port to see how *loop* and *toggle* relate in time.

### 11-stateBlink-RGB-CLASS

-- this example BLINKS an RGB LED, instead of a single color LED.

-- we worked thru this in class.

-- here we use predefined states of *ON* and *OFF* to control channels of the RGB LED.

-- NOTE that to control RGB we need 3 copies of the base code for a single LED (3x of all -- define pins, set pinModes, write to the LEDs)

-- With 3 LEDs there are 8 possible DIGITAL colors.  Can you make them all?


### 13-stateBlink-RGB-serial

-- essentially the same -- moves color states to *ON* and *OFF* globals.

### 20-RGB-RANDOM2-ON-OFF

-- playing with random numbers - extending the above.

-- imagine a number line from 0 to 100.

-- define a boundary (acts as a probability), it divides the line into two parts.

-- randomly pick a number (variable called lottery) between 0-100.  NOTE - lottery is of type LONG - i am pretty sure an INT would have been fine).

-- if lottery is bigger than the boundary set one color, if smaller set the other.

-- moving the boundary changes the likelihood that the color changes.

### 21-RGB-RANDOM3-ON-OFF

-- similiar to above but with 3 line segments and colors.

-- boundaries are fixed at a third -- feel free to move them
