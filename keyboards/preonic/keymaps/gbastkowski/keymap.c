#include QMK_KEYBOARD_H

#define L_QWERTSPLITLY 0
#define L_FN 1

#define MF_NOTI LALT(LGUI(LCTL(KC_B))) // Show Notification Center
#define MF_DASH LALT(LGUI(LCTL(KC_C))) // Show Dashboard

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QwertSplitly
 * ,------------------------------------------------------------------------------------------------------------------------.
 * |    1    |    2    |    3    |    4    |    5    |    =    ||    -    |    6    |    7    |    8    |    9    |    0    |
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
    KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,KC_EQL    ,KC_MINUS ,KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,\
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
 * |         |         |         |         |   Tab   |         ||         |   Del   |         |         |         |         |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
[L_FN] = LAYOUT_preonic_grid( \
    KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,_______   ,_______  ,KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,\
    _______  ,_______  ,MK_LPAR  ,MK_RPAR  ,_______  ,MK_TILD   ,KC_GRV   ,_______  ,_______  ,_______  ,_______  ,_______  ,\
    _______  ,_______  ,KC_LBRC  ,KC_RBRC  ,_______  ,_______   ,_______  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RGHT  ,_______  ,\
    _______  ,_______  ,MK_LBRA  ,MK_RBRA  ,_______  ,_______   ,TG_FN    ,_______  ,_______  ,_______  ,_______  ,_______  ,\
    _______  ,_______  ,_______  ,_______  ,_______  ,_______   ,_______  ,KC_DEL   ,_______  ,_______  ,_______  ,_______ \
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
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
