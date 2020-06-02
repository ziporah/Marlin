# ET4 for Marlin

This project is an effort to try to adapt the Anet ET4 motherboard and display for use with Marlin. It is based on the configuration of the BTT002. 
Pin mapping is below.
Anyone can contribute to completing this project, even Anet! ;).

-- Current status --

 Working: 
  - XYZ Steppers
  - Extruder
  - SD Card
  - USB comunication / pronterface
 Not working:
  - EEPROM
  - LCD
  - TouchPad: Config maybe ok, but useless without LCD
  - PowerLoss: Needs board pin identification.
  - Filament runout detector: Needs LCD or EMERGENCY_PARSER define (USB build problem, maybe easy to fix)
  - PC/SD firmware load/update: There is no bootloader currently. 
 To take a look:
  - All files on path "Marlin\buildroot\share\PlatformIO\variants\ET4\" should be adapted to ET4 Board. Specially peripheralPins.c, variant.cpp, variant.h etc..

--- BUILD/INSTALLATION ---

  DISCLAIMER: Since it is an unfinished project and under development, I am not responsible for what may happen to the motherboard or printer. Use at your own risk.

Currently you can only flash this firmware using a flasher (stlink, jlink, bmp etc).
Before flashing this firmware, I highly recommend making a backup of your firmware, or at least your bootlaoder addresses from 0x08000000 to 0x08010000. In this way we can always recover the stock firmware, flashing the bootloader (0x0800 - 0x801) and any of the available Anet firmware (0x0801 - ...).
  
  - Download or clone this repo.
  - Build with platform io.
  - Burn .elf with your flasher or .bin from 0x08000000 address.

--- HARDWARE ---

USB TO SERIAL CONVERTER: CH340G => https://www.mpja.com/download/35227cpdata.pdf
MOSFETS (BED/HOTEND): G90N04 => 
CLK: JF8.000 (MCU EXT CLK)
CLK: JF12.000 (USB-UART CLK)
FLASH: WINBOND W25Q128JVSQ (128M-bit) Serial Flash memory => https://www.winbond.com/resource-files/w25q128jv%20revf%2003272018%20plus.pdf
??: 293 ST69834
SS56: SCHOTTKY DIODE
AMS1117 3.3 DN811: REGULATOR
030N06: MOSFETs
A19T: TRANSISTOR
XL2596S -5.0E1 83296: STEP DOWN DC CONVERTER 3A/150KHZ
LCD: ST7789V | STP320240_0280E2T (40P/1,5): ST7789 (YT280S008)  => https://a.aliexpress.com/_dV4Bghv | https://www.crystalfontz.com/controllers/Sitronix/ST7789V/470/
TOUCH: XPT2046 => https://ldm-systems.ru/f/doc/catalog/HY-TFT-2,8/XPT2046.pdf

--- PIN MAPPING ---

E-STEP => PB9
E-DIR => PB8
E-ENABLE => PE0

X-STEP => PB6
X-DIR => PB5
X-ENABLE => PB7

Y-STEP => PB3
Y-DIR => PD6
Y-ENABLE => PB4

Z-STEP => PA12
Z-DIR => PA11
Z-ENABLE => PA15

Y-LIMIT => PE12 
X-LIMIT => PC13
Z-LIMIT => PE11

TEMP_BED => PA4
TEMP_EXB1 => PA1

END_FAN => PE1
LAY_FAN => PE3

END_CONTROL => PA0
BED_CONTROL => PE2

LV_DET => PC2
MAT_DET1 => PA2

SDIO_D2 => PC10
SDIO_D3 => PC11
SDIO_CMD => PD2
SDIO_CLK => PC12
SDIO_D0 => PC8
SDIO_D1 => PC9
TF_DET => PD3

USB_USART1_TX => PA9
USB_USART1_RX => PA10

RESET_BTN => NRST (14)
LED_D2 => PD12

WINBOND_CS => PB12
WINBOND_DO => PB14
WINBOND_DI => PB15
WINBOND_CLK => PB13

P1_1_LCD_9_CSX => PD7
P1_2_LCD_11_WRX => PD5
P1_3_TOUCH_15_/CS => PB2
P1_4_TOUCH_14_DIN => PE5
P1_5_TOUCH_12_DOUT => PE4
P1_6_TOUCH_16_DCLK => PB0
P1_7_TOUCH_11_/PENIRQ => PB1
P1_8_LCD_12_RDX => PD4
P1_9 => GND
P1_10 => 3.3V

