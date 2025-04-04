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

#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 800
#define CHARYBDIS_MINIMUM_SNIPING_DPI 400

#define MOUSE_EXTENDED_REPORT
#define MACCEL_TAKEOFF 0.5      // lower/higher value = curve takes off more smoothly/abruptly
#define MACCEL_GROWTH_RATE 0.1 // lower/higher value = curve reaches its upper limit slower/faster
#define MACCEL_OFFSET 2.2       // lower/higher value = acceleration kicks in earlier/later
#define MACCEL_LIMIT 0.2        // lower limit of accel curve (minimum acceleration factor)

#define RGBLIGHT_LAYERS
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE
