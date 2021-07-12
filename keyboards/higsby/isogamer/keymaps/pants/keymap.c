#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUMS,
  _SYM, 
  _FN,
  _UTIL,
  _NAV
};

enum combo_events {
  COMBO_ESC
};

#define NUM MO(_NUMS)
#define FN MO(_FN)
#define xxx KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
   KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
   LSFT_T(KC_TAB),LT(_NAV, KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_ENT),
   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,
   KC_LCPO, KC_RAPC,                LT(_NUMS, KC_SPC),                  MO(_SYM),   FN
  ),
  [_NUMS] = LAYOUT(
    xxx, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, xxx,
    xxx, KC_GRV, xxx, xxx, xxx, xxx, xxx, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_QUOT,
    KC_BSLS, xxx, xxx, xxx, KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    KC_LGUI, xxx,                   xxx,                          xxx, xxx 
  ),
  [_SYM] = LAYOUT(
    xxx, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, xxx,
    xxx, KC_GRV, xxx, xxx, xxx, xxx, xxx, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUOT,
    KC_PIPE, xxx, xxx, xxx, KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    KC_LGUI, xxx,                   xxx,                          xxx, xxx 
  ),
  [_FN] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    xxx, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, xxx, xxx, xxx, xxx, xxx, xxx,
    xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    MO(_UTIL), xxx,                 xxx,                          xxx, xxx
   ),
   [_UTIL] = LAYOUT(
    RESET, xxx, xxx, xxx, xxx, xxx, KC_CALC, xxx, xxx, xxx, xxx, xxx,
    KC_CAPS, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    xxx, xxx,                               xxx,                  xxx, xxx
   ),
    [_NAV] = LAYOUT(
    xxx, xxx, xxx, xxx, xxx, xxx, xxx, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_DEL,
    xxx, xxx, xxx, xxx, xxx, xxx, xxx, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, xxx,
    xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    xxx, xxx,                               xxx,                                xxx, xxx
   )
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC)
};

#endif
 
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
  return true;
}