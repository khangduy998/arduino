#include <Wire.h>
#include "rgb_lcd.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic(A3);
rgb_lcd lcd;
int hour=17;
int minute=16;
int second=00;
int rgb=0;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.print(hour);
lcd.print(":");
lcd.print(minute);
lcd.print(":");
lcd.print(second);
lcd.setRGB(0,0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  lcd.clear();
  second+=1;
  if(rgb==0) {
  lcd.setRGB(0,0,0);
  checkHand();
  }
  else rgb-=1;
if(second>59){
  minute+=1;
  second=0;
}
if(minute>59){
  hour+=1;
  minute=0;
}
lcd.print(hour);
lcd.print(":");
lcd.print(minute);
lcd.print(":");
lcd.print(second);
}
void checkHand(){
  long RangeInCentimeters;
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  if(RangeInCentimeters<15) {lcd.setRGB(255,255,255);
  rgb=6;
  }
}

