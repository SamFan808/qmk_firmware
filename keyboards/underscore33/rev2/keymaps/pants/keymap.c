/* Copyright 2020 tominabox1
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

enum layers{
  _BASE,
  _NUMS,
  _NUM_SYM,
  _TABSCAPE,
  _NAV,
  _UTIL
};

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  // COMBO_QUES,
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_GA LT(4,KC_A)
#define KC_LENT LT(3, KC_ENT)
#define KC_SZ LSFT_T(KC_Z)
#define KC_SSLS RSFT_T(KC_SLSH)
#define KC_SPC1 LT(2,KC_SPC)
#define KC_SPC2 LT(1,KC_SPC)
#define KC_A7 MO(_UTIL)
#define KC_CQUOT RCTL_T(KC_QUOT)
#define KC_ASCLN RALT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_33_split_space(
      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
      KC_GA, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_LENT,
      KC_SZ, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SSLS,
      KC_LCTL, KC_LALT, KC_SPC1, KC_SPC2, KC_ASCLN, KC_CQUOT
      ),

  [_NUMS] = LAYOUT_33_split_space(
      KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
      KC_A7, KC_MPLY, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS,
      KC_NO, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS
      ),

  [_NUM_SYM] = LAYOUT_33_split_space(
      KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_PIPE,
      KC_LGUI, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
      ),
  
  [_TABSCAPE] = LAYOUT_33_split_space(
      KC_GRV, KC_TILD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
      ),

  [_NAV] = LAYOUT_33_split_space(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
      ),

  [_UTIL] = LAYOUT_33_split_space(
      RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_CALC, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
      )
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
// const uint16_t PROGMEM combo_ques[] = {KC_COMM, KC_SDOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  // [COMBO_QUES] = COMBO(combo_ques,KC_SLSH),
};
#endif
