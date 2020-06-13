#include<LiquidCrystal.h>
int i=5;
LiquidCrystal lcd(7,6,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  if(i!=5);
   {
     lcd.setCursor(0,0);
     lcd.print("Sachin Kaushal");
   }
   else
   {
     lcd.setCursor(0,0);
     lcd.print("Aakash Verma");
   }
}
