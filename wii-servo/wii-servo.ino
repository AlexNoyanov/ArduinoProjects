/*
* Nunchuck
* Language - Arduino
* 2009 Ty Huffman, 5th & Penn, www.5thandpenn.com/blog.
*
* 2007 Tod E. Kurt, http://todbot.com/blog/
*
* The Wii Nunchuck reading code is taken from Windmeadow Labs
* http://www.windmeadow.com/node/42
*/

// simple servo controller

//#include

Servo servoX; // create servo object to control a servo in the X plane
Servo servoY; // create servo object to control a servo in the Y plane

int val = 0; // variable to store the servo position
int potpin = 0; // analog pin used to connect the potentiometer

//#include 
#include "WProgram.h"
//#include

// these may need to be adjusted for each nunchuck for calibration
#define ZEROX 122 // 139
#define ZEROY 132 // 490
#define ZEROZ 191 // 460
#define RADIUS 40 // probably pretty universal
#define joyXmax 99
#define joyXmin 100
#define joyYmax 90
#define joyYmin 103
#define pwmMax 255

#define DEFAULT_ZERO_JOY_X 129
#define DEFAULT_ZERO_JOY_Y 132

#define NUMREADINGS 6
#define DEBOUNCE 10.00

float gutter = DEBOUNCE - 0.01;

int smoothingArray = NUMREADINGS;
int delayTime = 10;

int joy_x_axis;
int joy_y_axis;
int joyXscaled;
int joyYscaled;
int joyXneg;
int joyXpos;
int joyYneg;
int joyYpos;
int valXpos;
int valYpos;
int valXneg;
int valYneg;

// int accelGX
int accel_x_axis;
int accel_y_axis;
int accel_z_axis;

int z_button = 0;
int c_button = 0;

int readingsX[NUMREADINGS];
int readingsY[NUMREADINGS];
int readingsZ[NUMREADINGS];
int indexX = 0; // the index of the current reading of X
int indexY = 0; // the index of the current reading of Y
int indexZ = 0; // the index of the current reading of Z
int totalX = 0; // the running total of X
int totalY = 0; // the running total of Y
int totalZ = 0; // the running total of Z
int averageX = 0; // the average X
int averageY = 0; // the average Y
int averageZ = 0; // the average Z
int avgAccelX = 0;
int avgAccelY = 0;
int avgAccelZ = 0;

float oldReadAccelX = 0.0;
float oldReadAccelY = 0.0;
float oldReadAccelZ = 0.0;

int value = 0; // variable to keep the actual value
int ledpinB = 3; // light connected to digital pin 3
int ledpinR = 11; // light connected to digital pin 11
int ledpinY = 5; // light connected to digital pin 5
int ledpinG = 6; // light connected to digital pin 6

