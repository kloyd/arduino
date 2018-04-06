#include <EEPROM.h>
String lee = String("read");
String escribe = String("write");
int index = 0; String a, valor, indice, numero;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    while (Serial.available()) {
      a = Serial.readString();
      int i = 0;
      if (a.substring(0, 4) == "read") {
        Serial.print("\nREAD-> ");
        //Serial.print(a.substring(4, a.length()));
        valor = a.substring(4, a.length());
        index = valor.toInt();
        Serial.println(index);
        //Serial.println("hola");
        Serial.println(EEPROM.read(index));
      }
      if (a.substring(0, 5) == "write") {
        Serial.print("WRITE-> ");
        valor = a.substring(6, a.length());
        indice = valor.substring(0, a.indexOf(' '));
        index = indice.toInt();
        Serial.print(index);
        Serial.print(" ");
        numero = valor.substring(valor.indexOf(' '), valor.length());
        //numero = valor.substring(0,valor.indexOf(' '));
        int kk = numero.toInt();
        Serial.print(kk);
        EEPROM.write(index, kk);
      }
    }
  }
}
