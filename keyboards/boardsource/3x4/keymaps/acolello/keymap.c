#include QMK_KEYBOARD_H

enum custom_keycodes {
    STEAM = SAFE_RANGE, // SAFE_RANGE prevents it from using a clashing keycode
    SAM,
    FUSION,
    VS_CODE,
    GITHUB,
    DESKTOP_LEFT,
    DESKTOP_RIGHT,
    DESKTOP_NEW,
    VIEW_DESKTOPS,
    KILL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      switch (keycode) {
          // unused
          case STEAM:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(400) "steam" SS_DELAY(50) SS_TAP(X_ENT));
              break;
          case SAM:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(400) "super animal" SS_DELAY(50) SS_TAP(X_ENT));
              break;
          case FUSION:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(400) "fusion" SS_DELAY(50) SS_TAP(X_ENT));
              break;
          case VS_CODE:
              SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_A))));
              break;
          case GITHUB:
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(400) "github" SS_DELAY(50) SS_TAP(X_ENT));
              break;
          case DESKTOP_LEFT:
              SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_LEFT))));
              break;
          case DESKTOP_RIGHT:
              SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_RIGHT))));
              break;
          //unused
          case DESKTOP_NEW:
              SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_D))));
              break;
          case VIEW_DESKTOPS:
              SEND_STRING(SS_LGUI(SS_TAP(X_TAB)));
              break;
          case KILL:
              SEND_STRING(SS_LALT(SS_TAP(X_F4)));
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
  DESKTOP_LEFT,  GITHUB,   KC_MPRV,    FUSION, 
  VIEW_DESKTOPS,   KILL,     KC_MPLY,    SAM, 
  DESKTOP_RIGHT, KC_TILDE, KC_MNXT,    VS_CODE
  )

};