void setup()
{
Serial.begin(9600); // was 115200
nunchuck_setpowerpins(); // use analog pins 2&3 as fake gnd & pwr
nunchuck_init(); // send the initilization handshake
Serial.print ("Finished setup\n");
int readings[smoothingArray]; // the smoothing array
for (int i = 0; i < smoothingArray; i++) readingsX[i] = 0; for (int i = 0; i < smoothingArray; i++) readingsY[i] = 0; for (int i = 0; i < smoothingArray; i++) readingsZ[i] = 0; servoX.attach(10); // attaches the servo on pin 10 to the servo object servoY.attach(9); // attaches the servo on pin 9 to the servo object } // // Nunchuck functions // static uint8_t nunchuck_buf[6]; // array to store nunchuck data, // Uses port C (analog in) pins as power & ground for Nunchuck static void nunchuck_setpowerpins() { #define pwrpin PORTC3 #define gndpin PORTC2 DDRC |= _BV(pwrpin) | _BV(gndpin); PORTC &=~ _BV(gndpin); PORTC |= _BV(pwrpin); delay(100); // wait for things to stabilize } // initialize the I2C system, join the I2C bus, // and tell the nunchuck we're talking to it void nunchuck_init() { Wire.begin();  // join i2c bus as master Wire.beginTransmission(0x52); // transmit to device 0x52 Wire.send(0x40); // sends memory address Wire.send(0x00);  // sends sent a zero. Wire.endTransmission(); // stop transmitting } // Send a request for data to the nunchuck // was "send_zero()" void nunchuck_send_request() { Wire.beginTransmission(0x52); // transmit to device 0x52 Wire.send(0x00); // sends one byte Wire.endTransmission(); // stop transmitting } void loop() { nunchuck_get_data(); nunchuck_print_data(); // val = analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023) // val = map(val, 0, 1023, 0, 179); // scale it to use it with the servo (value between 0 and 180) // myservo.write(val); // sets the servo position according to the scaled value delay(delayTime); // waits for the servo to get there } // Receive data back from the nunchuck, int nunchuck_get_data() { int cnt=0; Wire.requestFrom (0x52, 6);  // request data from nunchuck while (Wire.available ()) { // receive byte as an integer nunchuck_buf[cnt] = nunchuk_decode_byte(Wire.receive()); cnt++; } nunchuck_send_request(); // send request for next data payload // If we recieved the 6 bytes, then go print them if (cnt >= 5) {
return 1; // success
}
return 0; //failure
}

// Print the input data we have recieved
// accel data is 10 bits long
// so we read 8 bits, then we have to add
// on the last 2 bits. That is why I
// multiply them by 2 * 2

