#include "GyverNTP_Ex.h"

GyverNTP_Ex NTP_Ex;

bool GyverNTP_Ex::update()
{
  return tick();
}
bool GyverNTP_Ex::forceUpdate()
{
  return updateNow();
}

uint32_t GyverNTP_Ex::getEpochTime()
{
  return getUnix();
}

String GyverNTP_Ex::getFormattedTime(unsigned long secs){
  return timeString();
}

String GyverNTP_Ex::getFormattedDate(unsigned long secs){
  return dateToString();
}

String GyverNTP_Ex::getDurationOfWork(unsigned long secs) const
{
  String duration_str("");
  unsigned long duration_sec = (secs ? secs : millis() / 1000);

  if (duration_sec > 86399)
  { // days
    duration_str += duration_sec / 86400;
    duration_str += "d ";
    duration_sec %= 86400;
  }
  if (duration_sec > 3599)
  { // hours
    if (duration_sec < 36000 && !duration_str.isEmpty())
      duration_str += "0";
    duration_str += duration_sec / 3600;
    duration_str += "h ";
    duration_sec %= 3600;
  }
  else if (!duration_str.isEmpty())
    duration_str += "00h ";

  if (duration_sec > 59)
  { // minutes
    if (duration_sec < 600 && !duration_str.isEmpty())
      duration_str += "0";
    duration_str += duration_sec / 60;
    duration_str += "m ";
    duration_sec %= 60;
  }
  else if (!duration_str.isEmpty())
    duration_str += "00m ";

  if (duration_sec > 0)
  { // secounds
    if (duration_sec < 10 && !duration_str.isEmpty())
      duration_str += "0";
    duration_str += duration_sec;
    duration_str += "s";
  }
  else if (!duration_str.isEmpty())
    duration_str += "00s ";

  return duration_str;
} // getDurationOfWork
