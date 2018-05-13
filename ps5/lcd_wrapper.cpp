#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2);
#include "lcd_wrapper.h"


void lcd_init(){
}

void lcd_clear(){
}


void lcd_set_cursor(int y, int x){
}


void lcd_print(char* text){
    Serial.println(text);
}


void lcd_print_at(int y, int x, char* text){
    lcd_set_cursor(y, x);
    lcd_print(text);
}

