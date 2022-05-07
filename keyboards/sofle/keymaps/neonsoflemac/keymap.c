// kb: sofle
// km: neonsoflemac

#include QMK_KEYBOARD_H

enum sofle_layers { // las capas en este keymap
    _MACOS,
    _WIN10,
    _SYMB,
    _NUMP,
    _TUNE
};

enum custom_keycodes { // dando nombre de keycodes por definir
    SYMB = SAFE_RANGE,
    NUMP,
    HUI,
    HUD,
    OS,
    MAC_A,
    MAC_E,
    MAC_I,
    MAC_O,
    MAC_U,
    MAC_N,
};

enum td_keycodes {
    ESCAPE
};

// definiendo el keycode ESCAPE
// un pulso: Escape
// dos pulsos: Delete
qk_tap_dance_action_t tap_dance_actions[] = {
    [ESCAPE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_DEL)
};

// las keycodes en cada capa
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 

/*
      .--------------------------------------------------.                          .-------------------------------------------------.
      | ESC/DEL  | 1 ! ¡ |  2  @ |  3  # |  4  $ |  5  % |                          |  6  ^  |  7  & |  8  * |  9 (  |  0 )  |  +  =   |
      |----------+-------+-------+-------+-------+-------.                          |--------+-------+-------+-------+-------+---------|
      |   TAB    |   Q   |   W   |   E   |   R   |   T   |          _MACOS          |   Y    |   U   |   I   |   O   |   P   | BACKSPC |
      |----------+-------+-------+-------+-------+-------|                          |--------+-------+-------+-------+-------+---------|
      |SHIFT/CAPS|   A   |   S   |   D   |   F   |   G   |                          |   H    |   J   |   K   |   L   | / ? ¿ | Shift   |
      |----------+-------+-------+-------+-------+----------------.        .--------|--------+-------+-------+-------+-------+---------|
      |CTRL ' "  |   Z   |   X   |   C   |   V   |   B   |        |        |        |   N    |   M   |  , <  |  . >  |  ; :  |  -  _   |
      '------------------+-------+-------+-------+-------+--------|        |--------+--------+-------+-------+-------+-------+---------'
                         |  [ {  |PSCREEN|  CMD  | SYMB  |  SPACE |        | SPACE  |NUMP/ENT| ALTGR |  ALT  |  ] }  |
                         '----------------------------------------'        '-----------------------------------------'
*/

    [_MACOS] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.
  TD(ESCAPE),   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                              KC_6,   KC_7,    KC_8,    KC_9,    KC_0,  KC_PPLS,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|                         
      KC_TAB,   KC_Q,    KC_W,   MAC_E,    KC_R,   KC_T,         /* _MACOS */         KC_Y,   MAC_U,   MAC_I,   MAC_O,    KC_P,  KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|          
LSFT_T(KC_CAPS), MAC_A,   KC_S,    KC_D,    KC_F,   KC_G,                              KC_H,  KC_J,    KC_K,   KC_L,   KC_SLSH, KC_RSFT,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|          
LCTL_T(KC_QUOTE), KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,    XXXXXXX,         XXXXXXX, MAC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SCLN, KC_MINUS,
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'
                        KC_LBRC, KC_PSCREEN, KC_LCMD, SYMB,  KC_SPC,         KC_SPC, MT(NUMP,KC_ENT), KC_ALGR, KC_LALT, KC_RBRC
//                    '--------'--------'--------'--------'--------'      '--------'--------'--------'--------'--------'                 
    ),    

