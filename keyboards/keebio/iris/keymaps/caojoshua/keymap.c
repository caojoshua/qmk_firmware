#include QMK_KEYBOARD_H


#define _DEFAULT 0
#define _SYMBOL 1
#define _NUMBER 2
#define _GAME 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
  NUMBER,
  GAME,
};

#define KC_ALT_A  LALT_T(KC_A)
#define KC_SFT_S  LSFT_T(KC_S)
#define KC_CTL_D  LCTL_T(KC_D)
#define KC_GUI_F  LGUI_T(KC_F)
#define KC_GUI_J  RGUI_T(KC_J)
#define KC_CTL_K  RCTL_T(KC_K)
#define KC_SFT_L  RSFT_T(KC_L)
#define KC_ALT_SCLN  RALT_T(KC_SCLN)

#define KC_ALT_GRV  LALT_T(KC_GRV)
#define KC_SFT_EQL  LSFT_T(KC_EQL)
#define KC_CTL_MINS  LCTL_T(KC_MINS)
#define KC_GUI_LBRC  LGUI_T(KC_LBRC)
#define KC_GUI_RBRC  RGUI_T(KC_RBRC)
#define KC_CTL_TAB  RCTL_T(KC_TAB)
#define KC_SFT_BSLS  RSFT_T(KC_BSLS)
#define KC_ALT_QUOT   RALT_T(KC_QUOT)

#define KC_ALT_1  LALT_T(KC_1)
#define KC_SFT_2  LSFT_T(KC_2)
#define KC_CTL_3  LCTL_T(KC_3)
#define KC_GUI_4  LGUI_T(KC_4)
#define KC_GUI_7  RGUI_T(KC_7)
#define KC_CTL_8  RCTL_T(KC_8)
#define KC_SFT_9  RSFT_T(KC_9)
#define KC_ALT_0  RALT_T(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, TG(_GAME),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_ALT_A, KC_SFT_S, KC_CTL_D, KC_GUI_F, KC_G,                              KC_H, KC_GUI_J, KC_CTL_K, KC_SFT_L, KC_ALT_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,           _______,   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_SPC, NUMBER,   _______,                   KC_BSPC,  SYMBOL,  KC_ENT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_ALT_GRV, KC_SFT_EQL, KC_CTL_MINS, KC_GUI_LBRC, KC_LCBR,                            KC_RCBR,  KC_GUI_RBRC, KC_CTL_TAB, KC_SFT_BSLS, KC_ALT_QUOT, _______, //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_TILD, KC_PLUS, KC_UNDS, KC_PIPE, KC_CAPS, _______,          _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_DQT, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1, KC_F2,   KC_F3, KC_F4, KC_F5,                            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_ALT_1, KC_SFT_2,   KC_CTL_3, KC_GUI_4, KC_5,                            KC_6, KC_GUI_7, KC_CTL_8, KC_SFT_9, KC_ALT_0, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11, KC_F12,   KC_HASH, KC_DLR, KC_PERC,                    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______, _______,                  _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DEFAULT);
      }
      return false;
      break;
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _GAME);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_SYMBOL, _NUMBER, _GAME);
      }
      return false;
      break;
    case NUMBER:
      if (record->event.pressed) {
        layer_on(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _GAME);
      } else {
        layer_off(_NUMBER);
        update_tri_layer(_SYMBOL, _NUMBER, _GAME);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
        update_tri_layer(_SYMBOL, _NUMBER, _GAME);
      } else {
        layer_off(_GAME);
        update_tri_layer(_SYMBOL, _NUMBER, _GAME);
      }
      return false;
      break;
  }
  return true;
}
