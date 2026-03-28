// Copyright 2025 Jorge
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// ---------------------------------------------------------------------------
// Custom keycodes – Engram-ES-2021 (Spanish layout)
//
// Number row and special keys remapped for Español (España) OS layout.
// Dead key ☆ uses native Spanish dead keys (´ ¨ ` ^) instead of Unicode.
// ---------------------------------------------------------------------------
enum custom_keycodes {
    EG_LPAR = QK_USER,  // ( / [ / {
    EG_1,               // 1 / |
    EG_2,               // 2 / =
    EG_3,               // 3 / ~
    EG_4,               // 4 / +
    EG_5,               // 5 / <
    EG_6,               // 6 / >
    EG_7,               // 7 / ^
    EG_8,               // 8 / &
    EG_9,               // 9 / %
    EG_0,               // 0 / *
    EG_RPAR,            // ) / ] / }
    EG_FSLH,            // / / backslash
    EG_DQUO,            // " / '
    EG_DASH,            // - / _
    EG_HASH,            // # / @
    EG_IQMK,            // ¿ / ¡
    EG_QMRK,            // ? / !
    EG_ACNT,            // ☆ dead key
};

// ---------------------------------------------------------------------------
// Layers
// ---------------------------------------------------------------------------
enum layers {
    WIN_BASE,
    WIN_FN,
    MAC_BASE,
    MAC_FN,
};

// ---------------------------------------------------------------------------
// Helper: send one keycode normally, another when Shift is held.
// Clears all real modifiers before sending to avoid OS layout interference,
// then restores.  tap_code16 re-adds mods embedded in S() / ALGR() etc.
// ---------------------------------------------------------------------------
static void send_engram_key(uint16_t unshifted, uint16_t shifted, keyrecord_t *record) {
    if (!record->event.pressed) return;

    const uint8_t saved_mods = get_mods();
    const bool is_shifted = (saved_mods | get_oneshot_mods()) & MOD_MASK_SHIFT;

    clear_mods();
    clear_oneshot_mods();

    tap_code16(is_shifted ? shifted : unshifted);

    set_mods(saved_mods);
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Engram-ES-2021 – Windows Base Layer (default)  (OS = Español España)
     *
     *     Z H O X  .:  "'  M D B J W  -_ #@
     *     P I E A  ,;  ☆   T S N R K
     *     F Y Q U  ¿¡  ?!  C L V G
     *
     * ☆ = dead key for diacriticals (center-right column).
     *     ☆ + vowel              = acute (á é í ó ú)
     *     ☆ + n/c                = ñ/ç
     *     Shift + ☆ + vowel      = diaeresis (ä ë ï ö ü)
     *     AltGr + ☆ + vowel      = grave (à è ì ò ù)
     *     Shift + AltGr + ☆ + vowel = circumflex (â ê î ô û)
     *
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │Prt│Scr│Pau│
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
     * │([ │1| │2= │3~ │4+ │5< │6> │7^ │8& │9% │0* │)] │/\ │ Bksp │ │Ins│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤ ├───┼───┼───┤
     * │ Tab │ Z │ H │ O │ X │.: │"' │ M │ D │ B │ J │ W │-_ │#@ │ │Del│End│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤ └───┴───┴───┘
     * │CapsLk│ P │ I │ E │ A │,; │ ☆ │ T │ S │ N │ R │ K │Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤     ┌───┐
     * │ Shift  │ F │ Y │ Q │ U │¿¡ │?! │ C │ L │ V │ G │ Shift │     │ ↑ │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴───┼───┬────┤ ┌───┼───┼───┐
     * │Ctrl│Win │Alt │         Space           │AGr│ Fn │App│Ctrl│ │ ← │ ↓ │ → │
     * └────┴────┴────┴─────────────────────────┴───┴────┴───┴────┘ └───┴───┴───┘
     */
    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,
        EG_LPAR,  EG_1,     EG_2,     EG_3,     EG_4,     EG_5,     EG_6,     EG_7,     EG_8,     EG_9,     EG_0,     EG_RPAR,  EG_FSLH,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Z,     KC_H,     KC_O,     KC_X,     KC_DOT,   EG_DQUO,  KC_M,     KC_D,     KC_B,     KC_J,     KC_W,     EG_DASH,    EG_HASH,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_P,     KC_I,     KC_E,     KC_A,     KC_COMM,  EG_ACNT,  KC_T,     KC_S,     KC_N,     KC_R,     KC_K,                 KC_ENT,
        KC_LSFT,            KC_F,     KC_Y,     KC_Q,     KC_U,     EG_IQMK,  EG_QMRK,  KC_C,     KC_L,     KC_V,     KC_G,                 KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,MO(WIN_FN),KC_APP,     KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,            KC_BRID,  KC_BRIU,  _______,  _______,  LM_BRID,  LM_BRIU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  BL_STEP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  QK_BOOT,
        BL_TOGG,  BL_STEP,  LM_BRIU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        KC_OSSW,  _______,  LM_BRID,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    /*
     * Engram-ES-2021 – Mac Base Layer (same alpha, Mac modifiers)
     */
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,             KC_BRID,  KC_BRIU,  _______,  _______,  LM_BRID,  LM_BRIU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_NO,    KC_TRNS,  KC_PAUS,
        EG_LPAR,  EG_1,     EG_2,     EG_3,     EG_4,     EG_5,     EG_6,     EG_7,     EG_8,     EG_9,     EG_0,     EG_RPAR,  EG_FSLH,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Z,     KC_H,     KC_O,     KC_X,     KC_DOT,   EG_DQUO,  KC_M,     KC_D,     KC_B,     KC_J,     KC_W,     EG_DASH,    EG_HASH,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_P,     KC_I,     KC_E,     KC_A,     KC_COMM,  EG_ACNT,  KC_T,     KC_S,     KC_N,     KC_R,     KC_K,                 KC_ENT,
        KC_LSFT,            KC_F,     KC_Y,     KC_Q,     KC_U,     EG_IQMK,  EG_QMRK,  KC_C,     KC_L,     KC_V,     KC_G,                 KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,MO(MAC_FN),KC_TRNS,    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  BL_STEP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  QK_BOOT,
        BL_TOGG,  BL_STEP,  LM_BRIU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        KC_OSSW,  _______,  LM_BRID,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};
