void setup() {
   pinMode(9, OUTPUT);
   //Serial.begin(9600);
}

void loop() {
   int var;
   tone(9,440);
//   if (Serial.available() > 0){
//      var = Serial.read ();
//      if ( var == '1' ){
//         Serial.println("ON");
//         digitalWrite (LED_BUILTIN, 1);
//      }
//      else if ( var == '0' ){
//         Serial.println("OFF");
//         digitalWrite (LED_BUILTIN, 0);
//      }
//   }
}
