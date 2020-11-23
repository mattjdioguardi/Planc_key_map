/* Copyright 2018 GoTakigawa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #include QMK_KEYBOARD_H

 
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _THIRD,
  _NUM,
  _GAME,
};

 enum custom_keycodes {
   QWERTY = SAFE_RANGE,
   LOWER,
   RAISE,
   THIRD,
   NUM,
   GAME
 };

 #define LOWER MO(_LOWER)
 #define RAISE MO(_RAISE)
 #define THIRD MO(_THIRD)
 #define NUM MO(_NUM)


typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    QUOT_LAYR,
};


    


// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);






enum {
    TD_ESC_CAPS,
    TD_CRTL_ALT,
    TD_SFT_LAYR,
    TD_NUM,
};


 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Qwerty
  * ,---------------------------------------------------------------------.
  * |Q/caps|   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
  * |------+------+------+------+------+------|------+------+------+------|
  * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
  * |------+------+------+------+------+------+-------------+------+------|
  * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
  * |-------------+------+------+------+------+------+------+------+------'
  * |Shift |  GUI |del |Bksp/sh|Lower/t|space |Raise/E|ctrl | Left |Right |
  * `---------------------------------------------------------------------'
  */
 [_QWERTY] = LAYOUT_ortho_4x10( \
   TD(TD_ESC_CAPS),     KC_W,     KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,     \
   KC_A,     KC_S,     KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCOLON,  \
   KC_Z,     KC_X,     KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,  \
   TD(TD_SFT_LAYR), TD(TD_NUM), KC_DEL,LT(_LOWER,KC_TAB),SFT_T(KC_BSPC),KC_SPC, LT(_RAISE,KC_ENT),TD(TD_CRTL_ALT),  KC_LEFT, KC_RGHT\
 ),

 /* Lower
  * ,---------------------------------------------------------------------.
  * |  !   | @    |#     |$     |%     |  ^   | &    |  *   |(     | )    |
  * |------+------+------+------+------+------|------+------+------+------|
  * |  Esc | play | VDN  |  VUP |      |      | left |down  |  up  | right|
  * |------+------+------+------+------+------+-------------+------+------|
  * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 | F19  | F20  | F21  | F22  |
  * |-------------+------+------+------+------+------+------+------+------'
  * |  F1  | F2   |      | F3   |  F4  |  F5  |  F6  |      |  F7  |  F8  |
  * `---------------------------------------------------------------------'
  */
 [_LOWER] = LAYOUT_ortho_4x10( \
   KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN,KC_RIGHT_PAREN, \
   KC_ESC, KC_MPLY, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, \
   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  \
   KC_F1,   KC_F2,   _______, KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_F7,   KC_F8    \
 ),

 /* Raise
  * ,---------------------------------------------------------------------.
  * |   1  |   2  |　 3   |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
  * |------+------+------+------+------+------+------+------+------+------|
  * | PUP  | home | end  |   \  |   {  |  }   |  /   |   -  |  =   |   "  |
  * |------+------+------+------+------+------+-------------+------+------|
  * | pdn  |      |      |      |   [  |   ]  |   |  |   _  |   +  |   '  |
  * |-------------+------+------+------+------+------+------+------+------'
  * |      |      |      |      |      |      |      |      |      |      |
  * `---------------------------------------------------------------------'
  */
 [_RAISE] = LAYOUT_ortho_4x10( \
   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
   KC_PGUP, KC_HOME,  KC_END, KC_BSLS,  KC_LCBR, KC_RCBR, KC_SLASH, KC_MINUS, KC_EQUAL, KC_DQT,   \
   KC_PGDOWN, _______,  _______, _______,  KC_LBRC, KC_RBRC, KC_PIPE, KC_UNDS, KC_PLUS, KC_QUOT,  \
   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______   \
 ),


 /* third
  * ,---------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+-------------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |
  * |-------------+------+------+------+------+------+------+------+------'
  * |      |      |      |      |      |      |      |      |      |      |
  * `---------------------------------------------------------------------'
  */
 [_THIRD] = LAYOUT_ortho_4x10( \
    RESET, KC_SLEP,  KC_WAKE, _______,  _______, _______, _______, _______, _______, _______, \
    KC_PWR, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,   \
   _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,  \
   _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______   \
 ),

 /* num
  * ,---------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |   7  |  8   |  9   | 
  * |------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |   4  |   5  |  6   | 
  * |------+------+------+------+------+------+-------------+------+------|
  * |      |      |      |      |      |      |      | 1    |  2   |   3  | 
  * |-------------+------+------+------+------+------+------+------+------'
  * |      |      |      |      |      |      |      |  0   |   .  |enter |
  * `---------------------------------------------------------------------'
  */
 [_NUM] = LAYOUT_ortho_4x10( \
    _______,  _______, _______, _______,  _______, _______, _______, KC_7, KC_8, KC_9, \
    _______, _______,  _______, _______,  _______, _______, _______, KC_4, KC_5, KC_6,   \
   _______, _______,  _______, _______,  _______, _______, _______, KC_1, KC_2, KC_3,  \
   _______, _______,  _______, _______,  _______, _______, _______, KC_0, KC_DOT, KC_ENT \
 ),


 /* game
  * ,---------------------------------------------------------------------.
  * |   1  |   2  |　 3   |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
  * |------+------+------+------+------+------+------+------+------+------|
  * |      |   q  |   w  |  e   | R    |   T  |   Y  |   U  |   I  |   O  | 
  * |------+------+------+------+------+------|------+------+------+------|
  * |  shft|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | 
  * |-------------+------+------+------+------+------+------+------+------'
  * | cntrl|   x  |   c  |  m   |  alt | spc  |      |      |      |      |
  * `---------------------------------------------------------------------'
  */
 [_GAME] = LAYOUT_ortho_4x10( \
   KC_1,    KC_2,     KC_3,     KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0, \
   _______,  KC_Q,     KC_W,     KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O, \
   KC_LSFT, KC_A,     KC_S,     KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L, \
   KC_LCTL, KC_X,  KC_C, KC_M,  KC_LALT, KC_SPACE, _______, _______, _______, TG(_GAME)   \
 ),



 };




// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) return DOUBLE_TAP;
    else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap sl_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void sl_finished(qk_tap_dance_state_t *state, void *user_data) {
    sl_tap_state.state = cur_dance(state);
    switch (sl_tap_state.state) {
        case SINGLE_TAP:
            tap_code(KC_MPLY);
            break;
        case SINGLE_HOLD: 
	    layer_on(_GAME);
            break;
        case DOUBLE_TAP:
	    set_oneshot_layer(_THIRD, ONESHOT_START); 
	    clear_oneshot_layer_state(ONESHOT_PRESSED);
	    break;            	     
    }
}

void sl_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (sl_tap_state.state == SINGLE_HOLD) {
        unregister_code(KC_LSFT);
    }
    sl_tap_state.state = 0;		
}




qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_CAPS),	
    [TD_CRTL_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LALT),
    [TD_SFT_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sl_finished, sl_reset),
    [TD_NUM] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, _NUM),
};





