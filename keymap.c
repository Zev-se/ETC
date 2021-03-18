/* Copyright 2015-2017 Jack Humbert
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
 *
 * qmk compile -kb planck/rev6 -km ZevSwe
 * qmk flash -kb planck/rev6 -km ZevSwe
 *
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_swedish.h"
#include "keymap_nordic.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _LAYER4
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  CARROT,
  TILDE,
  BACKTICK,
  LSQUAREBRACKET,
  RSQUAREBRACKET
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
* Base layer
* ,----------------------------------------------------------------------------------------------------.
* | Tab  |   Q  |   W  |    E    |    R     |   T  |   Y  |     U    |   I   |    O  |     P    |  Å   |
* |------+------+------+---------+----------+------+------+----------+-------+-------+----------+------|
* | Esc  |   A  |   S  |    D    |    F     |   G  |   H  |     J    |   K   |    L  |     Ä    |  Ö   |
* |------+------+------+---------+----------+------+------+----------+-------+-------+----------+------|
* | Shift|   Z  |   X  |    C    |    V     |   B  |   N  |     M    |   ,   |    .  |     -    |Enter |
* |------+------+------+---------+----------+------+------+----------+-------+-------+----------+------|
* | Ctrl |  GUI | Alt  | L4/     |Lower/INS |    Space    |  Raise/? |   /   |       | BACKTICK | Bksp |
* `----------------------------------------------------------------------------------------------------'
*/
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_AA  ,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SE_OSLH, SE_AE  ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_MINS, KC_ENT ,
    KC_LCTL, KC_RCMD, KC_LALT, MO(_LAYER4), LT(_LOWER, KC_INS),   KC_SPC,  KC_SPC,LT(_RAISE, SE_QUES) , KC_KP_SLASH, _______,BACKTICK , KC_BSPC
),


/* Lower
* ,-------------------------------------------------------------------------------------------------.
* | Tab  |      |  Del  |   UP    |          | Play |  <<  |    >>    |  P Up |       | PRSC |      |
* |------+------+-------+---------+----------+------+------+----------+-------+-------+------+------|
* | Esc  |      |  Left |  Down   |  Right   |      |      |   Home   | P Dnw |  End  |      |      |
* |------+------+-------+---------+----------+------+------+----------+-------+-------+------+------|
* | Shift|SCR UP|SCR DWN|         |          | Mute | Vol- |   Vol+   |       |       |      |      |
* |------+------+-------+---------+----------+------+------+----------+-------+-------+------+------|
* | Ctrl |  GUI | Alt   |         |Lower/PRSC|    Bksp     | Raise/?  |       |       |      |      |
* `-------------------------------------------------------------------------------------------------'
*/
[_LOWER] = LAYOUT_planck_grid(
    KC_TAB, _______, KC_DEL,   KC_UP, _______,  KC_MPLY, KC_MPRV, KC_MNXT,    KC_PGUP,  _______, KC_PSCR, _______,
    KC_ESC,  _______,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   _______,   MU_TOG,   KC_HOME,    KC_PGDN,    KC_END, _______, _______,
    KC_LSFT, KC_WH_U,   KC_WH_D,   _______,   _______,  KC_MUTE,  KC_VOLD,  KC_VOLU, KC_VOLU, _______, _______,  _______,
    KC_LCTL, KC_RCMD, KC_LALT, _______, LT(_LOWER, KC_INS), KC_BSPC, KC_BSPC, _______,    _______,    _______, _______, _______
),

