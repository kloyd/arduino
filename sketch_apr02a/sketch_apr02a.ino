#include <EEPROM.h>
String scmd = "";
char crip[256];
boolean Message = true;
int lRead = 0;
int lWrite = 0;
int lSpace = 0;
int lAddress = 0;
byte lVal = 0;
String sTmp = "";
void setup() {
  Serial.begin(9600);
} void loop() {
  if (Message) {
    Serial.println("\nPlease enter a command. read address OR write address value");
    Message = false;
  } if (Serial.available()) {
    delay(100);
    if (false) {
      Serial.readBytes(crip, 128);
      scmd = String(crip);
    } else {
      scmd = Serial.readString();
      scmd.toUpperCase();
    } lRead = scmd.indexOf("READ");
    lWrite = scmd.indexOf("WRITE");
    if (lRead < 0 && lWrite < 0) {
      Serial.println(" No read or write command found, please try again.");
    } else {
      if (lRead >= 0) {
        sTmp = scmd.substring(lRead + 5);
        lAddress = sTmp.toInt();
        lVal = EEPROM.read(lAddress);
        Serial.println("The contents of EEPROM address " + String(lAddress) + " is " + String(lVal));
      } else {
        sTmp = scmd.substring(lWrite + 6);
        lAddress = sTmp.toInt();
        lSpace = sTmp.indexOf(" ");
        sTmp = sTmp.substring(lSpace + 1);
        lVal = sTmp.toInt();
        EEPROM.write(lAddress, lVal);
        Serial.println("The value of " + String(lVal) + " has been saved to EEPROM address " + String(lAddress));
      }
    } Message = true;
  }
}