P2_1_LCD_15_RESX => PE6
P2_2_LCD_10_DCX => PD13
P2_3_LCD_26_DB9 => PD15
P2_4_LCD_25_DB8 => PD14
P2_5_LCD_28_DB11 => PD1
P2_6_LCD_27_DB10 => PD0
P2_7_LCD_30_DB13 => PE8
P2_8_LCD_29_DB12 => PE7
P2_9_LCD_32_DB15 => PE10
P2_10_LCD_31_DB14 => PE9

# Resources

![ET4 Telegram Spanish Group Resources](https://drive.google.com/drive/folders/1bVusF9dMh1H7c2JM5ZWlbn2tWRGKsHre)

# Marlin 3D Printer Firmware

![GitHub](https://img.shields.io/github/license/marlinfirmware/marlin.svg)
![GitHub contributors](https://img.shields.io/github/contributors/marlinfirmware/marlin.svg)
![GitHub Release Date](https://img.shields.io/github/release-date/marlinfirmware/marlin.svg)
[![Build Status](https://github.com/MarlinFirmware/Marlin/workflows/CI/badge.svg?branch=bugfix-2.0.x)](https://github.com/MarlinFirmware/Marlin/actions)

<img align="right" width=175 src="buildroot/share/pixmaps/logo/marlin-250.png" />

Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

## Marlin 2.0 Bugfix Branch

__Not for production use. Use with caution!__

Marlin 2.0 takes this popular RepRap firmware to the next level by adding support for much faster 32-bit and ARM-based boards while improving support for 8-bit AVR boards. Read about Marlin's decision to use a "Hardware Abstraction Layer" below.

This branch is for patches to the latest 2.0.x release version. Periodically this branch will form the basis for the next minor 2.0.x release.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases).

## Building Marlin 2.0

To build Marlin 2.0 you'll need [Arduino IDE 1.8.8 or newer](https://www.arduino.cc/en/main/software) or [PlatformIO](http://docs.platformio.org/en/latest/ide.html#platformio-ide). We've posted detailed instructions on [Building Marlin with Arduino](https://marlinfw.org/docs/basics/install_arduino.html) and [Building Marlin with PlatformIO for ReArm](https://marlinfw.org/docs/basics/install_rearm.html) (which applies well to other 32-bit boards).

## Hardware Abstraction Layer (HAL)

Marlin 2.0 introduces a layer of abstraction so that all the existing high-level code can be built for 32-bit platforms while still retaining full 8-bit AVR compatibility. Retaining AVR compatibility and a single code-base is important to us, because we want to make sure that features and patches get as much testing and attention as possible, and that all platforms always benefit from the latest improvements.

### Current HALs

  #### AVR (8-bit)

  board|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Arduino AVR](https://www.arduino.cc/)|ATmega, ATTiny, etc.|16-20MHz|64-256k|2-16k|5V|no

  #### DUE

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Arduino Due](https://www.arduino.cc/en/Guide/ArduinoDue), [RAMPS-FD](http://www.reprap.org/wiki/RAMPS-FD), etc.|[SAM3X8E ARM-Cortex M3](http://www.microchip.com/wwwproducts/en/ATsam3x8e)|84MHz|512k|64+32k|3.3V|no

  #### ESP32

  board|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [ESP32](https://www.espressif.com/en/products/hardware/esp32/overview)|Tensilica Xtensa LX6|240MHz|---|---|3.3V|---

  #### LPC1768 / LPC1769

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Re-ARM](https://www.kickstarter.com/projects/1245051645/re-arm-for-ramps-simple-32-bit-upgrade)|[LPC1768 ARM-Cortex M3](http://www.nxp.com/products/microcontrollers-and-processors/arm-based-processors-and-mcus/lpc-cortex-m-mcus/lpc1700-cortex-m3/512kb-flash-64kb-sram-ethernet-usb-lqfp100-package:LPC1768FBD100)|100MHz|512k|32+16+16k|3.3-5V|no
  [MKS SBASE](http://forums.reprap.org/read.php?13,499322)|LPC1768 ARM-Cortex M3|100MHz|512k|32+16+16k|3.3-5V|no
  [Selena Compact](https://github.com/Ales2-k/Selena)|LPC1768 ARM-Cortex M3|100MHz|512k|32+16+16k|3.3-5V|no
  [Azteeg X5 GT](https://www.panucatt.com/azteeg_X5_GT_reprap_3d_printer_controller_p/ax5gt.htm)|LPC1769 ARM-Cortex M3|120MHz|512k|32+16+16k|3.3-5V|no
  [Smoothieboard](http://reprap.org/wiki/Smoothieboard)|LPC1769 ARM-Cortex M3|120MHz|512k|64k|3.3-5V|no

  #### SAMD51

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Adafruit Grand Central M4](https://www.adafruit.com/product/4064)|[SAMD51P20A ARM-Cortex M4](https://www.microchip.com/wwwproducts/en/ATSAMD51P20A)|120MHz|1M|256k|3.3V|yes

  #### STM32F1

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Arduino STM32](https://github.com/rogerclarkmelbourne/Arduino_STM32)|[STM32F1](https://www.st.com/en/microcontrollers-microprocessors/stm32f103.html) ARM-Cortex M3|72MHz|256-512k|48-64k|3.3V|no
  [Geeetech3D GTM32](https://github.com/Geeetech3D/Diagram/blob/master/Rostock301/Hardware_GTM32_PRO_VB.pdf)|[STM32F1](https://www.st.com/en/microcontrollers-microprocessors/stm32f103.html) ARM-Cortex M3|72MHz|256-512k|48-64k|3.3V|no

  #### STM32F4

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [STEVAL-3DP001V1](http://www.st.com/en/evaluation-tools/steval-3dp001v1.html)|[STM32F401VE Arm-Cortex M4](http://www.st.com/en/microcontrollers/stm32f401ve.html)|84MHz|512k|64+32k|3.3-5V|yes

  #### Teensy++ 2.0

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Teensy++ 2.0](http://www.microchip.com/wwwproducts/en/AT90USB1286)|[AT90USB1286](http://www.microchip.com/wwwproducts/en/AT90USB1286)|16MHz|128k|8k|5V|no

  #### Teensy 3.1 / 3.2

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Teensy 3.2](https://www.pjrc.com/store/teensy32.html)|[MK20DX256VLH7](https://www.mouser.com/ProductDetail/NXP-Freescale/MK20DX256VLH7) ARM-Cortex M4|72MHz|256k|32k|3.3V-5V|yes

  #### Teensy 3.5 / 3.6

  boards|processor|speed|flash|sram|logic|fpu
  ----|---------|-----|-----|----|-----|---
  [Teensy 3.5](https://www.pjrc.com/store/teensy35.html)|[MK64FX512VMD12](https://www.mouser.com/ProductDetail/NXP-Freescale/MK64FX512VMD12) ARM-Cortex M4|120MHz|512k|192k|3.3-5V|yes
  [Teensy 3.6](https://www.pjrc.com/store/teensy36.html)|[MK66FX1M0VMD18](https://www.mouser.com/ProductDetail/NXP-Freescale/MK66FX1M0VMD18) ARM-Cortex M4|180MHz|1M|256k|3.3V|yes

## Submitting Patches

Proposed patches should be submitted as a Pull Request against the ([bugfix-2.0.x](https://github.com/MarlinFirmware/Marlin/tree/bugfix-2.0.x)) branch.

- This branch is for fixing bugs and integrating any new features for the duration of the Marlin 2.0.x life-cycle.
- Follow the [Coding Standards](https://marlinfw.org/docs/development/coding_standards.html) to gain points with the maintainers.
- Please submit your questions and concerns to the [Issue Queue](https://github.com/MarlinFirmware/Marlin/issues).

### [RepRap.org Wiki Page](http://reprap.org/wiki/Marlin)

## Credits

The current Marlin dev team consists of:

 - Scott Lahteine [[@thinkyhead](https://github.com/thinkyhead)] - USA &nbsp; [Donate](http://www.thinkyhead.com/donate-to-marlin) / Flattr: [![Flattr Scott](http://api.flattr.com/button/flattr-badge-small.png)](https://flattr.com/submit/auto?user_id=thinkyhead&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)
 - Roxanne Neufeld [[@Roxy-3D](https://github.com/Roxy-3D)] - USA
 - Chris Pepper [[@p3p](https://github.com/p3p)] - UK
 - Bob Kuhn [[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)] - USA
 - João Brazio [[@jbrazio](https://github.com/jbrazio)] - Portugal
 - Erik van der Zalm [[@ErikZalm](https://github.com/ErikZalm)] - Netherlands &nbsp; [![Flattr Erik](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
