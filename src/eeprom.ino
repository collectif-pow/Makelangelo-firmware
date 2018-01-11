//------------------------------------------------------------------------------
// Makelangelo - firmware for various robot kinematic models
// dan@marginallycelver.com 2013-12-26
// Copyright at end of file.  Please see
// http://www.github.com/MarginallyClever/makelangeloFirmware for more information.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// INCLUDES
//------------------------------------------------------------------------------
#include <EEPROM.h>
#include <Arduino.h>  // for type definitions


/** 
 * from http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1234477290/3
 */
void EEPROM_writeLong(int ee, long value) {
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++)
  EEPROM.write(ee++, *p++);
}


/** 
 * from http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1234477290/3
 */
float EEPROM_readLong(int ee) {
  long value = 0;
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++)
  *p++ = EEPROM.read(ee++);
  return value;
}


/**
 * 
 */
char loadVersion() {
  return EEPROM.read(ADDR_VERSION);
}


/**
 * 
 */
void saveUID() {
  Serial.println(F("Saving UID."));
  EEPROM_writeLong(ADDR_UUID,(long)robot_uid);
}


/**
 * 
 */
void saveLimits() {
  Serial.println(F("Saving dimensions."));
  int i,j=ADDR_LIMITS;
  for(i=0;i<NUM_AXIES;++i) {
    EEPROM_writeLong(j,axies[i].limitMax*100);
    j+=4;
    EEPROM_writeLong(j,axies[i].limitMin*100);
    j+=4;
  }
}


/**
 * 
 */
void loadLimits() {
  int i,j=ADDR_LIMITS;
  for(i=0;i<NUM_AXIES;++i) {
    axies[i].limitMax = (float)EEPROM_readLong(j)/100.0f;
    j+=4;
    axies[i].limitMin = (float)EEPROM_readLong(j)/100.0f;
    j+=4;
  }
}


/**
 * @param limits NUM_AXIES pairs of floats.  each pair is one float for max limit and one for min limit.
 */
void adjustDimensions(float *limits) {
  int i,j;
  int changed=0;
  float v;
  for(i=0;i<NUM_AXIES;++i) {
    // max test
    v = floor(limits[j]*100.0f)/100.0f;
    if(v != axies[i].limitMax) {
      axies[i].limitMax = v;
      changed=1;
    }
    j++;
    // min test
    v = floor(limits[j]*100.0f)/100.0f;
    if(v != axies[i].limitMin) {
      axies[i].limitMin = v;
      changed=1;
    }
    j++;
  }

  if( changed != 0 ) {
    saveLimits();
  }
}


/**
 * 
 */
void saveHome() {
  Serial.println(F("Saving home."));
  int i,j=ADDR_HOME;
  for(i=0;i<NUM_AXIES;++i) {
    EEPROM_writeLong(j,axies[i].homePos*100);
    j+=4;
  }
}


/**
 * 
 */
void loadHome() {
  int i,j=ADDR_HOME;
  for(i=0;i<NUM_AXIES;++i) {
    axies[i].homePos = (float)EEPROM_readLong(j)/100.0f;
    j+=4;
  }
}


/**
 *
 */
void saveCalibration() {
  Serial.println(F("Saving calibration."));
  EEPROM_writeLong(ADDR_CALIBRATION_LEFT  ,calibrateLeft  *100);
  EEPROM_writeLong(ADDR_CALIBRATION_RIGHT ,calibrateRight *100);
}


/**
 * 
 */
void loadCalibration() {
  calibrateLeft   = (float)EEPROM_readLong(ADDR_CALIBRATION_LEFT  )/100.0f;
  calibrateRight  = (float)EEPROM_readLong(ADDR_CALIBRATION_RIGHT )/100.0f;
}


/**
 * 
 */
void loadConfig() {
  char versionNumber = loadVersion();
  if( versionNumber != EEPROM_VERSION ) {
    // If not the current EEPROM_VERSION or the EEPROM_VERSION is sullied (i.e. unknown data)
    // Update the version number
    EEPROM.write(ADDR_VERSION,EEPROM_VERSION);
#if MAKELANGELO_HARDWARE_VERSION == 5 || MAKELANGELO_HARDWARE_VERSION == 6
    adjustDimensions(50,-50,-32.5,32.5);
    saveCalibration();
#endif
  }
  
  // Retrieve stored configuration
  robot_uid=EEPROM_readLong(ADDR_UUID);
  loadLimits();
  loadHome();
  loadCalibration();
}

/**
 * This file is part of makelangelo-firmware.
 *
 * makelangelo-firmware is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * makelangelo-firmware is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with makelangelo-firmware.  If not, see <http://www.gnu.org/licenses/>.
 */
