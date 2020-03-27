/**********************************************************************

Signal.cpp
COPYRIGHT (c) 2020 duchonic

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/
/**********************************************************************

  <X lamp>:

**********************************************************************/

#include "DCCpp_Uno.h"
#include "Distance.h"
#include "Comm.h"
#include <Wire.h>
#include "Adafruit_VL6180X.h"

Adafruit_VL6180X vl = Adafruit_VL6180X();

void Distance::start(){
  INTERFACE.println("Adafruit VL6180x test!"); 
  if (! vl.begin()) {
    INTERFACE.println("Failed to find sensor");
  }
  else{
    INTERFACE.println("Sensor found!");
  }
}

///////////////////////////////////////////////////////////////////////////////

void Distance::check(){
    static bool state;
    uint8_t range = vl.readRange();
    if(!state &&  (range < 100) ){
      state=true;
      INTERFACE.println("<Qx>");
    } else if(state &&  (range > 200) ){
      state=false;
      INTERFACE.println("<qx>");
    }

    //float lux = vl.readLux(VL6180X_ALS_GAIN_5);
    //INTERFACE.print("Lux: "); Serial.println(lux);
    //INTERFACE.println( vl.readRange() );
}

///////////////////////////////////////////////////////////////////////////////

