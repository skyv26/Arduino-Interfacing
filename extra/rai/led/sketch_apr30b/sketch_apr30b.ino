int i,J;
void setup()
{
  for(i=0;i<=5;i++)
  {
    pinMode(i,OUTPUT);
  }
  
  for(J=6;J<=9;J++)
  {
  pinMode(J,INPUT);
  }
}

void loop()
{
  if(digitalRead(6)==LOW)
  {
    digitalWrite(0,HIGH);
    digitalWrite(4,HIGH);
    for(i=1;i<=3;i++)
    {
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
      delay(100);
     }
   }
  else if(digitalRead(7)==LOW)
  {
     for(i=0;i<5;i++)
     {
     digitalWrite(i,HIGH);
     digitalWrite(5-i,HIGH);
     delay(200);
     digitalWrite(i,LOW);
     digitalWrite(5-i,LOW);
      }
  } 
  else if(digitalRead(8)==LOW)
  {
      for(i=0;i<5;i++)
  {
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
  }
  }
  else if(digitalRead(9)==LOW)
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
  else
  {
    for(i=0;i<=5;i++)
    {
      digitalWrite(i,LOW);
    }
  }
 }
  

