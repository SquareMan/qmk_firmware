/*
Copyright 2025 Steven Casper

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum {
    _BASE,
    _GAME,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
    _TOTAL_LAYERS,
};

#define LT_ESC LT(_MEDIA, KC_ESC)
#define LT_SPC LT(_NAV, KC_SPC)
#define LT_TAB LT(_MOUSE, KC_TAB)
#define LT_ENT LT(_SYM, KC_ENT)
#define LT_BSPC LT(_NUM, KC_BSPC)
#define LT_DEL LT(_FUN, KC_DEL)

#define BASE DF(_BASE)
#define GAME DF(_GAME)

#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)
#define MOD_N RSFT_T(KC_N)
#define MOD_E RCTL_T(KC_E)
#define MOD_I RALT_T(KC_I)
#define MOD_O RGUI_T(KC_O)

const custom_shift_key_t custom_shift_keys[] = {
    // Base layer parens replace angle brackets
    {KC_COMM, KC_LPRN},
    {KC_DOT, KC_RPRN},

    // Invert ' and "
    {KC_DOUBLE_QUOTE, KC_QUOTE},

    // Symbol Layer
    {KC_LABK, KC_RABK}, // < >
    {KC_LBRC, KC_RBRC}, // [ ]
    {KC_LCBR, KC_RCBR}, // { }
    {KC_LPRN, KC_RPRN}, // ( )
    {KC_UNDS, KC_MINUS}, // _ -
    {KC_BSLS, KC_GRAVE}, // \ ^
    {KC_SLSH, KC_HASH}, // / #
    {KC_EQUAL, KC_EQUAL}, // Doubled for => bigram
    {KC_DLR, KC_QUES}, // # FIXME: KC_SLSH->KC_HASH prevents getting ? on the base layer. Can't use layer mask because I want ( ) to be avaiable on , .
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, XXXXXXX,    XXXXXXX,    KC_J,    KC_L,    KC_U,    KC_Y, KC_DQUO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   MOD_A,   MOD_R,   MOD_S,   MOD_T,    KC_G, XXXXXXX,    XXXXXXX,    KC_M,   MOD_N,   MOD_E,   MOD_I,   MOD_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                           LT_ESC,   LT_SPC, LT_TAB,     LT_ENT, LT_BSPC,  LT_DEL
                                      //'--------------------------'  '--------------------------'
  ),

    [_GAME] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------.
     MO(_NUM),    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, XXXXXXX,    XXXXXXX,    KC_J,    KC_L,    KC_U,    KC_Y,KC_QUOTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G, XXXXXXX,    XXXXXXX,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,    BASE,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                           KC_ESC,  KC_SPC,  KC_TAB,     KC_ENT, KC_BSPC,  KC_DEL
                                      //'--------------------------'  '--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //'--------------------------'  '--------------------------'
  ),

    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------.
         GAME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                          XXXXXXX, XXXXXXX, _______,    MS_BTN2, MS_BTN1, MS_BTN3
                                      //'--------------------------'  '--------------------------'
  ),

    [_MEDIA] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                          _______, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE
                                      //'--------------------------'  '--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------.
      XXXXXXX,KC_SLASH,    KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_COLN,    KC_4,    KC_5,    KC_6,KC_EQUAL, XXXXXXX,    XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PERC,    KC_1,    KC_2,    KC_3, KC_PLUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                           KC_DOT,    KC_0,KC_MINUS,    XXXXXXX, _______, XXXXXXX
                                      //'--------------------------'  '--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------.
      XXXXXXX, KC_BSLS, KC_TILD,KC_EQUAL, KC_LABK, KC_CIRC, XXXXXXX,    CW_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SLSH, KC_EXLM, KC_AMPR, KC_LBRC, KC_ASTR, XXXXXXX,    XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PLUS, KC_PIPE, KC_LCBR, KC_SCLN,  KC_DLR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                            KC_AT, KC_LPRN, KC_UNDS,    _______, XXXXXXX, XXXXXXX
                                      //'--------------------------'  '--------------------------'
  ),

    [_FUN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  .--------------------------------------------------------------,
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL, XXXXXXX,    XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,  KC_F2,    KC_F3,KC_PAUSE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                          XXXXXXX, KC_CAPS, XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //'--------------------------'  '--------------------------'
  )
};


#define RGB_split_3x6_3_ex2(k0A, k0B, k0C, k0D, k0E, k0F, k0G, k4G, k4F, k4E, k4D, k4C, k4B, k4A, k1A, k1B, k1C, k1D, k1E, k1F, k1G, k5G, k5F, k5E, k5D, k5C, k5B, k5A, k2A, k2B, k2C, k2D, k2E, k2F, k6F, k6E, k6D, k6C, k6B, k6A, k3D, k3E, k3F, k7F, k7E, k7D) \
{ 										\
	k3F, k2F, k1F, k0F,	\
	k0E, k1E, k2E, k3E, \
	k3D, k2D, k1D, k0D,	\
	k0C, k1C, k2C,		\
	k2B, k1B, k0B,		\
	k0A, k1A, k2A, 		\
	k0G, k1G,			\
						\
	k7F, k6F, k5F, k4F, \
	k4E, k5E, k6E, k7E, \
	k7D, k6D, k5D, k4D, \
	k4C, k5C, k6C,		\
	k6B, k5B, k4B,		\
	k4A, k5A, k6A,		\
	k4G, k5G			\
}

#define OFF {0,0,0}
#define BLUE {134,255,213}
#define GREEN {85,203,158}
#define ORANGE {10,235,255}
#define PINK {243,222,234}
#define LAYER BLUE
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
          OFF,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,     OFF,        OFF,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
          OFF,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,     OFF,        OFF,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
          OFF,    BLUE,    BLUE,    BLUE,    BLUE,    BLUE,                         BLUE,    BLUE,    BLUE,    BLUE,    BLUE,     OFF,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                             BLUE,    BLUE,    BLUE,       BLUE,    BLUE,    BLUE
                                      //'--------------------------'  '--------------------------'
    ),

    [_GAME] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
         BLUE,  ORANGE,  ORANGE,    PINK,  ORANGE,  ORANGE,    BLUE,       BLUE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,    BLUE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
         BLUE,  ORANGE,    PINK,    PINK,    PINK,  ORANGE,    BLUE,       BLUE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,    BLUE,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
         BLUE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,                       ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,    BLUE,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                             BLUE,    BLUE,    BLUE,       BLUE,    BLUE,    BLUE
                                      //'--------------------------'  '--------------------------'
    ),

    [_NAV] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,        OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
          OFF,   GREEN,   GREEN,   GREEN,   GREEN,     OFF,     OFF,        OFF,     OFF,  ORANGE,  ORANGE,  ORANGE,  ORANGE,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,                          OFF,  ORANGE,  ORANGE,  ORANGE,  ORANGE,     OFF,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                              OFF,   LAYER,     OFF,        OFF,     OFF,     OFF
                                      //'--------------------------'  '--------------------------'
    ),

    [_MOUSE] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
       ORANGE,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,        OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
          OFF,   GREEN,   GREEN,   GREEN,   GREEN,     OFF,     OFF,        OFF,     OFF,  ORANGE,  ORANGE,  ORANGE,  ORANGE,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,                          OFF,  ORANGE,  ORANGE,  ORANGE,  ORANGE,     OFF,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                              OFF,     OFF,   LAYER,      GREEN,   GREEN,   GREEN
                                      //'--------------------------'  '--------------------------'
    ),


    [_MEDIA] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,        OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
          OFF,   GREEN,   GREEN,   GREEN,   GREEN,     OFF,     OFF,        OFF,     OFF,   GREEN,   GREEN,   GREEN,   GREEN,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,                          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                            LAYER,     OFF,     OFF,      GREEN,   GREEN,   GREEN
                                      //'--------------------------'  '--------------------------'
    ),

    [_NUM] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
          OFF,  ORANGE,    BLUE,    BLUE,    BLUE,  ORANGE,     OFF,        OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
          OFF,  ORANGE,    BLUE,    BLUE,    BLUE,  ORANGE,     OFF,        OFF,     OFF,   GREEN,   GREEN,   GREEN,   GREEN,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
          OFF,  ORANGE,    BLUE,    BLUE,    BLUE,  ORANGE,                          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                           ORANGE,    BLUE,  ORANGE,        OFF,   LAYER,     OFF
                                      //'--------------------------'  '--------------------------'
    ),

    [_SYM] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
          OFF,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,     OFF,       PINK,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
          OFF,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,     OFF,        OFF,     OFF,   GREEN,   GREEN,   GREEN,   GREEN,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
          OFF,  ORANGE,  ORANGE,  ORANGE,  ORANGE,  ORANGE,                          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                           ORANGE,  ORANGE,  ORANGE,       BLUE,     OFF,     OFF
                                      //'--------------------------'  '--------------------------'
    ),

    [_FUN] = RGB_split_3x6_3_ex2(
  //,--------------------------------------------------------------,  ,--------------------------------------------------------------,
          OFF,   GREEN,   GREEN,   GREEN,   GREEN,  ORANGE,     OFF,        OFF,     OFF,     OFF,     OFF,     OFF,     OFF,    PINK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
          OFF,   GREEN,   GREEN,   GREEN,   GREEN,  ORANGE,     OFF,        OFF,     OFF,   GREEN,   GREEN,   GREEN,   GREEN,     OFF,
  //|--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------|
          OFF,   GREEN,   GREEN,   GREEN,   GREEN,  ORANGE,                          OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
  //'--------+--------+--------+--------+--------+--------+--------,  ,--------+--------+--------+--------+--------+--------+--------'
                                            GREEN,    BLUE,    BLUE,        OFF,     OFF,   LAYER
                                      //'--------------------------'  '--------------------------'
    ),
};
// clang-format on

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rgb_matrix_get_suspend_state()) {
        return false;
    }

    uint8_t layer = biton32(layer_state);
    if (layer < _TOTAL_LAYERS) {
        if (layer == 0) {
            set_layer_color(biton32(default_layer_state));
        } else {
            set_layer_color(layer);
        }
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
    return true;
}
