#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
//#include<SoftwareSerial.h>
//SoftwareSerial mySerial(10,11);

int a;
void setup()
{
  lcd.begin(16,2);
  lcd.print(" enter value ");
  lcd.setCursor(0,1);
//  mySerial.begin(19200);
  pinMode(A5,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
void loop()
{
 /* if (mySerial.available()>0)
  {
  a=mySerial.read();
  lcd.print(a);
  delay(1000);
  } */
  if (analogRead(A5)==657)
  {
  a=analogRead(A5);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(a);
  digitalWrite(9,1);
  digitalWrite(10,0);
  delay(500);
  } 
  else
  lcd.clear();
  lcd.setCursor(0,1);
  digitalWrite(10,1);
  digitalWrite(9,0);
  lcd.print("error");
  delay(200);
}  
  
