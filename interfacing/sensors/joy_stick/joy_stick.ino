#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);




void setup()
{
  lcd.begin(16,2);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
}

void loop()
{
  int a=digitalRead(8);
  int b=analogRead(9);
  int c=digitalRead(10);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(b);
  
  delay(800);
  
}
