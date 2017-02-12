#include "satan.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _BL 0
#define _FL 1
#define _KP 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* base layer */
[_BL] = KEYMAP_ANSI(
  F(0),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC, \
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS, \
  KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT,  \
  KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT, \
  MO(_FL),KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT,KC_RGUI,TG(_KP),MO(_FL)),

/* function layer */
[_FL] = KEYMAP_ANSI(
  KC_GRV ,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F8, KC_F10, KC_F11, KC_F12, KC_DEL, \
  _______,KC_HOME,  KC_UP,KC_PGUP,_______,_______,_______,_______,_______,_______,_______, BL_DEC, BL_INC,BL_TOGG, \
  _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
  _______,         KC_END,KC_PGDN,KC_VOLD,KC_VOLU,KC_MUTE,KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,        _______, \
  _______,_______,_______,                _______,                                _______,_______,_______,_______),

/* key pad layer */
[_KP] = KEYMAP_ANSI(
  _______,_______,_______,_______,_______,_______,_______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______,_______,KC_P7,  KC_P8,  KC_P9,  KC_PPLS,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______,_______,KC_P4,  KC_P5,  KC_P6,  _______,_______,        KC_PENT, \
  _______,        _______,_______,_______,_______,_______,_______,KC_P1,  KC_P2,  KC_P3,  _______,        _______, \
  _______,_______,_______,                KC_P0,                                  KC_PDOT,_______,_______,_______),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
