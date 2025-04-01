#include QMK_KEYBOARD_H
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _SYS
#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

enum sofle_layers {
    _QWERTY,
    _DHM,
    _MAP_GMS,
    _QWERTY_GMS,
    _GMS_NUMS,
    _SYS,
    _MNG,
    _SYM,
    _FS,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_DHM,
    KC_MAP_GMS,
    KC_QWERTY_GMS,
    KC_FS,
    KC_LT_SYS_CSG,
    KC_MT_CTRL_MEH,
    KC_MT_LSFT_CS,
};

enum tap_dance {
    TD_3_E,
    TD_X_b,
    TD_MS_4_5,
};
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        TD(TD_3_E) ,KC_Q    ,KC_W    ,KC_E     ,KC_R           ,KC_T          ,                /**/                   KC_Y   ,KC_U ,KC_I    ,KC_O   ,KC_P              ,TD(TD_X_b) ,
        KC_ESC     ,KC_A    ,KC_S    ,KC_D     ,KC_F           ,KC_G          ,                /**/                   KC_H   ,KC_J ,KC_K    ,KC_L   ,KC_SCLN           ,KC_ENT     ,
        KC_LGUI    ,KC_Z    ,KC_X    ,KC_C     ,KC_V           ,KC_B          ,                /**/                   KC_N   ,KC_M ,KC_COMM ,KC_DOT ,LT(_MNG, KC_SLSH) ,KC_LALT    ,
                                                KC_MT_CTRL_MEH ,KC_LT_SYS_CSG ,KC_MT_LSFT_CS , /**/ LT(_SYM, KC_TAB) ,KC_SPC
    ),
    [_DHM] = LAYOUT(
        _______ ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,          /**/          KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,_______ ,
        _______ ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,          /**/          KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,_______ ,
        _______ ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,          /**/          KC_K    ,KC_H    ,_______ ,_______ ,_______ ,_______ ,
                                            _______ ,_______ ,_______ , /**/ _______ ,_______
    ),
    [_MAP_GMS] = LAYOUT(
        KC_F/*T*/ ,KC_TAB  ,KC_Q/*Q*/ ,KC_W/*W*/ ,KC_K/*E*/ ,KC_S/*R*/ ,                        /**/          _______ ,_______   ,_______   ,_______ ,_______ ,_______ ,
        KC_G/*G*/ ,KC_LSFT ,KC_A/*A*/ ,KC_D/*S*/ ,KC_V/*D*/ ,KC_E/*F*/ ,                        /**/          _______ ,A(KC_TAB) ,G(KC_TAB) ,_______ ,_______ ,_______ ,
        KC_T/*B*/ ,KC_LCTL ,KC_Z/*Z*/ ,KC_X/*X*/ ,KC_C/*C*/ ,KC_B/*V*/ ,                        /**/          _______ ,_______   ,_______   ,_______ ,_______ ,_______ ,
                                                  KC_LALT   ,KC_SPC    ,LT(_GMS_NUMS, KC_ESC) , /**/ _______ ,_______
    ),
    [_QWERTY_GMS] = LAYOUT(
        KC_T    ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E     ,KC_R    ,                        /**/          _______ ,_______   ,_______   ,_______ ,_______ ,_______ ,
        KC_G    ,KC_LSFT ,KC_A    ,KC_S    ,KC_D     ,KC_F    ,                        /**/          _______ ,A(KC_TAB) ,G(KC_TAB) ,_______ ,_______ ,_______ ,
        KC_B    ,KC_LCTL ,KC_Z    ,KC_X    ,KC_C     ,KC_V    ,                        /**/          _______ ,_______   ,_______   ,_______ ,_______ ,_______ ,
                                            KC_LALT  ,KC_SPC  ,LT(_GMS_NUMS, KC_ESC) , /**/ _______ ,_______
    ),
    [_GMS_NUMS] = LAYOUT(
        KC_Y    ,HYPR(KC_QUOT) ,KC_1    ,_______ ,KC_2    ,KC_6    ,          /**/          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        KC_H    ,_______       ,_______ ,_______ ,_______ ,KC_7    ,          /**/          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        KC_N    ,_______       ,KC_3    ,KC_4    ,KC_5    ,KC_8    ,          /**/          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                                  _______ ,_______ ,_______ , /**/ _______ ,_______
    ),
    [_SYS] = LAYOUT(
        _______    ,G(C(KC_1)) ,G(C(KC_2)) ,G(C(KC_3)) ,G(C(KC_4)) ,G(C(KC_5))    ,          /**/          KC_PGUP ,KC_HOME    ,KC_UP   ,KC_END      ,_______ ,_______   ,
        C(KC_BSPC) ,KC_BSPC    ,MS_BTN2    ,MS_BTN3    ,MS_BTN1    ,TD(TD_MS_4_5) ,          /**/          KC_PGDN ,KC_LEFT    ,KC_DOWN ,KC_RIGHT    ,KC_DEL  ,C(KC_DEL) ,
        _______    ,G(KC_1)    ,G(KC_2)    ,G(KC_3)    ,G(KC_4)    ,G(KC_5)       ,          /**/          _______ ,C(KC_LEFT) ,_______ ,C(KC_RIGHT) ,_______ ,_______   ,
                                                        _______    ,_______       ,_______ , /**/ _______ ,KC_FS
    ),
    [_MNG] = LAYOUT(
        _______ ,HYPR(KC_QUOT) ,KC_CAPS ,KC_PSCR      ,KC_INS  ,_______ ,          /**/          _______           ,_______        ,_______   ,_______    ,_______ ,_______ ,
        _______ ,_______       ,KC_VOLD ,KC_MPLY      ,KC_VOLU ,_______ ,          /**/          DF(KC_QWERTY_GMS) ,DF(KC_MAP_GMS) ,KC_QWERTY ,DF(KC_DHM) ,_______ ,_______ ,
        _______ ,_______       ,KC_MPRV ,HYPR(KC_GRV) ,KC_MNXT ,_______ ,          /**/          _______           ,_______        ,_______   ,_______    ,_______ ,_______ ,
                                                       _______ ,_______ ,_______ , /**/ _______ ,_______
    ),
    [_SYM] = LAYOUT(
        KC_GRV  ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,          /**/          KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_UNDS ,LSFT(KC_P) ,_______ ,
        KC_QUOT ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,          /**/          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0       ,KC_DQT  ,
        KC_TILD ,KC_QUES ,KC_LBRC ,KC_LCBR ,KC_LPRN ,KC_LABK ,          /**/          KC_RABK ,KC_RPRN ,KC_RCBR ,KC_RBRC ,KC_BSLS    ,KC_PIPE ,
                                            KC_MINS ,KC_EQL  ,KC_PLUS , /**/ _______ ,_______
    ),
    [_FS] = LAYOUT(
        _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,          /**/          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
        _______ ,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTL ,_______ ,          /**/          _______ ,KC_LCTL ,KC_LSFT ,KC_LALT ,KC_LGUI ,_______ ,
        _______ ,KC_F11  ,KC_F12  ,_______ ,_______ ,_______ ,          /**/          _______ ,KC_DEL  ,_______ ,_______ ,_______ ,_______ ,
                                            _______ ,_______ ,_______ , /**/ _______ ,_______
    ),
};
// clang-format on
bool prev_prev_pressed = false;
bool prev_pressed      = false;
bool curr_pressed      = false;