void nunchuck_print_data()
{
static int i=0;

float joyX = (nunchuck_buf[0] - DEFAULT_ZERO_JOY_X);
float joyY = (nunchuck_buf[1] - DEFAULT_ZERO_JOY_Y);
// float joyXposRange = joyXmax - DEBOUNCE;
float joyXs = (joyX); //100 * 255;
float joyYs = (joyY); //100 * 255;
int accel_x_axis = nunchuck_buf[2]; // * 2 * 2;
int accel_y_axis = nunchuck_buf[3]; // * 2 * 2;
int accel_z_axis = nunchuck_buf[4]; // * 2 * 2;

// byte nunchuck_buf[5] contains bits for z and c buttons
// it also contains the least significant bits for the accelerometer data
// so we have to check each bit of byte outbuf[5]
if ((nunchuck_buf[5] >> 0) & 1)
z_button = 1;
if ((nunchuck_buf[5] >> 1) & 1)
c_button = 1;

if ((nunchuck_buf[5] >> 2) & 1)
accel_x_axis += 2;
if ((nunchuck_buf[5] >> 3) & 1)
accel_x_axis += 1;

if ((nunchuck_buf[5] >> 4) & 1)
accel_y_axis += 2;
if ((nunchuck_buf[5] >> 5) & 1)
accel_y_axis += 1;

if ((nunchuck_buf[5] >> 6) & 1)
accel_z_axis += 2;
if ((nunchuck_buf[5] >> 7) & 1)
accel_z_axis += 1;

// Serial.print(i,DEC);
// Serial.print("\t");
// int accelGX = accel_x_axis;
float readAccelX = accel_x_axis - ZEROX;
float readAccelY = accel_y_axis - ZEROY;
float readAccelZ = accel_z_axis - ZEROZ;
int accelDiffX = readAccelX - oldReadAccelX;
int accelDiffY = readAccelY - oldReadAccelY;
int accelDiffZ = readAccelZ - oldReadAccelZ;

// int joyX = (joyX / 100 * 255);
// int joyY = (joyY / 100 * 255);

// int joyXs = (joyX / 100 * 255);
// int joyYs = (joyY / 100 * 255);

// average X if value of X differs by more than 5
if (abs(accelDiffX) > 2) {
// delayTime = 12;
totalX -= readingsX[indexX]; // subtract the last reading
readingsX[indexX] = readAccelX; // read from the X value
totalX += readingsX[indexX]; // add the reading to the total
indexX = (indexX + 1); // advance to the next index

if (indexX >= smoothingArray) // if we're at the end of the array...
indexX = 0; // ...wrap around to the beginning

averageX = totalX / NUMREADINGS; // calculate the average
avgAccelX = averageX; // set accel X reading to average
oldReadAccelX = avgAccelX; // set old reading to new reading for future compare
// delayTime = 30; // reset delay time
}

// average Y if value of Y differs by more than 5
if (abs(accelDiffY) > 2) {
delayTime = 12;
totalY -= readingsY[indexY]; // subtract the last reading
readingsY[indexY] = readAccelY; // read from the X value
totalY += readingsY[indexY]; // add the reading to the total
indexY = (indexY + 1); // advance to the next index

if (indexY >= smoothingArray) // if we're at the end of the array...
indexY = 0; // ...wrap around to the beginning

averageY = totalY / NUMREADINGS; // calculate the average
avgAccelY = averageY; // set accel Y reading to average
oldReadAccelY = avgAccelY; // set old reading to new reading for future compare
// delayTime = 30; // reset delay time
}

// average Z if value of Z differs by more than 5
if (abs(accelDiffZ) > 2) {
delayTime = 12;
totalZ -= readingsZ[indexZ]; // subtract the last reading
readingsZ[indexZ] = readAccelZ; // read from the X value
totalZ += readingsZ[indexZ]; // add the reading to the total
indexZ = (indexZ + 1); // advance to the next index

if (indexZ >= smoothingArray) // if we're at the end of the array...
indexZ = 0; // ...wrap around to the beginning

averageZ = totalZ / NUMREADINGS; // calculate the average
avgAccelZ = averageZ; // set accel Y reading to average
oldReadAccelZ = avgAccelZ; // set old reading to new reading for future compare
}
// I could never get this to work correctly
// cos should not be used because at one point or another it will approach
// 0 divided a number which will cuase big problems, not stable.
// I chose to use the smoothing of a low pass filter to make it work rather than cos.
// int readRoll = -1*(cos(readAccelX) / M_PI * 180.0); // used to have , readAccelZ
// int R = sqrt(readAccelX * readAccelX + readAccelY * readAccelY + readAccelZ * readAccelZ);
// int readPitch = -1*(cos(readAccelY/R)/ M_PI * 180.0); // optionally swap 'RADIUS' for 'R()'

int roller = avgAccelX * 2;

int pitcher = avgAccelY * 2;

if (pitcher > 100) pitcher = 110;
if (pitcher < -100) pitcher = -110; if (roller > 100) roller = 110;
if (roller < -100) roller = -110; // Serial.print("acc:"); Serial.print(roller, DEC); // used to be accel_x_axis Serial.print(", "); Serial.print(pitcher, DEC); // used to be accel_y_axis Serial.print(", "); Serial.print(avgAccelX, DEC); // used to be accel_z_axis, Serial.print(", "); // Serial.print("\t"); // Serial.print("joy:"); Serial.print(avgAccelY, DEC); // used to be joy_x_axis, Serial.print(", "); Serial.print(avgAccelZ, DEC); // used to be joy_y_axis, // Serial.print(" Joy X Y "); // Serial.print(joyX); // Serial.print(", "); // Serial.print(joyY); // Serial.print(", "); // int joyX = ((joyX / 100) * 255); // int joyY = ((joyY / 100) * 255); // Serial.print("values scaled "); // Serial.print(joyXs); // Serial.print(" , "); // Serial.print(joyYs); // compute the X values and get the output stable if (joyXs >= DEBOUNCE) {
joyXpos = joyXs;
valXpos = joyXpos;
valXpos = pwmMax*((valXpos - DEBOUNCE)/(joyXmax - DEBOUNCE));
if (valXpos >= 255) {
valXpos = 255; }
analogWrite(ledpinB, valXpos); // sets the value (range from 0 to 255)
analogWrite(ledpinR, 0);
val = valXpos;
val = map(val, 0, 255, 91, 179); // scale it to use it with the servo (value between 0 and 180)
servoX.write(val); // sets the servo position according to the scaled value
}

