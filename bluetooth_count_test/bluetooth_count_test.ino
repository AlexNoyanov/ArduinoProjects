
int count = 0;
 
void setup() {
  Serial.begin(9600);
  Serial.println("Test Arduino + Bluetooth. http://tim4dev.com");
}
 
void loop() {
  count++;
  Serial.print("Count = ");
  Serial.println(count);
  delay(1000);
}
