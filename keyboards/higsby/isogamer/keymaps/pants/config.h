#pragma once

#ifdef COMBO_ENABLE
#    define COMBO_COUNT 1
#    define COMBO_TERM 25
#endif

// #define USB_POLLING_INTERVAL_MS 5
// Prevent normall rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT
// // Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
// // configure the global tapping term (default 200)
#define TAPPING_TERM 175
// // enable rapid switch from tap to hold, disables double tap hold auto-repeat
// #define TAPPING_FORCE_HOLD 
