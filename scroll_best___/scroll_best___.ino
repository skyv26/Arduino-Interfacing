#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int i,j,k=17;

void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  for (i=32;i>=0;i--)
    {
      if(k<0)
      break;
      j=i-16;
      if(j<0)
      { j=j-8;
        k--;
        if(j<-16)
         j=-15;
      }
      else
      k=17;
      lcd.setCursor(j,0);      
      lcd.print("hello");
      lcd.setCursor(k,0);
      lcd.print("hello");
      lcd.setCursor(0,1);
     /* lcd.print(j);
      lcd.print(" ");
      lcd.print(k); */     
      delay(200);
      lcd.clear();
    }
}