uint16_t prev_prev_keycode = KC_NO;
uint16_t prev_keycode      = KC_NO;
uint16_t curr_keycode      = KC_NO;

bool handle_mod_tap_oneshot(uint16_t mt_key, uint16_t oneshot_mods) {
    static uint16_t timer;
    bool            allow_mods = prev_keycode == curr_keycode && prev_pressed;
    clear_oneshot_mods();

    if (curr_pressed) {
        timer = timer_read();
        register_code(mt_key);
    } else {
        unregister_code(mt_key);

        if (allow_mods && timer_elapsed(timer) < TAPPING_TERM) {
            add_oneshot_mods(oneshot_mods);
        }
    }
    return false;
}

bool handle_layer_tap_oneshot(enum sofle_layers layer, uint16_t oneshot_mods) {
    static uint16_t timer;
    bool            allow_mods = prev_keycode == curr_keycode && prev_pressed;
    clear_oneshot_mods();

    if (curr_pressed) {
        timer = timer_read();
        layer_on(layer);
    } else {
        layer_off(layer);

        if (allow_mods && timer_elapsed(timer) < TAPPING_TERM) {
            add_oneshot_mods(oneshot_mods);
        }
    }
    return false;
}

bool handle_layer_on_off(enum sofle_layers layer) {
    curr_pressed ? layer_on(layer) : layer_off(layer);
    return false;
}

bool handle_persist_layer(enum sofle_layers layer) {
    if (curr_pressed) set_single_persistent_default_layer(layer);
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);

    prev_prev_pressed = prev_pressed;
    prev_pressed      = curr_pressed;
    curr_pressed      = record->event.pressed;

    prev_prev_keycode = prev_keycode;
    prev_keycode      = curr_keycode;
    curr_keycode      = keycode;

    switch (keycode) {
        case KC_QWERTY:
            return handle_persist_layer(_QWERTY);
        case KC_FS:
            return handle_layer_on_off(_FS);
        case KC_LT_SYS_CSG:
            return handle_layer_tap_oneshot(_SYS, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT));
        case KC_MT_CTRL_MEH:
            return handle_mod_tap_oneshot(KC_LCTL, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
        case KC_MT_LSFT_CS:
            return handle_mod_tap_oneshot(KC_LSFT, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT));
    }

    return true;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_3_E]    = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRV),
    [TD_X_b]    = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_MS_4_5] = ACTION_TAP_DANCE_DOUBLE(MS_BTN4, MS_BTN5),
};
