#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
int l,m=0;
void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("counting : ");
  if(m==1)
  {
     for(l=9 ; l>=0 ; l--)
  {
   lcd.setCursor(11,0);
   lcd.print(l);
   delay(500); 
  }
  }
  for(l=0 ; l<=10 ; l++)
   {
   lcd.setCursor(11,0);
   lcd.print(l);
   delay(500); 
   m=1;
  }
  if(l==11)
  lcd.clear();
}

