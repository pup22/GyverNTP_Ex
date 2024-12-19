#pragma once

#include "GyverNTP.h"

class GyverNTP_Ex : public GyverNTP
{
public:
  GyverNTP_Ex(int16_t gmt = 0) : GyverNTP(gmt) {}

  /**
   * This should be called in the main loop of your application. By default an update from the NTP Server is only
   * made every 60 seconds. This can be configured in the NTPClient constructor.
   *
   * @return true on success, false on failure
   */
  bool update();

  /**
   * This will force the update from the NTP Server.
   *
   * @return true on success, false on failure
   */
  bool forceUpdate();

  /**
   * @return time in seconds since Jan. 1, 1970
   */
  uint32_t getEpochTime();

  /**
   * @return time formatted like `hh:mm:ss`
   */
  String getFormattedTime(unsigned long secs = 0);

  /**
   * @return date formatted like `dd.mm.yyyy`
   */
  String getFormattedDate(unsigned long secs = 0);

  /**
   * converts seconds to days hours minutes seconds
   * @param secs if 0, then from the device startup time
   * @return duration formatted like `ddd hh mm ss`
   */
  String getDurationOfWork(unsigned long secs = 0) const; // running time since launch (format ddd hh mm ss)
};

extern GyverNTP_Ex NTP_Ex;
