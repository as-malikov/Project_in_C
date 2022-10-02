#include "my_decimal.h"

/*---------------------------------------------------------------------------
            my_FLOOR rounds a specified Decimal number to the closest
            integer toward negative infinity
 ---------------------------------------------------------------------------*/
int my_floor(my_decimal value, my_decimal *result) {
    my_status_code status = my_OK;
    if (result == NULL) {
        status = my_CALCULATION_ERROR;
    } else {
        my_decimal_initialization(result);
        my_truncate(value, result);
        if (my_get_sign(value) && !my_is_equal(value, *result)) {
            my_decimal one = {{1, 0, 0, 0}};
            my_sub(*result, one, result);
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_ROUND rounds a decimal value to the nearest integer
 ---------------------------------------------------------------------------*/
int my_round(my_decimal value, my_decimal *result) {
    my_status_code status = my_OK;
    if (result == NULL) {
        status = my_CALCULATION_ERROR;
    } else {
        my_decimal_initialization(result);
        *result = value;
        bit sign = my_get_sign(value);
        if (my_get_scale(value) > 0) {
            my_set_sign(result, my_plus);
            bit cloud = 0;
            for (bit index = my_get_scale(value); index > 0; index--) {
                cloud = my_mod_div_10(*result);
                *result = my_div_10(*result);
            }
            if (cloud >= 5) {
                my_decimal one = {{1, 0, 0, 0}};
                my_add(*result, one, result);
            }
            my_set_sign(result, sign);
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_TRUNCATE returns the integral digits of the specified
            Decimal; any fractional digits are discarded, including
            trailing zeroes
 ---------------------------------------------------------------------------*/
int my_truncate(my_decimal value, my_decimal *result) {
    my_status_code status = my_OK;
    if (result == NULL) {
        status = my_CALCULATION_ERROR;
    } else {
        *result = value;
        for (scale Scale = my_get_scale(value); Scale > 0; Scale--) {
            *result = my_div_10(*result);
        }
        my_set_sign(result, my_get_sign(value));
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_NEGATE returns the result of multiplying the specified
            Decimal value by negative one
 ---------------------------------------------------------------------------*/
int my_negate(my_decimal number, my_decimal *result) {
    my_status_code status = my_OK;
    if (result == NULL) {
        status = my_CALCULATION_ERROR;
    } else {
        for (int index = 0; index < SIZE_DECIMAL; index++) {
            result->bits[index] = number.bits[index];
        }
        if (my_get_sign(number)) {
            my_set_sign(result, my_plus);
        } else {
            my_set_sign(result, my_minus);
        }
    }
    return status;
}
