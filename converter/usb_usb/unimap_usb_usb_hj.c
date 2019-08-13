/*
Copyright 2016 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "unimap_trans.h"
/*
 * on**: { `ON_PRESS` | `ON_RELEASE` | `ON_BOTH` }
 * 
 * mods**: { ` MOD_LCTL`, ` MOD_LSFT`, ` MOD_LALT`, ` MOD_LGUI`,
    ` MOD_RCTL`, ` MOD_RSFT`, ` MOD_RALT`, ` MOD_RGUI` }ad
*/

// 时间设置请在./config.h中设置:
// #define TAPPING_TERM    270


#define AC_FN0 ACTION_LAYER_MOMENTARY(1)

/*
 激活指定层, 关闭其它层(不包括默认层)
*/
#define AC_LAY0 ACTION_LAYER_SET(0, ON_RELEASE)
#define AC_LAY1 ACTION_LAYER_SET(1, ON_RELEASE)
#define AC_LAY2 ACTION_LAYER_SET(2, ON_RELEASE)
#define AC_LAY3 ACTION_LAYER_SET(3, ON_RELEASE)
#define AC_LAY4 ACTION_LAYER_SET(4, ON_RELEASE)
#define AC_LAY5 ACTION_LAYER_SET(5, ON_RELEASE)
#define AC_LAY6 ACTION_LAYER_SET(6, ON_RELEASE)
#define AC_LAY7 ACTION_LAYER_SET(7, ON_RELEASE)

/*
 按住时临时激活指定层, 松开失效
*/
#define AC_L1M ACTION_LAYER_MOMENTARY(1)
#define AC_L2M ACTION_LAYER_MOMENTARY(2)
#define AC_L3M ACTION_LAYER_MOMENTARY(3)
#define AC_L4M ACTION_LAYER_MOMENTARY(4)
#define AC_L5M ACTION_LAYER_MOMENTARY(5)
#define AC_L6M ACTION_LAYER_MOMENTARY(6)
#define AC_L7M ACTION_LAYER_MOMENTARY(7)

/*
 按住时临时激活指定层, 保留点击功能
*/
#define AC_L1_A ACTION_LAYER_TAP_KEY(1, KC_A)
#define AC_L2_S ACTION_LAYER_TAP_KEY(2, KC_S)
#define AC_L3_D ACTION_LAYER_TAP_KEY(3, KC_D)
#define AC_L4_F ACTION_LAYER_TAP_KEY(4, KC_F)
#define AC_L7_ ACTION_LAYER_TAP_KEY(7, KC_BSLS)

/*
 组合键
*/
#define AC_ALTL ACTION_MODS_KEY(MOD_LALT, KC_LEFT)
#define AC_ALTR ACTION_MODS_KEY(MOD_LALT, KC_RIGHT)

#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
// 第0层, 默认层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
/*2*/ ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,         VOLD,VOLU,MUTE,
/*3*/ GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
/*4*/ TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     L7_,      DEL, END, PGDN,    P7,  P8,  P9,  PPLS,
/*5*/ CAPS,L1_A,L2_S,L3_D,L4_F,G,   H,   J,   K,   L,   SCLN,QUOT,     NUHS,ENT,                         P4,  P5,  P6,  PCMM,
/*6*/ LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PENT,
/*7*/ LALT,LGUI,LCTL,MHEN,          SPC,           HENK,KANA,RALT,RGUI,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PEQL
    ),

// 第1层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
/*2*/ TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
/*3*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
//                        R    T              I    O    P
/*4*/ TRNS,TRNS,TRNS,TRNS,ALTL,ALTR,TRNS,TRNS,UP,  PGUP,PGDN,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
//                   D    F         H    J    K    L    ;    '
/*5*/ TRNS,TRNS,TRNS,LSFT,LALT,TRNS,ESC, LEFT,DOWN,RGHT,HOME,END,      TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
//                                       N    M         .    /
/*6*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BSPC,DEL, TRNS,WH_U,WH_D,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
//                        /*        SpaceBar     */          
/*7*/ TRNS,TRNS,LCTL,TRNS,          ENT,           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

// 第2层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
/*2*/ TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
/*3*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*4*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,7,   8,   9,   0,   TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*5*/ TRNS,TRNS,TRNS,LSFT,LALT,TRNS,ESC, 4,   5,   6,   MINS,EQL,      TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
/*6*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BSPC,1,   2,   3,   TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
/*7*/ TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

// 第3层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
/*2*/ TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
/*3*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*4*/ TRNS,TRNS,TRNS,TRNS,ALTL,ALTR,TRNS,TRNS,MS_U,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*5*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,ESC, MS_L,MS_D,MS_R,BTN1,BTN2,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
/*6*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
/*7*/ TRNS,TRNS,TRNS,TRNS,          ENT,           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

// 第4层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
/*2*/ TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
/*3*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*4*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,F7,  F8,  F9,  F10, TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*5*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,ESC, F4,  F5,  F6,  F11, TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
/*6*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,F1,  F2,  F3,  F12,      TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
/*7*/ TRNS,TRNS,TRNS,TRNS,          ENT,           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

// 第5层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
/*2*/ TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
/*3*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*4*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*5*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
/*6*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
/*7*/ TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

// 第6层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
/*2*/ TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
/*3*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*4*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*5*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
/*6*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
/*7*/ TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

// 第7层
    UNIMAP(
//    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15        16   17   18       19   20   21   22
/*1*/           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
/*2*/ TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
/*3*/ LAY0,LAY1,LAY2,LAY3,LAY4,LAY5,LAY6,TRNS,TRNS,TRNS,LAY0,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*4*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
/*5*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
/*6*/ TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
/*7*/ TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

    /*
    UNIMAP(
              F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,         VOLD,VOLU,MUTE,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     NUHS,ENT,                         P4,  P5,  P6,  PCMM,
    LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PENT,
    LCTL,LGUI,LALT,MHEN,          SPC,           HENK,KANA,RALT,RGUI,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PEQL
    ),
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,    TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),
    */
};
