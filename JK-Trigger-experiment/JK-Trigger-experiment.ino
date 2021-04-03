// JK-Trigger experiments

// By Alexander Noyanov
// The 21st of September 2019


// Experiment 1: JK-Trigger working in RS mode
int pinR = 2;
int pinS = 3;
int pinC = 4;

int counter = 0;

void genImpuls(int t,int pin){    // Generating impulses o the following pin
  if(t%2){
    digitalWrite(pin,HIGH);
  }else{
    digitalWrite(pin,LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
pinMode(pinR,OUTPUT);
pinMode(pinS,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if(counter > 10000){
  counter == 0;
}
genImpuls(counter,pinC);    // Impulses on the pin C

delay(100);                 // Waiting 100 miliseconds (0,1 second) 
counter++;
}
