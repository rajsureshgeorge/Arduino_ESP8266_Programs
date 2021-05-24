//LCD Program
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.

}

void loop() {
  // Turn off the display:
   
   lcd.print("heloo everyone ");
    
     lcd.setCursor(2,1);
     lcd.print("pls care for the ic");
  delay(2000);
lcd.clear();
   lcd.print("use This ");
    
     lcd.setCursor(2,1);
     lcd.print("carefully");
       delay(700);
     lcd.clear();
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
 
  lcd.cursor();
  delay (1000);
  lcd.noCursor();
  delay(1000);}
}
