sssssssssssssss/* 
 * Project Galactic_Ecliptic_Equatorial_Extrapolation_and_Positiong_System
 * Author: Benjamin Brown
 * Date: 08022025
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */


#include "Particle.h"
#include "neopixel.h"
#include "math.h"

const float SAG_A_RA = 266.4;
const float SAG_A_DEC = 29.0;

unsigned int uni_tc;
unsigned int green_st;
unsigned int local_st;


unsigned float hour_Ang;
unsigned float local_Long;
unsigned float julian_days;
unsigned float X_Ang;
unsigned float Y_Ang;
unsigned float Z_Ang;




SYSTEM_MODE(AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor.SerialIsConnecteed(10000);

  Wire.begin();

}

void loop() {

}

float julianDate_Converter(int year, int month, int day, float uni_T){
  float JD;
  const float JD_DAY_CONST=367.0;
  const float MONTH_SHIFT = 275.0;
  const float JD_SHIFT_CONST = 1721013.5;

  JD= (JD_DAY_CONST*year)-(7*(year
  +floor(month+9.0)/12.0)/4.0)
  +floor((MONTH_SHIFT*month)/9.0)
  +day
  +JD_SHIFT_CONST
  +(uni_T/24.0);
  
  
  //(((7*(year+floor((month+9)/12)))/4)+(floor((MONTH_SHIFT*month)/9))+day+JD_SHIFT_CONST+(uni_T/24));
  return JD;

 }