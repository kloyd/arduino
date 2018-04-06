/*--------------------------------------------------------------------------------------
  Includes
--------------------------------------------------------------------------------------*/
#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

// DHT device
#include <Wire.h>
#include <DHT.h>

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
// Temp sensor
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
String temperature;

/*--------------------------------------------------------------------------------------
  Interrupt handler for Timer1 (TimerOne) driven DMD refresh scanning, this gets
  called at the period set in Timer1.initialize();
--------------------------------------------------------------------------------------*/
void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}

/*--------------------------------------------------------------------------------------
  setup
  Called by the Arduino architecture before the main loop begins
--------------------------------------------------------------------------------------*/
void setup(void)
{

   //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
   Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

   //clear/init the DMD pixels held in RAM
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
   temperature = "  F";

   //Serial.begin(9600);
   
}


void loop(void) {
  displayDMP();
  
  displayEntre();

  displayTemp();

}

void displayDMP() {
  dmd.clearScreen( true );
  dmd.selectFont(Arial_Black_16);
  //               .........11111111112222222222333333333344444444445
  //               12345678901234567890123456789012345678901234567890
  dmd.drawMarquee(". . . Digital Monitoring Products . . .",39,(32*DISPLAYS_ACROSS)-1,0);
  long start=millis();
  long timer=start;
  boolean ret=false;
  while(!ret){
    if ((timer+30) < millis()) {
      ret=dmd.stepMarquee(-1,0);
      timer=millis();
    }
  }
}

void displayTemp() {
  float t = dht.readTemperature();

  if (!isnan(t)) {
    int ti = t * 1.8 + 32.5;
    //Serial.println(ti);
    int th = ti / 10;
    int tl = ti % 10;
    temperature[0] = th + 48;
    temperature[1] = tl + 48;
  }

   // show temp for 5 seconds
   dmd.clearScreen( true );
   dmd.selectFont(Arial_Black_16);
   for (int n = 0 ; n < temperature.length(); n++) {
     dmd.drawChar(n * 9 + 3, 1, temperature[n], GRAPHICS_NORMAL);
   }
   delay(5000);
}

void displayEntre(){
  for (int n = 0; n < 5; n++) {
    cls();
    delay(500);
    dmd.selectFont(System5x7);
    for (byte x=0;x<DISPLAYS_ACROSS;x++) {
      for (byte y=0;y<DISPLAYS_DOWN;y++) {
        dmd.drawString(  2+(32*x),  1+(16*y), "Entre", 5, GRAPHICS_NORMAL );
        dmd.drawString(  2+(32*x),  9+(16*y), ".....", 5, GRAPHICS_NORMAL );
      }
    }
    delay(500);
  } 
}

void cls() {
  dmd.clearScreen(true);
}