// clang-format on

// ---------------------------------------------------------------------------
// Dead key ☆ – Native Spanish dead key sequences
//
// Modifiers are pressed BEFORE ☆, then the vowel:
//   - Shift + ☆ then vowel         → ¨ dead + vowel = diaeresis (ä ë ï ö ü)
//   - AltGr + ☆ then vowel         → ` dead + vowel = grave  (à è ì ò ù)
//   - Shift + AltGr + ☆ then vowel → ^ dead + vowel = circumflex (â ê î ô û)
//   - ☆ then vowel                 → ´ dead + vowel = acute  (á é í ó ú)
//   - ☆ then N                     → ñ
//   - ☆ then C                     → ç
//   - ☆ then Space                 → literal diacritical mark (´ ¨ ` ^)
//
// Uppercase via CapsLock.
// ---------------------------------------------------------------------------
static bool    accent_pending = false;
static uint8_t accent_mods    = 0;     // modifier snapshot taken when ☆ is pressed

// ---------------------------------------------------------------------------
// process_record_user
// ---------------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // --- ☆ dead key: snapshot mods and set flag on press ---
    if (keycode == EG_ACNT) {
        if (record->event.pressed) {
            accent_mods    = get_mods() | get_oneshot_mods();
            accent_pending = true;
        }
        return false;
    }

    // --- If accent is pending, intercept next key on press ---
    if (accent_pending && record->event.pressed) {
        // Modifier keys must not consume the flag
        if (keycode >= KC_LCTL && keycode <= KC_RGUI) {
            return true;
        }
        accent_pending = false;

        const bool has_shift = accent_mods & MOD_MASK_SHIFT;
        const bool has_ralt  = accent_mods & MOD_BIT(KC_RALT);

        // Direct characters: ñ / ç (only without modifier selection)
        if (!has_shift && !has_ralt) {
            if (keycode == KC_N) {
                tap_code16(ES_NTIL);  // ñ  (CapsLock → Ñ)
                return false;
            }
            if (keycode == KC_C) {
                tap_code16(ES_CCED);  // ç  (CapsLock → Ç)
                return false;
            }
        }

        // Determine which native dead key based on held modifiers
        uint16_t dead_key;
        if (has_shift && has_ralt)      dead_key = ES_CIRC;  // S(KC_LBRC) → ^
        else if (has_ralt)              dead_key = ES_GRV;   // KC_LBRC    → `
        else if (has_shift)             dead_key = ES_DIAE;  // S(KC_QUOT) → ¨
        else                            dead_key = ES_ACUT;  // KC_QUOT    → ´

        // Valid targets: vowels and Space
        switch (keycode) {
            case KC_A: case KC_E: case KC_I: case KC_O: case KC_U:
            case KC_SPC: {
                const uint8_t saved = get_mods();
                const uint8_t cur   = saved | get_oneshot_mods();
                const bool vowel_upper = (cur & MOD_MASK_SHIFT) && (keycode != KC_SPC);

                // Clear all mods → dead key uses its own via tap_code16
                clear_mods();
                clear_oneshot_mods();

                tap_code16(dead_key);   // send dead key (´ ¨ ` ^)

                // Uppercase vowel if Shift held at vowel-press time
                tap_code16(vowel_upper ? S(keycode) : keycode);

                set_mods(saved);
                return false;
            }
            default:
                break;  // not accentable → pass through normally
        }
    }

    // --- AltGr + letter → currency symbols ---
    if (record->event.pressed) {
        const uint8_t mods = get_mods() | get_oneshot_mods();
        if (mods & MOD_BIT(KC_RALT)) {
            uint16_t currency = 0;
            switch (keycode) {
                case KC_E: currency = ES_EURO; break;  // AltGr+E → €
                case KC_S: currency = ES_DLR;  break;  // AltGr+S → $
                case KC_L:                              // AltGr+L → £
                    clear_mods(); clear_oneshot_mods();
                    register_code(KC_LALT);
                    tap_code(KC_KP_0);
                    tap_code(KC_KP_1);
                    tap_code(KC_KP_6);
                    tap_code(KC_KP_3);
                    unregister_code(KC_LALT);
                    set_mods(mods);
                    return false;
                default: break;
            }
            if (currency) {
                clear_mods(); clear_oneshot_mods();
                tap_code16(currency);
                set_mods(mods);
                return false;
            }
        }
    }

    // --- Engram-ES custom keys (Spanish layout keycodes) ---
    switch (keycode) {
        case EG_LPAR:  // ( / [ / {
            if (record->event.pressed) {
                const uint8_t saved = get_mods();
                const bool shifted = (saved | get_oneshot_mods()) & MOD_MASK_SHIFT;
                const bool ralt    = (saved | get_oneshot_mods()) & MOD_BIT(KC_RALT);
                clear_mods(); clear_oneshot_mods();
                if (ralt)         tap_code16(ES_LCBR);
                else if (shifted) tap_code16(ES_LBRC);
                else              tap_code16(ES_LPRN);
                set_mods(saved);
            }
            return false;
        case EG_1:    send_engram_key(ES_1,        ES_PIPE,    record); return false;  // 1 / |
        case EG_2:    send_engram_key(ES_2,        ES_EQL,     record); return false;  // 2 / =
        case EG_3:  // 3 / ~  (~ is dead key on ES → need dead+space for literal)
            if (record->event.pressed) {
                const uint8_t saved = get_mods();
                const bool shifted = (saved | get_oneshot_mods()) & MOD_MASK_SHIFT;
                clear_mods();
                clear_oneshot_mods();
                if (shifted) {
                    tap_code16(ES_TILD);  // ~ dead key
                    tap_code16(KC_SPC);   // + space = literal ~
                } else {
                    tap_code16(ES_3);
                }
                set_mods(saved);
            }
            return false;
        case EG_4:    send_engram_key(ES_4,        ES_PLUS,    record); return false;  // 4 / +
        case EG_5:    send_engram_key(ES_5,        ES_LABK,    record); return false;  // 5 / <
        case EG_6:    send_engram_key(ES_6,        ES_RABK,    record); return false;  // 6 / >
        case EG_7:  // 7 / ^  (^ is dead key on ES → need dead+space for literal)
            if (record->event.pressed) {
                const uint8_t saved = get_mods();
                const bool shifted = (saved | get_oneshot_mods()) & MOD_MASK_SHIFT;
                clear_mods();
                clear_oneshot_mods();
                if (shifted) {
                    tap_code16(ES_CIRC);  // ^ dead key
                    tap_code16(KC_SPC);   // + space = literal ^
                } else {
                    tap_code16(ES_7);
                }
                set_mods(saved);
            }
            return false;
        case EG_8:    send_engram_key(ES_8,        ES_AMPR,    record); return false;  // 8 / &
        case EG_9:    send_engram_key(ES_9,        ES_PERC,    record); return false;  // 9 / %
        case EG_0:    send_engram_key(ES_0,        ES_ASTR,    record); return false;  // 0 / *
        case EG_RPAR:  // ) / ] / }
            if (record->event.pressed) {
                const uint8_t saved = get_mods();
                const bool shifted = (saved | get_oneshot_mods()) & MOD_MASK_SHIFT;
                const bool ralt    = (saved | get_oneshot_mods()) & MOD_BIT(KC_RALT);
                clear_mods(); clear_oneshot_mods();
                if (ralt)         tap_code16(ES_RCBR);
                else if (shifted) tap_code16(ES_RBRC);
                else              tap_code16(ES_RPRN);
                set_mods(saved);
            }
            return false;
        case EG_FSLH: send_engram_key(ES_SLSH,     ES_BSLS,    record); return false;  // / / backslash
        case EG_DQUO: send_engram_key(ES_DQUO,     ES_QUOT,    record); return false;  // " / '
        case EG_DASH: send_engram_key(ES_MINS,     ES_UNDS,    record); return false;  // - / _
        case EG_HASH: send_engram_key(ES_AT,       ES_HASH,    record); return false;  // @ / #
        case EG_IQMK: send_engram_key(ES_IQUE,     ES_IEXL,    record); return false;  // ¿ / ¡
        case EG_QMRK: send_engram_key(ES_QUES,     ES_EXLM,    record); return false;  // ? / !
        default:
            return true;
    }
}
