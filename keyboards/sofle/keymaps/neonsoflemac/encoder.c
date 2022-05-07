// kb: sofle
// km: neonsofle

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(HUI);
        } else {
            tap_code16(HUD);
        }
    }
    return true;
}