/* Raise
* ,------------------------------------------------------------------------------------------------.
* | Tab  |  {   |  }   |    $    |    #     |  <   |  >   |          |   %   |       |   |  |      |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Esc  |  @   |  *   |    '    |    "     |   (  |  )   |     !    |   ~   |   ^   |   ?  |      |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Shift|  [   |  ]   |         |    &     |      |      |          |       |       |      |      |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Ctrl |  GUI | Alt  | L4/Star |Lower/INS |     Bksp    |  Raise   |   \   |    ´  |      |      |
* `------------------------------------------------------------------------------------------------'
*/
[_RAISE] = LAYOUT_planck_grid(
    KC_TAB,  NO_LCBR,    NO_RCBR, SE_DLR, SE_HASH, SE_LABK, SE_RABK, _______, SE_PERC, _______, SE_PIPE,_______,
    KC_ESC,  SE_AT,  SE_ASTR,   KC_BSLS,   SE_DQUO,   SE_LPRN,  SE_RPRN,   SE_EXLM, NO_TILD, CARROT, _______, _______,
    KC_LSFT, LSQUAREBRACKET, RSQUAREBRACKET,   _______,   SE_AMPR,  _______,  _______,  _______, _______, _______, _______, _______,
    KC_LCTL, KC_RCMD, KC_LALT, _______, _______, KC_ENT, KC_ENT, MO(_RAISE), SE_BSLS, SE_ACUT, _______, _______
),
/* Layer 4
* ,------------------------------------------------------------------------------------------------.
* | Tab  | F13  | F14  |   F15   |   F16    |      |   *  |    7     |   8   |   9   |  -   |      |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Esc  | F17  | F18  |   F19   |   F20    |      |   /  |    4     |   5   |   6   |  +   |      |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Shift| F21  | F22  |   F23   |   F24    |      |   ^  |    1     |   2   |   3   |  =   | Enter|
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Ctrl |  GUI | Alt  | L4/Star |          |      .      |    0     |       |       |      |      |
* `------------------------------------------------------------------------------------------------'
*/

  [_LAYER4] = LAYOUT_planck_grid(
    KC_TAB,  KC_F13, KC_F14, KC_F15, KC_F16,    _______,    KC_KP_ASTERISK,    KC_P7, KC_P8,    KC_P9,    KC_KP_MINUS,    _______,
    KC_ESC,  KC_F17, KC_F18, KC_F19, KC_F20,    _______,    KC_KP_SLASH,    KC_P4,    KC_P5,    KC_P6,    KC_KP_PLUS,    _______,
    KC_LSFT, KC_F21, KC_F22, KC_F23, KC_F24,    _______,    CARROT,    KC_P1,        KC_P2,    KC_P3,    KC_PEQL,    _______,
    KC_LCTL, KC_RCMD, KC_LALT, MO(_LAYER4), _______,   KC_DOT,  KC_DOT,  KC_P0,   _______, _______, _______,   _______
),

/* Adjust (Lower + Raise)
* ,------------------------------------------------------------------------------------------------.
* | Tab  |  F1  |  F2  |   F3    |    F4    |      |      |          |       |       |      |RESET |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Esc  |  F5  |  F6  |   F7    |    F8    |      |      |          |       |       |      | Num  |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Shift|  F9  | F10  |   F11   |    F12   |Scr - | Scr +|  Tog RGB |       |       |      |      |
* |------+------+------+---------+----------+------+------+----------+-------+-------+------+------|
* | Ctrl |  GUI | Alt  |         |   Lower  |    Sleep    |  Raise   |       |       |      |      |
* `------------------------------------------------------------------------------------------------'
*/

[_ADJUST] = LAYOUT_planck_grid(
    KC_TAB, KC_F1,   KC_F2,   KC_F3, KC_F4, _______, _______, _______, _______,  _______, _______, RESET,
    KC_ESC, KC_F5, KC_F6,  KC_F7,   KC_F8,  BL_DEC, BL_INC, _______,  _______,  _______,  _______,  KC_LNUM,
    KC_LSFT, KC_F9,  KC_F10,  KC_F11,   KC_F12,  KC_BRID,   KC_BRIU,  RGB_TOG, _______, _______, _______, _______,
    KC_LCTL, KC_RCMD, KC_LALT, LT(_LAYER4, KC_PIPE), _______, KC_SLEP, KC_SLEP, MO(_RAISE), _______, _______,  _______, _______
),


/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
)

};



#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case CARROT:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("] "));
      }
      return false;
      break;
    case TILDE:
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("] "));
      }
      return false;
      break;
    case BACKTICK:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("= "));
      }
      return false;
      break;
    case LSQUAREBRACKET:
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("8"));
      }
      return false;
      break;
    case RSQUAREBRACKET:
      if (record->event.pressed) {
        SEND_STRING(SS_ALGR("9"));
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
