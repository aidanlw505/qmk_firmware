#include QMK_KEYBOARD_H


#define _MVML         SGUI(KC_LEFT)
#define _MVMR        SGUI(KC_RGHT)
#define _WDL         LCTL(KC_LEFT)
#define _WDR        LCTL(KC_RGHT)
#define _TBL         LCTL(KC_PGUP)
#define _TBR        LCTL(KC_PGDN)
#define _MWL         LGUI(KC_LEFT)
#define _MWU           LGUI(KC_UP)
#define _MWD         LGUI(KC_DOWN)
#define _MWR        LGUI(KC_RGHT)


#define _LMWL           LSFT(_MWL)
#define _LMWR           LSFT(_MWR)
#define _LMWU           LSFT(_MWU)
#define _LMWD           LSFT(_MWD)

#define _BASE           0
#define _RL             1
#define _LL             2 
#define _NUM            3
#define _MCRO           4
#define _RL2            5
#define _LL2            6


enum my_keycodes {
    // Windows
    _NDES = SAFE_RANGE,
    _XDES,
    _LDES,
    _RDES,
    _SETL,
    _SETW,
    _MORL,
    _MOLL,

};

typedef union {
    uint32_t raw;
    struct {
        bool    linux :1;
    };
} user_config_t;

user_config_t user_config;



