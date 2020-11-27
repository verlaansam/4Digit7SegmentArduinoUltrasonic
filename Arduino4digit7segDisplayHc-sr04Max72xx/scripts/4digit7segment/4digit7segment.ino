#include "LedControl.h" /*library for the display*/

/*
 MAX72XX pinout
 pin 12 to DataIn 
 pin 11 to CLK 
 pin 10 to LOAD */
LedControl lc=LedControl(12,10,11,1); /*define pins for display*/

void setup() {
  /*dislplay*/
  lc.shutdown(0,false); /*Wake-up call*/
  lc.setIntensity(0,8); /*Brightness*/
  lc.clearDisplay(0); /*Clear display*/
}

void loop() {
  lc.setChar(0,0, 'a', false);
  lc.setChar(0,1, 'a', false);
  lc.setChar(0,2, 'a', false);
  lc.setChar(0,3, 'a', false);
  delay(100);
}
