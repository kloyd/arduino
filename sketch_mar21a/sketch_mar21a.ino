void setup() {
  // put your setup code here, to run once:
pinMode (13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int x, y;

for(x=0;x<5;x++){
digitalWrite(13,HIGH);
delay(500);
digitalWrite(13,LOW);
delay(500);
}

for(y=0;y<5;y++){
digitalWrite(13,HIGH);
delay(2000);
digitalWrite(13,LOW);
delay(2000);
}
}
