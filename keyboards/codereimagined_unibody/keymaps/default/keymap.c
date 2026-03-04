// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "quantum/quantum_keycodes.h"

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
        RM_TOGG,  RM_NEXT,RM_PREV,   _______, _______, _______, _______, _______, _______, _______,  _______, KC_F12,
        _______,  RM_HUEU,RM_HUED,   _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,  RM_SATU,RM_SATD,   _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,  RM_VALU,RM_VALD,   _______, _______, _______, _______, _______, _______, _______,  QK_BOOT, _______,
        _______,  _______,_______,   _______, _______, _______, _______, _______, _______, _______,  _______, _______
    )
};

led_config_t g_led_config = {
    /* Matrix to LED index (6 rows × 12 cols) */
    {
        // Row 0 — number row
        { 24    , 23    , 14    , 13    , 4,      3,      41    , 42     , 51    , 52    , 61     , 62    },
        // Row 1 — Q row
        { 25    , 22    , 15    , 12    , 5,      2,      40    , 43     , 50    , 53    , 60     , 63    },
        // Row 2 — A row
        { 26    , 21    , 16    , 11    , 6,      1,      39    , 44     , 49    , 54    , 59     , 64    },
        // Row 3 — Z row
        { 27    , 20    , 17    , 10,     7,      0,      38    , 45     , 48    , 55    , 58    , 65     },
        // Row 4 — arrows, misc
        { NO_LED, 19    , 18    , 9,      8,      NO_LED, NO_LED, 46     , 47    , 56    , 57    , NO_LED },
        // Row 5 — thumbs
        { NO_LED, 28,     29,    30,     31,      32,     33,     34,      35,     36,     37,     NO_LED }
    },
    /* LED physical positions (rough ergonomic layout) */
    {
        { 100, 30 },  // LED 0 — B
        { 100, 40 },  // LED 1 — G
        { 100, 50 },  // LED 2 — T
        { 100, 60 },  // LED 3 — 5
        { 80,  60 },
        { 80,  50 },
        { 80,  40 },
        { 80,  30 },  // LED 7
        { 80,  20 },
        { 60,  20 },  // LED 9 -
        { 60,  30 },
        { 60,  40 },
        { 60,  50 },
        { 60,  60 },  // LED 13 - 3
        { 40,  60 },
        { 40,  50 },
        { 40,  40 },  // LED 16
        { 40,  30 },
        { 40,  20 },
        { 20,  20 },  // LED 19
        { 20,  30 },
        { 20,  40 },  // LED 21
        { 20,  50 },
        { 20,  60 },  // LED 23
        { 0,  60 },
        { 0,  50 },
        { 0,  40 },
        { 0,  30 }, // LED 27
        { 90, 20 },
        { 100, 18 },
        { 105, 15 },
        { 107, 20 },
        { 109, 25 }, // LED 32 - middle
        // ---- mirrored right half ----
        { 124, 25 }, // mirror of LED 32 (109,25)
        { 117, 20 }, // mirror of LED 31 (107,20)
        { 119, 15 }, // mirror of LED 30 (105,15)
        { 124, 18 }, // mirror of LED 29 (100,18)
        { 134, 20 }, // mirror of LED 28 (90,20)

        { 224, 30 }, // mirror of LED 27 (0,30)
        { 224, 40 },
        { 224, 50 },
        { 224, 60 },

        { 204, 60 }, // mirror of LED 23 (20,60)
        { 204, 50 },
        { 204, 40 },
        { 204, 30 },
        { 204, 20 },

        { 184, 20 }, // mirror of LED 18 (40,20)
        { 184, 30 },
        { 184, 40 },
        { 184, 50 },
        { 184, 60 },

        { 164, 60 }, // mirror of LED 13 (60,60)
        { 164, 50 },
        { 164, 40 },
        { 164, 30 },
        { 164, 20 },

        { 144, 20 }, // mirror of LED 8 (80,20)
        { 144, 30 },
        { 144, 40 },
        { 144, 50 },
        { 144, 60 },

        { 124, 60 }, // mirror of LED 3 (100,60)
        { 124, 50 },
        { 124, 40 },
        { 124, 30 }  // mirror of LED 0 (100,30)

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
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,
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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Caps lock in all red - from example
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
    // Layer indication in Yellow
    for (uint8_t i = led_min; i < led_max; i++) {
         switch(get_highest_layer(layer_state|default_layer_state)) {
             case 1:
                 rgb_matrix_set_color(i, RGB_YELLOW);
                 break;
             default:
                 break;
         }
     }
    return false;
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
