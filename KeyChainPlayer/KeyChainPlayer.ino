#include "durations.h"
#include "pitches.h"
#include "TimerFreeTone.h"

#define TONE_PIN 1 // Pin you have speaker/piezo connected to (be sure to include a 100 ohm resistor).
#define TONE_PIN2 0 // Pin you have speaker/piezo connected to (be sure to include a 100 ohm resistor).

int melody[] = { C5, D5, E5, F5, G5, A5, B5, C6 };
int duration[] = { WN, WN, WN, WN, WN, WN, WN, DWN  };

const int SPEED_FACTOR = 16;

void setup() {
  for (int thisNote = 0; thisNote < 8; thisNote++) { // Loop through the notes in the array.
    TimerFreeTone(TONE_PIN, TONE_PIN2, melody[thisNote], duration[thisNote] * SPEED_FACTOR); // Play thisNote for duration.
    delay(50); // Short delay between notes.
  }
}

void loop() {}
