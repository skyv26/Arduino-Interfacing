int i=0;
int j=1;
int k=13;
int statu=0;
void setup() {

 pinMode(i,INPUT);
 pinMode(j,INPUT);
 pinMode(k,OUTPUT);
}

void loop() {


  if(digitalRead(i)==0)
  {
    statu=1;
    digitalWrite(k,HIGH);
  }
  else if(digitalRead(j)==0)
  {
    statu=0;
    digitalWrite(k,LOW);
  }
  else
  {
    digitalWrite(k,statu);
  }
}
