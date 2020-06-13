int i;
int btn1=1;
int btn2=1;
int btn3=1;
int btn4=1;
int a=0; 
int b1=1;
int b2=2;
int b3=3;
int b4=4;
void setup ()
 { int btn1=1;
   int btn2=1;
   int btn3=1;
   int btn4=1;
    pinMode(b1,INPUT);
    pinMode(b2,INPUT);
    pinMode(b3,INPUT);
    pinMode(b4,INPUT);
    pinMode(5,OUTPUT);
 }
void loop ()
{ 
   btn1=digitalRead(b1);
   btn2=digitalRead(b2);
   btn3=digitalRead(b3);
   btn4=digitalRead(b4);
   if ( btn1==1 && btn2==1 && btn3==0 && btn4==1)
      { a=1;}
   if ( btn1==1 && btn2==0 && btn3==1 && btn4==1 && a==1)
      { a=2; }
   if ( btn1==0 && btn2==1 && btn3==1 && btn4==1 && a==2)
      { a=3; } 
   if ( btn1==1 && btn2==0 && btn3==1 && btn4==1 && a==3)
        { digitalWrite(5,1); }
   if ( btn1==1 && btn2==1 && btn3==1 && btn4==0 && a==3)
        { digitalWrite(5,0);
        }   
}