if (joyXs <= -DEBOUNCE) { joyXneg = joyXs; // Serial.print(" joyXs "); // Serial.print(joyXs); int valXneg = -1 * joyXneg; // Serial.print(" valXneg "); // Serial.print(valXneg); valXneg = pwmMax*((valXneg - DEBOUNCE)/(joyXmin - DEBOUNCE)); // Serial.print(" newValXneg "); // Serial.print(valXneg); if (valXneg >= 255) {
valXneg = 255; }
analogWrite(ledpinR, valXneg); // sets the value (range from 0 to 255)
analogWrite(ledpinB, 0);
val = valXneg;
val = map(val, 0, 255, 89, 1); // scale it to use it with the servo (value between 0 and 180)
servoX.write(val); // sets the servo position according to the scaled value
}

if (joyXs < gutter && joyXs > -gutter) {
valXpos = 0;
valXneg = 0;
analogWrite(ledpinB, valXpos);
analogWrite(ledpinR, valXneg);
val = 90; // setting the servo to home 90 degree position
servoX.write(val); // sets the servo position according to the scaled value
}

// Do the Y values like we did the x values

if (joyYs >= DEBOUNCE) {
joyYpos = joyYs;
valYpos = joyYpos;
valYpos = pwmMax * (valYpos - DEBOUNCE) / (joyYmax - DEBOUNCE);
if (valYpos >= 255) {
valYpos = 255; }
analogWrite(ledpinG, valYpos); // sets the value (range from 0 to 255)
analogWrite(ledpinY, 0);
val = valYpos;
val = map(val, 0, 255, 91, 179); // scale it to use it with the servo (value between 0 and 180)
servoY.write(val); // sets the servo position according to the scaled value
}

// Serial.print(" valYpos");
// Serial.print(", ");
// Serial.print(valYpos);

if (joyYs <= -DEBOUNCE) { joyYneg = joyYs; // Serial.print(" joyYs "); // Serial.print(joyYs); int valYneg = -1 * joyYneg; // Serial.print(" valYneg "); // Serial.print(valYneg); valYneg = pwmMax * (valYneg - DEBOUNCE) / (joyYmin - DEBOUNCE); // Serial.print(" NewValYneg "); // Serial.print(valYneg); if (valYneg >= 255) {
valYneg = 255; }
analogWrite(ledpinY, valYneg); // sets the value (range from 0 to 255)
analogWrite(ledpinG, 0);
val = valYneg;
val = map(val, 0, 255, 89, 1); // scale it to use it with the servo (value between 0 and 180)
servoY.write(val); // sets the servo position according to the scaled value
}

// Serial.print(" valYneg");
// Serial.print(", ");
// Serial.print(valYneg);

if (joyYs < gutter && joyYs > -gutter) {
valYpos = 0;
valYneg = 0;
analogWrite(ledpinY, valYpos);
analogWrite(ledpinG, valYneg);
val = 90; // setting the servo to home 90 degree position
servoY.write(val);
}

// Serial.print(" \t");
// Serial.print(", ");
// Serial.print(accel_x_axis, DEC); // used to be joy_x_axis,
// Serial.print(", ");
// Serial.print(accel_y_axis, DEC); // used to be joy_y_axis,

// Serial.print("but:");
// Serial.print(z_button, DEC);
// Serial.print(",");
// Serial.print(c_button, DEC);
Serial.println();
// Serial.print("\r\n"); // newline
i++;

// for(value = 0 ; value <= 255; value+=5) // fade in (from min to max) // { // analogWrite(ledpin, valXpos); // sets the value (range from 0 to 255) // delay(3); // waits for 30 milli seconds to see the dimming effect // } } // Encode data to format that most wiimote drivers except // only needed if you use one of the regular wiimote drivers char nunchuk_decode_byte (char x) { x = (x ^ 0x17) + 0x17; return x; }

