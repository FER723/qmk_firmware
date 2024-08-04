// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum combos {
  FS_V,
  FD_G,
  RE_Y,
  ET_W,
  DS_C,
  NM_H,
  NL_B,
  UI_K,
  IO_J,
  ML_Z,
  FE_BS,
  FDS_ENTER,
  NI_DEL,
  LX_ESC,
  FQ_DEL
};

const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM re_combo[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM et_combo[] = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM nl_combo[] = {KC_N, KC_L, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM ml_combo[] = {KC_M, KC_L, COMBO_END};
const uint16_t PROGMEM fe_combo[] = {KC_F, KC_E, COMBO_END};
const uint16_t PROGMEM fds_combo[] = {KC_F, KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM ni_combo[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM lx_combo[] = {KC_L, KC_X, COMBO_END};
const uint16_t PROGMEM fq_combo[] = {KC_F, KC_Q, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [FS_V] = COMBO(fs_combo, KC_V),
  [FD_G] = COMBO(fd_combo, KC_G),
  [RE_Y] = COMBO(re_combo, KC_Y),
  [ET_W] = COMBO(et_combo, KC_W),
  [DS_C] = COMBO(ds_combo, KC_C),
  [NM_H] = COMBO(nm_combo, KC_H),
  [NL_B] = COMBO(nl_combo, KC_B),
  [UI_K] = COMBO(ui_combo, KC_K),
  [IO_J] = COMBO(io_combo, KC_J),
  [ML_Z] = COMBO(ml_combo, KC_Z),
  [FE_BS] = COMBO(fe_combo, KC_BSPC),
  [FDS_ENTER] = COMBO(fds_combo, KC_ENT),
  [NI_DEL] = COMBO(ni_combo, KC_DEL),
  [LX_ESC] = COMBO(lx_combo, KC_ESC),
  [FQ_DEL] = COMBO(fq_combo, KC_DEL)
};

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_PGDN)
#define KC_RLSH RSFT_T(KC_PGUP)
#define KC_SPM2 LT(3, KC_SPC)
#define KC_BSM1 LT(1, KC_ENT)
#define KC_GUTA GUI_T(KC_BSPC)
#define KC_CLGV CTL_T(KC_TAB)
#define KC_BSM3 LT(2, KC_X)


 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,    KC_T,    KC_E,    KC_R,    KC_SLSH,            S(KC_MINS),  KC_U,     KC_I,    KC_O,   KC_P,
    KC_CTLA, KC_S,    KC_D,    KC_F,    KC_COMM,            KC_DOT,      KC_N,     KC_M,    KC_L,   KC_BSM3,
    KC_LSHZ, KC_HOME, KC_LEFT, KC_DOWN, KC_SCLN,            KC_UP,       KC_RGHT,  KC_END,  KC_DOT, KC_RLSH,
                                    KC_CLGV, KC_BSM1, KC_SPM2, KC_GUTA
  ),

  [1] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
    KC_LSFT, KC_F11,  KC_F12,  KC_TAB,  KC_LALT,         KC_UNDS, KC_LALT, KC_LSFT, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [2] = LAYOUT(
    KC_TRNS, S(KC_BSLS),  KC_LBRC,     KC_RBRC,    KC_GRV,          S(KC_GRV), S(KC_LBRC), S(KC_RBRC),  KC_BSLS,  QK_BOOT,
    S(KC_1), S(KC_2),     S(KC_3),     S(KC_4),    S(KC_5),         S(KC_7),   S(KC_9),    S(KC_0),     S(KC_8),  KC_TRNS,
    KC_TRNS, KC_TRNS,     S(KC_QUOT),  S(KC_COMM), KC_MINS,         S(KC_EQL), S(KC_DOT),  KC_QUOT,     S(KC_6),  KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  
  ),

  [3] = LAYOUT(
    KC_TRNS,  KC_WH_D, KC_MS_U, KC_WH_U, KC_TRNS,         KC_TRNS, KC_BTN3, KC_BTN5, KC_BTN4, NK_TOGG,
    KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,         KC_TRNS, KC_BTN1, KC_BTN2, KC_ACL2, KC_TRNS,
    KC_TRNS,  KC_WH_L, KC_TRNS, KC_WH_R, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_ACL0, KC_TRNS, KC_TRNS
  ),
};
