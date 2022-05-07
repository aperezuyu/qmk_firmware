// kb: sofle
// km: neonsofle

#pragma once

// #define OLED_TIMEOUT 60000

#define OLED_DISABLE_TIMEOUT

#define SPLIT_OLED_ENABLE

#define SPLIT_WPM_ENABLE

#define EE_HANDS

#define RGB_DI_PIN D3

#undef TAPPING_TERM

#define TAPPING_TERM 300 // el doble pulso del Tap Dance debe hacerse en menos de 400ms

#define TAPPING_TERM_PER_KEY

#define OLED_BRIGHTNESS 120

#ifdef RGBLIGHT_ENABLE // si la linea RGBLIGHT_ENABLE = yes esta en rules.mk

    #undef RGBLED_NUM
       
    #define RGBLED_NUM 74 // numero de LEDs en el teclado
    
    #undef RGBLED_SPLIT
    
    #define RGBLED_SPLIT \
        {37,37}
       
    // #define RGBLIGHT_EFFECT_BREATHING
    // incluyendo el efecto RGB breathing
    
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // incluyendo el efecto RGB rainbow mood
    
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
               
    #define RGBLIGHT_LIMIT_VAL 110
    // maximo valor para Value en HSV
    
    #define RGBLIGHT_HUE_STEP 5
    // valor del step al modificar Hue
    
    #define RGBLIGHT_SAT_STEP 17
    // valor del step al modificar Saturation
    
    #define RGBLIGHT_VAL_STEP 17
    // valor del step al modificar Value
    
#endif

#define NO_ACTION_MACRO 
// ya que tengo EXTRAFLAGS += -flto en rules.mk

#define NO_ACTION_FUNCTION 
// ya que tengo EXTRAFLAGS += -flto en rules.mk

#define NO_ACTION_ONESHOT
// reduce size al firmware