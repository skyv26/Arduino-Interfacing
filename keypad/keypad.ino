#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int r1=8;
int r2=9;
int r3=10;
int r4=11;
int c1=12;
int c2=13;
int c3=A0;
int c4=A1;
int b=A2;
int neww=0;
int check[4]={1,2,0,4};
int store[4];
int k=0;
void setup()
{
  lcd.begin(16,2);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  lcd.print("Enter PassCode");
  lcd.setCursor(0,1);
  pinMode(b,INPUT);
}

void loop()
{
x:
  store[k]=keypad();
  if(store[k]>0)
  {
    if(store[k]==16)
    store[k]=0;
    lcd.print(store[k]);
    delay(500);
    if(k==3)
    {
    if(store[0]==check[0])
    if(store[1]==check[1])
    if(store[2]==check[2])
    if(store[3]==check[3])
    neww=1;
     if(neww==1)
     {
      neww=0;
      k=0;
      lcd.clear();
      lcd.print("Access Granted");
      delay(500);
      lcd.clear();
      lcd.print("Enter PassCode");
      lcd.setCursor(0,1);
      goto x;
      }
    else
    {
      k=0;      
      lcd.clear();
      lcd.print("Access Denied");
      delay(500);
      lcd.clear();
      lcd.print("Enter PassCode");
      lcd.setCursor(0,1);
      goto x;
    }
    }
    k++;
  }
}
int keypad()
{ 
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  if(digitalRead(c1)==0)
  return 1;
  if(digitalRead(c2)==0)
  return 2;
  if(digitalRead(c3)==0)
  return 3;
  if(digitalRead(c4)==0)
  return 10;
  delay(10);
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  
  if(digitalRead(c1)==0)
  return 4;
  if(digitalRead(c2)==0)
  return 5;
  if(digitalRead(c3)==0)
  return 6;
  if(digitalRead(c4)==0)
  return 11;
  delay(10);
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  
  if(digitalRead(c1)==0)
  return 7;
  if(digitalRead(c2)==0)
  return 8;
  if(digitalRead(c3)==0)
  return 9;
  if(digitalRead(c4)==0)
  return 12;
  delay(10);  
   
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);     
  
  if(digitalRead(c1)==0)
  return 15;
  if(digitalRead(c2)==0)
  return 16;
  if(digitalRead(c3)==0)
  return 14;
  if(digitalRead(c4)==0)
  return 13; 
  delay(10);
  
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);     
  
  if(digitalRead(c1)==1)
  return 0;
  if(digitalRead(c2)==1)
  return 0;
  if(digitalRead(c3)==1)
  return 0;
  if(digitalRead(c4)==1)
  return 0; 
}