/*
      .--------------------------------------------------.                          .-------------------------------------------------.
      | ESC/DEL  | 1 ! ¡ |  2  @ |  3  # |  4  $ |  5  % |                          |  6  ^  |  7  & |  8  * |  9 (  |  0 )  |  +  =   |
      |----------+-------+-------+-------+-------+-------.                          |--------+-------+-------+-------+-------+---------|
      |   TAB    |   Q   |   W   |   E   |   R   |   T   |           _WIN10         |   Y    |   U   |   I   |   O   |   P   | BACKSPC |
      |----------+-------+-------+-------+-------+-------|                          |--------+-------+-------+-------+-------+---------|
      |Shift/CAPS|   A   |   S   |   D   |   F   |   G   |                          |   H    |   J   |   K   |   L   | / ? ¿ | Shift   |
      |----------+-------+-------+-------+-------+----------------.        .--------|--------+-------+-------+-------+-------+---------|
      | CTRL ' " |   Z   |   X   |   C   |   V   |   B   |        |        |        |   N    |   M   |  , <  |  . >  |  ; :  |  -  _   |
      '------------------+-------+-------+-------+-------+--------|        |--------+--------+-------+-------+-------+-------+---------'
                         |  [ {  |PSCREEN|  CMD  | SYMB  |  SPACE |        | SPACE  |NUMP/ENT| ALTGR |  ALT  |  ] }  |
                         '----------------------------------------'        '-----------------------------------------'
*/

    [_WIN10] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.
    TD(ESCAPE), KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                              KC_6,   KC_7,    KC_8,    KC_9,    KC_0,  KC_PPLS,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|                         
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,          /* _WIN10 */        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|          
LSFT_T(KC_CAPS), KC_A,   KC_S,    KC_D,    KC_F,   KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,  KC_SLSH, KC_RSFT,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|          
LCTL_T(KC_QUOTE), KC_Z,  KC_X,    KC_C,    KC_V,   KC_B,   XXXXXXX,         XXXXXXX,  KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SCLN, KC_MINUS,
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'
                       KC_LBRC, KC_PSCREEN, KC_LCMD, SYMB,  KC_SPC,        KC_SPC, MT(NUMP,KC_ENT), KC_ALGR, KC_LALT, KC_RBRC
//                    '--------'--------'--------'--------'--------'      '--------'--------'--------'--------'--------'                 
    ),
    
/*
      .--------------------------------------------------.                          .-------------------------------------------------.
      | ESC/DEL  |   (   |   )   |   <   |   >   |       |                          |       |       |       |       |       |         |
      |----------+-------+-------+-------+-------+-------.                          |-------+-------+-------+-------+-------+---------|
      |    -     |   +   |   1   |   2   |   3   |   ,   |           _NUMP          |       | HOME  |   UP  |  END  |       | BACKSPC |
      |----------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+---------|
      |    /     |   *   |   4   |   5   |   6   |   .   |                          |       |  LEFT |  DOWN | RIGHT |       |         |
      |----------+-------+-------+-------+-------+-----------------.        .-------|-------+-------+-------+-------+-------+---------|
      |    ^     |   =   |   7   |   8   |   9   |   0    |        |        |       |       |   [   |   ]   |   {   |   }   |         |
      '------------------+-------+-------+-------+--------+--------|        |-------+-------+-------+-------+-------+-------+---------'
                         |       |PSCREEN|  CMD  |SYMB/ENT|  SPACE |        | SPACE |       |  ALGR |   ALT |       |
                         '-----------------------------------------'        '---------------------------------------'
*/

    [_NUMP] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.    
  TD(ESCAPE), LSFT(KC_9), LSFT(KC_0), KC_LABK, KC_RABK, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|          
      KC_MINUS, KC_PPLS, KC_1,   KC_2,    KC_3,   KC_COMM,        /* _NUMP */         XXXXXXX, KC_HOME,  KC_UP,  KC_END,  XXXXXXX, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|                          
     KC_SLASH, KC_ASTR,  KC_4,   KC_5,    KC_6,   KC_DOT,                            XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|                          
     KC_CIRC, KC_EQUAL,  KC_7,   KC_8,    KC_9,    KC_0,   XXXXXXX,        XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'  
                XXXXXXX, KC_PSCREEN, KC_LCMD, MT(SYMB,KC_ENT), KC_SPC,      KC_SPC,  _______, KC_ALGR, KC_LALT, XXXXXXX
//                    '--------------------------------------------'      '--------------------------------------------'                      
    ),

