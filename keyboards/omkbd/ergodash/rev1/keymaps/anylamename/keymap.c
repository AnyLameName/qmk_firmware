#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
    _CODE
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  ADJUST,
  CODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |             |      |      |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+-Bksp +------+------+------+ Space+------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | Code |||||||| Lower|      | Shift|||||||| Shift|      | Raise|||||||| Left | Down |  Up  | Ctrl |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5,  KC_NO,                         KC_NO,  KC_6,  KC_7, KC_8,    KC_9,    KC_0,    KC_PSCR,
    KC_GRV,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,  KC_NO,                         KC_NO,  KC_Y,  KC_U, KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_ESC,  KC_A,    KC_S,    KC_D, KC_F, KC_G,  KC_NO,                         KC_NO,  KC_H,  KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,  KC_NO,                         KC_NO,  KC_N,  KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, CODE,       LOWER, KC_BSPC, KC_LSFT,     KC_RSFT, KC_SPC, RAISE,       KC_LEFT, KC_DOWN, KC_UP,   KC_LCTL
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   _  |      |                    |      |   +  | Home | End  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |      |                    |      | Left | Down |  Up  | Right|   :  |  "   |
   * |------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   {  |      |             |      |      |   }  |PageUp|PageDn|  End |   ?  | Shift|
   * |-------------+------+------+------+------+  Del +------+------+------+ Space+------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | Code |||||||| Lower|      | Shift|||||||| Shift|      | Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12 ,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_UNDS, _______,                        _______, KC_PLUS, KC_HOME, KC_END,  KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT ,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,   KC_LCBR, _______,                        _______, KC_RCBR, KC_PGUP, KC_PGDN, KC_END,  KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, CODE,            LOWER,   KC_DEL,  KC_LSFT,      KC_RSFT,  KC_SPC, RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |       |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+-------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   -  |       |                    |      |   =  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+-------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |  Tab |   [  |       |                    |      |   ]  | Enter|   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+----------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   [  |       |                    |      |   ]  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+  Del  +------+------+------+ Bksp +------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | Code |||||||| Lower|       | Shift|||||||| Shift|      | Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_MINS, _______,                        _______, KC_EQL,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_TAB, KC_LBRC, _______,                        _______, KC_RBRC, KC_ENT,  KC_K,    KC_L,    KC_COLN, KC_DQT ,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,   KC_LBRC, _______,                        _______, KC_RBRC, KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, CODE,            LOWER,   KC_DEL,  KC_LSFT,      KC_RSFT, KC_BSPC, RAISE,             KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON| MODE | HUE- | HUE+ |      |                    |      | SAT- | SAT+ | VAL- | VAL+ | Play |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON| BRTG | INC  |  DEC |      |                    |      |      | VOL- | VOL+ |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      | Mute |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, QK_BOOT, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_MPLY, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_UP  , BL_DOWN,_______,                       _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_MUTE, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  ),

  // Code layer is basically just ctrl+shift for VS Code shortcuts.
  [_CODE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, RCS(KC_E), _______, RCS(KC_T),_______,                       _______, _______, _______, _______, _______,RCS(KC_P), _______,
    _______, _______, _______, RCS(KC_D), RCS(KC_F), RCS(KC_G),_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, RCS(KC_X), RCS(KC_C), _______, _______,_______,                       _______, RCS(KC_M),_______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_PURPLE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
  #endif
}

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
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case CODE:
      if (record->event.pressed) {
        layer_on(_CODE);
      } else {
        layer_off(_CODE);
      }
      return false;
      break;
  }
  return true;
}
