#include<LiquidCrystal.h>
char i[100],j[15];
char b[5]={'c','l','e','a','r'};
char ok[2]={'o','k'};
char h[4]={'s','t','o','p'};
char d[6]={'s','c','r','o','l','l'};
int k,c,l,m;

LiquidCrystal lcd(7,6,5,4,3,2);
#include<SoftwareSerial.h>
SoftwareSerial a(10,11);
void setup()
{
  a.begin(19200);
  lcd.begin(16,2);
  lcd.print("    welcome    ");
  delay(1000);
  lcd.clear();
}

void loop()
{
x:
  if(a.available()>0)
  { 
    
    i[k]=a.read();
    if(k>=16&&k<35)
    {
      c=k-17;
      lcd.setCursor(c,1);
    }
    if (c==17)
    {
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      c=0;
    }  
    lcd.print(i[k]);    
    if(i[k-4]==b[0] && i[k-3]==b[1] && i[k-2]==b[2] && i[k-1]==b[3] && i[k-0]==b[4])
    {
      lcd.clear();
      k=0;
    }
    if(i[k-5]==d[0] && i[k-4]==d[1] && i[k-3]==d[2] && i[k-2]==d[3] && i[k-1]==d[4] && i[k-0]==d[5])
    {
      lcd.clear();
      lcd.print("  please speak");
      lcd.setCursor(0,1);
      m=scroll();
      if (m==3)
       { 
         lcd.clear();
         while(1)
         {
          for(int r=16;r>-42;r--)
           {  
             if(r<0)
              r-=10;
             if(a.available()>0)
             {
               i[k]=a.read();
               if(i[k-3]==h[0] && i[k-2]==h[1] && i[k-1]==h[2] && i[k-0]==h[3])
               
               m=0;
               goto x;
               k++;
             }
            lcd.setCursor(r,0);
            lcd.print(j);
            delay(50);
           }
           lcd.clear();
         }
       }
      l=0;
    }
    
    delay(10);
    k++;
  }
}

int scroll()
{
  while(1)
  {
    if(a.available()>0)
    {
     i[k]=a.read();
     lcd.print(i[k]);     
     if(i[k-1]==ok[0] && i[k-0]==ok[1])
     {
       j[l-1]=' ';
       j[l]=' ';
       return 3;
     }
     j[l]=i[k];
     delay(200);
     l++;
     k++;
    }
  }
}

