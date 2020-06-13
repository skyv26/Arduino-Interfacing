int i;
void setup() {

  pinMode(8,INPUT);
  pinMode(9,INPUT);
  for(i=0;i<5;i++)
  {
  pinMode(i,OUTPUT);
  }
}

void loop() {

 if(digitalRead(8)==LOW)
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
    else if(digitalRead(9)==LOW)
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

 else
 {
    for(i=0;i<5;i++)
  {
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
   //   delay(100);
  }
  }
 }
