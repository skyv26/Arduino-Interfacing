int i; 
void setup() 
{
  for(i=0;i<5;i++)
  {
    pinMode(i,OUTPUT);

  }
}

void loop() 
{
  for(i=0;i<=4;i++)
  {
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
    delay(200);
  }
  for(i=3;i>=1;i--)
   {
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
    delay(200);
   }
}
