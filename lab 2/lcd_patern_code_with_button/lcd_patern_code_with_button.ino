#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int i;

void march()
{
x:
  while(digitalRead(17)==1 && digitalRead(18)==1 && digitalRead(19)==1)
    for(i=8;i<16;i++)
    {
     digitalWrite(i,1);
     lcd.setCursor(i-8,0);
     lcd.print("*");
     delay(400); 
     digitalWrite(i,0);
     lcd.clear();
     if(digitalRead(17)==0 || digitalRead(18)==0 || digitalRead(19)==0)
     goto x;
    }
}
void march2()
{
 x:
  while(digitalRead(16)==1 && digitalRead(18)==1 && digitalRead(19)==1)
    for(i=15;i>7;i--)
    {
     digitalWrite(i,1);
     lcd.setCursor(i-8,0);
     lcd.print("*");
     delay(400); 
     digitalWrite(i,0);
     lcd.clear();
     if(digitalRead(16)==0 || digitalRead(18)==0 || digitalRead(19)==0)
     goto x;
    }  
}
void even()
{
x:
  while(digitalRead(16)==1 && digitalRead(17)==1 && digitalRead(19)==1)
    for(i=8;i<16;i=i+2)
    {
     digitalWrite(i,1);
     lcd.setCursor(i-8,0);
     lcd.print("*");
     delay(400); 
     digitalWrite(i,0);
     lcd.clear();
     if(digitalRead(16)==0 || digitalRead(17)==0 || digitalRead(19)==0)
     goto x;
    }  
}
void odd()
{
x:
  while(digitalRead(16)==1 && digitalRead(17)==1 && digitalRead(18)==1)
    for(i=9;i<16;i=i+2)
    {
     analogWrite(i,1);
     lcd.setCursor(i-8,0);
     lcd.print("*");
     delay(400); 
     digitalWrite(i,0);
     lcd.clear();
     if(digitalRead(16)==0 || digitalRead(17)==0 || digitalRead(18)==0)
     goto x;
    } 
}
void setup()
{ 
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("****welcome!****");
  delay(1000);
  lcd.clear();
 for (i=8;i<16;i++)
  {
    pinMode(i,OUTPUT);
  } 
}
void loop()
{
  if(digitalRead(16)==0)
   march();
  if(digitalRead(17)==0)
   march2();
  if(digitalRead(18)==0)
   even();
  if(digitalRead(19)==0)
   odd();
  
}

