#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);



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
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
}
void loop()
{
x:  
  if(digitalRead(16)==0)
   {
     digitalWrite(8,1);
     lcd.print("RED");
     delay(500);
     digitalWrite(8,0);
     lcd.clear();
     if(digitalRead(19)==0 || digitalRead(17)==0 || digitalRead(18)==0)
     goto x;
   }
    
  if(digitalRead(17)==0)
   {
     digitalWrite(9,1);
     lcd.print("GREEN");
     delay(500);
     digitalWrite(9,0);
     lcd.clear();
     if(digitalRead(16)==0 || digitalRead(19)==0 || digitalRead(18)==0)
     goto x;
   }
  if(digitalRead(18)==0)
   {
     digitalWrite(10,1);
     lcd.print("BLUE");
     delay(500);
     digitalWrite(10,0);
     lcd.clear();
     if(digitalRead(16)==0 || digitalRead(17)==0 || digitalRead(19)==0)
     goto x;
   }
  if(digitalRead(19)==0)
   {
     digitalWrite(8,1);
     digitalWrite(9,1);
     digitalWrite(10,1);
     lcd.print("RED|GREEN|BLUE");
     delay(500);
     digitalWrite(8,0);
     lcd.clear();
     lcd.print("   |GREEN|BLUE");
     delay(500);
     digitalWrite(9,0);
     lcd.clear();
     lcd.print("         |BLUE");
     delay(500);
     digitalWrite(10,0);
     lcd.clear();
     lcd.print(" BYE ");
     delay(800);
     lcd.clear();
     if(digitalRead(16)==0 || digitalRead(17)==0 || digitalRead(18)==0)
     goto x;
   }
  
}
