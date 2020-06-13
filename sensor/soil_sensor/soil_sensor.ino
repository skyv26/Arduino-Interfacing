#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
LiquidCrystal lcd(7,6,5,4,3,2);
SoftwareSerial mySerial(8,9);

float d,e;
void setup()
{
  lcd.begin(16,2);  
  mySerial.begin(19200);
  pinMode(A0,INPUT);
  
}


void loop()
{
  d=analogRead(A0);
  e=((d/1024)*100);
  lcd.print("resist :");
  lcd.print(e);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}

