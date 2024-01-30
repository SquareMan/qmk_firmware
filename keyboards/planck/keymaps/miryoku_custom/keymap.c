#include QMK_KEYBOARD_H

#define KC_PC_UNDO LCTL(KC_Z)

enum planck_keycodes {
    PAIR_ANGLE = SAFE_RANGE,
    PAIR_SQUARE,
    PAIR_CURL,
    PAIR_PAREN,
};

enum planck_layers {
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRANSPARENT, KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       
    LGUI_T(KC_A),   LALT_T(KC_R),   LCTL_T(KC_S),   LSFT_T(KC_T),   KC_G,           KC_TRANSPARENT, KC_TRANSPARENT, KC_M,           RSFT_T(KC_N),   LCTL_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_O),   
    KC_Z,           RALT_T(KC_X),   KC_C,           KC_D,           KC_V,           KC_TRANSPARENT, KC_TRANSPARENT, KC_K,           KC_H,           KC_COMMA,       RALT_T(KC_DOT), KC_SLASH,       
    KC_TRANSPARENT, KC_TRANSPARENT, LT(_MEDIA,KC_ESCAPE),LT(_NAV,KC_SPACE), LT(_MOUSE,KC_TAB),   KC_TRANSPARENT, KC_NO,          LT(_SYM,KC_ENTER), LT(_NUM,KC_BACKSPACE),LT(_FUN,KC_DELETE),KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_GAME] = LAYOUT_planck_grid(
    KC_Q,     KC_W,    KC_F,     KC_P,     KC_B,   KC_3,      KC_6,  KC_J,     KC_L,      KC_U,      KC_Y,           KC_QUOTE,
    KC_A,     KC_R,    KC_S,     KC_T,     KC_G,   KC_2,      KC_5,  KC_M,     KC_N,      KC_E,      KC_I,           KC_O,
    KC_Z,     KC_X,    KC_C,     KC_D,     KC_V,   KC_1,      KC_4,  KC_K,     KC_H,      KC_COMMA,  KC_DOT,         KC_SLASH,
    MO(_NUM), KC_LALT, KC_LCTL, KC_SPACE, KC_TAB, KC_ESCAPE, KC_NO, KC_ENTER, KC_BACKSPACE, KC_DELETE, KC_TRANSPARENT, DF(_BASE)
  ),

  [_NAV] = LAYOUT_planck_grid(
    QK_BOOTLOADER,          KC_NO,          KC_NO,    KC_NO,          KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,       LSFT(KC_INSERT), LCTL(KC_INSERT), LSFT(KC_DELETE), KC_PC_UNDO,
    KC_LGUI,        KC_LALT,        KC_LCTL, KC_LSFT,      KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPS_LOCK, KC_LEFT,         KC_DOWN,         KC_UP,           KC_RIGHT,
    WEBUSB_PAIR,    KC_RALT,        KC_NO,    KC_NO,          KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,   KC_HOME,         KC_PGDN,       KC_PGUP,         KC_END,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,    KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_NO,          KC_ENTER,    KC_BACKSPACE,       KC_DELETE,       KC_TRANSPARENT,  KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    QK_BOOTLOADER,          KC_NO,          KC_NO,    KC_NO,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,      LSFT(KC_INSERT), LCTL(KC_INSERT), LSFT(KC_DELETE), KC_PC_UNDO,
    KC_LGUI,        KC_LALT,        KC_LCTL, KC_LSFT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,      KC_MS_LEFT,      KC_MS_DOWN,      KC_MS_UP,        KC_MS_RIGHT,
    WEBUSB_PAIR,    KC_RALT,        KC_NO,    KC_NO,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,      KC_MS_WH_LEFT,   KC_MS_WH_DOWN,   KC_MS_WH_UP,     KC_MS_WH_RIGHT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,    KC_NO,     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_MS_BTN2, KC_MS_BTN1,      KC_MS_BTN3,      KC_TRANSPARENT,  KC_TRANSPARENT
  ),

  [_MEDIA] = LAYOUT_planck_grid(
    QK_BOOTLOADER,          KC_NO,          KC_NO,          KC_NO,     KC_NO,     KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,       RGB_MOD,             RGB_HUI,           RGB_SAI,         RGB_VAI,
    KC_LGUI,        KC_LALT,        KC_LCTL,       KC_LSFT, DF(_GAME), KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,         KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK,
    WEBUSB_PAIR,    KC_RALT,        KC_NO,          KC_NO,     KC_NO,     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,         KC_NO,               KC_NO,             KC_NO,           KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,     KC_NO,     KC_TRANSPARENT, KC_NO,          KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE,     KC_TRANSPARENT,  KC_TRANSPARENT
  ),

  [_NUM] = LAYOUT_planck_grid(
    KC_SLASH,       KC_7,           KC_8,   KC_9, KC_ASTR,  KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_NO,          KC_NO,    KC_NO,          QK_BOOTLOADER,
    KC_COLN,        KC_4,           KC_5,   KC_6, KC_EQUAL, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_LSFT,      KC_LCTL, KC_LALT,        KC_LGUI,
    KC_PERC,        KC_1,           KC_2,   KC_3, KC_PLUS,  KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_NO,          KC_NO,    KC_RALT,        WEBUSB_PAIR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT, KC_0, KC_MINUS, KC_TRANSPARENT, KC_NO,          KC_NO, KC_TRANSPARENT, KC_NO,    KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_SYM] = LAYOUT_planck_grid(
    KC_BACKSLASH,      KC_TILD,        KC_PIPE,   PAIR_ANGLE,  KC_GRAVE, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,     KC_NO,    KC_NO,          QK_BOOTLOADER,
    KC_SEMICOLON,      KC_EXLM,        KC_AMPR,   PAIR_SQUARE, KC_EQUAL, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LSFT, KC_LCTL, KC_LALT,        KC_LGUI,
    KC_DLR,         KC_COLN,        KC_AT,     KC_HASH,     KC_CIRC,  KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,     KC_NO,    KC_RALT,        WEBUSB_PAIR,
    KC_TRANSPARENT, KC_TRANSPARENT, PAIR_CURL, PAIR_PAREN,  KC_UNDS,  KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,     KC_NO,    KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FUN] = LAYOUT_planck_grid(
    KC_F12,         KC_F7,          KC_F8,          KC_F9,    KC_PSCR,    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_NO,     KC_NO,          KC_NO,          QK_BOOTLOADER,
    KC_F11,         KC_F4,          KC_F5,          KC_F6,    KC_SCROLL_LOCK, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_LSFT, KC_LCTL,       KC_LALT,        KC_LGUI,
    KC_F10,         KC_F1,          KC_F2,          KC_F3,    KC_PAUSE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_NO,     KC_NO,          KC_RALT,        WEBUSB_PAIR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_SPACE, KC_TAB,        KC_TRANSPARENT, KC_NO,          KC_NO, KC_NO,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

#define OFF {0,0,0}
#define BLUE {134,255,213}
#define GREEN {85,203,158}
#define ORANGE {10,235,255}
#define PINK {243,222,234}
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = {
        BLUE, BLUE, BLUE, BLUE, BLUE, OFF, OFF,  BLUE, BLUE, BLUE, BLUE, BLUE,
        BLUE, BLUE, BLUE, BLUE, BLUE, OFF, OFF,  BLUE, BLUE, BLUE, BLUE, BLUE,
        BLUE, BLUE, BLUE, BLUE, BLUE, OFF, OFF,  BLUE, BLUE, BLUE, BLUE, BLUE,
        OFF,  OFF,  BLUE, BLUE, BLUE, OFF, BLUE, BLUE, BLUE, OFF,  OFF
    },

    [_GAME] = {
        ORANGE, ORANGE, PINK,   ORANGE, ORANGE, BLUE,   BLUE,   ORANGE, ORANGE, ORANGE, ORANGE, ORANGE,
        ORANGE, PINK,   PINK,   PINK,   ORANGE, BLUE,   BLUE,   ORANGE, ORANGE, ORANGE, ORANGE, ORANGE,
        ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, BLUE,   BLUE,   ORANGE, ORANGE, ORANGE, ORANGE, ORANGE,
        BLUE,   ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, BLUE
    },

    [_NAV] = {
        PINK,  OFF,   OFF,   OFF,   OFF, OFF, OFF,  ORANGE, ORANGE, ORANGE, ORANGE, ORANGE,
        GREEN, GREEN, GREEN, GREEN, OFF, OFF, OFF,  ORANGE, ORANGE, ORANGE, ORANGE, ORANGE,
        PINK,  GREEN, OFF,   OFF,   OFF, OFF, OFF,  ORANGE, ORANGE, ORANGE, ORANGE, ORANGE,
        OFF,   OFF,   OFF,   BLUE,  OFF, OFF, BLUE, BLUE,   BLUE,   OFF,    OFF
    },

    [_MOUSE] = {
        PINK,  OFF,   OFF,   OFF,   OFF,  OFF, OFF,    OFF,    ORANGE, ORANGE, ORANGE, ORANGE,
        GREEN, GREEN, GREEN, GREEN, OFF,  OFF, OFF,    OFF,    ORANGE, ORANGE, ORANGE, ORANGE,
        PINK,  GREEN, OFF,   OFF,   OFF,  OFF, OFF,    OFF,    ORANGE, ORANGE, ORANGE, ORANGE,
        OFF,   OFF,   OFF,   OFF,   BLUE, OFF, ORANGE, ORANGE, ORANGE, OFF,    OFF
    },

    [_MEDIA] = {
        PINK,  OFF,   OFF,   OFF,   OFF,    OFF, OFF,   GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, ORANGE, OFF, OFF,   OFF,   GREEN, GREEN, GREEN, GREEN,
        PINK,  GREEN, OFF,   OFF,   OFF,    OFF, OFF,   OFF,   OFF,   OFF,   OFF,   OFF,
        OFF,   OFF,   BLUE,  OFF,   OFF,    OFF, GREEN, GREEN, GREEN, OFF,   OFF
    },

    [_NUM] = {
        ORANGE, BLUE, BLUE,   BLUE, ORANGE, OFF, OFF, OFF,  OFF,   OFF,   OFF,   PINK,
        ORANGE, BLUE, BLUE,   BLUE, ORANGE, OFF, OFF, OFF,  GREEN, GREEN, GREEN, GREEN,
        ORANGE, BLUE, BLUE,   BLUE, ORANGE, OFF, OFF, OFF,  OFF,   OFF,   GREEN, PINK,
        OFF,    OFF,  ORANGE, BLUE, ORANGE, OFF, OFF, BLUE, OFF,   OFF,   OFF
    },

    [_SYM] = {
        ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, OFF, OFF,  OFF, OFF,   OFF,   OFF,   PINK,
        ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, OFF, OFF,  OFF, GREEN, GREEN, GREEN, GREEN,
        ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, OFF, OFF,  OFF, OFF,   OFF,   GREEN, PINK,
        OFF,    OFF,    ORANGE, ORANGE, ORANGE, OFF, BLUE, OFF, OFF,   OFF,   OFF
    },

    [_FUN] = {
        GREEN, GREEN, GREEN, GREEN, ORANGE, OFF, OFF, OFF, OFF,   OFF,   OFF,   PINK,
        GREEN, GREEN, GREEN, GREEN, ORANGE, OFF, OFF, OFF, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, ORANGE, OFF, OFF, OFF, OFF,   OFF,   GREEN, PINK,
        OFF,   OFF,   GREEN, BLUE,  BLUE,   OFF, OFF, OFF, BLUE,  OFF,   OFF
    },

};
// clang-format on

extern bool         g_suspend_state;
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
    if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led) {
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

static uint16_t code_timer  = 0;
static char     queued_char = 0;

void process_pair(keyrecord_t *record, char left, char right) {
    if (record->event.pressed) {
        code_timer  = timer_read();
        queued_char = right;
    } else if (code_timer != 0) {
        // timer has not expired since it is not set to zero
        send_char(left);
        code_timer = 0;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PAIR_PAREN:
            process_pair(record, '(', ')');
            return false;
        case PAIR_CURL:
            process_pair(record, '{', '}');
            return false;
        case PAIR_SQUARE:
            process_pair(record, '[', ']');
            return false;
        case PAIR_ANGLE:
            process_pair(record, '<', '>');
            return false;
    }
    return true;
}

void matrix_scan_user() {
    if (code_timer != 0 && timer_elapsed(code_timer) > TAPPING_TERM) {
        send_char(queued_char);
        code_timer = 0;
    }
}

void suspend_wakeup_init_user() {
    default_layer_set(_BASE);
}
