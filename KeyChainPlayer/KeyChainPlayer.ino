#include <avr/interrupt.h> // needed for the additional interrupt
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include "MinorSwing.h"
#include "TimerFreeTone.h"

#define adc_disable() (ADCSRA &= ~(1<<ADEN)) // disable ADC (before power-off)
#define adc_enable()  (ADCSRA |=  (1<<ADEN)) // re-enable ADC

#define BTN_PIN 0
#define TONE_PIN1 1  // Pin you have speaker/piezo connected to
#define TONE_PIN2 2 // Pin you have speaker/piezo connected to
#define LED_PIN 4

volatile bool pushed = false;

const int SPEED_FACTOR = 3;

ISR(PCINT0_vect){ // PB0 pin button interrupt
  if (digitalRead(BTN_PIN) == HIGH) pushed = true;
}

void play() {
  bool led_on = false;
  uint32_t time = 0;
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(int); thisNote++) { // Loop through the notes in the array.
    int note = pgm_read_word_near(melody + thisNote);
    int len = pgm_read_word_near(duration + thisNote);
    led_on = !led_on;
    if (note == ZZ) led_on = false;
    digitalWrite(LED_PIN, led_on ? HIGH : LOW);
    TimerFreeTone(TONE_PIN1, TONE_PIN2, note, len * SPEED_FACTOR); // Play thisNote for duration.
    digitalWrite(LED_PIN, led_on ? LOW : HIGH);
    time += len;
    if (pushed) break;
  }
  digitalWrite(LED_PIN, LOW);
}

void powerDown() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu();
  sleep_disable();
}

void setup() {
  pinMode(BTN_PIN, INPUT);
  pinMode(TONE_PIN1, OUTPUT);
  pinMode(TONE_PIN2, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  adc_disable();
  PCMSK |= 0b00000001;  // pin change mask: listen to portb bit 1
  GIMSK |= 0b00100000;  // enable PCINT interrupt
}

void loop() {
  delay(400);
  pushed = false;
  play();
  delay(400);
  powerDown();
}