bool process_record_user(uint16_t keycode, keyrecord_t *record);
void macro_check(uint16_t keycode, keyrecord_t *record);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Ctrl |  GUI |  Num | Alt  | Lower| Ent  | Space|Raise | Alt  | Mcro |  Gui | Ctrl |
     * `-----------------------------------------------------------------------------------'
     */


    [_BASE] = LAYOUT_ortho_5x12( \
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
            KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
            KC_LCTL, KC_LGUI, TT(_NUM),KC_LALT, _MOLL,KC_ENT,  KC_SPC,  _MORL,KC_RALT, MO(_MCRO),  KC_RGUI,   KC_RCTL  \
            ),
    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F1  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  `   |  {   |  [   |  (   |  <   |  >   |   )  |   ]  |   }  |   ~  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |  F11 |  F12 |      |   ,  |   .  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RL] = LAYOUT_ortho_5x12( \
            _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,   KC_PERC, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, _______, \
            _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,    KC_F5,   _WDL, _TBL, _TBR,_WDR,KC_NO,   KC_SLCK, \
            _______, KC_GRV,  KC_LBRC, KC_LCBR,KC_LPRN,  KC_LT,  KC_LEFT,   KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_PSCR, \
            _______, KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_F11,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,    _______, \
            _______, _______, _______, _______, _MOLL, _______,  _______, _MORL, _______, _______, _______, _______ \
            ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F1  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  `   |  {   |  [   |  (   |  <   |  >   |   )  |   ]  |   }  |   ~  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |  F11 |  F12 |      |   ,  |   .  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     3zj* `-----------------------------------------------------------------------------------'
     */
    [_LL] = LAYOUT_ortho_5x12( \
            _______, KC_F13,  KC_F14, _NDES,   _XDES,    KC_NO,  KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______, \
            _______, KC_NO,   _LDES,  _MVML,   _MVMR,    _RDES,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
            _______, KC_NO,   _MWL,   _MWU,_MWD, _MWR,   KC_GT,   KC_RPRN,  KC_RCBR,KC_RBRC, KC_TILD, KC_DQUO, \
            _______, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_F12,  KC_NO,   KC_COMM, KC_DOT,  KC_QUES,  _______, \
            _______, _______, _______, _______,_MOLL, _______,  _______, _MORL, _______, _______, _______, _______ \
            ),








    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F1  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  `   |  {   |  [   |  (   |  <   |  >   |   )  |   ]  |   }  |   ~  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |  F11 |  F12 |      |   ,  |   .  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RL2] = LAYOUT_ortho_5x12( \
            _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,   KC_PERC, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, _______, \
            _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,    KC_F5,   _WDL, _TBL, _TBR,_WDR,KC_NO,   KC_SLCK, \
            _______, KC_GRV,  KC_LBRC, KC_LCBR,KC_LPRN,  KC_LT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_PSCR, \
            _______, KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_F11,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,    _______, \
            _______, _______, _______,_______, _MOLL, _______,  _______, _MORL, _______, _______, _______, _______ \
            ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F1  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  `   |  {   |  [   |  (   |  <   |  >   |   )  |   ]  |   }  |   ~  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |  F11 |  F12 |      |   ,  |   .  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     3zj* `-----------------------------------------------------------------------------------'
     */
    [_LL2] = LAYOUT_ortho_5x12( \
            _______, KC_F13,  KC_F14, _NDES,   _XDES,    KC_NO,  KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______, \
            _______, KC_NO,   _LMWL,  _LMWU,_LMWD,_LMWR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
            _______, KC_NO,   _MWL,   _MWU,_MWD, _MWR,   KC_GT,   KC_RPRN,  KC_RCBR,KC_RBRC, KC_TILD, KC_DQUO, \
            _______, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_F12,  KC_NO,   KC_COMM, KC_DOT,  KC_QUES,  _______, \
            _______, _______, _______,_______,_MOLL, _______,  _______, _MORL, _______, _______, _______, _______ \
            ),


    /* numpad
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  f1  |  f1  |  f3  |  f4  |  f5  |  f6  |  f7  |  f8  |  f9  |  f10 | del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  `   |  {   |  [   |  (   |  <   |  >   |   )  |   ]  |   }  |   ~  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |  f11 |  f12 |      |   ,  |   .  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_5x12( \
            _______, KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_7,   KC_8,   KC_9,  KC_PSLS,   _______,  \
            _______, KC_PGUP, KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_4,   KC_5,   KC_6,  KC_PAST,   KC_SLCK,   \
            _______, KC_PGDN, KC_LEFT,KC_UP,   KC_DOWN,  KC_RIGHT,KC_NO,    KC_1,   KC_2,   KC_3,  KC_PMNS,   KC_NLCK,   \
            _______, KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_0,   KC_COMMA,   KC_PDOT,  KC_PPLS,    _______, \
            _______, KC_LGUI,  _______, _______, _MOLL, _______,  _______, _MORL, _______, _______, _______, _______ \
            ),


    /* marco
     * ,-----------------------------------------------------------------------------------.
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  f1  |  f1  |  f3  |  f4  |  f5  |  f6  |  f7  |  f8  |  f9  |  f10 | del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  `   |  {   |  [   |  (   |  <   |  >   |   )  |   ]  |   }  |   ~  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |  f11 |  f12 |      |   ,  |   .  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_MCRO] = LAYOUT_ortho_5x12( \
            DM_RSTP, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
            _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
            _______, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
            _______, RGB_MOD, RGB_VAD, RGB_HUI, RGB_SAI, _SETL,   _SETW,    KC_M,    KC_COMMA, RESET, RGB_TOG, _______, 
            _______, _______, _______,_______, TG(_LL),_______, _______, TG(_RL),_______, _______, _______, _______ \
            )




              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////
              ////////////////////////////////////////////////////////////////////////////////////////////////////




};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {


    if(record->event.pressed)
    {
        switch (keycode) {
            case _NDES:
                SEND_STRING(SS_LCTRL(SS_TAP(X_LALT)));
                register_code(KC_LCTRL);
                register_code(KC_LGUI);
                tap_code(KC_D);
                unregister_code(KC_LCTRL);
                unregister_code(KC_LGUI);
                break;
            case _XDES:
                SEND_STRING(SS_LCTRL(SS_TAP(X_LALT)));
                register_code(KC_LCTRL);
                register_code(KC_LGUI);
                tap_code(KC_F4);
                unregister_code(KC_LCTRL);
                unregister_code(KC_LGUI);

                break;
            case _LDES:
                SEND_STRING(SS_LCTRL(SS_TAP(X_LALT)));
                register_code(KC_LCTRL);
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTRL);
                unregister_code(KC_LGUI);

                break;
            case _RDES:
                SEND_STRING(SS_LCTRL(SS_TAP(X_LALT)));
                register_code(KC_LCTRL);
                register_code(KC_LGUI);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCTRL);
                unregister_code(KC_LGUI);

                break;
            case _SETW:
                user_config.linux = false;
                eeconfig_update_user(user_config.raw);
                break;
            case _SETL:
                user_config.linux = true;
                eeconfig_update_user(user_config.raw);
                break;
        }

    }
    if (keycode == _MOLL) {
        if(record->event.pressed) {
            if (!user_config.linux) {
                layer_on(_LL);
            } else {
                layer_on(_LL2);
            }

        } else {
            if (!user_config.linux) {
                layer_off(_LL);
            } else {
                layer_off(_LL2);
            }
        }
    }


    if (keycode == _MORL) {
        if(record->event.pressed) {
            if (!user_config.linux) {
                layer_on(_RL);
            } else {
                layer_on(_RL2);
            }

        } else {
            if (!user_config.linux) {
                layer_off(_RL);
            } else {
                layer_off(_RL2);
            }
        }
    }



    /*
       if (layer_state_is(_MCRO)) {
       if(record->event.pressed) {
       register_code(KC_F24);
       } else {
       unregister_code(KC_F24);
       }
       }
       */
    return true;
}


void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_DOWN);
    } else {
        tap_code(KC_UP);
    }

}




void eeconfig_init_user(void) {  // EEPROM is getting reset!
    user_config.raw = 0;
    user_config.linux = false; // We want this enabled by default
    eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

}
/*

// RGB LAYERS
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {4, 9, HSV_RED}       // Light 4 LEDs, starting with LED 6
        );
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {9, 2, HSV_WHITE}
        );
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {6, 2, HSV_WHITE}
        );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_capslock_layer,
        my_layer1_layer,    // Overrides caps lock layer
        my_layer2_layer     // Overrides other layers
        );



layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, _RL) || layer_state_cmp(state, _RL2));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RL) || layer_state_cmp(state, _LL2));
    return state;
}





bool led_update_user(led_t led_state) {
    for(unsigned int i = 0; i < 25; i++) {
        setrgb(0,0,0, (LED_TYPE *)&led[i]);
    }
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

*/
void keyboard_post_init_user(void) {
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
    // Enable the LED layers
    //   rgblight_layers = my_rgb_layers;
}