/*
      .--------------------------------------------------.                          .--------------------------------------------------.
      | ESC/DEL  |       |       |       |       |       |                          |        |       |       |       |       |         |
      |----------+-------+-------+-------+-------+-------.                          |--------+-------+-------+-------+-------+---------|
      |          |   #   |   $   |   %   |   &   |       |          _SYMB           |        | HOME  |   UP  |  END  |       | BACKSPC |
      |----------+-------+-------+-------+-------+-------|                          |--------+-------+-------+-------+-------+---------|
      |     |    |   ´   |   `   |   ¬   |   ~   |   \   |                          |        |  LEFT |  DOWN | RIGHT |       |         |
      |----------+-------+-------+-------+-------+----------------.        .--------|--------+-------+-------+-------+-------+---------|
      |          |       |       |       |       |       |        |        |        |        |       |       |       |       |         |
      '------------------+-------+-------+-------+-------+--------|        |--------+--------+-------+-------+-------+-------+---------'
                         |       |PSCREEN|  CMD  |       |  SPACE |        | SPACE  |NUMP/ENT| ALTGR |  ALT  |       |
                         '----------------------------------------'        '-----------------------------------------'
*/

    [_SYMB] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.        
    TD(ESCAPE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|   
     XXXXXXX, KC_HASH, KC_DOLLAR, KC_PERC, KC_AMPR, XXXXXXX,        /* _SYMB */       XXXXXXX, KC_HOME,  KC_UP,  KC_END,  XXXXXXX, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|       
LSFT(KC_BSLS), ALGR(KC_QUOTE), KC_GRV, ALGR(KC_BSLS), KC_TILDE, KC_BSLS,              XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|       
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'    
                    XXXXXXX, KC_PSCREEN, KC_LCMD,  _______,   KC_SPC,       KC_SPC, MT(NUMP,KC_ENT), KC_ALGR, KC_LALT, XXXXXXX
//                    '--------------------------------------------'      '--------------------------------------------'                        
    ),

/*
      .--------------------------------------------------.                          .-------------------------------------------------.
      |          |       |       |       |       |       |                          |       |       |       |       |       |         |
      |----------+-------+-------+-------+-------+-------.                          |-------+-------+-------+-------+-------+---------|
      |   TOG    |  HUI  | PLAIN |BREATH | MOOD  | SWIRL |          _TUNE           |       |       |       |       |       |         |
      |----------+-------+-------+-------+-------+-------|                          |-------+-------+-------+-------+-------+---------|
      |          |  HUD  |       |       |       |       |                          |       |       |       |       |       |         |
      |----------+-------+-------+-------+-------+----------------.        .--------|-------+-------+-------+-------+-------+---------|
      |    F1    |   F2  |  F3   |   F4  |   F5 |   F6   |        |        |        |  F7   |  F8   |  F9  |  F10   |  F11  |  F12    |
      '------------------+-------+-------+-------+-------+--------|        |--------+-------+-------+-------+-------+-------+---------'
                         |       |       |       |       |        |        |        |       |      l |       |       |
                         '----------------------------------------'        '----------------------------------------'
*/
    
    [_TUNE] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.            
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      RGB_TOG,  HUI,   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,       /* _TUNE */       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------| 
      XXXXXXX,  HUD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX,    OS,   XXXXXXX, XXXXXXX, XXXXXXX, 
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|      
      KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_F6,  XXXXXXX,        XXXXXXX,  KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11, KC_F12,
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'    
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//                    '--------------------------------------------'      '--------------------------------------------'
    )
};

// ---------------------- variables -----------------------------

// #define ANIM_SIZE_GHOST 128 // size en bytes de cada frame
// #define ANIM_FRAME_DURATION 200// cuanto tiempo mostrar cada frame

led_t led_usb_state;

uint8_t mod_state;
bool key_registered;

uint32_t master_sleep;
uint32_t slave_sleep;

uint8_t current_wpm = 0;
uint8_t hue_value;
uint8_t sat_value;
uint8_t val_value;
uint8_t mode_value;
uint8_t current_hue;
uint8_t current_val;

char hue_str[4];
char sat_str[4];
char val_str[4];
char mode_str[4];
// char wpm_str[4];

// --------------------------------------------------------------

void keyboard_post_init_user(void) {
    current_hue = rgblight_get_hue();
    current_val = RGBLIGHT_LIMIT_VAL;
}    

layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    
        case _TUNE:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_WHITE);
            }
            break;    
            
        case _NUMP:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_TEAL);
            }    
            break;            
            
        case _SYMB:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(245, 255, current_val);
            }
            break;
    
        case _WIN10: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(current_hue, 255, current_val);
            }
            break;  

        case _MACOS: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(current_hue, 255, current_val);
            }
            break;  
    }
    
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_sethsv(20, 255, current_val); // amarillo
    } else { 
        rgblight_sethsv(current_hue, 255, current_val);
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_CAPS):
        case MT(SYMB,KC_ENT):
        case MT(NUMP,KC_ENT):
        case LCTL_T(KC_QUOTE):    
            return 150;
            
        default:
            return TAPPING_TERM;
    }
}

#ifdef OLED_ENABLE

static void master_logo(void) {
    static const char PROGMEM sol_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x30, 0x40, 0xc0, 0x80, 0xc8, 0xc4, 0x6c, 0x78, 0x38, 0xb0, 0xb8, 0xa4, 
        0xa4, 0xb0, 0x3c, 0x68, 0x64, 0xf8, 0x88, 0x90, 0x10, 0xc0, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x02, 0x84, 0xcc, 0xec, 0xee, 0xfe, 0x03, 0xf1, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf1, 0x07, 0xff, 0x79, 0x30, 0x10, 0x30, 0x20, 0x20, 0x00, 
        0x00, 0x01, 0x00, 0x18, 0x08, 0x19, 0x37, 0x3c, 0x31, 0xe7, 0xcf, 0xdf, 0x9f, 0xbf, 0xbf, 0xbf, 
        0xbf, 0xbf, 0xdf, 0x5f, 0xcf, 0xe7, 0x31, 0x7c, 0xc7, 0x83, 0x86, 0x08, 0x08, 0x08, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 
        0x03, 0x01, 0x01, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    
    oled_write_raw_P(sol_logo, 128);
    
    if (current_wpm != 0) { 
        master_sleep = timer_read32(); // se actualiza oled_sleep
    }        
}

static void render_layer(void) { // esta funcion muestra las capas en el OLED y resalta la capa presente
    if (IS_LAYER_ON(_WIN10)) { 
        oled_write_P(PSTR("WIN10"), layer_state_is(_WIN10) && !layer_state_is(_SYMB) && !layer_state_is(_NUMP) && !layer_state_is(_TUNE));
    } else {
        oled_write_P(PSTR("MACOS"), layer_state_is(_MACOS));
    }    
    oled_write_P(PSTR("SYMB\n"), layer_state_is(_SYMB) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("NUMP\n"), layer_state_is(_NUMP) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("TUNE\n"), layer_state_is(_TUNE));
}

static void render_mode(void) {
    mode_str[3] = '\0';
    mode_str[2] = '0' + mode_value % 10;
    mode_str[1] = '0' + ( mode_value /= 10) % 10;
    mode_str[0] = '0' + mode_value / 10;
    oled_write("M ", false);
    oled_write(mode_str, false); // printear valor de WPM
} 

static void render_hsv(void) {

    oled_write("H ", false);
    hue_str[3] = '\0';
    hue_str[2] = '0' + hue_value % 10;
    hue_str[1] = '0' + ( hue_value /= 10) % 10;
    hue_str[0] = '0' + hue_value / 10;
    oled_write(hue_str, false);
            
    oled_write("S ", false);
    sat_str[3] = '\0';
    sat_str[2] = '0' + sat_value % 10;
    sat_str[1] = '0' + ( sat_value /= 10) % 10;
    sat_str[0] = '0' + sat_value / 10;
    oled_write(sat_str, false);
            
    oled_write("V ", false);
    val_str[3] = '\0';
    val_str[2] = '0' + val_value % 10;
    val_str[1] = '0' + ( val_value /= 10) % 10;
    val_str[0] = '0' + val_value / 10;
    oled_write(val_str, false);      
} 

static void slave_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
    
    if (current_wpm != 0) { 
        slave_sleep = timer_read32(); // se actualiza oled_sleep
    }        
}

/*
static void render_wpm(void) {
    oled_write(" WPM\n", false);
    sprintf(wpm_str, "%03d", current_wpm);
    oled_write(wpm_str, false); // printear valor de WPM
} 
*/ 

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }    
    return rotation;
    // rotacion de 270 en pantalla OLED del master y de 270 en la del slave
    // de manera que el punto inicial este en un cierto extremo en cada OLED
    // y se siga cierta orientacion    
}

