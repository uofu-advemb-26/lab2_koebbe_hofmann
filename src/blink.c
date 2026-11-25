#include "blink.h"

bool blink_next_state(bool on, int *count)
{
    // Post-increment on purpose: the original loop tested `count++ % 11`,
    // so the check uses the value before the increment. Changing this would
    // shift the position of the long gap by one blink.
    return ((*count)++ % BLINK_PERIOD) ? !on : on;
}
