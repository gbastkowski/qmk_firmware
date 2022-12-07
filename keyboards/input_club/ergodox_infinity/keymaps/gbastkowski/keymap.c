#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define L0 0 // default layer
#define L1 1
#define L2 2

#define KC_STAB LSFT(KC_TAB)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * LAYOUT 0
 */
[L0] = LAYOUT_ergodox_pretty(
/*
 * ,---------------------------------------------------------.left         right,---------------------------------------------------------.
 * |  Vol +  |   1   |   2   |   3   |   4   |   5   |   =   |hand          hand|   +   |   6   |   7   |   8   |   9   |   0   |         |
 * |---------+-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------+---------|
 * |  Vol -  |   Q   |   W   |   E   |   R   |   T   |   \   |                  |   '   |   Y   |   U   |   I   |   O   |   P   |         |
 * |---------+-------+-------+-------+-------+-------|       |                  |       |-------+-------+-------+-------+-------+---------|
 * |  Mute   |   A   |   S   |   D   |   F   |   G   |-------|                  +-------|   H   |   J   |   K   |   L   |   ;   |         |
 * |---------+-------+-------+-------+-------+-------|   [   |                  |   ]   |-------+-------+-------+-------+-------+---------|
 * |  Play   |   Z   |   X   |   C   |   V   |   B   |       |                  |       |   N   |   M   |   ,   |   .   |   /   |         |
 * `---------+-------+-------+-------+-------+---------------'                  +---------------+-------+-------+-------+-------+---------|
 *   | AltGr | Shift | LCtrl |  Alt  | LGui  |       ,---------------.  ,---------------.       | RGui  |  Alt  | RCtrl | Shift |  AltGr  |
 *   `---------------------------------------'       | ShTab |  Tab  |  | L1Lck | L2Lck |       `-----------------------------------------'
 *                                           ,-------+-------+-------|  |-------+-------+-------.
 *                                           |       |       |  App  |  |  L2   |       |       |
 *                                           | Space |  Ent  |-------|  |-------| BkSpc |  Del  |
 *                                           |       |       |  Esc  |  |  L1   |       |       |
 *                                           `-----------------------'  `-----------------------'
 */
   KC_VOLU   ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_EQL ,                   KC_MINS,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______  ,
   KC_VOLD   ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_BSLS,                   KC_QUOT,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,_______  ,
   KC_MUTE   ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                                   KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,_______  ,
   KC_MPLY   ,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_LBRC,                   KC_RBRC,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,_______  ,
   KC_RALT   ,KC_LSFT,KC_LCTL,KC_LALT,KC_LGUI,                                                   KC_RGUI,KC_LALT,KC_RCTL,KC_RSFT,KC_RALT  ,
                                                      KC_STAB,KC_TAB ,   TG(L1) ,TG(L2) ,
                                                              KC_APP ,   MO(L2) ,
                                               KC_SPC,KC_ENT ,KC_ESC ,   MO(L1) ,KC_BSPC,KC_DEL
),


/*
 * LAYOUT 1
 */
