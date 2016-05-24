// ---------------------------------------------------------------------------
// Created by Tim Eckel - teckel@leethost.com
// Copyright 2015 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// Modified by Francisco Zamora-Martinez (pakozm) 2016
//
// See "TimerFreeTone.h" for purpose, syntax, version history, links, and more.
// ---------------------------------------------------------------------------

#include "TimerFreeTone.h"

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void TimerFreeTone(uint8_t pin1, uint8_t pin2, uint32_t frequency, uint32_t duration, float delay_between_notes) {
  if (!frequency) { delay(duration); return; } // Frequency is false (zero), nothing to play, just delay for duration and return.
  uint32_t rest = duration*delay_between_notes;
  duration -= rest;
  uint32_t notch = 500000 / frequency;         // Calculate how long to leave the pin high and low.
  uint32_t noteEnd = millis() + duration;      // Calculate when the note will end.
  int state1 = HIGH, state2 = LOW;
  while(millis() <= noteEnd) {  // Loop for the duration.
    digitalWrite(pin1, state1);
    digitalWrite(pin2, state2);
    delayMicroseconds(notch); // Square wave duration (how long to leave pin high).
    swap(state1, state2);
  }
  digitalWrite(pin1,LOW);     // Set pin low.
  digitalWrite(pin2,LOW);     // Set pin low.
  delay(rest);
}
