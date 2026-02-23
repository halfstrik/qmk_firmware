// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"

enum layers {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_EQUAL, KC_1,   KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINUS,
        KC_TAB,   KC_Q,   KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSLS,
        KC_CAPS,  KC_A,   KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
        KC_L,     KC_GRV, KC_ESC,   KC_LEFT,  KC_RIGHT,KC_A,    KC_B,    KC_UP,   KC_DOWN, KC_LBRC,  KC_RBRC, KC_R,
        KC_ESC,   KC_LALT,KC_LCMD,  MO(_FN),  KC_SPC,  KC_LCTL, KC_ENTER,KC_BSPC, KC_RCTL, KC_RCMD,  KC_RALT, KC_DEL
    ),
    [_FN] = LAYOUT(
        KC_ESC,   KC_F1,  KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        _______,  _______,_______,   _______, _______, _______, _______, _______, _______, _______,  _______, KC_F12,
        _______,  _______,_______,   _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,  _______,_______,   _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,  _______,_______,   _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,  _______,_______,   _______, _______, _______, _______, _______, _______, _______,  _______, _______
    )
};

led_config_t g_led_config = {
    /* Matrix to LED index (6 rows × 12 cols) */
    {
        // Row 0 — number row
        { NO_LED, NO_LED, NO_LED, NO_LED, 4,      3,      NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        // Row 1 — Q row
        { NO_LED, NO_LED, NO_LED, NO_LED, 5,      2,      NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        // Row 2 — A row
        { NO_LED, NO_LED, NO_LED, NO_LED, 6,      1,      NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        // Row 3 — Z row
        { NO_LED, NO_LED, NO_LED, NO_LED, 7,      0,      NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        // Row 4 — arrows, misc
        { NO_LED, NO_LED, NO_LED, NO_LED, 8,      NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        // Row 5 — thumbs
        { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
    },
    /* LED physical positions (rough ergonomic layout) */
    {
        { 60, 48 },  // LED 0 — B
        { 60, 32 },  // LED 1 — G
        { 60, 16 },  // LED 2 — T
        { 60,  0 },  // LED 3 — 5
        { 40,  0 },
        { 40, 16 },
        { 40, 32 },
        { 40, 48 },
        { 40, 60 }
    },
    /* LED flags */
    {
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT
    }
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();        // turn LEDs on
    rgblight_sethsv_noeeprom(170, 255, 120);  // solid blue
}
