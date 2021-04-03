void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
 int x[10];
 for(int i = 0; i < 10; i++)
 {
   x[i] = random(100);
   Serial.println(x[i]);
 }
 int minim = x[0];
 int maxim = x[0];
 for(int i = 1; i < 10; i++)
 {
   if(x[i] > maxim)
     maxim = x[i];
 }
  for(int i = 0; i < 10; i++)
  {
   if(x[i] < minim)
     minim = x[i];
 }
  Serial.print("max=");
   Serial.println(maxim);
   Serial.print("Min=");
   Serial.println(minim);
   
   Serial.println("Sort");
   int j = 0;
   while(j < 9)
   {
     if(x[j] > x[j+1])
     {
        swap(x[j], x[j+1]);
        if(j > 0)
          j--;
     } else {
       j++;
     }
       
   }   
   for(int f = 0; f<10; f++)
   { 
     Serial.println(x[f]);
   }
delay(10000);
}

void swap(int& a, int& b)
{
  int x = a;
  a = b;
  b = x;
  
  
}

 
