byte sineValues[] = {100,113,125,137,148,159,168,177,184,190,195,198,200,
200,198,195,190,184,177,168,159,148,137,125,113,100,
87,75,63,52,41,32,23,16,10,5,2,0,0,
2,5,10,16,23,32,41,52,63,75,87,100,};


void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 10; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 50; i++ ) {
    writeByte(sineValues[i]);
    //delay(1);
  }
 // writeByte(127);
 // delay(10);
 // writeByte(0);
 // delay(10);
}

void writeByte(byte value) {
  for (int n = 0; n < 8; n++) {
    digitalWrite(n+2, bitRead(value, n));
    
  }
}

