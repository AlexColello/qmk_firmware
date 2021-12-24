#include QMK_KEYBOARD_H

enum custom_keycodes {
    STEAM = SAFE_RANGE, // SAFE_RANGE prevents it from using a clashing keycode
    SAM,
    FUSION,
    VS_CODE,
    GITHUB
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      switch (keycode) {
          case STEAM:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(500) "steam" SS_DELAY(100) SS_TAP(X_ENT));
              break;
          case SAM:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(500) "super animal" SS_DELAY(100) SS_TAP(X_ENT));
              break;
          case FUSION:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(500) "fusion" SS_DELAY(100) SS_TAP(X_ENT));
              break;
          case VS_CODE:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(500) "vscode" SS_DELAY(100) SS_TAP(X_ENT));
              break;
          case GITHUB:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(500) "github" SS_DELAY(100) SS_TAP(X_ENT));
              break;
      }
    }
    return true;
}

enum layers {
    _MAIN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  KC_LEFT,  GITHUB,   KC_MPRV,    FUSION, 
  KC_DOWN,  KC_UP,    KC_MPLY,    SAM, 
  KC_RIGHT, KC_TILDE, KC_MNXT,    VS_CODE
  )

};
