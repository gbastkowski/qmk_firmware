#include QMK_KEYBOARD_H
#include "muse.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define L_QWERTSPLITLY 0
#define L_FN 1
#define L_STENO 2

// Defines for Mac specific key accelerators used in map. Some of these are very awkward to type.
// These are the default bindings for Mac, some of which may be turned off or changed, check your
// settings in System Preferences
#define LS_TAB LSFT(KC_TAB) // Shift-TAB
#define MF_MENU LCTL(KC_F2) // Move focus to menu bar default keybinding in MacOS
#define MF_DOCK LCTL(KC_F3) // Move focus to dock
#define MF_TOOL LCTL(KC_F5) // Move focus to window toolbar
#define MF_STAT LCTL(KC_F8) // Move focus to status bar side of menu bar
#define MF_DRWR LALT(LGUI(KC_QUOTE)) // Move focus to window drawer
#define MF_LPAD LALT(LGUI(KC_Q)) // Show Launchpad
#define MF_NOTI LALT(LGUI(LCTL(KC_B))) // Show Notification Center
#define MF_DASH LALT(LGUI(LCTL(KC_C))) // Show Dashboard
#define MF_HELP LSFT(LGUI(KC_SLASH)) // Position in menu Help search box

// Momentary/Tap Combos used by this layout
#define LT_FNESC LT(L_FN, KC_ESC) // ESC when tapped, Fn layer when held

#define MT_SHSPC MT(MOD_RSFT, KC_SPC) // Spc when tapped, right shift when held
#define MK_LPAR LSFT(KC_9)
#define MK_RPAR LSFT(KC_0)
#define MK_LBRA LSFT(KC_LBRC)
#define MK_RBRA LSFT(KC_RBRC)
#define MK_TILD LSFT(KC_GRV)
#define MK_RALT OSM(MOD_RALT)
#define TG_FN   TG(L_FN)

