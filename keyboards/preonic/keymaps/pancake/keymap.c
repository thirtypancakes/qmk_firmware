#include "preonic.h"
#include "muse.h" // nicer beeps

enum my_keys {
    WINLEFT = LCTL(LGUI(KC_LEFT)),
    WINRIGHT = RCTL(RGUI(KC_RGHT)),
    WINUP = RGUI(KC_UP),
    WINMIN = RGUI(KC_M),
    CTRLESC = MT(MOD_RCTL, KC_ESC),
    SHFTENT = RSFT_T(KC_ENT),
    MVRGHT = LGUI(LALT(LSFT(KC_RGHT))),
    MVLEFT = LGUI(LALT(LSFT(KC_LEFT)))
};

enum preonic_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMS,
    _FUNCTIONS
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    NUMS
};
enum my_td_keys {
    LYR
};

enum tap_keycodes {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD
};


typedef struct tap_state {
    bool is_press_action;
    uint8_t state;
} tap;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
    [_QWERTY] = LAYOUT_ortho_5x12(\
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_NO,    \
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_DEL,   \
            CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, KC_QUOT,  \
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, SHFTENT,  \
            KC_LCTL, _______, KC_LGUI, KC_LALT, TD(LYR),  KC_SPC,  KC_BSPC, RAISE,   KC_LALT,  KC_RGUI,  _______, _______),

      [_LOWER] = LAYOUT_ortho_5x12(\
            KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F12,   \
            KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_LPRN, KC_RPRN, KC_GRV,  KC_RPRN,  KC_ASTR,  KC_PLUS, KC_BSPC,  \
            KC_DEL,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,   KC_NUHS,  KC_NUBS, KC_QUOT,  \
            _______, _______, _______, _______, _______,  KC_LCBR, KC_RCBR, KC_LT,   KC_LT,    KC_GT,    _______, _______,  \
            _______, _______, _______, _______, LOWER,    _______, KC_ENT , RAISE,   KC_MNXT,  KC_VOLD,  KC_VOLU, KC_MPLY),

      [_RAISE] = LAYOUT_ortho_5x12(\
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,   \
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,    KC_BSPC,  \
            KC_DEL,  _______, _______, _______, _______,  _______, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,  KC_QUOT, KC_BSLS,  \
            _______, KC_BSLS, _______, _______, _______,  _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   _______, _______,  \
            _______, _______, _______, _______, LOWER,    _______, _______, RAISE,   KC_MNXT,  KC_VOLD,  KC_VOLU, KC_MPLY),

      [_ADJUST] = LAYOUT_ortho_5x12(\
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,   \
            _______, _______, MU_MOD,  AU_ON,   AU_OFF,   _______, _______, TERM_ON, TERM_OFF, _______,  _______, KC_BSPC,  \
            _______, DF(0),   DF(0),   DF(0),   DF(0),    AG_NORM, AG_SWAP, RESET,   DEBUG,    _______,  RGB_HUI, RGB_HUD,  \
            _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,   MI_ON,   MI_OFF,  RGB_TOG, RGB_MOD,  RGB_RMOD, RGB_SAI, RGB_SAD,  \
            _______, _______, _______, _______, _______,  _______, _______, _______, RGB_SPD,  RGB_SPD,  RGB_VAI, RGB_VAD),

      [_NUMS] = LAYOUT_ortho_5x12(\
            DF(0),   _______, _______, _______, _______,  _______, _______, _______, KC_PSLS,  KC_PAST,  KC_PMNS, KC_BSPC,  \
            KC_TAB,  _______, _______, _______, _______,  _______, _______, KC_7,    KC_8,     KC_9,     KC_PPLS, KC_QUOT,  \
            KC_ESC,  _______, _______, _______, _______,  _______, _______, KC_4,    KC_5,     KC_6,     KC_PCMM, _______,  \
            KC_LSFT, _______, _______, _______, _______,  _______, _______, KC_1,    KC_2,     KC_3,     KC_PEQL, KC_ENT,   \
            _______, _______, _______, _______, _______,  _______, _______, _______, KC_0,     KC_DOT,   _______, _______),

      [_FUNCTIONS] = LAYOUT_ortho_5x12(\
            _______,  MEH(KC_1),  MEH(KC_2),  MEH(KC_3),  MEH(KC_4),   MEH(KC_5),  MEH(KC_6),  MEH(KC_7),  MEH(KC_8),   MEH(KC_9),   MEH(KC_0), _______,  \
            _______, _______, _______, WINUP,   _______,  _______, _______, _______, _______,  _______,  _______, _______,  \
            _______, _______, WINLEFT, WINMIN,  WINRIGHT, _______, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R,  _______, _______,  \
            _______, _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______, KC_BTN1,  \
            _______, _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______, _______),
};

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

// `finished` and `reset` functions for each tapdance keycode
/* void ql_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void ql_reset(qk_tap_dance_state_t *state, void *user_data); */

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
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
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
void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case SINGLE_HOLD: layer_off(_LOWER); break;
        case DOUBLE_HOLD: layer_off(_FUNCTIONS); break;
    }
    ql_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [LYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 200)
};

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
        case NUMS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NUMS);
            }
            return false;
            break;
    }
    return true;
};
