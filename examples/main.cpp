#include "secret.h"
#include <DebugRS.h>
#include <GyverTimer.h>
#include <GyverNTP_Ex.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

static GTimer timer_shedule(MS); // создать миллисекундный таймер

void setup()
{
  SERIAL_BEGIN_RS(115200);
  SERIAL_SETTIMEOUT(20);
  PRINTLN_RS();

  {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println("Connected");
  }

  NTP_Ex.begin(2);
  timer_shedule.setInterval(1000); // настроить интервал
}

void loop()
{
  NTP_Ex.tick();
  if (timer_shedule.isReady())
  {
    PRINTLN_RS(NTP_Ex.forceUpdate());
    PRINTLN_RS(NTP_Ex.update());
    PRINTLN_RS(NTP_Ex.getEpochTime());
    PRINTLN_RS(NTP_Ex.getFormattedDate());
    PRINTLN_RS(NTP_Ex.getFormattedTime());
    PRINTLN_RS(NTP_Ex.getDurationOfWork());
  }
}