/* * Sketch: eeprom_serial
  Author: Kelly S. Loyd
  Date: 30 March 2018

  Write a sketch that allows a user to access data in EEPROM using the serial monitor.
  In the serial monitor the user should be able to type one of two commands: "read" and "write".
  "Read" takes one argument, an EEPROM address.
  "Write" takes two arguments, an EEPROM address and a value.
*/

#include <EEPROM.h>

const int MAX_CHARS = 40;
char command[MAX_CHARS];
int counter;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("EEPROM test, enter read <addr> or write <addr> <val>");
}

void loop() {
  if (Serial.available() > 0) {
    Serial.readBytesUntil(10, command, 40);
    parseCommand(command);
    for (counter = 0; counter < MAX_CHARS; counter++) {
      command[counter] = 0;
    }
  }
}

void parseCommand(String command) {
  if (command.substring(0, 4) == "read") {
    handleRead(command.substring(5));
  } else if (command.substring(0, 5) == "write") {
    handleWrite(command.substring(6));
  } else {
    Serial.println("I don't understand '" + command + "'");
    Serial.println("Try 'read <address>' or 'write <address> <value>'");
  }
}

void handleRead(String argument) {
  int address = argument.toInt();
  byte data;
  data = EEPROM.read(address);
  String eePromData = String(data);
  String eePromAddress = String(address);
  Serial.println("Read from Address: " + eePromAddress + ", data: " + eePromData);
}

void handleWrite(String arguments) {
  int spacer = arguments.indexOf(' ');
  int address;
  int data;
  String eePromAddress = arguments.substring(0, spacer);
  String eePromData = arguments.substring(spacer + 1);
  address = eePromAddress.toInt();
  data = eePromData.toInt() & 0xFF;
  Serial.println("Write " + eePromData + " to Address " + eePromAddress);
  EEPROM.write(address, data);
}


