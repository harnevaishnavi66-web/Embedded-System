#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,4);



void setup() {
  lcd.backlight();
  lcd.setCursor(0 , 0);
  lcd.print("Hello,ESP32!");
  lcd.setCursor(0,1);
  lcd.print("Maulit");

}
void loop(){

}
