#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd( 0x27, 20, 4 ); // 20 chars, 4 line
String temperature;
String humidity;
float humidRead;
float tempC;
float tempF;

void setup()
{
  lcd.init();
  lcd.print("Initializing...");
}

void loop()
{
    // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  humidRead = dht.readHumidity();
  float tempC = dht.readTemperature();
  lcd.clear();
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(tempC) || isnan(humidRead)) {
    lcd.print("Initializing...");
  } else {
    tempF = tempC * 1.8 + 32;
    temperature = "Temp (F)  ";
    temperature = temperature + tempF;
    humidity =    "Humidity  ";
    humidity = humidity + humidRead;
    humidity = humidity + "%";
    lcd.setCursor(0,0);
    lcd.print(temperature);
    lcd.setCursor(0,1);
    lcd.print(humidity);
    lcd.setCursor(0,2);
    temperature = "Temp (C)  ";
    temperature = temperature + tempC;
    lcd.print(temperature);

  }
  delay(500);
}

