#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int l=0;
float cel;
float perc,k;
void setup() {

  lcd.begin(16,2);
  pinMode(A0,INPUT);

}

void loop() {

 l=analogRead(A0);
 perc = 1023.99*100;
 lcd.clear();
 perc/=l;
 cel = perc/4.0392 ; 
 delay(700);
 lcd.print(cel);
 delay(2000);

}
