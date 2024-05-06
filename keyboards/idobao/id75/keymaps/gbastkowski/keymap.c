/* Copyright 2018 Milton Griffin
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

// Keyboard Layers
#define _QW 0
#define _FN 1
#define _KB 2

// Momentary/Tap Combos used by this layout
#define LT_FNESC LT(_FN, KC_ESC) // ESC when tapped, Fn layer when held
#define MK_LPAR LSFT(KC_9)
#define MK_RPAR LSFT(KC_0)
#define MK_LBRA LSFT(KC_LBRC)
#define MK_RBRA LSFT(KC_RBRC)
#define MK_TILD LSFT(KC_GRV)
#define MK_RALT OSM(MOD_RALT)
#define TG_FN   TG(_FN)
#define TG_KB   TG(_KB)
#define TO_FN   TO(_FN)
#define TO_KB   TO(_KB)

// TODO KC_GRV, KC_BSPC, KC_HOME,  KC_LEFT,  KC_DOWN, KC_DEL, KC_PGUP, KC_END, KC_UP, KC_PGDN, KC_RSFT, KC_LGUI, KC_LALT, MO(_FN)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QW] = LAYOUT_ortho_5x15(/* QWERTY */
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,     KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        KC_MUTE, KC_VOLD, KC_VOLU,
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSLS,     KC_QUOT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,        KC_MRWD, KC_MPLY, KC_MFFD,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,     KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_HOME, TG_FN,   KC_PGUP,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,      KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_END,  KC_UP,   KC_PGDN,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_ENT,      LT_FNESC,KC_BSPC, KC_RGUI, KC_LALT, KC_RCTL, KC_RSFT,     KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT_ortho_5x15(/* FUNCTION */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_PSCR, KC_SCRL, KC_PAUS,
        _______, _______, MK_LPAR, MK_RPAR, _______, MK_TILD,     KC_GRV,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,     _______, _______, _______,
        _______, _______, KC_LBRC, KC_RBRC, _______, _______,     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,     _______, _______, TG_KB,
        _______, _______, MK_LBRA, MK_RBRA, _______, _______,     _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______,     _______, KC_DEL,  _______, _______, _______, _______,     _______, _______, QK_BOOT
    ),

    [_KB] = LAYOUT_ortho_5x15(/* FUNCTION */
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, RGB_HUD, RGB_HUI,     _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, RGB_SAD, RGB_SAI,     _______, _______, _______, _______, _______, _______,     _______, _______, TG_KB,
        _______, _______, _______, _______, RGB_VAD, RGB_VAI,     _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, RGB_TOG, RGB_RMOD,RGB_MOD,     _______, _______, _______, _______, _______, _______,     _______, _______, _______
    ),

};


/* void set_hsv_at(HSV hsv, uint8_t index); */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     return true; */
/* } */

bool rgb_matrix_indicators_user(void) {
    HSV hsv = rgb_matrix_config.hsv;
    if (host_keyboard_led_state().caps_lock) {
        HSV hsv_inv_hue = {hsv.h + 128, hsv.s, hsv.v};
        set_hsv_at(hsv_inv_hue, 30);
    }
    indicate which higher layer is currently active on which key
    HSV hsv1 = {hsv.h - 64, hsv.s, hsv.v};
    HSV hsv2 = {hsv.h + 64, hsv.s, hsv.v};
    except when we are in any animated LED mode
    if (rgb_matrix_config.mode < RGB_MATRIX_BREATHING || rgb_matrix_config.mode > RGB_MATRIX_JELLYBEAN_RAINDROPS) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            keypos_t pos = {col, row};
            uint8_t key_layer = layer_switch_get_layer(pos);
            uint8_t key_led = g_led_config.matrix_co[row][col];
            if (key_led != NO_LED) {
                switch(key_layer) {
                case _QW:
                    set_hsv_at(hsv2, key_led);
                    break;
                case _FN:
                    set_hsv_at(hsv1, key_led);
                    break;
                case _KB:
                    set_hsv_at(hsv1, key_led);
                    break;
                default:
                    break;
                }
            }
        }
    }
    }
    sticky layer indicators regardless of RGB mode. Hardcoded for lack of better idea.
    set_hsv_at(hsv1, 63);
    set_hsv_at(hsv2, 57);
    return false;
}

/* void set_hsv_at(HSV hsv, uint8_t index) { */
/*     RGB rgb = hsv_to_rgb(hsv); */
/*     rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b); */
/* } */
