/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off
 
 enum layers{
     MAC_BASE,
     MAC_FN,
     WIN_BASE,
     WIN_FN
 };
 
 #define KC_TASK LGUI(KC_TAB)
 #define KC_FLXP LGUI(KC_E)
 
 enum custom_keycodes {
     QMKBEST = SAFE_RANGE,
     MACCY,
     MACOS_SCREENLOCK,
     ID_TECH,
     OPEN_WARP,
     OPEN_VS_CODE,
     FULL_SCREEN_WINDOW,
     TILE_LEFT,
     TILE_RIGHT,
     MAXIMIZE_WINDOW,
 };
 
 layer_state_t layer_state_set_user(layer_state_t state) {
     switch (get_highest_layer(state)) {
         case MAC_BASE:
             // RGB_MATRIX_EFFECT(SOLID_COLOR);
             rgb_matrix_mode(RGB_MATRIX_CUSTOM_default_solid_blue);
             break;
         case WIN_BASE:
             rgb_matrix_mode(RGB_MATRIX_CUSTOM_green_shortcut_keys);
             break;
     }
     return state;    
 }
 
 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
     case QMKBEST:
         if (record->event.pressed) {
             // when keycode QMKBEST is pressed
             SEND_STRING("QMK is the best thing ever!");
         } else {
             // when keycode QMKBEST is released
         }
         break;
     case MACOS_SCREENLOCK:
         if (record->event.pressed) {
             // SEND_STRING(SS_DOWN(KC_LCTL) SS_DOWN(KC_LCMD) "Q");
             register_code(KC_LCTL);
             register_code(KC_LCMD);
             register_code(KC_Q);
             unregister_code(KC_LCTL);
             unregister_code(KC_LCMD);
             unregister_code(KC_Q);
         }
         break;
     case MACCY:
         if (record->event.pressed) {
             register_code(KC_LSFT);
             register_code(KC_LCMD);
             register_code(KC_LBRC);
             unregister_code(KC_LSFT);
             unregister_code(KC_LCMD);
             unregister_code(KC_LBRC);
         }
         break;
     case ID_TECH:
         if (record->event.pressed) {
             SEND_STRING(SS_TAP(X_LCMD) SS_TAP(X_LCMD) SS_DELAY(300) "Run iD Tech Shortcut" SS_TAP(X_ENT) );
         }
         break;
    case OPEN_WARP:
         if (record->event.pressed) {
             SEND_STRING(SS_TAP(X_LCMD) SS_TAP(X_LCMD) SS_DELAY(300) "Open Warp" SS_TAP(X_ENT) SS_DELAY(500) SS_TAP(X_ESC));
         }
         break;
     case OPEN_VS_CODE:
        if (record->event.pressed) {
             SEND_STRING(SS_TAP(X_LCMD) SS_TAP(X_LCMD) SS_DELAY(300) "Open Visual Studio Code" SS_TAP(X_ENT) SS_DELAY(500) SS_TAP(X_ESC));
         }
         break;
        case FULL_SCREEN_WINDOW:
         if (record->event.pressed) {
             register_code(KC_LCTL);
             register_code(KC_LCMD);
             register_code(KC_F);
             unregister_code(KC_LCTL);
             unregister_code(KC_LCMD);
             unregister_code(KC_F);
         }
         break;
     case TILE_LEFT:
         if (record->event.pressed) {
             register_code(KC_LCTL);
             register_code(KC_LOPT);
             register_code(KC_LEFT);
             unregister_code(KC_LCTL);
             unregister_code(KC_LOPT);
             unregister_code(KC_LEFT);
         }
         break;
     case TILE_RIGHT:
        if (record->event.pressed) {
             register_code(KC_LCTL);
             register_code(KC_LOPT);
             register_code(KC_RGHT);
             unregister_code(KC_LCTL);
             unregister_code(KC_LOPT);
             unregister_code(KC_RGHT);
         }
         break;
     case MAXIMIZE_WINDOW:
         if (record->event.pressed) {
             register_code(KC_LCTL);
             register_code(KC_LOPT);
             register_code(KC_UP);
             unregister_code(KC_LCTL);
             unregister_code(KC_LOPT);
             unregister_code(KC_UP);
         }
         break;
    }
     return true;
 };
 
 
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [MAC_BASE] = LAYOUT_ansi_82(
         KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  MACOS_SCREENLOCK,   KC_MUTE,
         KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_DEL,
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGUP,
         MO(WIN_BASE),KC_A,  KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_PGDN,
         KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
         KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
 
     [MAC_FN] = LAYOUT_ansi_82(
         _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,            RM_TOGG,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
         _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
         _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
 
     [WIN_BASE] = LAYOUT_ansi_82(
         KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MPLY,
         KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     OPEN_WARP,KC_Y,     KC_U,     ID_TECH,  KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
         KC_CAPS,  KC_A,     KC_S,     KC_D,     QK_BOOT,  KC_G,     KC_H,     KC_J,     KC_K,     RM_TOGG,  KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
         KC_LSFT,            KC_Z,     KC_X,     MACCY,OPEN_VS_CODE, KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  MAXIMIZE_WINDOW,
         KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  TILE_LEFT,  FULL_SCREEN_WINDOW,  TILE_RIGHT),
 
     [WIN_FN] = LAYOUT_ansi_82(
         _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            RM_TOGG,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
         _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
         _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
 };
 
 #if defined(ENCODER_MAP_ENABLE)
 const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
     [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
     [MAC_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
     [WIN_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
     [WIN_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)}
 };
 #endif // ENCODER_MAP_ENABLE
 