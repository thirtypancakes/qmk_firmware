#include QMK_KEYBOARD_H

enum my_keys {
    WINLEFT  = LCTL(LGUI(KC_LEFT)),
    WINRIGHT = RCTL(RGUI(KC_RGHT)),
    WINUP    = RGUI(KC_UP),
    WINMIN   = RGUI(KC_M),
    CTRLESC  = MT(MOD_RCTL, KC_ESC),
    CQUOT    = MT(MOD_LCTL, KC_QUOT),
    SHFTENT  = RSFT_T(KC_ENT),
    MVRGHT   = LGUI(LALT(LSFT(KC_RGHT))),
    MVLEFT   = LGUI(LALT(LSFT(KC_LEFT))),
    MYMUTE   = LGUI(KC_K)
};

// keycode names for layer keys
enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    NUMS
};

// layer names
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTIONS
};

// tapdance key names
enum my_td_keys {
    LLYR,
    RLYR // raise layer tap dance, unused now but may come back to this

};

// dedicated names used in tapdances
enum tap_keycodes {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD
};

// define tap_state
typedef struct tap_state {
    bool is_press_action;
    uint8_t state;
} tap;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
     [_QWERTY] = LAYOUT(\
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                     KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_GRV,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                     KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_MINS, \
        CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                     KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, CQUOT,   \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_PGUP, KC_PGDN, KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, SHFTENT, \
                                   KC_LGUI, KC_LALT, TD(LLYR),KC_SPC,  KC_BSPC, RAISE, KC_RCTL, KC_RGUI                             \
    ),

    [_LOWER] = LAYOUT(\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        KC_GRV,  KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_AMPR,                   KC_GRV,  KC_EQL,  KC_LPRN, KC_RPRN, KC_PLUS, KC_BSPC, \
        KC_DEL,  KC_PERC, KC_LEFT, KC_DOWN, KC_RGHT, KC_CIRC,                   KC_NUHS, KC_MINS, KC_LBRC, KC_RBRC, KC_NUBS, KC_QUOT, \
        _______, KC_0,    KC_AT,   KC_HASH, KC_DLR,  KC_ASTR, _______, _______, KC_RCBR, KC_GT,   KC_LCBR, KC_RCBR, _______, _______, \
                          _______, _______, _______, _______,                   _______, _______, _______, _______                  \
    ),

    [_RAISE] = LAYOUT(\
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______,                   _______, KC_7,    KC_8,    KC_9,    _______, _______, \
        _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______,                   _______, KC_4,    KC_5,    KC_6,    KC_0,    XXXXXXX, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_RBRC, KC_NUBS, \
                                   _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_ADJUST] = LAYOUT(\
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                 _______, _______, _______, _______, _______,  _______, _______, _______ \
    ),

    [_FUNCTIONS] = LAYOUT(\
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, WINUP,   XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, WINLEFT, WINMIN,  WINRIGHT,XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                 _______, _______, _______, _______, _______,  _______, _______, _______ \
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

// `finished` and `reset` functions for each tapdance keycode
void lower_finished(qk_tap_dance_state_t *state, void *user_data);
void lower_reset(qk_tap_dance_state_t *state, void *user_data);

// check tap dance state of LOWER key,
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_HOLD;
        else return SINGLE_HOLD;
    }
    else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_HOLD;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    else return 8;
}

/* function controlling LOWER key, on single hold activate _LOWER
 * on double hold activate layer _FUNCTIONS */
void lower_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_HOLD:
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            break;
        case DOUBLE_HOLD:
            layer_on(_FUNCTIONS);
            break;
    }
}

// cleanup function when tapdance is finished
void lower_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_HOLD: layer_off(_LOWER); break;
        case DOUBLE_HOLD: layer_off(_FUNCTIONS); break;
    }
    ql_tap_state.state = 0;
}

// name associated with each tapdance
qk_tap_dance_action_t tap_dance_actions[] = {
    [LLYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lower_finished, lower_reset, 150),
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// olded functions
const char *read_layer_state(void);
const char *read_logo(void);
/* void set_keylog(uint16_t keycode, keyrecord_t *record); */
/* const char *read_keylog(void); */
/* const char *read_keylogs(void); */

const char *read_mode_icon(bool swap);
/* const char *read_host_led_state(void); */
/* void set_timelog(void); */
/* const char *read_timelog(void); */

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    /* oled_write_ln(read_keylog(), false); */
    /* oled_write_ln(read_keylogs(), false); */
    /* oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false); */
    /* oled_write_ln(read_host_led_state(), false); */
    /* oled_write_ln(read_timelog(), false); */
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

// key functions unctions 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
    }
    return true;
};
