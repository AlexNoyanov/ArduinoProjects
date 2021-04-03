// Processing and arduino
// Processing: arduino_acc_cube
// Use Accelerometer module
// By Alex Noyanov

int x;
int y;
int z;

// Send Your results like this: 
//  data1,data2|data3.
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Serial port data speed
}

void loop() {
  // put your main code here, to run repeatedly:
x = analogRead(A0);
Serial.println(x); // Serial port output data

Serial.println(".");  // Data transmissions end
//y = analogRead(A1);
//z = analogRead(A2);

}
