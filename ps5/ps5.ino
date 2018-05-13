#include "mastermind.h"
#include"lcd_wrapper.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
 pinMode(BTN_1_PIN, INPUT);
 pinMode(BTN_2_PIN, INPUT);
 pinMode(BTN_3_PIN, INPUT);
 pinMode(BTN_4_PIN, INPUT);
 pinMode(BTN_ENTER_PIN, INPUT);
 
 pinMode(LED_BLUE_1, OUTPUT);
 pinMode(LED_RED_1, OUTPUT);
 pinMode(LED_BLUE_2, OUTPUT);
 pinMode(LED_RED_2, OUTPUT);
 pinMode(LED_BLUE_3, OUTPUT);
 pinMode(LED_RED_3, OUTPUT);
 pinMode(LED_BLUE_4, OUTPUT);
 pinMode(LED_RED_4, OUTPUT);
 char n[] = {"Mastermind"};
  lcd.init();
  lcd.backlight();
  for (int i = 0; i < strlen(n); i++) {
    lcd.setCursor(i, 0);
    lcd.print(n[i]);
  }  
  lcd.init();                                                                             
  lcd.backlight();
  Serial.begin(9600);
  Serial.println(' ');
}

void loop() {
  lcd.backlight();
  lcd.clear();
  char* code = generate_code(false, 8);
  for (int i = 0; i < 4; i++) {
    lcd.print((int)code[i]);
  }
  delay(5555);
  play_game(code);
  for (int i = 0; i < 4; i++) {
    lcd.print((int)code[i]);
  }
  delay(1000);
  free(code);

}
