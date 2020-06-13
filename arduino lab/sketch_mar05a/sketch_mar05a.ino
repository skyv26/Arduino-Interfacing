int i;
int btn1=1;
int btn2=1;
int btn3=1;
int btn4=1;
int a=0; 
void setup ()
 { int btn1=1;
   int btn2=1;
   int btn3=1;
   int btn4=1;
   for(i=1;1<=4;i++)
    pinMode(i,INPUT);
    pinMode(5,OUTPUT);
 }
void loop ()
{ 
   btn1=digitalRead(1);
   btn2=digitalRead(2);
   btn3=digitalRead(3);
   btn4=digitalRead(4);
   if ( btn1==0 && btn2==1 && btn3==1 && btn4==1)
    { a=1 ;}
   if ( btn1==1 && btn2==0 && btn3==1 &&btn4==1 && a==1)
     { a=2; }
   if ( btn1==1 && btn2==1 && btn3==0 && btn4==1 && a==2)
      { a=3; } 
   if ( btn1==1 && btn2==1 && btn3==1 && btn4==0 && a==3)
        {
          digitalWrite(5,HIGH);
        }
}
    
