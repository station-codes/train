/**********************************************************************

Sensor.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#ifndef Signal_h
#define Signal_h

#include "Arduino.h"


struct 
Signal{
  static void start();
  static void parse(char *c);
}; // Signal

#endif

