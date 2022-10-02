#include "my_decimal.h"

/*---------------------------------------------------------------------------
            my_DECIMAL_INITIALIZATION creating and filling a number
            with zeros
 ---------------------------------------------------------------------------*/
void my_decimal_initialization(my_decimal *number) {
    for (int value = 0; value < SIZE_DECIMAL; value++) {
        number->bits[value] = 0UL;
    }
}

/*---------------------------------------------------------------------------
            my_GET_BIT get a bit value by given index
 ---------------------------------------------------------------------------*/
bit my_get_bit(my_decimal value, int index) {
    bit mask = 1u << (index % 32);
    bit Bit = value.bits[index / 32] & mask;
    if (Bit) {
        Bit = 1;
    } else {
        Bit = 0;
    }
    return Bit;
}

/*---------------------------------------------------------------------------
            my_SET_BIT set a bit value by given index
 ---------------------------------------------------------------------------*/
void my_set_bit(my_decimal *value, int index, bit value_bit) {
    bit mask = 1u << (index % 32);
    if (value_bit) {
        value->bits[index / 32] |= mask;
    } else {
        value->bits[index / 32] &= ~mask;
    }
}

/*---------------------------------------------------------------------------
            my_GET_SCALE get a scale
 ---------------------------------------------------------------------------*/
scale my_get_scale(my_decimal value) {
    scale mask = 0x00ff0000;
    scale Scale = value.bits[SCALE] & mask;
    Scale >>= 16;
    return Scale;
}

/*---------------------------------------------------------------------------
            my_SET_SCALE set a scale
 ---------------------------------------------------------------------------*/
void my_set_scale(my_decimal *value, scale scale_value) {
    value->bits[SCALE] &= 0x80000000;
    scale_value <<= 16;
    value->bits[SCALE] |= scale_value;
}

/*---------------------------------------------------------------------------
            my_SHIFT_RIGHT bitewise shift to the right by number of character
 ---------------------------------------------------------------------------*/
