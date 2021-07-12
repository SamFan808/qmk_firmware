#include "EU_ISO.h"

enum layers {
    _BASE = 0,
    _NUMS,
    _SYM,
    _NAV,
    _FN
};

// I put these combos in because they're easy to impliment and it gives you an idea of what you need to do
// Go nuts, have fun! It's why I build the board :)
// enum WOMBO_COMBOS {
//     VOLUME_UP = 0,
//     VOLUME_DOWN
// };

// const uint16_t PROGMEM VOLUME_UP_COMBO[] = { KC_F1, KC_F2, COMBO_END };
// const uint16_t PROGMEM VOLUME_DN_COMBO[] = { KC_F3, KC_F4, COMBO_END };

// combo_t key_combos[COMBO_COUNT] = {
//     [VOLUME_UP] = COMBO(VOLUME_UP_COMBO, KC_VOLU),
//     [VOLUME_DOWN] = COMBO(VOLUME_DN_COMBO, KC_VOLD)
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_euiso_bigspace(
                          KC_GESC,           KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_VOLD, KC_VOLU, LT(_NAV, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_MPLY, KC_MNXT, KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_QUOT),
                          KC_LCPO,   KC_RAPC,                          LT(_NUMS, KC_SPC),                            MO(_SYM), MO(_FN)
    ),

    [_NUMS] = LAYOUT_euiso_bigspace(
                          KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_TRNS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC, KC_TRNS,
        _______, _______, _______, KC_BSLS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, KC_DQUO,
                          KC_LGUI, _______,                         _______,                                         _______,  _______
    ),

    [_SYM] = LAYOUT_euiso_bigspace(
                          KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,
        _______, _______, _______, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______,                         _______,                                        _______, _______
    ),

    [_NAV] = LAYOUT_euiso_bigspace(
                          _______, _______, _______, _______, _______, _______, KC_CALC, KC_HOME, KC_UP,   KC_END,   KC_PGUP, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_TRNS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
                          _______, _______,                         _______,                                         _______, RESET
   ), 
   
   [_FN] = LAYOUT_euiso_bigspace(
                          KC_F1,   KC_F2,  KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
                          _______, _______,                         _______,                                         _______, _______
   )
};
