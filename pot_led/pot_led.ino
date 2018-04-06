/* Control the brightness of an LED with potentiometer */

int sensorPin = A0;
int ledPin = 3; 
int potValue = 0;
int ledValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  potValue = analogRead(sensorPin);
  //Serial.println(potValue);
  ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, ledValue);
  delay(10);
}
