//We always have to include the library
#include "LedControl.h"

/*
  Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD
  We have only a single MAX72XX.
*/
LedControl lc = LedControl(12, 11, 10, 6);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 500;

void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  lc.shutdown(0, false);
  lc.shutdown(1, false);
  lc.shutdown(2, false);
  lc.shutdown(3, false);
  lc.shutdown(4, false);
  lc.shutdown(5, false);
  lc.shutdown(6, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 0);
  lc.setIntensity(1, 0);
  lc.setIntensity(2, 0);
  lc.setIntensity(3, 0);
  lc.setIntensity(4, 0);
  lc.setIntensity(5, 0);
  lc.setIntensity(6, 0);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
  lc.clearDisplay(4);
  lc.clearDisplay(5);
  lc.clearDisplay(6);
}

/*
  This method will display the characters for the
  word "Arduino" one after the other on the matrix.
  (you need at least 5x7 leds to see the whole chars)
*/
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[8] = {B00000000, B01111110, B10001000, B10001000, B10001000, B10001000, B01111110, B00000000};
  byte r[8] = {B00000000, B00100000, B00101100, B00110000, B00100000, B00100000, B00100000, B00000000};
  byte d[8] = {B00000000, B00000000, B11111100, B00100010, B00100010, B00100010, B00011100, B00000000};
  byte u[8] = {B00000000, B00111100, B00000010, B00000010, B00000010, B00000010, B00111100, B00000000};
  byte i[8] = {B00000000, B00000000, B00000000, B00100010, B10111110, B00000010, B00000000, B00000000};
  byte n[8] = {B00000000, B00000000, B00111110, B00010000, B00100000, B00100000, B00011110, B00000000};
  byte o[8] = {B00000000, B00000000, B00011100, B00100010, B00100010, B00100010, B00011100, B00000000};

  /* now display them one by one with a small delay */
  for (int f = 0; f <= 8; f++)
  {
    lc.setRow(0, f, a[f]);
    delay(100);
    lc.setRow(1, f, r[f]);
    delay(100);
    lc.setRow(2, f, d[f]);
    delay(100);
    lc.setRow(3, f, u[f]);
    delay(100);
    lc.setRow(4, f, i[f]);
    delay(100);
    lc.setRow(5, f, n[f]);
    delay(100);
    lc.setRow(6, f, o[f]);
    delay(100);
  }
  /*
    //#1
    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
    lc.setRow(0, 8, a[8]);
    delay(delaytime);
    //#2
    lc.setRow(1, 0, r[0]);
    lc.setRow(1, 1, r[1]);
    lc.setRow(1, 2, r[2]);
    lc.setRow(1, 3, r[3]);
    lc.setRow(1, 4, r[4]);
    lc.setRow(1, 5, r[5]);
    lc.setRow(1, 6, r[6]);
    lc.setRow(1, 7, r[7]);
    lc.setRow(1, 8, a[8]);
    delay(delaytime);
    //#3
    lc.setRow(2, 0, d[0]);
    lc.setRow(2, 1, d[1]);
    lc.setRow(2, 2, d[2]);
    lc.setRow(2, 3, d[3]);
    lc.setRow(2, 4, d[4]);
    lc.setRow(2, 5, d[5]);
    lc.setRow(2, 6, d[6]);
    lc.setRow(2, 7, d[7]);
    lc.setRow(2, 8, a[8]);
    delay(delaytime);
    //#4
    lc.setRow(3, 0, u[0]);
    lc.setRow(3, 1, u[1]);
    lc.setRow(3, 2, u[2]);
    lc.setRow(3, 3, u[3]);
    lc.setRow(3, 4, u[4]);
    lc.setRow(3, 5, u[5]);
    lc.setRow(3, 6, u[6]);
    lc.setRow(3, 7, u[7]);
    lc.setRow(3, 8, u[8]);
    delay(delaytime);
    //#5
    lc.setRow(4, 0, i[0]);
    lc.setRow(4, 1, i[1]);
    lc.setRow(4, 2, i[2]);
    lc.setRow(4, 3, i[3]);
    lc.setRow(4, 4, i[4]);
    lc.setRow(4, 5, i[5]);
    lc.setRow(4, 6, i[6]);
    lc.setRow(4, 7, i[7]);
    lc.setRow(4, 8, i[8]);
    delay(delaytime);
    //#6
    lc.setRow(5, 0, n[0]);
    lc.setRow(5, 1, n[1]);
    lc.setRow(5, 2, n[2]);
    lc.setRow(5, 3, n[3]);
    lc.setRow(5, 4, n[4]);
    lc.setRow(5, 5, n[5]);
    lc.setRow(5, 6, n[6]);
    lc.setRow(5, 7, n[7]);
    lc.setRow(5, 8, n[8]);
    delay(delaytime);
  */
}
void loop() {
  writeArduinoOnMatrix();
}
