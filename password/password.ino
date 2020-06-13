#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);


int r1=12;
int r2=13;
int r3=A0;
int r4=A1;
int c1=A2;
int c2=A3;
int c3=A4;
int c4=A5;
int b=11;
int store[4];
int pass[4]={1,2,3,4};
int k=0,j=0;
int led1=8;
int led2=9;
int p=3;
void setup()
{
  lcd.begin(16,2);
 
 pinMode(b,INPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(r3,OUTPUT);
 pinMode(r4,OUTPUT);
 
 pinMode(c1,INPUT);
 pinMode(c2,INPUT);
 pinMode(c3,INPUT);
 pinMode(c4,INPUT);
 lcd.print(" ENTER PASSWORD");
 lcd.setCursor(0,1);
 Serial.begin(9600);
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
 delay(200);
 k++;
 }
  if(k==4)
 {
   if(store[0]== pass[0])
   if(store[1]== pass[1])
   if(store[2]== pass[2])
   if(store[3]== pass[3])
   j=1;
   
   if(j==1)
    {
     lcd.clear();
     lcd.setCursor(0,1);
     lcd.print("   GRANTED");
     digitalWrite(led1,HIGH);
     delay(800);
     digitalWrite(led1,LOW);
    
    }
   else
     { 
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("   NOT GRANTED");
      delay(500);
      lcd.clear();
      lcd.print(p);
      lcd.print(" attempt left");     
      digitalWrite(led2,HIGH);
      delay(800);
      digitalWrite(led2,LOW);
      p--;
      k=0;
       if(p==0)
      SYSTEMHANG();
      goto x;
     
    
    }
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
return 13;
if(digitalRead(c2)==0)
return 16;
if(digitalRead(c3)==0)
return 14;
if(digitalRead(c4)==0)
return 15;
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
delay(10);
}
void SYSTEMHANG()
{
  while (1)
  {
    lcd.clear();
    lcd.print("SYSTEM HANG");
    delay(10);
   }
}