[L1] = LAYOUT_ergodox_pretty(
/*
 * ,---------------------------------------------------------.left         right,---------------------------------------------------------.
 * |  Next   |  f1   |  f2   |  f3   |  f4   |  f5   |  f11  |hand          hand|  f12  |  f6   |  f7   |  f8   |  f9   |  f10  |         |
 * |---------+-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------+---------|
 * |  Prev   |   !   |   @   |   {   |   }   |   |   |   ~   |                  |   `   |       |       |       |       |       |         |
 * |---------+-------+-------+-------+-------+-------|       |                  |       |-------+-------+-------+-------+-------+---------|
 * |  Stop   |   #   |   $   |   (   |   )   |   `   |-------|                  +-------| Left  | Down  |  Up   | Right |       |         |
 * |---------+-------+-------+-------+-------+-------|       |                  |       |-------+-------+-------+-------+-------+---------|
 * |         |   %   |   ^   |   [   |   ]   |       |       |                  |       |       |       |       |       |       |         |
 * `---------+-------+-------+-------+-------+---------------'                  +---------------+-------+-------+-------+-------+---------|
 *   |       |       |       |       |       |       ,---------------.  ,---------------.       |       |       |       |       |         |
 *   `---------------------------------------'       |       |       |  |       |       |       `-----------------------------------------'
 *                                           ,-------+-------+-------|  |-------+-------+-------.
 *                                           |       |       |       |  |       |       |       |
 *                                           |       |       |-------|  |-------|       |       |
 *                                           |       |       |       |  |       |       |       |
 *                                           `-----------------------'  `-----------------------'
 */
   KC_MNXT   ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F11 ,                   KC_F12 ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______  ,
   KC_MPRV   ,KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_PIPE,KC_TILD,                   KC_GRV ,_______,_______,_______,_______,_______,_______  ,
   KC_STOP   ,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                   KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______  ,
   _______   ,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,_______,_______,                   _______,_______,_______,_______,_______,_______,_______  ,
   _______   ,_______,_______,_______,_______,                                                   _______,_______,_______,_______,_______  ,
                                                      _______,_______,   _______,_______,
                                                              _______,   _______,
                                              _______,_______,_______,   _______,_______,_______
),
[L2] = LAYOUT_ergodox_pretty(
/*
 * ,---------------------------------------------------------.left         right,---------------------------------------------------------.
 * |  Flash  |       |       |       |       |       |       |hand          hand|       |       | NmLck |  P/   |  P*   |  P-   |         |
 * |---------+-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------+---------|
 * |         |  P/   |  P7   |  P8   |  P9   |  P-   |   ~   |                  |       |       |  P7   |  P8   |  P9   |  P+   |         |
 * |---------+-------+-------+-------+-------+-------|       |                  |       |-------+-------+-------+-------+-------+---------|
 * |         |  P*   |  P4   |  P5   |  P6   |  P+   |-------|                  +-------|       |  P4   |  P5   |  P6   |  P+   |         |
 * |---------+-------+-------+-------+-------+-------|       |                  |       |-------+-------+-------+-------+-------+---------|
 * |         |  P0   |  P1   |  P2   |  P3   |  P.   |       |                  |       |       |  P1   |  P2   |  P3   | Pent  |         |
 * `---------+-------+-------+-------+-------+---------------'                  +---------------+-------+-------+-------+-------+---------|
 *   |       |       |       |       |       |       ,---------------.  ,---------------.       |       |       |  P.   | Pent  |         |
 *   `---------------------------------------'       |       |       |  |       |       |       `-----------------------------------------'
 *                                           ,-------+-------+-------|  |-------+-------+-------.
 *                                           |       |       |       |  |       |       |       |
 *                                           |       |  Ent  |-------|  |-------|       |  P0   |
 *                                           |       |       |       |  |       |       |       |
 *                                           `-----------------------'  `-----------------------'
 */
    RESET    ,_______,_______,_______,_______,_______,_______,                   _______,_______,KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,_______  ,
    _______  ,KC_PSLS,KC_KP_7,KC_KP_8,KC_KP_9,KC_PMNS,KC_TILD,                   _______,_______,KC_KP_7,KC_KP_8,KC_KP_9,KC_PPLS,_______  ,
    _______  ,KC_PAST,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,                                   _______,KC_KP_4,KC_KP_5,KC_KP_6,KC_PPLS,_______  ,
    _______  ,KC_KP_0,KC_KP_1,KC_KP_2,KC_KP_3,KC_PDOT,_______,                   _______,_______,KC_KP_1,KC_KP_2,KC_KP_3,KC_PENT,_______  ,
    _______  ,_______,_______,_______,_______,                                                   _______,_______,KC_PDOT,KC_PENT,_______  ,
                                                      _______,_______,   _______,_______,
                                                              _______,   _______,
                                              _______,KC_PENT,_______,   _______,_______,KC_KP_0
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
