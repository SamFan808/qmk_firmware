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

#pragma once

#ifdef COMBO_ENABLE
#   define COMBO_COUNT 2
#   define COMBO_TERM  25
#endif

// place overrides here
#define TAPPING_TERM 175
// Prevent normall rollover on alphas from accidentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT
// // Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

#define TAPPING_LAYER_TERM 150 // Custom LT Tapping term
#define TAPPING_TERM_PER_KEY
