#pragma once

#include <pebble.h>

#define ANTIALIASING true

// Layout
#define MARGIN 5
#define THICKNESS 3
#define ANIMATION_DELAY 300
#define ANIMATION_DURATION 1000
#define HAND_LENGTH_SEC 65
#define HAND_LENGTH_MIN 65
#define HAND_LENGTH_HOUR 45

#define PERSIST_DEFAULTS_SET 3489

// Persist
#define PERSIST_KEY_DATE        0
#define PERSIST_KEY_DAY         1
#define PERSIST_KEY_BT          2
#define PERSIST_KEY_BATTERY     3
#define PERSIST_KEY_SECOND_HAND 4
#define PERSIST_KEY_THEME       5
#define NUM_SETTINGS            5

typedef struct {
  int days;
  int hours;
  int minutes;
  int seconds;
} Time;

// Theme IDs
enum theme_id {
  THEME_BLUE   = 0,
  THEME_GREEN  = 1,
  THEME_RED    = 2,
  THEME_PURPLE = 3
};