#include QMK_KEYBOARD_H

enum layers {
  _ART_BASE,
  _ART_NUM,
  _ART_CUS,
  _ART_PUNC,
  _ART_MOU,
  _ART_NAV,
  _ART_SYM,
};

#include "aliases.c"
#include "combos.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ART_BASE] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_1, KC_2, KC_3, KC_4
),

[_ART_NUM] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_1, KC_2, KC_3, KC_4
),


[_ART_PUNC] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_1, KC_2, KC_3, KC_4
),

[_ART_CUS] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_1, KC_2, KC_3, KC_4
),

[_ART_SYM] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_1, KC_2, KC_3, KC_4
),

[_ART_MOU] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_1, KC_2, KC_3, KC_4
),

[_ART_NAV] = LAYOUT_split_3x5_2(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_1, KC_2, KC_3, KC_4
),
};