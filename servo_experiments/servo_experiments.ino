/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int looper = 0;

void setup() {
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object
  pos = 95;
  myservo.write(pos);
}

void loop() {
  for (looper = pos; looper <= 180; looper++) {
    myservo.write(looper);
    delay(10);
  }
  pos = looper;
  delay(1000);

  
  for (looper = pos; looper >= 95; looper--) {
    myservo.write(looper);
    delay(10);
  }
  pos = looper;
  delay(1000);

}