// el OLED es de 128x32 pixeles
// cada page es de 8 pixeles a lo largo del lado con 128 px
// por lo que hay 16 pages a lo largo de los 128 px
bool oled_task_user(void) { // funcion en la cual se indica que poner en cada OLED

    current_wpm = get_current_wpm();
    mode_value = rgblight_get_mode();
    hue_value = rgblight_get_hue();
    sat_value = rgblight_get_sat();
    val_value = rgblight_get_val();
    
    /*
    if (timer_elapsed32(anim_ghost_sleep) > 60000 && timer_elapsed32(anim_fishing_sleep) > 60000 && current_wpm == 0) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return;
    }
    */
    
    if (timer_elapsed32(master_sleep) > 60000 && timer_elapsed32(slave_sleep) > 60000 && current_wpm == 0) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return false;
    }
    
    if (current_wpm != 0 && !is_oled_on()) {
        oled_on();
    }
    
    led_usb_state = host_keyboard_led_state();        
    
    if (is_keyboard_master()) { // OLED del master
        // oled_set_cursor(0,1);
        master_logo();
        oled_set_cursor(0,4);
        oled_write_P(PSTR("Sofle"), false);
        oled_set_cursor(0,6);
        render_layer(); // lo de las capas
        oled_set_cursor(0,11);
        render_mode(); // lo del RGB Mode
        oled_set_cursor(0,12);
        render_hsv(); // lo del HSV
    } else {
        slave_logo();
        // oled_set_cursor(0,1);
        // slave_render_ghost();
        // oled_set_cursor(0,13);
        // render_wpm();
        // render_mode();
    }

    return false;
}

#endif // OLED_ENABLE

#ifdef ENCODER_ENABLE

#include "encoder.c"

