// Blinky
/*
Write a program that causes the built-in LED connected to pin 13 on the Arduino to blink, 
alternating between fast blinks and slow blinks. The LED should blink 5 times, 
once every half second, and then it should blink 5 more times, once every two seconds. 
The LED should continue to blink in this alternating fashion for as long as the Arduino receives power.
*/


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // blink fast 5 times.
  for (int i = 0; i < 5; i++) {
    // On for 1/2 second.
    digitalWrite(13, HIGH);   
    delay(250);    
    // off for 1/2 second.
    digitalWrite(13, LOW);   
    delay(250);
  }

  // blink slow 5 times.
  for (int i = 0; i < 5; i++) {
    // On for 2 seconds.
    digitalWrite(13, HIGH);
    delay(1000);  
    // Off for 2 seconds.
    digitalWrite(13, LOW);  
    delay(1000); 
  }
                      
}
