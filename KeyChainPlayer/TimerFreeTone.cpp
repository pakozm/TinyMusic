// ---------------------------------------------------------------------------
// Created by Tim Eckel - teckel@leethost.com
// Copyright 2015 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// Modified by Francisco Zamora-Martinez (pakozm) 2016
//
// See "TimerFreeTone.h" for purpose, syntax, version history, links, and more.
// ---------------------------------------------------------------------------

#include "TimerFreeTone.h"

void TimerFreeTone(uint8_t pin1, uint8_t pin2, uint32_t frequency, uint32_t duration, float delay_between_notes) {
  if (!frequency) { delay(duration); return; } // Frequency is false (zero), nothing to play, just delay for duration and return.
  uint32_t rest = duration*delay_between_notes;
  duration -= rest;
  uint32_t notch = 500000 / frequency;       // Calculate how fast to toggle the pin.
  uint32_t loops = (duration * 500) / notch; // Calculate the number of loops to run.
  for (uint32_t i=0; i<loops; i++) { // Loop for the desired number of loops.
    digitalWrite(pin1,HIGH);    // Set pin high.
    digitalWrite(pin2,LOW);    // Set pin low.
    delayMicroseconds(notch);  // Square wave duration (how long to leave pin high).
    digitalWrite(pin1,LOW);     // Set pin low.
    digitalWrite(pin2,HIGH);     // Set pin high.
  }
  digitalWrite(pin1,LOW);     // Set pin low.
  digitalWrite(pin2,LOW);     // Set pin high.
  delay(rest);
}

