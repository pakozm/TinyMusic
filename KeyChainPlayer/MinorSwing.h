#ifndef MINOR_SWING_H
#define MINOR_SWING_H

#include "durations.h"
#include "pitches.h"

PROGMEM const int melody[] =   {
  A3, C4, E4, E4, F4, E4, // 0
  D4, F4, A4, ZZ, // 0
  A3, C4, E4, E4, F4, E4, // 0
  D4, F4, A4, ZZ, // 0
  A3, C4, E4, E4, F4, E4, // 0
  D4, F4, A4, ZZ, // 0
  A3, ZZ, // 0
  ZZ, // 0

  A3, C4, E4, E4, F4, E4, // 0
  D4, F4, A4, ZZ, // 0
  A3, C4, E4, E4, F4, E4, // 0
  D4, F4, A4, ZZ, // 0
  A3, C4, E4, E4, F4, E4, // 0
  D4, F4, A4, ZZ, // 0
  A3, ZZ, GS2, // 0
  C3, B3, F3, F3, // 0
  
  E3, C5, C5, C5, ZZ, C5, B4, // 1
  ZZ, A4, A4, A4, ZZ, // 2
  ZZ, B4, A4, GS4, A4, B4, A4, GS4, B4, // 3
  A4, F4, D4, B3, ZZ, // 4

  ZZ, F4, D5, C5, B4, A4, // 5
  GS4, A4, GS4, F4, D4, B3, ZZ, // 6
  ZZ, GS3, B3, D4, F4, E4, F4, E4, // 7
  C4, B3, A3, A3, ZZ, // 8

  ZZ, A4, B4, C5, D5, // 9
  ZZ, D5, ZZ, C5, B4, A4, // 10
  B4, A4, GS4, B4, A4, F4, E4, // 11
  D4, C4, B3, F4, E4, C4, A3, // 12
  
  E3, A3, C4, E4, A4, B4, C5, A4, // 13
  B4, FS4, A4, GS4, E4, DS4, // 14
  D4, C5, B4, A4, GS4, B4, // 15
  A4, E4, C4, A3, ZZ, // 16

  ZZ, E5, ZZ, E5, ZZ, // 17
  E5, B4, C5, E5, A4, C5, // 18
  E5, A4, C5, E5, A4, C5, E5, // 19
  F5, CS5, E5, D5, A4, F4, D4, // 20

  ZZ, A3, D4, F4, A4, E5, ZZ, D5, // 21
  C5, B4, A4, GS4, B4, F4, // 22
  D4, B3, AS3, A3, GS3, B3, D4, F4, // 23
  E4, C4, A3, C4, ZZ, A3, // 24

  C4, E4, A4, C5, E5, G5, F5, // 25
  D5, ZZ, F5, // 26
  A5, ZZ, F5, D5, A4, F4, D4, // 27
  F4, E4, A4, ZZ, // 28

  ZZ, E5, E5, DS5, DS5, D5, // 29
  D5, CS5, CS5, C5, C5, B4, B4, A4, // 30
  A4, GS4, GS4, F4, F4, E4, E4, E4, // 31
  A3, ZZ, A3, A3, ZZ, // 32

  ZZ, F4, E4, DS4, E4, E5, B4, D5, // 33
  C5, GS4, B4, A4, E4, ZZ, // 34
  ZZ, E4, F4, E4, DS4, E4, F4, E4, // 35
  G4, F4, // 36

  B3, A3, A3, // 37
  GS3, B3, D4, D4, ZZ, // 38
  GS3, B3, D4, F4, GS4, B4, D5, F5, // 39
  FS4, ZZ, B4, D5, C5, // 40

  A4, C5, A4, E4, C4, E4, A4, C5, // 41
  D5, B4, B4, C5, A4, B4, // 42
  GS4, B4, A4, F4, D4, C4, B3, F4, // 43
  F4, E4, C4, A3, E3, // 44
  
  ZZ, E3, ZZ, // 45
  ZZ, E3, ZZ, // 46
  DS3, E3, F3, E3, DS3, E3, E3, E3, // 47
  A3, E3, C3, A2, A2, C3, E3, // 48

  A3, ZZ, C5, C5, C5, // 49
  B4, A4, C5, ZZ, A4, // 50
  A4, B4, C5, CS5, // 51
  D5, ZZ, G5, F5, E5, D5, C5, B4, A4, // 52

  G4, ZZ, G4, FS4, F4, E4, DS4, D4, // 53
  CS4, C4, B3, AS3, A3, GS3, G3, FS3, F3, E3, DS3, D3, // 54
  CS3, E3, F3, GS3, B3, D4, F4, GS4, B4, B4, // 55
  ZZ, A4, E4, C4, A3, ZZ, // 56
  
  ZZ, C5, B4, A4, GS4, B4, A4, F4, // 57
  D4, B3, G4, F4, E4, // 58
  B3, C4, D4, C4, B3, D4, // 59
  C4, A3, E3, E3, // 60
  
  ZZ, DS4, E4, // 61
  F4, E4, B4, C5, // 62
  D5, DS5, E5, GS4, A4, // 63
  ZZ, A4, // 64
  
  ZZ, // 65
};