my_decimal my_shift_right(my_decimal value, int shift) {
    my_decimal result;
    my_decimal_initialization(&result);
    for (int index = 0; index < 96 - shift; index++) {
        my_set_bit(&result, index, my_get_bit(value, shift + index));
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_SHIFT_LEFT bitewise shift to the left by number of character
 ---------------------------------------------------------------------------*/
my_decimal my_shift_left(my_decimal value, int shift) {
    my_status_code status = my_OK;
    my_decimal result;
    my_decimal_initialization(&result);
    result.bits[SCALE] = value.bits[SCALE];
    for (int index = 95; index > 95 - shift; index--) {
        if (my_get_bit(value, index)) {
            status = my_INFINITY;
        }
    }
    if (status) {
        my_decimal_initialization(&result);
    } else {
        for (int index = 95; index >= shift; index--) {
            my_set_bit(&result, index, my_get_bit(value, index - shift));
        }
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_GET_SIGN get a sign bit of number
 ---------------------------------------------------------------------------*/
bit my_get_sign(my_decimal value) {
    return (value.bits[SCALE] >> 31) & 1UL;
}

/*---------------------------------------------------------------------------
            my_SET_SIGN set a sign bit of number
 ---------------------------------------------------------------------------*/
void my_set_sign(my_decimal *value, bit sign) {
    scale scale = my_get_scale(*value);
    value->bits[SCALE] = sign << 31;
    my_set_scale(value, scale);
}

/*---------------------------------------------------------------------------
            my_FROM_SUPER_DECIMAL_TO_DECIMAL conversion of number 
            from super decimal to decimal
 ---------------------------------------------------------------------------*/
my_decimal my_from_super_decimal_to_decimal(my_super_decimal value, my_status_code *status) {
    my_decimal result;
    my_decimal_initialization(&result);
    bit sign = my_get_sign_super(value);
    scale Scale = my_get_scale_super(value);
    bit cloud = 0;
    while (Scale > my_MAX_SCALE || (!my_check_entry_super(value) && Scale)) {
        Scale--;
        cloud = my_mod_div_10_super(value);
        value = my_div_10_super(value);
    }
    if (my_check_entry_super(value)) {
        if (cloud >= 5) {
            my_super_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
            my_super_decimal tmp = my_add_super_decimal(value, one);
            if (my_check_entry_super(tmp) && !Scale) {
                my_decimal_initialization(&result);
            } else if (!my_check_entry_super(tmp) && Scale) {
                cloud = my_mod_div_10_super(value);
                value = my_div_10_super(value);
                Scale--;
                if (cloud >= 5) value = my_add_super_decimal(value, one);
                for (int i = 0; i < 3; i++) {
                    result.bits[i] = value.bits[i];
                }
                my_set_scale(&result, Scale);
                my_set_sign(&result, sign);
            } else {
                for (int i = 0; i < 3; i++) {
                    result.bits[i] = tmp.bits[i];
                }
                my_set_scale(&result, Scale);
                my_set_sign(&result, sign);
            }
        } else {
            for (int i = 0; i < 3; i++) {
                result.bits[i] = value.bits[i];
            }
            my_set_scale(&result, Scale);
            my_set_sign(&result, sign);
        }
    } else {
        if (sign) {
            *status = my_NEGATIVE_INFINITY;
        } else {
            *status = my_INFINITY;
        }
    }
    return result;
}


/*---------------------------------------------------------------------------
            my_DIV_10 dividing decimal by 10
 ---------------------------------------------------------------------------*/
my_decimal my_div_10(my_decimal value) {
    my_decimal result;
    my_decimal_initialization(&result);
    my_decimal quotient;
    my_decimal_initialization(&quotient);
    int divident = 0;
    int pos = 0;
    int status = 0;
    for (int index = 95; index >= 0; index--) {
        if (status) pos++;
        divident <<= 1;
        divident |= my_get_bit(value, index);
        if (divident >= 10) {
            my_set_bit(&quotient, pos, 1);
            divident -= 10;
            status = 1;
        }
    }
    for (int index = pos, index_2 = 0; index >= 0; index--, index_2++) {
        my_set_bit(&result, index_2, my_get_bit(quotient, index));
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_MOD_DIV_10 get a remainder of decimal division by 10
 ---------------------------------------------------------------------------*/
int my_mod_div_10(my_decimal value) {
    int devident = 0;
    for (int index = 95; index >= 0; index--) {
        devident <<= 1;
        devident |= my_get_bit(value, index);
        if (devident >= 10) devident -= 10;
    }
    return devident;
}

/*---------------------------------------------------------------------------
            my_MUL_10 multiplies decimal by 10
 ---------------------------------------------------------------------------*/
my_decimal my_mul_10(my_decimal value) {
    my_decimal result;
    my_decimal_initialization(&result);
    result.bits[SCALE] = value.bits[SCALE];
    for (int index = 1; index <= 2; index++) {
        value = my_shift_left(value, index);
        my_add(result, value, &result);
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_IS_ZERO check if a number is zero
 ---------------------------------------------------------------------------*/
bool my_is_zero(my_decimal value) {
    my_status_code status = my_TRUE;
    for (int index = LOW; index < HIGH; index++) {
        if (value.bits[index]) {
            status = my_FALSE;
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_GET_FLOAT_SCALE get exponent value of float number
 ---------------------------------------------------------------------------*/
int my_get_float_scale(float source) {
    bit float_bits = *((bit *)&source);
    scale exp = (float_bits >> 23) & 0xff;
    return exp - 127;
}

/*---------------------------------------------------------------------------
            my_GET_BIT_FLOAT get a sign bit of float number
 ---------------------------------------------------------------------------*/
bit my_get_bit_float(float source, int index) {
    bit float_bits = *((bit *)&source);
    bit mask = 1u << index;
    bit result_bit = float_bits & mask;
    if (result_bit) {
        result_bit = 1;
    } else {
        result_bit = 0;
    }
    return result_bit;
}
