#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
char a;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
int i,j;
void setup()
{
 mySerial.begin(19200);
 lcd.begin(16,2);
 //lcd.print(" "); 
}
void loop()
{

if(mySerial.available())
{
 j=mySerial.read();
 if(j=='!')
 lcd.clear();
 if(j==10 || j==13 || j==32)
 {
   
 }
 else
 {
  a=j;
 if(j!='!') 
 lcd.print(a);
 delay(100);
 }
}
}
