#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
LiquidCrystal lcd(7,6,5,4,3,2);
SoftwareSerial mySerial(8,9);

char apple[5]={'c','l','e','a','r',};
char daman[100];
int k=0;
void setup()
{
  lcd.begin(16,2);  
  mySerial.begin(9600);
  lcd.print("     Welcome     ");
  delay(1000);
  lcd.clear();
  lcd.print("   Please speak  ");
  delay(2000);
  lcd.clear();
}

void loop()
{
  if(mySerial.available()>0)
  {
    daman[k]=mySerial.read();
    lcd.print(daman[k]);
    delay(10);
    if(daman[k-4]==apple[0] && daman[k-3]==apple[1] && daman[k-2]==apple[2] && daman[k-1]==apple[3] && daman[k-0]==apple[4])
    {
    lcd.clear();
    k=0;
    }
    k++;
  }
}

