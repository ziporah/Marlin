/**
 * Author: David Terán Garrido
 * e-mail: davidtgbe@hotmail.com
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

#pragma once

/* 
 * Easy configuration settings.
 * Only mandatory parmeter is "ET_MODEL". 
 * Rest of parameters can be commented if they are the defaults for the printer model:
	+-------------------+-------------+------------+--------------+--------------+---------+
	|       Model       |    SIZE     | AUTOLEVEL  | HOMING Z-DIR | PHY ENDSTOPS | DRIVERS |
	+-------------------+-------------+------------+--------------+--------------+---------+
	| ET4               | 220X220X250 | FILM STRIP | UP           | X-L,Y-B,Z-T  | A4988   |
	| ET4X              | 220X220X250 | NONE       | DOWN         | X-L,Y-B,Z-B  | A4988   |
	| ET4+              | 220X220X250 | CAPACITIVE | DOWN         | X-L,Y-B      | A4988   |
	| ET4 PRO / Labists | 220X220X250 | CAPACITIVE | DOWN         | X-L,Y-B      | TMC2208 |
	| ET5               | 300X300X400 | CAPACITIVE | DOWN         | X-L,Y-B      | A4988   |
	| ET5X              | 300X300X400 | CAPACITIVE | DOWN         | X-L,Y-B      | A4988   |
	| ET5 PRO           | 300X300X400 | CAPACITIVE | DOWN         | X-L,Y-B      | TMC2208 |
	+-------------------+-------------+------------+--------------+--------------+---------+
	PHY endstops legend: Axis + (Left, Right, Front, Back, Top, Bottom)
 */

//
// Basic settings
//

#define ET_MODEL            		ET_MODEL_ET4				// Mandatory. Available values [ET_MODEL_ET4 ,ET_MODEL_ET4_PLUS, ET_MODEL_ET4X, ET_MODEL_ET4_PRO, ET_MODEL_ET5, ET_MODEL_ET5X, ET_MODEL_ET5_PRO]
//#define ET_BOARD            		ET_BOARD_SILENT				// Optional. Available values [ET_BOARD_SILENT, ET_BOARD_NOISY]
#define ET_LEVELLING        		ET_LV_BLTOUCH				// Optional. Available values [ET_LV_NONE, ET_LV_BLTOUCH, ET_LV_CAPACITIVE, ET_LV_FILM_STRIP]
#define ET_Z_HOMING_DIR	  			ET_Z_HOMING_DIR_DOWN		// Optional. Available values [ET_Z_HOMING_DIR_UP, ET_Z_HOMING_DIR_DOWN]
//#define ET_MOD              		ET_MOD_NONE           		// Optional. Available values [ET_MOD_BMG, ET_MOD_BMG_MINI, ET_MOD_V6]. To select multiple mods use '|' to join. ex: (ET_MOD_BMG | ET_MOD_V6)
#define ET_Z_ENDSTOP_POSTION      	ET_Z_ENDSTOP_POSTION_NONE	// Optional. Available values [ET_Z_ENDSTOP_POSTION_NONE, ET_Z_ENDSTOP_POSTION_TOP, ET_Z_ENDSTOP_POSTION_BOTTOM]
#define ET_CUSTOM_MACHINE_NAME 		"Anet ET4 A4988 BLTOUCH" 	// Optional

/*  !!! BASIC POST installation configuration steps !!!
 *
 * Below steps must be performed to complet Marlin configuration and set parameters which are dependant 
 * on your current setup/printer. You can use pronterface to send gcodes.
 *
 * 1. EEPROM initialization -> https://marlinfw.org/docs/gcode/M502.html
 * 		> M502; M500
 * 		
 * 2. Hotend PID autotune -> https://marlinfw.org/docs/gcode/M303.html ; https://marlinfw.org/docs/gcode/M301.html
 * 		> M303 E0 S210 C3; M301 P<Presult> I<Iresult> D<Dresult>
 * 
 * 3. Bed PID autotune -> https://marlinfw.org/docs/gcode/M303.html ; https://marlinfw.org/docs/gcode/M304.html
 *
 * 		> M303 E1 S60 C3; M304 P<Presult> I<Iresult> D<Dresult> 
 * 		
 * 4. Calibrate motors steps -> https://marlinfw.org/docs/gcode/M092.html | Guide: https://www.instructables.com/Calibrating-your-3D-printer-using-minimal-filament/
 *
 * 		> M92 E<value> X<value> Y<value> Z<value>
 * 		
 * 4. Nozzle to probe offset in case of mounted probe autolevel feature -> https://marlinfw.org/docs/gcode/M851.html | Guide: https://www.thingiverse.com/thing:3700194
 *
 * 		> M851 X<value> Y<value> Z<value> 
 *
 * 5. Save EEPROM -> https://marlinfw.org/docs/gcode/M500.html 
 *
 * 		> M500 
 *
 * Optional:
 * - Bltouch test
 * 		
 * 		> M43 S P1
 * 
 * Other guides:
 * https://marlinfw.org/docs/configuration/configuration.html
 * https://teachingtechyt.github.io/calibration.html
 * 
 */

//
// Color Theme
//

/* Black Theme */

#define COLOR_RED2              0xF003
#define COLOR_ORANGE2           0xFDE0
#define COLOR_LIME2             0xA7E0
#define COLOR_BLACK2            0x2124

#define COLOR_BACKGROUND        COLOR_BLACK2
#define COLOR_SELECTION_BG      COLOR_ORANGE2
#define COLOR_COLD              COLOR_WHITE
#define COLOR_HOTEND            COLOR_RED2
#define COLOR_HEATED_BED        COLOR_RED2
#define COLOR_CHAMBER           COLOR_WHITE
#define COLOR_FAN               COLOR_WHITE
#define COLOR_AXIS_FRAME        COLOR_WHITE
#define COLOR_AXIS_HOMED        COLOR_ORANGE2
#define COLOR_AXIS_NOT_HOMED    COLOR_ORANGE2
#define COLOR_RATE_100          COLOR_LIME2
#define COLOR_RATE_ALTERED      COLOR_ORANGE2
#define COLOR_PRINT_TIME        COLOR_WHITE
#define COLOR_PROGRESS_BAR      COLOR_ORANGE2
#define COLOR_STATUS_MESSAGE    COLOR_ORANGE2
#define COLOR_SD_ENABLED        COLOR_CONTROL_ENABLED
#define COLOR_SD_DISABLED       COLOR_CONTROL_DISABLED
#define COLOR_MENU_TEXT         COLOR_WHITE
#define COLOR_MENU_VALUE_FONT   COLOR_ORANGE2
#define COLOR_SLIDER            COLOR_ORANGE2
#define COLOR_INCREASE          COLOR_WHITE
#define COLOR_DECREASE          COLOR_WHITE
#define COLOR_TICK              COLOR_VIVID_GREEN