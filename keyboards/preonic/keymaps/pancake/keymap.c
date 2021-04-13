#include "preonic.h"
#include "muse.h" // nicer beeps

// easier names for long keycodes
enum my_keys {
    WINLEFT  = LCTL(LGUI(KC_LEFT)),
    WINRIGHT = RCTL(RGUI(KC_RGHT)),
    WINUP    = RGUI(KC_UP),
    WINMIN   = RGUI(KC_M),
    CTRLESC  = MT(MOD_RCTL, KC_ESC),
    CQUOT    = MT(MOD_LCTL, KC_QUOT),
    SHFTENT  = RSFT_T(KC_ENT),
    MVRGHT   = LGUI(LALT(LSFT(KC_RGHT))),
    MVLEFT   = LGUI(LALT(LSFT(KC_LEFT)))
};

// layers
enum preonic_layers {
    _QWERTY,    // default layer
    _LOWER,     // symbols
    _RAISE,     // numpad, movement keys
    _ADJUST,    // qmk funtions, misc
    _FUNCTIONS // windows window management, mouse keys
};

// names for switching to layers
enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    NUMS
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

enum combo_keys {
    RPRN,
    RBRC,
    RBCR,
    LPRN,
    LBRC,
    LBCR
};


// define tap_state
typedef struct tap_state {
    bool is_press_action;
    uint8_t state;
} tap;

// combo keys
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [RPRN] = COMBO(er_combo, KC_LPRN),
    [RBRC] = COMBO(df_combo, KC_LBRC),
    [RBCR] = COMBO(cv_combo, KC_LBRC),
    [LPRN] = COMBO(ui_combo, KC_RPRN),
    [LBRC] = COMBO(jk_combo, KC_RBRC),
    [LBCR] = COMBO(mcom_combo, KC_RBRC)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
    [_QWERTY] = LAYOUT_ortho_5x12(\
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_NO,    \
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_DEL,   \
            CTRLESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, CQUOT,    \
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_SLSH, SHFTENT,  \
            KC_LCTL, _______, KC_LGUI, KC_LALT, TD(LLYR), KC_SPC, KC_BSPC, TT(_RAISE), KC_LALT, KC_RGUI, _______, _______),

      [_LOWER] = LAYOUT_ortho_5x12(\
            KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,   \
            KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_RPRN, KC_NO,   KC_PLUS, KC_BSPC,  \
            KC_DEL,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_NUHS, KC_NUBS, KC_QUOT,  \
            _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LT,   KC_LT,   KC_GT,   _______, _______,  \
            _______, _______, _______, _______, LOWER,   _______, KC_ENT,  RAISE,   KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

      [_RAISE] = LAYOUT_ortho_5x12(\
            KC_GRV,  _______, KC_7, KC_8,    KC_9,  _______, _______, _______, _______, _______, _______, _______,  \
            _______, _______, KC_7, KC_8,    KC_9,  _______, KC_UP,   _______, _______, _______, _______, KC_BSPC,  \
            KC_DEL,  _______, KC_4, KC_5,    KC_6,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_BSLS,  \
            _______, _______, KC_1, KC_2,    KC_3,  _______, _______, _______, _______, _______, _______, _______,  \
            _______, _______, KC_0, _______, LOWER, _______, _______, RAISE,   _______, KC_VOLD, KC_VOLU, KC_MPLY),

      [_ADJUST] = LAYOUT_ortho_5x12(\
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,   \
            _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL,   \
            _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,  \
            _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  _______, _______, _______,  \
            _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______),

      [_FUNCTIONS] = LAYOUT_ortho_5x12(\
            _______, MEH(KC_1),  MEH(KC_2),  MEH(KC_3),  MEH(KC_4),   MEH(KC_5),  MEH(KC_6),  MEH(KC_7),  MEH(KC_8),   MEH(KC_9),   MEH(KC_0), _______,  \
            _______, _______, _______, WINUP,   _______,  _______, _______, _______, _______,  _______,  _______, _______,  \
            _______, _______, WINLEFT, WINMIN,  WINRIGHT, _______, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R,  _______, _______,  \
            _______, _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______, KC_BTN1,  \
            _______, _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______, _______),
};
            /* old adjust layer, here as a comment until I decide how I want to map it                                           */
            /* KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,  KC_F12,   \ */
            /* _______, _______, MU_MOD,  AU_ON,   AU_OFF,   _______, _______, TERM_ON, TERM_OFF, _______,  _______, KC_BSPC,  \ */
            /* _______, DF(0),   DF(0),   DF(0),   DF(0),    AG_NORM, AG_SWAP, RESET,   DEBUG,    _______,  RGB_HUI, RGB_HUD,  \ */
            /* _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,   MI_ON,   MI_OFF,  RGB_TOG, RGB_MOD,  RGB_RMOD, RGB_SAI, RGB_SAD,  \ */
            /* _______, _______, _______, _______, _______,  _______, _______, _______, RGB_SPD,  RGB_SPD,  RGB_VAI, RGB_VAD), */

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
    [LLYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lower_finished, lower_reset, 200),
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
    }
    return true;
};
