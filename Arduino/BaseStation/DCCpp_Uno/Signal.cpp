/**********************************************************************

Signal.cpp
COPYRIGHT (c) 2020 duchonic

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/
/**********************************************************************

  <X lamp>:

**********************************************************************/

#include "DCCpp_Uno.h"
#include "Signal.h"
#include "Comm.h"
#include <Wire.h>
#include "lp55231.h"

static Lp55231 signalA(0x34);
static Lp55231 signalB(0x35);

void Signal::start(){
  signalA.Begin();
  signalA.Enable();

  signalB.Begin();
  signalB.Enable();
}


///////////////////////////////////////////////////////////////////////////////

void Signal::parse(char *c){
  int n,s,m;

  static int oldStateA;
  static int oldStateB;

  switch(sscanf(c,"%d %d %d",&n,&s,&m)){
    
    case 3:{
        INTERFACE.print("<X -1>");
        break;
    }
    case 2:{
      if( (s >= 0) && (s <= 8) )
          switch(n){
            case 0:{
              signalA.SetChannelPWM(oldStateA, 0);
              signalA.SetChannelPWM(s, 255);
              oldStateA = s;
              INTERFACE.print("<X 0 ");
              INTERFACE.print(s);
              INTERFACE.print(">");
              break;
            }
            case 1:{
              signalB.SetChannelPWM(oldStateB, 0);
              signalB.SetChannelPWM(s, 255);
              oldStateB = s;
              INTERFACE.print("<X 1 ");
              INTERFACE.print(s);
              INTERFACE.print(">");
              break;
            }
            default:{
              INTERFACE.print("<X -1>");
              break;
            }
          }
      else
      {
        INTERFACE.print("<X -1>");
      }
      
      break;
    }
    case 1:{
        INTERFACE.print("<X -1>");
        break;

    }                     // argument is a string with id number only
    case -1:{// no arguments
        INTERFACE.print("<X -1>");
        break;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////

