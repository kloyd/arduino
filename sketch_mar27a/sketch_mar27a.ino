int swch = 0;

void setup() { 
   pinMode(13, OUTPUT); 
   Serial.begin(115200);
}
 
void loop() {
   if (Serial.available() > 0) {
      swch = Serial.read();
      if (swch == 49) digitalWrite(13, HIGH); 
        else if (swch == 48) digitalWrite(13, LOW);   
           else Serial.println("To control the LED, use 1 or 0 ONLY");   
     }                     

 }
