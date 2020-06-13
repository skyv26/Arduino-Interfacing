#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
  pinMode(A5,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
void loop()
{ 
   if (analogRead(8))
   {
     lcd.clear();
     lcd.setCursor(0,1);
     int a=analogRead(8);
     lcd.print(a);
     delay(1000);
   }
   if(analogRead(A5)>100)
    {digitalWrite(8,1);
    digitalWrite(9,0);
    digitalWrite(10,0);}
   if(analogRead(A5)>100&&analogRead(A5)<300)
   { digitalWrite(8,0);
    digitalWrite(9,1);
    digitalWrite(10,0);}
   if(analogRead(A5)>300)
    { digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(10,1);}
}