#endif // ENCODER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();

    switch (keycode) {
/*    
        case KC_LABK:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    register_code(KC_DOT); // ya que SHIFT + KC_DOT entrega el simbolo >
                    key_registered = true; 
                    return false; // ya que true registraria ademas el keycode <
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    unregister_code(KC_DOT); // dejar de registrar KC_DOT
                    key_registered = false;
                    return false;
                }
            }
            return true; // lo anterior es solo para cuando esta presionado SHIFT. Si no lo esta, simplemente hacer lo de KC_LABK
*/        
        case HUI:
            if (record->event.pressed) {
                current_hue = current_hue + 5;
                if (current_hue > 255) {
                    current_hue = current_hue - 256;
                }    
            } else {
                ;
            }
            return false;    
            
        case HUD:
            if (record->event.pressed) {
                current_hue = current_hue - 5;
                if (current_hue < 0) {
                    current_hue = 256 + current_hue;
                }    
            } else {
                ;
            }
            return false;    
        
        case SYMB:
            if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;

        case MT(SYMB,KC_ENT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ENT);
            } else if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;
            
        case MT(NUMP,KC_ENT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ENT);
            } else if (record->event.pressed) {
                layer_on(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;               
            
        case KC_1:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_EXLM); // registrar !
                    key_registered = true; 
                    set_mods(mod_state); 
                    return false; // ya que true registraria ademas el keycode slash
                } else if (mod_state & MOD_MASK_ALT) {
                    del_mods(MOD_MASK_ALT);
                    tap_code16(ALGR(KC_1)); // registrar ¡
                    key_registered = true; 
                    set_mods(mod_state); 
                    return false; // ya que true registraria ademas el keycode slash
                } else {
                    tap_code16(KC_1);
                    key_registered = true;
                    return false;
                }    
            } else { // al liberar el keycode

                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }

        case LCTL_T(KC_QUOTE):  
            if (record->tap.count && record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_DQUO);
                    tap_code16(KC_SPC);
                    set_mods(mod_state);
                    return false;
                } else {
                    tap_code16(KC_QUOTE);
                    tap_code16(KC_SPC);
                    return false;
                }
            } else if (record->event.pressed) {
                register_code16(KC_LCTRL);
                return false;
            } else {
                unregister_code16(KC_LCTRL);
                return false;
            }    

        case KC_SLSH:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_QUES); // registrar ?
                    key_registered = true; 
                    set_mods(mod_state); 
                    return false; // ya que true registraria ademas el keycode slash
                } else if (mod_state & MOD_MASK_ALT) {
                    del_mods(MOD_MASK_ALT);
                    tap_code16(ALGR(KC_SLSH)); // registrar ¿
                    key_registered = true; 
                    set_mods(mod_state); 
                    return false; // ya que true registraria ademas el keycode slash
                } else {
                    tap_code16(KC_SLSH);
                    key_registered = true;
                    return false;
                }    
            } else { // al liberar el keycode

                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
        
        case KC_CIRC:
            if (record->event.pressed) {
                register_code16(KC_CIRC);
                register_code16(KC_SPC);
            } else {
                unregister_code16(KC_CIRC);  
                unregister_code16(KC_SPC); 
            }
            return false;
            
        case KC_GRV:
            if (record->event.pressed) {
                register_code16(KC_GRV);
                register_code16(KC_SPC);
            } else {
                unregister_code16(KC_GRV);  
                unregister_code16(KC_SPC); 
            }
            return false;  
            
        case KC_TILDE:
            if (record->event.pressed) {
                register_code16(KC_TILDE);
                register_code16(KC_SPC);
            } else {
                unregister_code16(KC_TILDE);  
                unregister_code16(KC_SPC); 
            }
            return false;  
            
        case KC_PPLS:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                    del_mods(MOD_MASK_SHIFT); // desactivar SHIFT
                    register_code16(KC_EQUAL); // ya que KC_EQUAL entrega el simbolo =
                    key_registered = true; 
                    set_mods(mod_state); // volver a activar SHIFT
                    return false; // ya que true registraria ademas el keycode KC_PPLS simbolo +
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    unregister_code16(KC_EQUAL); // dejar de registrar KC_EQUAL
                    key_registered = false;
                    return false;
                }
            }
            return true; // lo anterior es solo para cuando esta presionado SHIFT. Si no lo esta, simplemente hacer KC_PPLS          
            
        case OS: 
            if (record->event.pressed) {
                if (IS_LAYER_OFF(_WIN10)) {
                    layer_on(_WIN10);
                } else {
                    layer_off(_WIN10);
                }
            } else {
                ;
            }
            return false;    
            
        case MAC_A:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_A)); // registrar A
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_A); // registrar a
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_A));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_A);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;   
            
        case MAC_E:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_E)); // registrar E
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_E); // registrar e
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_E));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_E);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;     
            
        case MAC_I:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_I)); // registrar I
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_I); // registrar i
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_I));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_I);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;                       
            
        case MAC_O:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_O)); // registrar O
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_O); // registrar o
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_O));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_O);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;       
            
        case MAC_U:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(LSFT(KC_U)); // registrar U
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_E)); // registrar ALTGR + e
                        tap_code16(KC_U); // registrar u
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_U));   
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado
                        tap_code16(KC_U);
                        key_registered = true;
                        return false;
                    }    
                }
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;                                 
        
        case MAC_N:
            if (record->event.pressed) { // al presionar el keycode
                if (mod_state & MOD_MASK_ALT) { // si algun ALT esta presionado
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_ALT);
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(ALGR(KC_N)); // registrar ALTGR + n
                        tap_code16(LSFT(KC_N));
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else {
                        del_mods(MOD_MASK_ALT);
                        tap_code16(ALGR(KC_N)); // registrar ALTGR + n
                        tap_code16(KC_N); // registrar n
                        key_registered = true;
                        set_mods(mod_state);
                        return false; 
                    }    
                } else { // si no hay ningun ALT presionado
                    if (mod_state & MOD_MASK_SHIFT) { // si SHIFT esta presionado o bloq mayus activado
                        del_mods(MOD_MASK_SHIFT);
                        tap_code16(LSFT(KC_N)); 
                        key_registered = true;
                        set_mods(mod_state);
                        return false;
                    } else { // si SHIFT no esta presionado ni bloq mayus activado
                        tap_code16(KC_N);
                        key_registered = true;
                        return false;
                    }    
                }            
            } else { // al liberar el keycode
                if (key_registered) {
                    key_registered = false;
                    return false;
                }
            }
            return false;

    }
    return true;
}
