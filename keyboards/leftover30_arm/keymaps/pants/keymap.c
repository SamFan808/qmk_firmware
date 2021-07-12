/* Copyright 2020 marksard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
    _BASE,
    _NUMS,
    _NUMSYM,
    _NAV,
    _ADJUST,
};

enum custom_events {
    COMBO_GESC,
    COMBO_TAB,
};

// #define KC_ESAD  LT(_ADJUST, KC_ESC)
// #define KC_BSLO  LT(_NUMS, KC_BSPC)

#define KC_NUMSPC  LT(_NUMS, KC_SPC)
#define KC_NSCLN LT(_NUMSYM, KC_SCLN)
#define KC_ANAV  LT(_NAV, KC_A)
#define KC_AJST  MO(_ADJUST)
#define KC_RRCTL RCTL_T(KC_QUOT)
#define KC_Z_SF  LSFT_T(KC_Z)
#define KC_ENSF  RSFT_T(KC_ENT)

#define KC_UNDO  LCTL(KC_Z)
#define KC_REDO  LCTL(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_iso(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_Q_AL,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_ANAV,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_ENSF,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_Z_SF,    KC_X_AL, KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_MPLY, KC_LCTL,                                KC_NUMSPC,                                 KC_NSCLN, KC_RRCTL
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_NUMS] = LAYOUT_iso(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_1,      KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_TRNS,   KC_MPLY, KC_VOLD,  KC_VOLU, KC_MPRV, KC_MNXT, KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_F7,     KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_GRV,  KC_TRNS, KC_SLSH,     
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_UNDO, KC_LGUI,                                _______,                                 KC_AJST, _______
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_NUMSYM] = LAYOUT_iso(
  //,-----------------------------------------------------------------------------------------------------------.
               KC_EXLM,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LRPN, KC_RPRN, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILD, KC_TRNS,  KC_QUES,     
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_REDO, _______,                                KC_AJST,                                 _______, _______
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_NAV] = LAYOUT_iso(
  //,-----------------------------------------------------------------------------------------------------------.
                 KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CALC, KC_HOME, KC_UP,  KC_END,  KC_PGUP, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DN, KC_RIGHT,     KC_PGDN,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX,     
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      _______, _______,                                _______,                                 _______, KC_CAPS
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_iso(
  //,-----------------------------------------------------------------------------------------------------------.
                 RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,   KC_NLCK,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX,     
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      RESET, _______,                                _______,                                 _______, KC_CAPS
  //`-----------------------------------------------------------------------------------------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case KC_NUMSPC:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_gesc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_GESC] = COMBO(combo_gesc, KC_GESC),
  [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
};
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder
        if (IS_LAYER_ON(_ADJUST)) {
          if (clockwise) {
              rgblight_increase_hue_noeeprom();
          } else {
              rgblight_decrease_hue_noeeprom();
          }
        } else if (IS_LAYER_ON(_NUMS)) {
          tap_code16((clockwise == true) ? LCTL(KC_Y) : LCTL(KC_Z));
        } else if (IS_LAYER_ON(_NUMSYM)) {
          tap_code16((clockwise == true) ? S(KC_DOWN) : S(KC_UP));
        } else {
          tap_code((clockwise == true) ? KC_WH_D : KC_WH_U);
        }

    }
    else if (index == 1) { //right encoder
    if (IS_LAYER_ON(_ADJUST)) {
          if (clockwise) {
              rgblight_increase_hue_noeeprom();
          } else {
              rgblight_decrease_hue_noeeprom();
          }
        } else if (IS_LAYER_ON(_NUMS)) {
          tap_code16((clockwise == true) ? LCTL(KC_Y) : LCTL(KC_Z));
        } else if (IS_LAYER_ON(_NUMSYM)) {
          tap_code16((clockwise == true) ? S(KC_DOWN) : S(KC_UP));
        } else {
          tap_code((clockwise == true) ? KC_WH_D : KC_WH_U);
        }
    }
    return true;
}

// for exsample customize of LED inducator
bool led_update_user(led_t led_state) {
    writePin(B10, IS_LAYER_ON(_NUMS));
    writePin(B11, IS_LAYER_ON(_NUMSYM));
    return false;
}



