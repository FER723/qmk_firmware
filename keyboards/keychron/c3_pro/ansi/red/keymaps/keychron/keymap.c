/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include "keychron_common.h"

enum layers {
    WIN_BASE,
    WIN_FN,
    MAC_BASE,
    MAC_FN,
};

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
  NI_BS,
  NML_ENTER,
  FT_ESC,
  NO_ESC,
  FA_TAB,
  NX_TAB,
  RET_DEL,
  UIO_DEL,
  FN_1,
  DM_2,
  SL_3,
  AX_4,
  RU_5,
  EI_6,
  TO_7,
  QP_8,
  EN_9,
  IF_0
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
const uint16_t PROGMEM nml_combo[] = {KC_N, KC_M, KC_L, COMBO_END};
const uint16_t PROGMEM ret_combo[] = {KC_R, KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};

const uint16_t PROGMEM ft_combo[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM no_combo[] = {KC_N, KC_O, COMBO_END};
const uint16_t PROGMEM fa_combo[] = {KC_F, KC_A, COMBO_END};
const uint16_t PROGMEM nx_combo[] = {KC_N, KC_X, COMBO_END};

const uint16_t PROGMEM fn_combo[] = {KC_F, KC_N, COMBO_END};
const uint16_t PROGMEM dm_combo[] = {KC_D, KC_M, COMBO_END};
const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM ax_combo[] = {KC_A, KC_X, COMBO_END};
const uint16_t PROGMEM ru_combo[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM to_combo[] = {KC_T, KC_O, COMBO_END};
const uint16_t PROGMEM qp_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM en_combo[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM if_combo[] = {KC_I, KC_F, COMBO_END};



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
  [NI_BS] = COMBO(ni_combo, KC_BSPC),
  [NML_ENTER] = COMBO(nml_combo, KC_ENT),
  [RET_DEL] = COMBO(ret_combo, KC_DEL),
  [UIO_DEL] = COMBO(uio_combo, KC_DEL),
  [FT_ESC] = COMBO(ft_combo, KC_ESC),
  [NO_ESC] = COMBO(no_combo, KC_ESC),
  [FA_TAB] = COMBO(fa_combo, KC_TAB),
  [NX_TAB] = COMBO(nx_combo, KC_TAB),

  [FN_1] = COMBO(fn_combo, KC_1),
  [DM_2] = COMBO(dm_combo, KC_2),
  [SL_3] = COMBO(sl_combo, KC_3),
  [AX_4] = COMBO(ax_combo, KC_4),
  [RU_5] = COMBO(ru_combo, KC_5),
  [EI_6] = COMBO(ei_combo, KC_6),
  [TO_7] = COMBO(to_combo, KC_7),
  [QP_8] = COMBO(qp_combo, KC_8),
  [EN_9] = COMBO(en_combo, KC_9),
  [IF_0] = COMBO(if_combo, KC_0)

};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_QUOT,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_T,     KC_E,     KC_R,     KC_SLSH,     S(KC_MINS),     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_COMM,     KC_DOT,     KC_N,     KC_M,     KC_L,     KC_X,  LT(MAC_BASE, KC_QUOT),              KC_ENT,
        KC_LSFT,            KC_PGDN,     KC_HOME,     KC_LEFT,     KC_DOWN,     KC_SCLN,     KC_UP,     KC_RGHT,     KC_END,  KC_PGUP,   LT(MAC_FN, KC_F12),              KC_RSFT,            KC_UP,
        KC_CAPS,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN),KC_APP,    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  KC_CRTA,  BL_STEP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  NK_TOGG,
        BL_TOGG,  BL_STEP,  KC_WH_D,    KC_MS_U,  KC_WH_U,  _______,  _______,  _______,  KC_BTN3,  KC_BTN5,  KC_BTN4,  _______,  _______,    _______,  _______,  _______,  QK_BOOT,
        _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  KC_BTN1,  KC_BTN2,  KC_ACL1,  KC_ACL2,  _______,              _______,
        _______,            _______,  KC_WH_L,  KC_WH_R,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  GU_TOGG,  _______,                                KC_ACL0,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

	 [MAC_BASE] = LAYOUT_tkl_ansi(
        _______,             _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,   _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,  _______,     _______,  _______,   _______,  _______,
        _______,   S(KC_5),     S(KC_6),     S(KC_7),     S(KC_8),     _______,     _______,     S(KC_QUOT),     S(KC_EQL),     KC_MINS,     _______,     _______,  _______,    _______,  _______,   KC_OSSW,   _______,
        _______,  S(KC_1),     S(KC_2),     S(KC_3),     S(KC_4),     _______,     _______,     S(KC_9),     S(KC_0),     S(KC_BSLS),     _______,  _______,              _______,
        _______,            _______,     KC_QUOT,     S(KC_LBRC),     KC_LBRC,     KC_EQL,     KC_RBRC,     S(KC_RBRC),     KC_BSLS,  _______,   _______,              _______,            _______,
        _______,  _______, _______,                               _______,                                 _______, _______,_______,   _______,  _______,  _______,  _______),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  KC_SIRI,  BL_STEP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  KC_F3,    KC_F5,  KC_F8,  _______,  _______,  _______,  KC_F6,  KC_F7,  _______,  _______,  _______,    _______,  _______,  KC_OSSW,  QK_BOOT,
        _______,  KC_F12,  KC_F11,  KC_F10,  KC_F9,  _______,  _______,  _______,  KC_F1,  KC_F2,  KC_F4,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

};

// clang-format on
void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}


// [MAC_BASE] = LAYOUT_tkl_ansi(
//         KC_ESC,             KC_BRID,  KC_BRIU,  KC_MICT,  KC_LAPA,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_SNAP,  KC_TRNS,  KC_PAUS,
//         KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
//         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
//         KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
//         KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
//         KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, MO(MAC_FN),KC_TRNS,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),