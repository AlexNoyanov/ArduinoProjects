/*
Date : 21/02/2010
Projet : Arduino + nunchuck + Processing
*/
#include <Wire.h>

void setup(){
  Serial.begin(19200);
  nunchuck_init_with_power();
  nunchuck_init();
}

void loop(){
  nunchuck_get_data();
  nunchuck_print_data();
}

static uint8_t nunchuck_buf[6];   // zone de données du nunchuck

// Initialisation du system I2C pour communiquer avec le nunchuck
static void nunchuck_init()
{
  Wire.begin();                
  Wire.beginTransmission(0x52);
  Wire.write(0x40);// Adresse Mémoire
  Wire.write(0x00);// effectue un envoi à 0  
  Wire.endTransmission();
}


static void nunchuck_init_with_power_pins(byte pwrpin, byte gndpin)
{
  DDRC |= _BV(pwrpin) | _BV(gndpin);  
  PORTC &=~ _BV(gndpin);
  PORTC |=  _BV(pwrpin);
  delay(100);  // attente pour stabilisatio

  nunchuck_init();
}

// A appeler quand le nunchuck est connecté© directement à  Arduino
static void nunchuck_init_with_power()
{
nunchuck_init_with_power_pins(PORTC3,PORTC2);
}

// Envoi d'une requête pour obtenir les données du nunchuck
static void nunchuck_send_request()
{
  Wire.beginTransmission(0x52);
  Wire.write(0x00);
  Wire.endTransmission();
}

// Encode les données du nunchuck
static char nunchuk_decode_byte (char x)
{
  x = (x ^ 0x17) + 0x17;
  return x;
}

// Réception des données du nunchuck
// retourne 1 si ok, sinon 0
static int nunchuck_get_data()
{
  int cnt=0;
  Wire.requestFrom (0x52, 6);
  while (Wire.available ()) {
    nunchuck_buf[cnt] = nunchuk_decode_byte(Wire.read());
    cnt++;
  }
  nunchuck_send_request();  
  
  if (cnt >= 5) {
    return 1;   // ok
  }
  return 0; // ko
}

static void nunchuck_print_data()
{
  static int i=0;
  int joy_x_axis = nunchuck_buf[0];
  int joy_y_axis = nunchuck_buf[1];
  int accel_x_axis = nunchuck_buf[2]; // * 2 * 2; 
  int accel_y_axis = nunchuck_buf[3]; // * 2 * 2;
  int accel_z_axis = nunchuck_buf[4]; // * 2 * 2;

  int z_button = 0;
  int c_button = 0;

  // byte nunchuck_buf[5] contient les bits pour les boutons z et c
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

  Serial.print(joy_x_axis,DEC);
  Serial.print(",");
  Serial.print(joy_y_axis, DEC);
  Serial.print(",");
  Serial.print(accel_x_axis, DEC);
  Serial.print(",");
  Serial.print(accel_y_axis, DEC);
  Serial.print(",");
  Serial.print(accel_z_axis, DEC);

  Serial.println();  
}
