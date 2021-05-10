/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 * Platform-independent Arduino functions for I2C EEPROM.
 * Enable USE_SHARED_EEPROM if not supplied by the framework.
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(I2C_EEPROM)

#include "eeprom_if.h"

#if ENABLED(SOFT_I2C_EEPROM)
  #include <SlowSoftWire.h>
  SlowSoftWire Wire = SlowSoftWire(I2C_SDA_PIN, I2C_SCL_PIN, true);
#else
  #include <Wire.h>
#endif

void eeprom_init() {
  Wire.begin(
    #if PINS_EXIST(I2C_SCL, I2C_SDA) && DISABLED(SOFT_I2C_EEPROM)
      uint8_t(I2C_SDA_PIN), uint8_t(I2C_SCL_PIN)
    #endif
  );
}

#if ENABLED(USE_SHARED_EEPROM)

#ifndef EEPROM_WRITE_DELAY
  #define EEPROM_WRITE_DELAY    5
#endif
#ifndef EEPROM_DEVICE_ADDRESS
  #define EEPROM_DEVICE_ADDRESS  0x50
#endif

// if 24Cxx is equal or greater than 24C32 (32Kb/4KB), 16 bit word addressing has to be used.
// if not, patch device address to include MSB address into A0, A1, A2
#if MARLIN_EEPROM_SIZE >= 0x1000 && !defined EEPROM_WORD_ADDRESS_16BIT // 4KB
  #define EEPROM_WORD_ADDRESS_16BIT
#endif

static constexpr uint8_t eeprom_device_address = I2C_ADDRESS(EEPROM_DEVICE_ADDRESS);

// ------------------------
// Public functions
// ------------------------

static uint8_t _eeprom_begin(uint8_t * const pos) {
  const unsigned eeprom_address = (unsigned)pos;
  uint8_t patched_eeprom_device_address = 0;

  #ifndef EEPROM_WORD_ADDRESS_16BIT
    // patch high bits of EEPROM address into EEPROM_DEVICE_ADDRESS (A0, A1, A2)
    patched_eeprom_device_address = eeprom_device_address | ((eeprom_address >> 8) & 0x07);
    Wire.beginTransmission(patched_eeprom_device_address);
  #else
    Wire.beginTransmission(eeprom_device_address);
    Wire.write(int(eeprom_address >> 8));   // MSB
  #endif

  Wire.write(int(eeprom_address & 0xFF)); // LSB

  return patched_eeprom_device_address == 0 ? eeprom_device_address : patched_eeprom_device_address;
}

void eeprom_write_byte(uint8_t *pos, unsigned char value) {
  _eeprom_begin(pos);
  Wire.write(value);
  Wire.endTransmission();

  // wait for write cycle to complete
  // this could be done more efficiently with "acknowledge polling"
  delay(EEPROM_WRITE_DELAY);
}

uint8_t eeprom_read_byte(uint8_t *pos) {
  const uint8_t patched_eeprom_device_address = _eeprom_begin(pos);
  Wire.endTransmission(false);
  Wire.requestFrom(patched_eeprom_device_address, (byte)1);
  return Wire.available() ? Wire.read() : 0xFF;
}

#endif // USE_SHARED_EEPROM
#endif // I2C_EEPROM