#pragma once

#include <stdbool.h>

// Number of blink iterations per pattern period. On the iteration where the
// count is a multiple of this, the LED is not toggled, which leaves one
// double-length gap per period.
#define BLINK_PERIOD 11

/*
 * Pure blink logic: returns the LED state for the next iteration and
 * advances *count by one. The state toggles unless *count (the value
 * before the increment) is a multiple of BLINK_PERIOD.
 *
 *   on    - current LED state
 *   count - in/out iteration counter
 */
bool blink_next_state(bool on, int *count);
