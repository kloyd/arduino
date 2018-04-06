/*
 * ***** Serial LED Control *****
 * Author: Kelly S. Loyd
 * Date:   March 26 2018
 * 
 * Write a program that allows the user to control the LED connected to pin 13 of the Arduino. 
 * When the program is started, the LED should be off. The user should open the serial monitor 
 * to communicate with the Arduino. If the user sends the character '1' through the serial 
 * monitor then the LED should turn on. If the user sends the character '0' through the 
 * serial monitor then the LED should turn off.
 * 
 */

int LED_OUT = 13;     // use onboard LED pin 13
char inputLine[40];   // a buffer to hold the user input
char command = '0';   // the command typed
int bytesRead = 0;    // for use by Serial.readBytesUntil()

void setup() {
  Serial.begin(9600);
  pinMode(LED_OUT, OUTPUT);
  digitalWrite(LED_OUT, LOW);
  Serial.write("\n\nLED commands\n");
  // Tell the user what input is expected.
  usage();
}

void loop() {
  // wait until there is some data from the serial port.
  if (Serial.available() > 0) {
    bytesRead = Serial.readBytesUntil('\n', inputLine, 40);  // grab maximum of 40 characters.

    // Only process if the user entered exactly one character.
    if (bytesRead == 1) { 
      command = inputLine[0];
      if (command == '0') {
        // got a 0, turn off
        digitalWrite(LED_OUT, LOW);
        Serial.write("Turning LED off.\n");
      } else if (command == '1') {
        // got a 1, turn on.
        digitalWrite(LED_OUT, HIGH);
        Serial.write("Turning LED on.\n");
      } else {
        // bad user data... remind user what to do!
        usage();
      }
    } else {
      // Otherwise, print the Usage message.
      usage();
    }
  }

}

void usage() {
  Serial.write("Usage: Enter 0 for LED off or 1 for LED on.\n");
}


