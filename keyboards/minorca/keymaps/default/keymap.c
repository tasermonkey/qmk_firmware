#include "minorca.h"

#define _BL 0
#define _UP 1
#define _DN 2
#define _FN 3

#define _______ KC_TRNS

#define RAISE LT(_UP, KC_SPC)
#define LOWER LT(_DN, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* base layer */
    [_BL] = KEYMAP( \
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
            KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT, \
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
            MO(_FN), KC_LALT, KC_LGUI,          RAISE,            LOWER,                     KC_ESC,  KC_RGUI, MO(_FN) \
    ),

    /* up */
    [_UP] = KEYMAP( \
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
            _______, _______, _______, _______, KC_QUOT, _______, _______, KC_LPRN, KC_RPRN, KC_EQL,  KC_SCLN, \
            _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_BSLS, \
            _______, _______, _______,          _______,          KC_SPC,                    _______, _______, _______ \
    ),

    /* down */
    [_DN] = KEYMAP( \
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_UNDS, \
            _______, _______, _______, _______, KC_DQUO, _______, _______, KC_LBRC, KC_RBRC, KC_PLUS, KC_COLN, \
            _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_PIPE, \
            _______, _______, _______,          KC_SPC,           _______,                   _______, _______, _______),

    /* function */
    [_FN] = KEYMAP( \
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
            _______, _______, KC_PGDN, KC_HOME, KC_END,  KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, \
            _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, RESET, \
            _______, _______, _______,          _______,          _______,                   _______, _______, _______),

};

const uint16_t PROGMEM fn_actions[] = {


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
