/* Copyright 2020 makenova
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

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_bspc,KC_BSPC), // 1
  COMBO(combo_tab,KC_TAB), // 2
  COMBO(combo_esc,KC_ESC), // 3
  COMBO(combo_tilde,KC_GRV), // 4
  COMBO(combo_ent,KC_ENT), // 5
};
#endif

// ctrl
#define CTRL_A LCTL_T(KC_A)
#define CTRL_SCLN RCTL_T(KC_SCLN)
#define CTRL_TAB MT(MOD_LCTL,KC_TAB)
// alt
#define ALT_S LALT_T(KC_S)
#define ALT_L RALT_T(KC_L)
//gui
#define GUI_G LGUI_T(KC_G)
#define GUI_H RGUI_T(KC_H)
// shift
#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLSH RSFT_T(KC_SLSH)
// layers
// #define OS_SHIFT OSM(MOD_RSFT)
// #define OS_3 OSL(3)
#define LT1_SPC LT(1,KC_SPC)
#define LT2_ESC LT(2,KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,      KC_BSPC,
    CTRL_TAB, CTRL_A,  ALT_S,   KC_D,    KC_F,    GUI_G,  GUI_H, KC_J,  KC_K,    ALT_L,   CTRL_SCLN,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT,  SFT_SLSH,
    KC_LCTL,  KC_LALT, KC_LGUI, LT1_SPC, KC_RGUI, LT2_ESC
    ),
    [1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,  KC_9,     KC_0,   KC_DEL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUOT,
    KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_MINS, KC_EQL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
    KC_POWER, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL,
    KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_F14, KC_F15,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS,
    RESET, KC_TRNS, KC_POWER, KC_TRNS, KC_TRNS, KC_TRNS
    )
};