

const int flashy=8;

int dot_delay = 200;
int dash_delay = 400;
int pause_delay = 100;
int character_delay = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(flashy, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  dot();
  delay(character_delay);
  dash();
  dot();
  delay(character_delay);
  dash();
  delay(character_delay);
  dot();
  dash();
  dot();
  delay(character_delay);
  dot();
  delay(character_delay);
  dot();
  dot();
  dot();
  delay(character_delay);
  dash();
  dash();
  dash();
  delay(character_delay);
  dot();
  dot();
  dot();
  delay(1000);
}

void dot() {
  // pause very brief 
  delay(pause_delay);
  digitalWrite(flashy, HIGH);
  delay(dot_delay);
  digitalWrite(flashy, LOW);
}


void dash() {
  delay(pause_delay);
  digitalWrite(flashy, HIGH);
  delay(dash_delay);
  digitalWrite(flashy, LOW);
}

