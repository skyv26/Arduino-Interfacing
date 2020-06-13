#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int l,u;
int t[10];
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
}

void loop()
{
  l=Serial.read(A0);
  if(l>1000)
  {
    u++;
    delay(100);
  } 
  lcd.print("u : ");
  lcd.print(l);
  delay(200);                        
  lcd.clear();
}
