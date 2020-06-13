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
int store[5];
int code[4]={1,2,3,4};
int led3=10,led1=8,led2=9,j=0,k=0,l=3,m,y=0,rem;
int n,q,w,store1,p=0,code2;
int flag;


int otp()
{ 
   store1=keypad();
   if(store1>0)
   {
     if(store1==16)
     store1=0;
     
     lcd.print(store1);
     p=store1;
     delay(250);
   } 
   if (store1==10)
   { 
     if(p==code2)
       flag=1;
     if(flag==1)
       return 3;
     else
        return 1;
   }
}
void hang()
{
  while(1)
  {  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("system hang");
    digitalWrite(led3,1);
    delay(100);
  }
}

void setup()
{
  lcd.begin(16,2);
  lcd.print(" enter passcode");
  lcd.setCursor(0,1);
  randomSeed(analogRead(0));
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);
}

void loop()
 {
x:
   store[k] = keypad();
   if(store[k]>0)
   {
     if(store[k]==16)
     store[k]=0;
     lcd.print(store[k]);
      delay(400);
     k++;
   
    
   }
   if (k==4)
   { 
     if(store[0]==code[0])
      if(store[1]==code[1])
       if(store[2]==code[2])
        if(store[3]==code[3])
         j=1;
         if(j==1)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("ACCESS GRANTED");
          delay(1000);
          lcd.clear();
          lcd.print("your otp= ");
          n=random(1000,9999);
          Serial.print(n);
          while(n!=0)
           {
             rem=n%10;
             y+=rem;
             n/=10;
           }
          code2=y;
          delay(2000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(" enter otp =");
          k=0;
          j=0;
          m=otp();
          if(m==3)
           {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ACCESS GRANTED"); 
            digitalWrite(led1,1);
            delay(1000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("      BYE");
            delay(1000);
            lcd.clear();
            digitalWrite(led1,0);
            lcd.setCursor(0,0);
            lcd.print(" enter passcode");
            lcd.setCursor(0,1);
            k=0;
            l=3; 
            j=0;
            y=0;
            flag=0;
            goto x;        
           }
           else
           {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ACCESS DENIED");
            digitalWrite(led2,1);
            lcd.setCursor(0,1);
            lcd.print(l-1);
            lcd.print(" atempts left");
            delay(1000);
            lcd.clear();
            digitalWrite(led2,0);
            lcd.setCursor(0,0);
            lcd.print(" enter passcode");
            lcd.setCursor(0,1);
            k=0;
            l--;
            y=0;
            flag=0;
            if (l==0)
            hang();         
            goto x;  
           }    
         }
        else
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("ACCESS DENIED");
          digitalWrite(led2,1);
          lcd.setCursor(0,1);
          lcd.print(l-1);
          lcd.print(" atempts left");
          delay(1000);
          lcd.clear();
          digitalWrite(led2,0);
          lcd.setCursor(0,0);
          lcd.print(" enter passcode");
          lcd.setCursor(0,1);
          k=0;
          j=0;
          l--;
          flag=0;
          if (l==0)
           hang();         
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
   if (digitalRead(c1)==0)
     return 1;
   if (digitalRead(c2)==0)
     return 2;
   if (digitalRead(c3)==0)
     return 3;
   if (digitalRead(c4)==0)
   return 10;
   delay(10);
   
   
   digitalWrite(r1,HIGH);
   digitalWrite(r2,LOW);
   digitalWrite(r3,HIGH);
   digitalWrite(r4,HIGH);
   if (digitalRead(c1)==0)
     return 4;
   if (digitalRead(c2)==0)
     return 5;
   if (digitalRead(c3)==0)
     return 6;
   if (digitalRead(c4)==0)
     return 11;
   delay(10);
     
   digitalWrite(r1,HIGH);
   digitalWrite(r2,HIGH);
   digitalWrite(r3,LOW);
   digitalWrite(r4,HIGH);
   if (digitalRead(c1)==0)
     return 7;
   if (digitalRead(c2)==0)
     return 8;
   if (digitalRead(c3)==0)
     return 9;
   if (digitalRead(c4)==0)
     return 12;
   delay(10);
   
   digitalWrite(r1,HIGH);
   digitalWrite(r2,HIGH);
   digitalWrite(r3,HIGH);
   digitalWrite(r4,LOW);
   if (digitalRead(c1)==0)
     return 15;
   if (digitalRead(c2)==0)
     return 16;
   if (digitalRead(c3)==0)
     return 14;
   if (digitalRead(c4)==0)
     return 13;
   delay(10);
   digitalWrite(r1,HIGH);
   digitalWrite(r2,HIGH);
   digitalWrite(r3,HIGH);
   digitalWrite(r4,HIGH);
   if (digitalRead(c1)==1)
     return 0;
   if (digitalRead(c2)==1)
     return 0;
   if (digitalRead(c3)==1)
     return 0;
   if (digitalRead(c4)==1)
     return 0;
   delay(10);
   
}

