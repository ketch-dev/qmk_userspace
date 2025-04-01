#pragma once
#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__


#define TAPPING_TERM 250
#define ONESHOT_TIMEOUT 250
#define ONESHOT_TAP_TOGGLE 0
#define HOLD_ON_OTHER_KEY_PRESS
#define QUICK_TAP_TERM 0