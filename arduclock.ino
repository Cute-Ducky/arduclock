#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
int h = 12;
int m = 0;
int s = 0;
const int hs = A0;
const int ms = A1;
int state1 = 0;
int state2 = 0;
void setup()
{
  display.begin();
  display.setContrast(40);
  display.clearDisplay();
  pinMode(hs, INPUT_PULLUP);
  pinMode(ms, INPUT_PULLUP);
}
void loop()
{
  display.setCursor(12,12);
  display.setTextSize(2);
  s++;
  if (h<=9)
  {
    display.print(" ");
    display.print(h);
  }
  else
  {
    display.print(h);
  }
  display.print(":");
  if (m<=9)
  {
    display.print(0);
    display.print(m);
  }
  else
  {
    display.print(m);
  }
  display.setCursor(18,30);
  display.setTextSize(1);
  display.print("inserttext");
  display.display();
  delay(1000);
  display.clearDisplay();
  if (s == 60)
  {
    s = 0;
    m = m + 1;
  }
  if(h==24)
    h=0;
  if(h==23 && m==60)
  {
    m=0;
    h=0;
  }
  if (m == 60)
  {
    m = 0;
    h = h + 1;
  }
  state1 = digitalRead(hs);
  if (state1 == 0)
  {
    h = h + 1;
  }
  state2 = digitalRead(ms);
  if (state2 == 0)
  {
    s = 0;
    m = m + 1;
  }
}
