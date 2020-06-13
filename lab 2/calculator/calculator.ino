#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
int l=0,m=0,a,b,c;
float d,k,j;
int btn1=8;
int btn2=9;
int reset=10;
int ok=11;
int flag=0;
int flag2=0;
int flag3=0;
void first()
{
   lcd.setCursor(0,0);
   lcd.print("l=");
   lcd.setCursor(4,0);
   lcd.print(l);
  if(digitalRead(btn1)==0)
  {
    l=l+1;
    delay(100);
  }
  if(digitalRead(btn2)==0)
  {
    l=l-1;
    delay(100);
  }
  if(digitalRead(reset)==0)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("l=");
    lcd.setCursor(4,0);
    l=0;
    lcd.print(l);
  }
  if(digitalRead(ok)==0)
  {
   flag=1;
   lcd.clear();
   delay(250);
  }
  if (l>9)
  l=0;
}
void second()
{  
   lcd.setCursor(0,0);
   lcd.print("m=");
   lcd.setCursor(4,0);
   lcd.print(m);
  if(digitalRead(btn1)==0)
  {
    m=m+1;
    delay(100);
  }
  if(digitalRead(btn2)==0)
  {
    m=m-1;
    delay(100);
  }
  if(digitalRead(reset)==0)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("m=");
    lcd.setCursor(11,0);
    m=0;
    lcd.print(m);
  }
  if(digitalRead(ok)==0)
  {
    lcd.clear();
    flag2=1;
  } 
  if (m>9)
  m=0;
}
 void calculate()
 {  
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1 for add");
    lcd.setCursor(0,1);
    lcd.print("2 for subtract");
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("3 for multiply");
    lcd.setCursor(0,1);
    lcd.print("4 for divide");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("select command");
    delay(500);
    while(flag3==0)
    {
    if(digitalRead(btn1)==0)
     {
      a=l+m;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(l);
      lcd.print("+");
      lcd.print(m);
      lcd.print("=");
      lcd.print(a);
      lcd.setCursor(0,1);
      lcd.print("*****thanks*****");
      delay(2000);
     flag3=1;
     }
    if(digitalRead(btn2)==0)
      {
       b=l-m;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(l);
       lcd.print("-");
       lcd.print(m);
       lcd.print("=");       
       lcd.print(b);
       lcd.setCursor(0,1);
       lcd.print("*****thanks*****");
       delay(2000);
       flag3=1;
      }
    if(digitalRead(reset)==0)
      {
       c=l*m;
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(l);
       lcd.print("*");
       lcd.print(m);
       lcd.print("=");
       lcd.print(c);
       lcd.setCursor(0,1);
       lcd.print("*****thanks*****");
       delay(2000);
       flag3=1;
      }
    if(digitalRead(ok)==0)
     {
      k=l;
      j=m; 
      d=k/j;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(l);
      lcd.print("/");
      lcd.print(m);
      lcd.print("=");
      lcd.print(d);
      lcd.setCursor(0,1);
      lcd.print("*****thanks*****");
      delay(2000);
      flag3=1;
      } 
    }
}
void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("hello!!");
  delay(1000 );
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(reset,INPUT);
  pinMode(ok,INPUT);
  lcd.clear();
}

void loop()
{
x:
 lcd.clear();
 flag3=0;
 first(); 
 delay(10);
 if(flag==1)
 {
  flag=0;
  while(flag2==0)
  {
  second();
  } 
  if(flag2==1)
  {
    flag2=0;
    lcd.clear();
    calculate();
  }
 }
}

