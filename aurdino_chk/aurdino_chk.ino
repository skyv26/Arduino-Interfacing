#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
char p[50];
int store,a,m;
#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);

void setup()
{
  lcd.begin(16,2);
  lcd.print(" enter value ");
  lcd.setCursor(0,1);
  mySerial.begin(19200);
}
void loop()
{ 
k:
      if(mySerial.available() > 0)
      {
        p[m]=mySerial.read();
        lcd.print(p[m]);
        if(p[m]=='~')
        {
        lcd.clear();
        delay(2000);
        lcd.print(p);
        }
        if(p[m]=='_')
        {
          m=0;
          goto k;
        }
        m++;
      }
}
