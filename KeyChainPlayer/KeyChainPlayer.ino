/*
   This file is part of TinyMusican Arduino project for an ATtiny85 music player.

   Copyright (c) 2016 Francisco Zamora-Martinez (pakozm@gmail.com)

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/

/**
 * Attiny85 PINS
 *            ____
 * RESET    -|    |- 5V
 * LED1 (3) -|    |- (2) BUZ2
 * LED2 (4) -|    |- (1) BUZ2
 * GND      -|____|- (0) BTN
 */

#include <avr/eeprom.h>
#include <avr/interrupt.h> // needed for the additional interrupt
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include "MinorSwing.h"
#include "TimerFreeTone.h"

#define adc_disable() (ADCSRA &= ~(1<<ADEN)) // disable ADC (before power-off)
#define adc_enable()  (ADCSRA |=  (1<<ADEN)) // re-enable ADC

#define BTN_PIN  0
#define BUZ_PIN1 1  // Pin you have speaker/piezo connected to
#define BUZ_PIN2 2 // Pin you have speaker/piezo connected to
#define LED1_PIN 3
#define LED2_PIN 4

volatile bool pushed = false;
const float SPEED_FACTOR = 1.6f;
const long RND_TIME = 40, RND_TIME2 = 20;

ISR(PCINT0_vect){ // PB0 pin button interrupt
  if (digitalRead(BTN_PIN) == HIGH) pushed = true;
}

void play() {
  bool led_on = false;
  unsigned long t0 = micros();
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(int); thisNote++) { // Loop through the notes in the array.
    long rnd = random(RND_TIME+1) - RND_TIME2;
    int note = pgm_read_word_near(melody + thisNote) * 2;
    long len = pgm_read_word_near(duration + thisNote);
    if (note != ZZ) {
      led_on = !led_on;
      digitalWrite(LED1_PIN, led_on ? HIGH : LOW);
      digitalWrite(LED2_PIN, led_on ? HIGH : LOW);
    }
    else {
      if (led_on) {
        digitalWrite(LED1_PIN, LOW);
        digitalWrite(LED2_PIN, LOW);
      }
      led_on = false;
    }
    unsigned long t = (micros() - t0) / 1000;
    TimerFreeTone(BUZ_PIN1, BUZ_PIN2, note, max(1, len * SPEED_FACTOR - t + rnd)); // Play thisNote for duration.
    if (pushed) break;
    t0 = micros();
  }
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);  
}

void powerDown() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu();
  sleep_disable();
}

void setup() {
  pinMode(BTN_PIN, INPUT);
  pinMode(BUZ_PIN1, OUTPUT);
  pinMode(BUZ_PIN2, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  adc_disable();
  PCMSK |= 0b00000001;  // pin change mask: listen to portb bit 1
  GIMSK |= 0b00100000;  // enable PCINT interrupt
}

void loop() {
  delay(400);
  powerDown();
  delay(400);
  pushed = false;
  play();
}

