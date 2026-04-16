#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ^    |   <  |   {  |   (  |   [  |   $  |   %  |           |   +  |   !  |   ]  |   )  |   }  |   >  |   *    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  '"  |   ,  |   .  |   P  |   Y  |  |   |           |   -  |   F  |   G  |   C  |   T  |   Z  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   O  |   E  |   I  |   U  |------|           |------|   H  |   D  |   R  |   N  |   S  |   L    |
 * |--------+------+------+------+------+------|  =   |           |  #   |------+------+------+------+------+--------|
 * | LShift |   @  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   \  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Down | Up   |                                       | Left | Right| Symb | Media| ~L1   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                                              // right hand 
  KC_CIRC,         KC_LT,       KC_LCBR,       KC_LPRN, KC_LBRC, KC_DLR,  KC_PERC,          KC_PLUS,      KC_EXLM, KC_RBRC, KC_RPRN, KC_RCBR,  KC_GT,    KC_ASTR,
  KC_TAB,          KC_DQT,      KC_COMM,       KC_DOT,  KC_P,    KC_Y,    KC_PIPE,          KC_MINS,      KC_F,    KC_G,    KC_C,    KC_T,     KC_Z,     KC_SLSH,
  CTL_T(KC_ESC),   KC_A,        KC_O,          KC_E,    KC_I,    KC_U,                                    KC_H,    KC_D,    KC_R,    KC_N,     KC_S,     KC_L,
  KC_LSFT,         KC_AT,       KC_Q,          KC_J,    KC_K,    KC_X,    KC_EQL,           KC_HASH,      KC_B,    KC_M,    KC_W,    KC_V,     KC_BSLS,  KC_RSFT,
  LT(SYMB,KC_GRV), KC_GRV,      TT(SYMB),      KC_DOWN, KC_UP,                                                     KC_LEFT, KC_RGHT, TG(SYMB), TG(MDIA), TT(SYMB),

                                                                  KC_LALT, KC_LGUI,         KC_DEL,  KC_RALT,
                                                                           KC_HOME,         KC_PGUP,
                                                   LSFT_T(KC_SPC), KC_ENT, KC_END,          KC_PGDN, KC_BSPC, LSFT_T(KC_SPC)
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                                               UG_NEXT, KC_TRNS,     UG_TOGG, RGB_M_P,
                                                        KC_TRNS,     KC_TRNS,
                                      UG_VALD, UG_VALU, KC_TRNS,     KC_TRNS, UG_HUED, UG_HUEU
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, MS_UP,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WBAK
),
};

const key_override_t quot_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DQT, KC_QUOT);
const key_override_t dot_key_override   = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCLN);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_ASTR);
const key_override_t pipe_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_AMPR);
const key_override_t circ_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_CIRC, KC_TILD);

// 1234 <-> <{([
const key_override_t one_key_override   = ko_make_basic(MOD_MASK_SHIFT, KC_LT,   KC_1);
const key_override_t two_key_override   = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_2);
const key_override_t three_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_3);
const key_override_t four_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_4);

// 5678 <-> $%+!
const key_override_t five_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DLR,  KC_5);
const key_override_t six_key_override   = ko_make_basic(MOD_MASK_SHIFT, KC_PERC, KC_6);
const key_override_t seven_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_7);
const key_override_t eight_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_8);

// \?09 <-> >})]
const key_override_t bslsh_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GT,   KC_BSLS);
const key_override_t qm_key_override    = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_QUES);
const key_override_t zero_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_0);
const key_override_t nine_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_9);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &quot_key_override,
    &dot_key_override,
    &comma_key_override,
    &slash_key_override,
    &pipe_key_override,
    &circ_key_override,

    &one_key_override,
    &two_key_override,
    &three_key_override,
    &four_key_override,

    &five_key_override,
    &six_key_override,
    &seven_key_override,
    &eight_key_override,

    &nine_key_override,
    &zero_key_override,
    &qm_key_override,
    &bslsh_key_override
};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
