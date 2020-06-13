#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);

int store[5];
int code[4]={1,2,3,4};
int led3=1,led1=8,led2=9,j=0,k=0,l=3,m,y=0,rem;
int n,q,w,p=0,code2,a=0,jk=0;
int flag;
int store1;
char gh,input[100];
char b[7]={'b','u','l','b',' ','o','n'};
char c[8]={'b','u','l','b',' ','o','f','f'};
char d[5]={'r','e','s','e','t'};
int bluetooth()
{
  
    int z=mySerial.read();
     
    if (z==48)
    return 10;
    if (z==49)
    return 1;
     if (z==50)
    return 2;
    if (z==51)
    return 3;
    if (z==52)
    return 4;
    if (z==53)
    return 5;
    if (z==54)
    return 6;
    if (z==55)
    return 7;
    if (z==56)
    return 8;
    if (z==57)
    return 9;
    if(z==46)
    return 12;
  
  
}

int otp()
{ 
  while(1)
  {
   store1=bluetooth();
   if(store1>0&&store1!=12)
   { 
     if (store1==10)
      store1=0;
     p*=10;
     lcd.print(store1);
     p+=store1;
     delay(250);
   } 
   if (store1==12)
   { 
     if(p==code2)
       {
         p=0;
         flag=1;
       }
     if(flag==1)
       return 3;
     else
       {
         p=0;
        return 1;
       }
   }
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
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  mySerial.begin(9600);
}

void loop()
 {
x:
   store[k] = bluetooth();
   if(store[k]>0)
   {
     if(store[k]==10)
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
          lcd.print("your otp is sent ");
          n=random(1000,9999);
          delay(100);
          mySerial.print("  your otp : ");
          mySerial.print(n);
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
            delay(2000);
            while(m==3)
            {
               if(mySerial.available()>0)
               { 
               gh=mySerial.read();
               if(gh!='~')
               if(gh!='^')
               input[jk]=gh;
              if(gh=='~')
              {
                lcd.clear();
              }
              if(gh=='^')
              {
                lcd.print(input);
              }
              if(input[jk-6]==b[0] && input[jk-5]==b[1] && input[jk-4]==b[2] && input[jk-3]==b[3] && input[jk-2]==b[4] && input[jk-1]==b[5] && input[jk-0]==b[6])
               {
                 lcd.clear();
                 lcd.print("**bulb on**");
                 digitalWrite(led1,1);
                }
              if(input[jk-7]==c[0]&&input[jk-6]==c[1] && input[jk-5]==c[2] && input[jk-4]==c[3] && input[jk-3]==c[4] && input[jk-2]==c[5] && input[jk-1]==c[6] && input[jk-0]==c[7])
               {
                 lcd.clear();
                 lcd.print("**bulb off**");
                 digitalWrite(led1,0);
                }
              
           /* digitalWrite(led1,1);
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
            flag=0;*/
            if(input[jk-4]==d[0] && input[jk-3]==d[1] && input[jk-2]==d[2] && input[jk-1]==d[3] && input[jk-0]==d[4])
            {
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
            jk++;   
           }
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
 /*
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
*/
