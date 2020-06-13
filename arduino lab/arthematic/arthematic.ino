 int a=2,b=3,result;
 void setup() 
 {
  Serial.begin(9600);
  Serial.println("addition of a and b=");
  result=a+b;
  Serial.println(result);
  delay(2000);
  Serial.println("subtraction of a and b=");
  result=a-b;
  Serial.println(result);
  Serial.println("division of a and b=");
  result=a/b;
  Serial.println(result);
  delay(2000);
  Serial.println("multipication of a and b=");
  result=a*b;
  Serial.println(result);
  delay(2000);
 }
 void loop()
 {
 }
