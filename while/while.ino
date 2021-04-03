void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

}

void loop() 
{
  // put your main code here, to run repeatedly:
// Serial.begin(9600);
  if (Serial.available() > 0) 
  {
    long vv = 0;
    long mul = 1;
    while(Serial.available() > 0)
    {
       // read the incoming byte:
       int incomingByte = Serial.read();    
       long c = incomingByte - '0';
       vv = vv + c*mul;
       mul = mul * 10;
       // say what you got:
     }
     Serial.print("I received: ");
     Serial.println(vv, DEC);
   
     computeDelitels(vv);
  }
}

void computeDelitels(long v)
{
 long delitel = 2;
  while(delitel < v) 
  { 
    if(v%delitel == 0) 
    {
      Serial.println(delitel);
    }
    
    if(delitel > 10000)
      break;
 
    delitel +=1;
  }
  Serial.println("Bolshe net");
}


