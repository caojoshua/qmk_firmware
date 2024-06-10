#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,
     KC_6, KC_7, KC_8, KC_9, KC_0, TG(_GAME),
     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
     MT(MOD_LCTL, KC_CAPSLOCK), KC_A, KC_S, KC_D, KC_F, KC_G,
     KC_H, KC_J, KC_K, KC_L, KC_SCLN, MT(MOD_RCTL, KC_QUOT),
     MT(MOD_LSFT, KC_MINUS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC,
     _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
     MT(MOD_RSFT, KC_EQUAL), MT(MOD_LALT, KC_LBRACKET), LT(_LOWER, KC_SPC),   _______,
     KC_BSPC, LT(_RAISE, KC_ENT), MT(MOD_RGUI, KC_RBRACKET)
  ),

  [_LOWER] = LAYOUT(
     KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______,  _______, _______, _______, _______,
     _______, _______, _______,
     _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
     RGB_TOG, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, RGB_MOD,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, KC_MS_WH_LEFT, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_RIGHT,
     KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, KC__VOLDOWN, KC__VOLUP, KC__MUTE, _______, _______,
     KC_MS_BTN2, KC_MS_BTN1, _______,
     _______, _______, _______
  ),

  // Overwrite all the modtaps
  [_GAME] = LAYOUT(
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     KC_LCTRL, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, KC_RCTRL,
     KC_LSHIFT, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, KC_RSHIFT,
     KC_LALT, KC_SPC, _______,
     _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      } else {
        layer_off(_GAME);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      }
      return false;
      break;
  }
  return true;
}
