#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
int l=0;
int btn1=8;
int btn2=9;
int btn3=10;
int btn4=11;
int u;
void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
}

void loop()
{
  k:
  lcd.setCursor(0,0);
  lcd.print("counting : ");
  lcd.setCursor(11,0);
  lcd.print(l);
  if(digitalRead(8)==0)
  {
    l=l+1;
    delay(500);
  }
  if(digitalRead(9)==0)
  {
    l=l-1;
    delay(500);
  }
  if(digitalRead(10)==0)
  {
    lcd.clear();
    l=0;
  }
  if(digitalRead(11)==0)
  {
    
    for(;l<=9;l++)
    {     
     lcd.setCursor(11,0);
     lcd.print(l);
     delay(500);
     if (digitalRead(9)==0)
        {
         goto k;
        }
    }
  }
  if (l==10)
  {lcd.clear();
   l=0;}
  if (l>9)
  l=0;
  if (l<0)
   l=9; 
}