enum custom_keycodes {
    PLOVER = SAFE_RANGE,
    EXT_PLV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QwertSplitly
 * ,------------------------------------------------------------------------------------------------------------------------.
 * |    1    |    2    |    3    |    4    |    5    |    -    ||    =    |    6    |    7    |    8    |    9    |    0    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |    Q    |    W    |    E    |    R    |    T    |    \    ||    '    |    Y    |    U    |    I    |    O    |    P    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |    A    |    S    |    D    |    F    |    G    |    [    ||    ]    |    H    |    J    |    K    |    L    |    ;    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |    Z    |    X    |    C    |    V    |    B    |   Tab   ||  AltGr  |    N    |    M    |    ,    |    .    |    /    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * | LShift  |  LCtrl  |   Alt   |  LGui   |  Space  |  Enter  || Fn/ESC  |  BkSpc  |  RGui   |   Alt   |  RCtrl  | RShift  |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
[L_QWERTSPLITLY] = LAYOUT_preonic_grid( \
    KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,KC_MINUS  ,KC_EQL   ,KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,\
    KC_Q     ,KC_W     ,KC_E     ,KC_R     ,KC_T     ,KC_BSLS   ,KC_QUOTE ,KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,\
    KC_A     ,KC_S     ,KC_D     ,KC_F     ,KC_G     ,KC_LBRC   ,KC_RBRC  ,KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN  ,\
    KC_Z     ,KC_X     ,KC_C     ,KC_V     ,KC_B     ,KC_TAB    ,MK_RALT  ,KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,\
    KC_LSFT  ,KC_LCTL  ,KC_LALT  ,KC_LGUI  ,KC_SPC   ,KC_ENT    ,LT_FNESC ,KC_BSPC  ,KC_RGUI  ,KC_LALT  ,KC_RCTL  ,KC_RSFT   \
),

/* Fn
 * ,------------------------------------------------------------------------------------------------------------------------.
 * |   F1    |   F2    |   F3    |   F4    |   F5    |         ||         |   F6    |   F7    |   F8    |   F9    |   F10   |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |         |         |    (    |    )    |         |    ~    ||    `    |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |         |         |    [    |    ]    |         |         ||         |  Left   |  Down   |   Up    |  Rght   |    '    |
 * |---------+---------+---------+---------+---------+---------||---------+---------+---------+---------+---------+---------|
 * |         |         |    {    |    }    |         |         ||   Fn    |         |         |         |         |    \    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |  CAPS   |  STENO  |         |         |   Tab   |         ||         |   Del   |         |         |         |         |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
[L_FN] = LAYOUT_preonic_grid( \
    KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,_______   ,_______  ,KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,\
    _______  ,_______  ,MK_LPAR  ,MK_RPAR  ,_______  ,MK_TILD   ,KC_GRV   ,_______  ,_______  ,_______  ,_______  ,_______  ,\
    _______  ,_______  ,KC_LBRC  ,KC_RBRC  ,_______  ,_______   ,_______  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RGHT  ,_______  ,\
    _______  ,_______  ,MK_LBRA  ,MK_RBRA  ,_______  ,_______   ,TG_FN    ,_______  ,_______  ,_______  ,_______  ,_______  ,\
    KC_CAPS  ,PLOVER   ,_______  ,_______  ,_______  ,_______   ,_______  ,KC_DEL   ,_______  ,_______  ,_______  ,_______   \
),

/* Steno
 * ,------------------------------------------------------------------------------------------------------------------------.
 * |    #    |    #    |    #    |    #    |    #    |    #    ||    #    |    #    |    #    |    #    |    #    |    #    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |   Fn    |    S    |    T    |    P    |    H    |    *    ||    *    |    F    |    P    |    L    |    T    |    D    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |         |    S    |    K    |    W    |    R    |    *    ||    *    |    R    |    B    |    G    |    S    |    Z    |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |         |         |         |         |         |         ||         |         |         |         |         |         |
 * |---------+---------+---------+---------+---------+---------++---------+---------+---------+---------+---------+---------|
 * |  Exit   |         |         |         |    A    |    O    ||    E    |    U    |         |   PWR   |  RES1   |  RES2   |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
[L_STENO] = LAYOUT_preonic_grid( \
    STN_N1   ,STN_N2   ,STN_N3   ,STN_N4   ,STN_N5   ,STN_N6    ,STN_N7   ,STN_N8   ,STN_N9   ,STN_NA   ,STN_NB   ,STN_NC   ,\
    STN_FN   ,STN_S1   ,STN_TL   ,STN_PL   ,STN_HL   ,STN_ST1   ,STN_ST3  ,STN_FR   ,STN_PR   ,STN_LR   ,STN_TR   ,STN_DR   ,\
    XXXXXXX  ,STN_S2   ,STN_KL   ,STN_WL   ,STN_RL   ,STN_ST2   ,STN_ST4  ,STN_RR   ,STN_BR   ,STN_GR   ,STN_SR   ,STN_ZR   ,\
    XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,\
    EXT_PLV  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,STN_A    ,STN_O     ,STN_E    ,STN_U    ,XXXXXXX  ,STN_PWR  ,STN_RE1  ,STN_RE2   \
)

};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_C5, 8},
  {NOTE_E6, 4},
  {NOTE_D6, 16},
  {NOTE_G6, 8}
};

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        /* startup_user(); */
    #endif
#ifdef STENO_ENABLE_ALL
    steno_set_mode(STENO_MODE_GEMINI);
#endif
}

#ifdef AUDIO_ENABLE

/* void startup_user() */
/* { */
/*     PLAY_SONG(tone_startup); */
/* } */

/* void shutdown_user() */
/* { */
/*     PLAY_SONG(tone_goodbye); */
/*     stop_all_notes(); */
/* } */

/* void music_on_user(void) */
/* { */
/*     music_scale_user(); */
/* } */

/* void music_scale_user(void) */
/* { */
/*     PLAY_SONG(music_scale); */
/* } */

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PLOVER:
            if (!record->event.pressed) {
                layer_on(L_STENO);
            }
            return false;
        case EXT_PLV:
            if (record->event.pressed) {
                layer_off(L_STENO);
            }
            return false;
    }
    return true;
}
