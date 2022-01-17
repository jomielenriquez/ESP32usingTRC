#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "RTClib.h"
 
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//vcc => 3.3v
//SCL => G22
//SDA => G21
void setup() 
{
 
  Serial.begin(9600);
   
  if (! rtc.begin()) {
  Serial.println("Couldn't find RTC");
  while (1);
  }
   
  rtc.adjust(DateTime(__DATE__, __TIME__));
   
   
  delay(3000);
}
 
void loop()
{
  DateTime now = rtc.now();
  String Time = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  String Date = String(now.month()) + "-" + String(now.day()) + "-" + String(now.year());
  String StrDay = daysOfTheWeek[now.dayOfTheWeek()];

  Serial.println(Time + " " + Date + " " + StrDay);
 
  delay(1000); 
}
