void setup ()
{
  for(int pin=2;pin<=11;pin++)
  {pinMode(pin,OUTPUT);}
}
void loop()
{
  randomSeed(analogRead(10));
  if (abs(analogRead(A0)-analogRead(A1)) >100)
  {
    flash(100);
  }
  else
  {
    while (abs(analogRead(A0)-analogRead(A1)) <100)
    {
      int pickme=random(1,10);
       switch(pickme)
        {case 1:
         march(random(20,50));
         break;
        case 2:
         alternate(random(80,100));
         break;
        case 3:
         bullets(random(50,80));
         break;
        case 4:
         radiat(random(80,100));
         break;
        case 5:
         negmarch(random(20,50));
         break;
        case 6:
         stackdots(random(30,50));
         break;
        case 7:
         smash(random(80,100));
         break;
        case 8:
         fadeflash(random(80,100));
         break;
        case 9:
         fadealter(random(80,100));
         break;}
    }
  }
}
 void clearall()
   {
     for(int pin=2;pin<=11;pin++)
     {
       digitalWrite(pin,LOW);
     }
   }
 void fillall()
   {
     for(int pin=2;pin<=11;pin++)
     {
       digitalWrite(pin,HIGH);
     }
   }
 void march(int delaytime)
   {
     
     for(int pin=2;pin<=11;pin++)
     {
       clearall;
       digitalWrite(pin,HIGH);
       delay(delaytime);
     }
     for(int pin=10;pin>=2;pin--)
     {
       clearall;
       digitalWrite(pin,HIGH);
       delay(delaytime); 
     }
   }
  void negmarch(int delaytime)
   {
     
     for(int pin=2;pin<=11;pin++)
     {
       fillall;
       digitalWrite(pin,LOW);
       delay(delaytime);
     }
     for(int pin=10;pin>=2;pin--)
     {
       fillall;
       digitalWrite(pin,LOW);
       delay(delaytime); 
     }
   }
  void flash (int delaytime)
  {
    for (int i=1;i<=5;i++)
    {
    clearall;
    delay(delaytime);
    fillall;
    delay(delaytime);
    }
  }
 void fadeflash(int delaytime)
   {
     clearall();
     int newdelay=delaytime/5;
     for(int fade=0;fade<=255;fade+=5)
     {
      for (int pin=2;pin<=11;pin++)
      {
       analogWrite(pin,fade);
      }
      delay(newdelay);
     }
     for(int fade=255;fade>=0;fade-=5)
     {
      for (int pin=2;pin<=11;pin++)
      {
       analogWrite(pin,fade);
      }
      delay(newdelay);
     }
   }
  void fadealter(int delaytime)
    {
      clearall();
     int newdelay=delaytime/5;
     for(int fade=0;fade<=255;fade+=5)
     {
      for (int i=2;i<=10;i++)
      {
       analogWrite(i,fade);
      }
      for (int j=3;j<=11;j++)
      {
       analogWrite(j,255-fade);
      }
      delay(newdelay);
     }
     for(int fade=255;fade>=0;fade-=5)
     {
      for (int pin=2;pin<=11;pin+=2)
      {
       analogWrite(pin,fade);
      }
      for (int pin2=2;pin2<=11;pin2+=2)
      {
       analogWrite(pin2,fade);
      }
      delay(newdelay);
     }
    }
  void alternate(int delaytime)
    {
      for (int n=1;n<=5;n++)
      {
        clearall();
        for (int i=2;i<=10;i+=2)
        {
         digitalWrite(i,HIGH);
        }
        delay(delaytime);
        clearall();
        for (int j=3;j<=11;j+=2)
        {
         digitalWrite(j,HIGH);
        }
        delay(delaytime);
      }
    }
  void bullets(int delaytime)
    {
      for (int n=2;n<=26;n++)
      {
       clearall();
       if (n<13)
       {
         drawbullet(n);
       }
       if (n>=8&&n<21)
       {
         drawbullet(n-6);
       }
       if (n>=14&&n<29)
       {
         drawbullet(n-18);
       }
      }
    }
  void drawbullet(int pos)
    {
      switch (pos)
      {
        case 2:
          digitalWrite(2,HIGH);
          break;
        case 3:
          digitalWrite(2,HIGH);
          analogWrite(3,round(255/10));
          break;
        case 12:
          digitalWrite(10,HIGH);
          analogWrite(11,round(255/10));
          break;
        case 13:
          digitalWrite(11,HIGH);
          break;
        default:
          digitalWrite(pos,HIGH);
          analogWrite(pos-1,round(255/10));
          analogWrite(pos-2,round(255/10));
          break;
      }
    }
 void radiat(int delaytime)
    {
      for(int n=7;n<28;n++)
      {
        clearall();
        if (n<12)
         {
           drawray(n);
         }
        if (n>=10&&n<=14)
         {
           drawray(n-3);
         }
        if (n>=13&&n<=17)
         {
           drawray(n-6);
         }
        if (n>=16&&n<=20)
         {
           drawray(n-9);
         }
        if (n>=19&&n<=23)
         {
           drawray(n-12);
         }
        if (n>=22&&n<=26)
         {
           drawray(n-15);
         }
        delay(delaytime);
      }
    }
  void drawray(int pos)
    {
      int factor=5;
      analogWrite(pos,round(255*((pow(7,factor))/(pow(pos,factor)))));
      analogWrite(2+(11-pos),round(255*((pow(7,factor))/(pow(pos,factor)))));
    }
  void stackdots(int delaytime)
   {
     int stack=0;
     while (stack<10)
     {
       for (int pos=2;pos<=(11-stack);pos++)
       {
         clearall();
         digitalWrite(pos,HIGH);
         drawstack;
         delay (delaytime);
       }
       stack++;
     }
   }
 void drawstack(int stack)
   {
     for(int n=11; n>(11-stack);n--)
     {
       if (n>=2)
       {
         digitalWrite(n,HIGH);
       }
     }
   }
 void smash(int delaytime)
   {
     int time;
     int div=20;
     int flashtime=delaytime/div;
     int A=random(2,7);
     int B=random(7,12);
     int Av=1;
     int Bv=1;
    if (random(0,2))
       {
         Av*=-1; 
       }
    if (random(0,2))
       {
         Bv*=-1; 
       }
    for ( time=1 ; time<50 ; time++ )
     {
       if(abs(A-B)==1&&(Av*Bv)==-1)
        {
          for (int f=1;f<round(div/4);f++)
          {
            clearall();
            delay(flashtime);
            digitalWrite(A,HIGH);
            digitalWrite(B,HIGH);
            delay(flashtime);
          }
          Av*=-1;
          Bv*=-1;
          A+=Av;
          B+=Bv;
        }       
      else
       {
         clearall();
         digitalWrite(A,HIGH);
         digitalWrite(B,HIGH);
         A+=Av;
         B+=Bv;
         delay(delaytime);
       }  
     if(A<2)
       {
         A=3;
         Av*=-1; 
       }
     if(B>11)
       {
         B=10;
         Bv*=-1; 
       }
      if(A>=B)
       {
         A=B-1; 
       } 
     }
   }
   
   
