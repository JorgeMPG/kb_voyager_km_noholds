// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"


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
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
};



enum tap_dance_codes {
  DANCE_0,
};

// Layer Declarations
enum {
    _BASE,
    _L_OSL,
    _R_OSL,
    _L_NAV,
    _R_NAV,
    _L_NUM,
    _R_NUM,
    _KBCONTROL,
};

// Vim macros:
//  - Bring the last column (current and 3 lines below) to the current position, shifting all intermediate columns one column to the right.
//    jjj$F,€ýa;d$p

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_voyager(
    //-------------  , --------------  , --------------  , --------------  , --------------  , ---------SPLIT  , SPLIT---------  , --------------  , --------------  , --------------  , --------------  , --------------  ,
    KC_ESCAPE        , KC_1            , KC_2            , KC_3            , KC_4            , KC_5            , KC_6            , KC_7            , KC_8            , KC_9            , KC_0            , KC_BACKSPACE    ,
    KC_TAB           , KC_Q            , KC_W            , KC_E            , KC_R            , KC_T            , KC_Y            , KC_U            , KC_I            , KC_O            , KC_P            , KC_MINUS        ,
    OSM(MOD_LSFT)    , KC_A            , KC_S            , KC_D            , KC_F            , KC_G            , KC_H            , KC_J            , KC_K            , KC_L            , KC_SCLN         , KC_QUOTE        ,
    OSM(MOD_LCTL)    , KC_Z            , KC_X            , KC_C            , KC_V            , KC_B            , KC_N            , KC_M            , KC_COMMA        , KC_DOT          , KC_SLASH        , KC_ENTER        ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      OSL(_L_OSL)    ,  KC_SPACE       ,  KC_SPACE       ,  OSL(_R_OSL)
  ),
  [_L_OSL] = LAYOUT_voyager(
    //------------- ,  --------------      ,  -------------- ,  -------------- ,  -------------- ,  ---------SPLIT ,  SPLIT--------- ,  -------------- ,  -------------- ,  -------------- ,  -------------- ,  -------------- ,
    KC_F11          ,  KC_F1               ,  KC_F2          ,  KC_F3          ,  KC_F4          ,  KC_F5          ,  KC_F6          ,  KC_F7          ,  KC_F8          ,  KC_F9          ,  KC_F10         ,  KC_F11 ,
    KC_F12          ,  QK_CAPS_WORD_TOGGLE ,  KC_TAB         ,  OSM(MOD_LCTL)  ,  OSM(MOD_LALT)  ,  KC_BSPC        ,  _______        ,  _______        ,  _______        ,  _______        ,  _______        ,  KC_F12 ,
    _______         ,  KC_CIRC             ,  KC_ENTER       ,  OSM(MOD_LGUI)  ,  OSM(MOD_LSFT)  ,  KC_ESCAPE      ,  _______        ,  _______        ,  _______        ,  _______        ,  _______        ,  _______ ,
    TO(_KBCONTROL)   ,  _______             ,  TO(_L_NUM)     ,  TO(_L_NAV)     ,  KC_BACKSLASH   ,  KC_DEL         ,  _______        ,  _______        ,  _______        ,  _______        ,  _______        ,  _______ ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      XXXXXXX        ,  XXXXXXX        ,  XXXXXXX        ,  XXXXXXX
  ),
  [_R_OSL] = LAYOUT_voyager(
    //-------------  , --------------  , --------------  , --------------  , --------------  , ---------SPLIT  , SPLIT---------  , --------------  , --------------  , --------------  , --------------       , --------------  ,
    KC_F11           , KC_F10          , KC_F9           , KC_F8           , KC_F7           , KC_F6           , KC_F5           , KC_F4           , KC_F3           , KC_F2           , KC_F1                , KC_F11          ,
    KC_F12           , _______         , _______         , _______         , _______         , _______         , KC_BSPC         , OSM(MOD_LALT)   , OSM(MOD_LCTL)   , KC_TAB          , QK_CAPS_WORD_TOGGLE  , KC_F12          ,
    _______          , _______         , _______         , _______         , _______         , _______         , KC_ESCAPE       , OSM(MOD_LSFT)   , OSM(MOD_LGUI)   , KC_ENTER        , KC_CIRC              , _______         ,
    _______          , _______         , _______         , _______         , _______         , _______         , KC_DEL          , KC_BACKSLASH    , TO(_R_NAV)      , TO(_R_NUM)      , _______              , TO(_KBCONTROL)   ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      XXXXXXX        ,  XXXXXXX        ,  XXXXXXX        ,  XXXXXXX
  ),
  [_L_NAV] = LAYOUT_voyager(
    //-------------  , --------------  , --------------  , --------------  , --------------  , ---------SPLIT  , SPLIT---------  , --------------  , --------------  , --------------  , --------------       , --------------  ,
    _______          , _______         , _______         , _______         , _______         , _______         , _______         , _______         , _______         , _______         , _______              , _______         ,
    _______          , KC_PAGE_UP      , KC_W            , KC_UP           , KC_R            , _______         , KC_BSPC         , OSM(MOD_LALT)   , OSM(MOD_LCTL)   , KC_TAB          , QK_CAPS_WORD_TOGGLE  , _______         ,
    _______          , KC_PAGE_DOWN    , KC_LEFT         , KC_DOWN         , KC_RIGHT        , _______         , KC_ESCAPE       , OSM(MOD_LSFT)   , OSM(MOD_LGUI)   , KC_ENTER        , KC_CIRC              , _______         ,
    _______          , _______         , KC_BACKSPACE    , _______         , KC_DEL          , _______         , KC_DEL          , KC_BACKSLASH    , _______         , _______         , _______              , _______         ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      XXXXXXX        ,  TO(_BASE)      ,  TO(_BASE)      ,  XXXXXXX
  ),
  [_R_NAV] = LAYOUT_voyager(
    //-------------  , --------------       , --------------  , --------------  , --------------  , ---------SPLIT  , SPLIT---------  , --------------  , --------------  , --------------  , --------------  , --------------  ,
    _______          , _______              , _______         , _______         , _______         , _______         , _______         , _______         , _______         , _______         , _______         , _______         ,
    _______          , QK_CAPS_WORD_TOGGLE  , KC_TAB          , OSM(MOD_LCTL)   , OSM(MOD_LALT)   , KC_BSPC         , _______         , KC_R            , KC_UP           , KC_W            , KC_PAGE_UP      , _______         ,
    _______          , KC_CIRC              , KC_ENTER        , OSM(MOD_LGUI)   , OSM(MOD_LSFT)   , KC_ESCAPE       , _______         , KC_LEFT         , KC_DOWN         , KC_RIGHT        , KC_PAGE_DOWN    , _______         ,
    _______          , _______              , _______         , _______         , KC_BACKSLASH    , KC_DEL          , _______         , KC_BACKSPACE    , _______         , KC_DEL          , _______         , _______         ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      XXXXXXX        ,  TO(_BASE)      ,  TO(_BASE)      ,  XXXXXXX
  ),
  [_L_NUM] = LAYOUT_voyager(
    //-------------  , --------------  , --------------       , --------------        , --------------  , ---------SPLIT  , SPLIT---------  , --------------  , --------------  , --------------  , --------------       , --------------  ,
    _______          , KC_1            , KC_2                 , KC_3                  , KC_4            , KC_5            , _______         , _______         , _______         , _______         , _______              , _______         ,
    _______          , KC_6            , KC_7                 , KC_8                  , KC_9            , KC_0            , KC_BSPC         , OSM(MOD_LALT)   , OSM(MOD_LCTL)   , KC_TAB          , QK_CAPS_WORD_TOGGLE  , _______         ,
    _______          , KC_BACKSLASH    , KC_LEFT_BRACKET      , KC_RIGHT_BRACKET      , KC_MINUS        , KC_SLASH        , KC_ESCAPE       , OSM(MOD_LSFT)   , OSM(MOD_LGUI)   , KC_ENTER        , KC_CIRC              , _______         ,
    _______          , KC_SEMICOLON    , KC_LEFT_CURLY_BRACE  , KC_RIGHT_CURLY_BRACE  , KC_EQUAL        , KC_DOT          , KC_DEL          , KC_BACKSLASH    , _______         , _______         , _______              , _______         ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      XXXXXXX        ,  TO(_BASE)      ,  TO(_BASE)      ,  XXXXXXX
  ),
  [_R_NUM] = LAYOUT_voyager(
    //-------------  , --------------       , --------------  , --------------  , --------------  , ---------SPLIT  , SPLIT---------  , --------------  , --------------       , --------------        , --------------  , --------------  ,
    _______          , _______              , _______         , _______         , _______         , _______         , KC_1            , KC_2            , KC_3                 , KC_4                  , KC_5            , _______         ,
    _______          , QK_CAPS_WORD_TOGGLE  , KC_TAB          , OSM(MOD_LCTL)   , OSM(MOD_LALT)   , KC_BSPC         , KC_6            , KC_7            , KC_8                 , KC_9                  , KC_0            , _______         ,
    _______          , KC_CIRC              , KC_ENTER        , OSM(MOD_LGUI)   , OSM(MOD_LSFT)   , KC_ESCAPE       , KC_SLASH        , KC_MINUS        , KC_LEFT_BRACKET      , KC_RIGHT_BRACKET      , KC_BACKSLASH    , _______         ,
    _______          , _______              , _______         , _______         , KC_BACKSLASH    , KC_DEL          , KC_DOT          , KC_EQUAL        , KC_LEFT_CURLY_BRACE  , KC_RIGHT_CURLY_BRACE  , KC_SEMICOLON    , _______         ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      XXXXXXX        ,  TO(_BASE)      ,  TO(_BASE)      ,  XXXXXXX
  ),
  [_KBCONTROL] = LAYOUT_voyager(
    //-------------  , --------------      , --------------  , --------------      , --------------    , ---------SPLIT  , SPLIT---------  , --------------  , --------------  , --------------  , --------------       , --------------  ,
    RGB_TOG          , TOGGLE_LAYER_COLOR  , RGB_MOD         , RGB_SLD             , RGB_VAD           , RGB_VAI         , _______         , _______         , _______         , _______         , _______              , _______         ,
    XXXXXXX          , XXXXXXX             , HSV_0_255_255   , HSV_74_255_255      , HSV_169_255_255   , XXXXXXX         , KC_BSPC         , OSM(MOD_LALT)   , OSM(MOD_LCTL)   , KC_TAB          , QK_CAPS_WORD_TOGGLE  , _______         ,
    XXXXXXX          , XXXXXXX             , KC_AUDIO_MUTE   , KC_AUDIO_VOL_DOWN   , KC_AUDIO_VOL_UP   , XXXXXXX         , KC_ESCAPE       , OSM(MOD_LSFT)   , OSM(MOD_LGUI)   , KC_ENTER        , KC_CIRC              , _______         ,
    XXXXXXX          , XXXXXXX             , XXXXXXX         , KC_BRIGHTNESS_DOWN  , KC_BRIGHTNESS_UP  , XXXXXXX         , KC_DEL          , KC_BACKSLASH    , _______         , _______         , _______              , _______         ,
    // Thumb cluster
    //-------------- ,  ---------SPLIT ,  SPLIT--------- ,  --------------
      XXXXXXX        ,  TO(_BASE)      ,  TO(_BASE)      ,  XXXXXXX
  ),
};

const uint16_t PROGMEM combo0[] = { MT(MOD_RSFT, KC_QUOTE), MT(MOD_LSFT, KC_BSPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_CAPS),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}

// https://github.com/qmk/qmk_firmware/issues/22566
// Restore deprecated OSL quirk: Disable OSL upon OSM tap.
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_ONE_SHOT_MOD(keycode) && is_oneshot_layer_active() && record->event.pressed) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    }
    return;
}



typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