PROGMEM const int duration[] = {
  WN, WN, WN+HN, EN, EN, QN, // 0
  WN, HN, HN+WN, WN, // 0
  WN, WN, WN+HN, EN, EN, QN, // 0
  WN, HN, HN+WN, WN, // 0
  WN, WN, WN+HN, EN, EN, QN, // 0
  WN, HN, HN+WN, WN, // 0
  WN, 3*WN, // 0
  4*WN, // 0

  WN, WN, WN+HN, EN, EN, QN, // 0
  WN, HN, HN+WN, WN, // 0
  WN, WN, WN+HN, EN, EN, QN, // 0
  WN, HN, HN+WN, WN, // 0
  WN, WN, WN+HN, EN, EN, QN, // 0
  WN, HN, HN+WN, WN, // 0
  WN, 2*WN + HN + QN, QN, // 0
  WN, WN, WN, WN, // 0
  
  HN, HN, HN, HN, HN, HN, WN, // 1
  HN, HN, WN, WN, WN, // 2
  HN, QN, QN, HN, HN, HN, HN, HN, HN, // 3
  WN, HN, HN, WN, WN, // 4

  WN+HN, HN, HN, HN, HN, HN, // 5
  QN, QN, HN, HN, HN, WN, WN, // 6
  WN, HNT, HNT, HNT, WN, HNT, HNT, HNT, // 7
  HN, HN, WN, WN, WN, // 8

  WN+HN, HN, WN, HN, HN, // 9
  HN, WN+HN, HN, HN, HN, HN, // 10
  WN, HN, HN, HN, HN, HN, HN, // 11
  HN, HN, HN, HN, WN, HN, HN, // 12

  HN, HN, HN, HN, HN, HN, HN, HN, // 13
  WN, HN, HN, WN, HN, HN, // 14
  HN, WN+HN, HN, HN, HN, HN, // 15
  HN, HN, WN, WN, WN, // 16

  HN, HN, WN, WN, WN, // 17
  WN, HN, HN, WN, HN, HN, // 18
  WN, HN, HN, HN, HN, HN, HN, // 19
  HN, HN, HN, HN, HN, HN, WN, // 20

  WN, QN, QN, QN, QN, WN, HN, HN, // 21
  HN, HN, HN, HN, WN+HN, HN, // 22
  WN, QN, QN, HN, HN, HN, HN, HN, // 23
  HN, HN, WN, WN, HN, HN, // 24

  HN, HN, HN, HN, WNT, WNT, WNT, // 25
  WN, 2*WN+HN, HN, // 26
  WN, HN, HN, HN, HN, HN, HN, // 27
  WN, WN, WN, WN, // 28

  WN+HN, HN, HN, HN, HN, HN, // 29
  HN, HN, HN, HN, HN, HN, HN, HN, // 30
  HN, HN, HN, HN, HN, HN, HN, HN, // 31
  HN, HN, WN, WN, WN, // 32

  HN, QN, QN, HN, HN, WN, HN, HN, // 33
  HN, HN, HN, HN, WN, WN, // 34
  WN, QN, QN, HN, HN, HN, HN, HN, // 35
  3*WN, WN, // 36

  3*WN, HN, HN, // 37
  HN, HN, WN, WN, WN, // 38
  HN, HN, HN, HN, HN, HN, HN, HN, // 39
  WN, WN+HN, HN, HN, HN, // 40
  
  HN, HN, HN, HN, HN, HN, HN, HN, // 41
  WN+HN, HN, HN, HN, HN, HN, // 42
  HN, HN, HN, HN, HN, HN, HN, HN, // 43
  WN+HN, HN, HN, HN, WN, // 44

  2*WN, WN, WN, // 45
  WN, WN, 2*WN, // 46
  HN, HN, HN, HN, HN, HN, HN, HN, // 47
  WN, HN, HN, HN, HN, HN, HN, // 48

  WN, HN, HN, WN, WN, // 49
  WN, WN, WN, HN, HN, // 50
  WN, WN, WN, WN, // 51
  WN, WN, HN, QN, QN, QN, QN, QN, QN, // 52

  WN, WN, HNT, HNT, HNT, HNT, HNT, HNT, // 53
  HNT, HNT, HNT, HNT, HNT, HNT, HNT, HNT, HNT, HNT, HNT, HNT, // 54
  HNT, HNT, HNT, QN, QN, QN, QN, WN, HN, HN, // 55
  HN, HN, HN, HN, WN+HN, HN, // 56

  HN, HN, HN, HN, HN, HN, HN, HN, // 57
  HN, HN, 2*WN, HN, HN, // 58
  QN, QN, HN, HN, HN, 2*WN, // 59
  HN, HN, WN, 2*WN, // 60

  2*WN, WN, WN, // 61
  WN, WN, WN, WN, // 62
  WN, HN, HN+WN, HN, HN, // 63
  HN, 3*WN+HN, // 64
  
  4*WN, // 65
};

#endif // MINOR_SWING_H
