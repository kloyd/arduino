#include <Wire.h>
#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );
String temperature;
String humidity;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Initializing...");
}

void loop()
{
    // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.clear();
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    lcd.print("Initializing...");
  } else {
    t = t * 1.8 + 32;
    temperature = "Temp: ";
    temperature = temperature + t;
    humidity = "Humidity: ";
    humidity = humidity + h;
    lcd.setCursor(0,0);
    lcd.print(temperature);
    lcd.setCursor(0,1);
    lcd.print(humidity);

  }
  delay(500);
}

