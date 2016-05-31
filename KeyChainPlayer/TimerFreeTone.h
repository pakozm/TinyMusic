// ---------------------------------------------------------------------------
// TimerFreeTone Library - v1.2 - 04/01/2015
//
// AUTHOR/LICENSE:
// Created by Tim Eckel - teckel@leethost.com
// Copyright 2015 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// Modified by Francisco Zamora-Martinez (pakozm) 2016:
//
//   - Added differential driving for double sound volume when using ATtiny85
//     with 3V coin cell.
//
// LINKS:
// Project home: https://bitbucket.org/teckel12/arduino-timer-free-tone
// Blog: http://forum.arduino.cc/index.php?topic=235774.0
//
// DISCLAIMER:
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
//
// PURPOSE:
// Doesn't use timers which frees up conflicts with other libraries. Compatible
// with all ATmega, ATtiny and ARM-based microcontrollers. Over 1,500 bytes
// smaller binary sketch size than the standard tone library. Exclusive use of
// port registers for AVR-based microcontrollers for fastest and smallest code.
// Close to a plug-in replacement for the standard Tone library.
//
// SYNTAX:
//   TimerFreeTone( pin1, pin2, frequency, duration [, overhead ] )
//   Play a note using pin1 and pin2 at frequency in Hz for duration in milliseconds.
//
//     Parameters:
//       * frequency  - Play the specified frequency (should work fairly well in the 100 to 15000 Hz range).
//       * duration   - Set the duration to play in milliseconds. Range: 0 to 65535 (65.5 seconds).
//
// HISTORY:
// 19/04/2016 v2.0 - Uses differential driving for double sound volume (pakozm).
//
// 01/14/2015 v1.2 - Calculates duration differently for higher tone accuracy
// and smaller code size.
//
// 04/30/2014 v1.1 - Automatically sets mode of pin to OUTPUT as does the
// standard Tone library. Sets pinOutput variable to volatile to work with
// certain microcontrollers. Removed overhead parameter and calculation, fairly
// accurate anyway at audible frequencies. Even smaller binary sketch size.
//
// 04/25/2014 v1.0 - Initial release.
//
// ---------------------------------------------------------------------------

#ifndef TimerFreeTone_h
#define TimerFreeTone_h

#include <Arduino.h>

void TimerFreeTone(byte pin, byte pin2, uint32_t frequency, uint32_t duration, float delay_between_notes=0.15f);
#endif
