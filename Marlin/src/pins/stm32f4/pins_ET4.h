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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#ifndef TARGET_STM32F4
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#elif HOTENDS > 1 || E_STEPPERS > 1
  #error "ET4 supports up to 1 hotends / E-steppers."
#endif

#define BOARD_INFO_NAME "ET4"

//
// Limit Switches
//
#define X_STOP_PIN                          PC13 
#define Y_STOP_PIN                          PE12
#define Z_STOP_PIN                          PE11

//
// Z Probe
//
 #ifndef Z_MIN_PROBE_PIN
   #define Z_MIN_PROBE_PIN                   PC2
 #endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PA2
#endif

//
// Power Loss Detection (Pending PIN)
//
//#ifndef POWER_LOSS_PIN
//  #define POWER_LOSS_PIN                    ??
//#endif

//
// LED PIN
//

#define LED_PIN                             PD12

//
// Steppers
//

#define X_STEP_PIN                          PB6
#define X_DIR_PIN                           PB5
#define X_ENABLE_PIN                        PB7

#define Y_STEP_PIN                          PB3
#define Y_DIR_PIN                           PD6
#define Y_ENABLE_PIN                        PB4

#define Z_STEP_PIN                          PA12
#define Z_DIR_PIN                           PA11
#define Z_ENABLE_PIN                        PA15

#define E0_STEP_PIN                         PB9
#define E0_DIR_PIN                          PB8
#define E0_ENABLE_PIN                       PE0

//
// Temperature Sensors
//

#define TEMP_0_PIN                          PA1
#define TEMP_BED_PIN                        PA4

//
// Heaters / Fans
//

#define HEATER_0_PIN                        PA0
#define HEATER_BED_PIN                      PE2
#define FAN_PIN                             PE3
#define FAN1_PIN                            PE1

//
// Persistent Storage
// If no option is selected below the SD Card will be used
//

/**
 *  Status: Not Working/Testing
 *  Hardware: WINBOND W25Q128JVSQ (128M-bit) => https://www.winbond.com/resource-files/w25q128jv%20revf%2003272018%20plus.pdf
 *  Notes: 
 *    - Copied config from another board. 
 *    - Throws Read/Write errors so far.
 */

//#define SPI_EEPROM
//#define CUSTOM_SPI_PINS
//#define FLASH_EEPROM_EMULATION
//#define SPI_MODULE 2

#if ENABLED(SPI_EEPROM)
  // WINBOND W25Q128JVSQ (128M-bit)
  #define SPI_CHAN_EEPROM1      1
  #define SPI_EEPROM1_CS        PB12   
  #define EEPROM_SCK            PB13
  #define EEPROM_MISO           PB14
  #define EEPROM_MOSI           PB15
  #define EEPROM_PAGE_SIZE      0x1000U                     // 4KB (from datasheet)
  //#undef E2END
  //#define E2END                 16UL * (EEPROM_PAGE_SIZE)   // Limit to 64KB for now...
  # define MARLIN_EEPROM_SIZE   16UL * (EEPROM_PAGE_SIZE)   // Limit to 64KB for now...
#elif ENABLED(FLASH_EEPROM_EMULATION)
  // SoC Flash (framework-arduinoststm32-maple/STM32F1/libraries/EEPROM/EEPROM.h)
  #define EEPROM_START_ADDRESS (0x8000000UL + (512 * 1024) - 2 * EEPROM_PAGE_SIZE)
  #define EEPROM_PAGE_SIZE     (0x800U)     // 2KB, but will use 2x more (4KB)
  #define E2END (EEPROM_PAGE_SIZE - 1)
#else
  #define MARLIN_EEPROM_SIZE 0x800U 
  //#define E2END (0x7FFU) // On SD, Limit to 2KB, require this amount of RAM
#endif

//
// LCD
//

/**
 * Status: Working. Merged FSMC/DMA implementation for stm32f4 from jmz52 fork.
 * Hardware: IC ST7789V | STP320240_0280E2T (40P/1,5): ST7789 (YT280S008)  => https://a.aliexpress.com/_dV4Bghv
 * Notes: 
 *  - Defined PINS: CSX, DCX, WRX, RESX, RDX, DB[8:15]
 *  - FSMC/DMA and 8080-8 inteface
 */

#define TFT_DRIVER                         ST7789
#define TFT_RESET_PIN                      PE6
#define TFT_CS_PIN                         PD7
#define TFT_RS_PIN                         PD13

//
// Touch Screen
//

/**
 * Status: Working. Merged implementation from jmz52 fork.
 * Hardware: TOUCH: XPT2046 => https://ldm-systems.ru/f/doc/catalog/HY-TFT-2,8/XPT2046.pdf
 */

#if ENABLED(TOUCH_SCREEN)
  #define TOUCH_CS_PIN                      PB2
  #define TOUCH_SCK_PIN                     PB0
  #define TOUCH_MOSI_PIN                    PE5
  #define TOUCH_MISO_PIN                    PE4
  #define TOUCH_INT_PIN                     PB1
#endif

//
// Onboard SD support
//

/**
 * Status: Working.
 */

#define SDIO_SUPPORT
#define SDSUPPORT

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION                  ONBOARD
#endif

#if ENABLED(SDSUPPORT)
  #define SDIO_D0_PIN                         PC8
  #define SDIO_D1_PIN                         PC9
  #define SDIO_D2_PIN                         PC10
  #define SDIO_D3_PIN                         PC11
  #define SDIO_CK_PIN                         PC12
  #define SDIO_CMD_PIN                        PD2
  #define SD_DETECT_PIN                       PD3
#endif