Here is the code for the Processing sketch - Spinning Cube

/**
* Spinning Cube
* Language Processing
*
* wii controlled RGB Cube.
*
* The three primary colors of the additive color model are red, green, and blue.
* This RGB color cube displays smooth transitions between these colors.
*/

float xmag, ymag = 0;
float newXmag, newYmag = 0;
int sensorCount = 5; // number of values to expect

import processing.serial.*;
Serial myPort; // The serial port

int BAUDRATE = 9600; // was 115200
char DELIM = ','; // the delimeter for parsing incoming data

void setup()
{
size(600, 600, P3D); // was 200, 200
noStroke();
colorMode(RGB, 1);
myPort = new Serial(this, Serial.list()[0], BAUDRATE);
// clear the serial buffer:
myPort.clear();

}
float x, z;

void draw()
{
background(0.5, 0.5, 0.45);

pushMatrix();

translate(width/2, height/2, -30);

newXmag = mouseX/float(width) * TWO_PI;
newYmag = mouseY/float(height) * TWO_PI;

float diff = xmag-newXmag;
if (abs(diff) > 0.01) {
xmag -= diff/4.0;
}

diff = ymag-newYmag;
if (abs(diff) > 0.01) {
ymag -= diff/4.0;
}

// if ((sensorValues[1] > 15) && (sensorValues[1] < 165)) { z = sensorValues[0] / 180 * PI ; x = sensorValues[1] / 180 * PI; // } rotateZ(z); rotateX(x); scale(100); beginShape(QUADS); fill(0, 1, 1); vertex(-1, 1, 1); fill(1, 1, 1); vertex( 1, 1, 1); fill(1, 0, 1); vertex( 1, -1, 1); fill(0, 0, 1); vertex(-1, -1, 1); fill(1, 1, 1); vertex( 1, 1, 1); fill(1, 1, 0); vertex( 1, 1, -1); fill(1, 0, 0); vertex( 1, -1, -1); fill(1, 0, 1); vertex( 1, -1, 1); fill(1, 1, 0); vertex( 1, 1, -1); fill(0, 1, 0); vertex(-1, 1, -1); fill(0, 0, 0); vertex(-1, -1, -1); fill(1, 0, 0); vertex( 1, -1, -1); fill(0, 1, 0); vertex(-1, 1, -1); fill(0, 1, 1); vertex(-1, 1, 1); fill(0, 0, 1); vertex(-1, -1, 1); fill(0, 0, 0); vertex(-1, -1, -1); fill(0, 1, 0); vertex(-1, 1, -1); fill(1, 1, 0); vertex( 1, 1, -1); fill(1, 1, 1); vertex( 1, 1, 1); fill(0, 1, 1); vertex(-1, 1, 1); fill(0, 0, 0); vertex(-1, -1, -1); fill(1, 0, 0); vertex( 1, -1, -1); fill(1, 0, 1); vertex( 1, -1, 1); fill(0, 0, 1); vertex(-1, -1, 1); endShape(); popMatrix(); } float[] sensorValues = new float[sensorCount]; // array to hold the incoming values void serialEvent(Serial myPort) { // read incoming data until you get a newline: String serialString = myPort.readStringUntil('\n'); // if the read data is a real string, parse it: if (serialString != null) { println(serialString); println(serialString.charAt(serialString.length()-3)); println(serialString.charAt(serialString.length()-2)); // split it into substrings on the DELIM character: String[] numbers = split(serialString, DELIM); // convert each subastring into an int if (numbers.length == sensorCount) { for (int i = 0; i < numbers.length; i++) { // make sure you're only reading as many numbers as // you can fit in the array: if (i <= sensorCount) { // trim off any whitespace from the substring: numbers[i] = trim(numbers[i]); sensorValues[i] = float(numbers[i]); } // Things we don't handle in particular can get output to the text window print(serialString); } } } }
