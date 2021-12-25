#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum planck_keycodes {
    PAIR_ANGLE = EZ_SAFE_RANGE,
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
    KC_TRANSPARENT, KC_TRANSPARENT, LT(_MEDIA,KC_ESCAPE),LT(_NAV,KC_SPACE), LT(_MOUSE,KC_TAB),   KC_TRANSPARENT, KC_NO,          LT(_SYM,KC_ENTER), LT(_NUM,KC_BSPACE),LT(_FUN,KC_DELETE),KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_GAME] = LAYOUT_planck_grid(
    KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           DF(_BASE), KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       
    KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_TRANSPARENT, KC_TRANSPARENT, KC_M,           KC_N,           KC_E,           KC_I,           KC_O,   
    KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRANSPARENT, KC_TRANSPARENT, KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       
    MO(_NUM), KC_TRANSPARENT, KC_ESCAPE,      KC_SPACE,       KC_TAB,         KC_TRANSPARENT, KC_NO,          LT(_SYM,KC_ENTER), LT(_NUM,KC_BSPACE),LT(_FUN,KC_DELETE),KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_NAV] = LAYOUT_planck_grid(
    RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),KC_PC_UNDO,     
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPSLOCK,    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       
    WEBUSB_PAIR,    KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_ENTER,       KC_BSPACE,      KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          LSFT(KC_INSERT),LCTL(KC_INSERT),LSFT(KC_DELETE),KC_PC_UNDO,     
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    
    WEBUSB_PAIR,    KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_MS_BTN2,     KC_MS_BTN1,     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_MEDIA] = LAYOUT_planck_grid(
    RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_MOD,        RGB_HUI,        RGB_SAI,        RGB_VAI,        
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      DF(_GAME),      KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,
    WEBUSB_PAIR,    KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_NUM] = LAYOUT_planck_grid(
    KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          
    KC_COLN,        KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        
    KC_PERC,        KC_1,           KC_2,           KC_3,           KC_PLUS,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_RALT,        WEBUSB_PAIR,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_0,           KC_MINUS,       KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_SYM] = LAYOUT_planck_grid(
    KC_BSLASH,      KC_TILD,        KC_PIPE,         PAIR_ANGLE,    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          
    KC_SCOLON,      KC_EXLM,        KC_AMPR,        PAIR_SQUARE,    KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        
    KC_DLR,         KC_COLN,        KC_AT,          KC_HASH,        KC_CIRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_RALT,        WEBUSB_PAIR,    
    KC_TRANSPARENT, KC_TRANSPARENT, PAIR_CURL,    PAIR_PAREN,    KC_UNDS,        KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FUN] = LAYOUT_planck_grid(
    KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_PSCREEN,     KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          RESET,          
    KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_SCROLLLOCK,  KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        
    KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_PAUSE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_RALT,        WEBUSB_PAIR,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_SPACE,       KC_TAB,         KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_BASE] = { {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0} },

    [_GAME] = { {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0} },

    [_NAV] = { {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {0,183,238}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0} },

    [_MOUSE] = { {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {243,222,234}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0} },

    [_MEDIA] = { {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {10,225,255}, {243,222,234}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0} },

    [_NUM] = { {10,225,255}, {134,255,213}, {134,255,213}, {134,255,213}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {10,225,255}, {134,255,213}, {134,255,213}, {134,255,213}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {10,225,255}, {134,255,213}, {134,255,213}, {134,255,213}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {243,222,234}, {0,0,0}, {0,0,0}, {10,225,255}, {134,255,213}, {10,225,255}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_SYM] = { {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {243,222,234}, {0,0,0}, {0,0,0}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_FUN] = { {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {243,222,234}, {0,0,0}, {0,0,0}, {85,203,158}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0} },

};
// clang-format on

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) {
        return;
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
}

static uint16_t code_timer  = 0;
static char     queued_char = 0;
void            process_pair(keyrecord_t *record, char left, char right) {
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

