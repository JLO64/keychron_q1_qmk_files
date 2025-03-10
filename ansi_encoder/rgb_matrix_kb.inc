// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(default_solid_blue)
RGB_MATRIX_EFFECT(green_shortcut_keys)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool default_solid_blue(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if ((i >= 16 && i < 28) || (i >= 31 && i < 43) || (i >= 46 && i < 57) || (i >= 60 && i < 70)) {
            rgb_matrix_set_color(i, 116, 192, 252);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool green_shortcut_keys(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    rgb_matrix_sethsv_noeeprom(0, 0, 255);
    // rgb_t rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if ((i == 62) || (i == 54) || (i == 38)) {
            rgb_matrix_set_color(i, 0, 200, 0);
        } else {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS