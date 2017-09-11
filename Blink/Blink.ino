/*
  Blink.ino
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:Loovee
  2013-9-18

  Grove - Serial LCD RGB Backlight demo.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Wire.h>
#include "rgb_lcd.h"
#define LED A0
#include "Ultrasonic.h"

Ultrasonic ultrasonic(A3);
rgb_lcd lcd;


void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    // Print a message to the LCD.

}

void loop() 
{
    // Turn off the blinking cursor:
    long RangeInCentimeters;
    RangeInCentimeters = ultrasonic.MeasureInCentimeters();
    lcd.clear();
    if(RangeInCentimeters<=5){
    lcd.println("I can feel your ");
    lcd.setCursor(1,1);
    lcd.print("finger");
    delay(1000);
    }
    // Turn on the blinking cursor:
    else
    {
    lcd.print("I cant feel your");
    lcd.setCursor(1,1);
    lcd.print("finger");
    delay(3000);
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
