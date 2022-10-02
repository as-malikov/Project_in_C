#include "my_decimal.h"

/*---------------------------------------------------------------------------
            my_DECIMAL_INITIALIZATION сreating and filling a number
            with zeros
 ---------------------------------------------------------------------------*/
void my_super_decimal_initialization(my_super_decimal *number) {
    for (int value = 0; value < SIZE_SUPER_DECIMAL; value++) {
        number->bits[value] = 0UL;
    }
}

/*---------------------------------------------------------------------------
            my_FROM_DECIMAL_TO_SUPER_DECIMAL conversion from 
            decimal to super decimal
 ---------------------------------------------------------------------------*/
my_super_decimal my_from_decimal_to_super_decimal(my_decimal value) {
    my_super_decimal result;
    my_super_decimal_initialization(&result);
    for (int number = 0; number < SIZE_DECIMAL - 1; number++) {
        result.bits[number] = value.bits[number];
    }
    result.bits[SUPER_SCALE] = value.bits[SCALE];
    return result;
}

/*---------------------------------------------------------------------------
            my_GET_BIT_SUPER get a bit value of super decimal by given index
 ---------------------------------------------------------------------------*/
bit my_get_bit_super(my_super_decimal value, int index) {
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
            my_SET_BIT_SUPER set a bit value of super decimal by given index
 ---------------------------------------------------------------------------*/
void my_set_bit_super(my_super_decimal *value, int index, bit value_bit) {
    bit mask = 1u << (index % 32);
    if (value_bit) {
        value->bits[index / 32] |= mask;
    } else {
        value->bits[index / 32] &= ~mask;
    }
}

/*---------------------------------------------------------------------------
            my_GET_SIGN_SUPER get a sign bit of super decimal
 ---------------------------------------------------------------------------*/
bit my_get_sign_super(my_super_decimal value) {
    return (value.bits[SUPER_SCALE] >> 31) & 1UL;
}

/*---------------------------------------------------------------------------
            my_SET_SIGN_SUPER set a sign bit of float number
 ---------------------------------------------------------------------------*/
void my_set_sign_super(my_super_decimal *value, bit sign) {
    scale scale = my_get_scale_super(*value);
    value->bits[SUPER_SCALE] = ((value->bits[SUPER_SCALE] >> 31)  ^ sign) << 31;
    my_set_scale_super(value, scale);
}

/*---------------------------------------------------------------------------
            my_GET_SCALE_SUPER get a scale of super decimal
 ---------------------------------------------------------------------------*/
scale my_get_scale_super(my_super_decimal value) {
    scale mask = 0x00ff0000;
    scale Scale = value.bits[SUPER_SCALE] & mask;
    Scale >>= 16;
    return Scale;
}

/*---------------------------------------------------------------------------
            my_SET_SCALE set a scale of super decimal
 ---------------------------------------------------------------------------*/
void my_set_scale_super(my_super_decimal *value, scale scale_value) {
    value->bits[SUPER_SCALE] &= 0x80000000;
    scale_value <<= 16;
    value->bits[SUPER_SCALE] |= scale_value;
}

/*---------------------------------------------------------------------------
            my_ADD_SUPER_DECIMAL bitwise addition of two super decimal
 ---------------------------------------------------------------------------*/
my_super_decimal my_add_super_decimal(my_super_decimal value_1, my_super_decimal value_2) {
    my_super_decimal result;
    my_super_decimal_initialization(&result);
    bit cloud = 0;
    for (int index = 0; index < 192; index++) {
        bit bit_value_1 = my_get_bit_super(value_1, index);
        bit bit_value_2 = my_get_bit_super(value_2, index);
        if (bit_value_1 & bit_value_2) {
            if (cloud) {
                my_set_bit_super(&result, index, 1);
            } else {
                my_set_bit_super(&result, index, 0);
                cloud = 1;
            }
        } else if (bit_value_1 ^ bit_value_2) {
            if (cloud) {
                my_set_bit_super(&result, index, 0);
            } else {
                my_set_bit_super(&result, index, 1);
            }
        } else {
            if (cloud) {
                my_set_bit_super(&result, index, 1);
                cloud = 0;
            } else {
                my_set_bit_super(&result, index, 0);
            }
        }
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_CHECK_ENTRY_SUPER check if super decimal has empty bites
 ---------------------------------------------------------------------------*/
bool my_check_entry_super(my_super_decimal value) {
    bool answer = my_TRUE;
    for (int index = LOW_SUPER; index <= HIGH_SUPER && answer; index++) {
        if (value.bits[index]) answer = my_FALSE;
    }
    return answer;
}

/*---------------------------------------------------------------------------
            my_EQUALIZE_SCALE equalization of scales of super decimal
 ---------------------------------------------------------------------------*/
void my_equalize_scale(my_super_decimal *value_1, my_super_decimal *value_2) {
    scale scale_1 = my_get_scale_super(*value_1);
    scale scale_2 = my_get_scale_super(*value_2);
    int difference = scale_1 - scale_2;
    if (difference < 0) {
        difference *= -1;
        *value_1 = my_increase_super_decimal(*value_1, difference);
    } else if (difference > 0) {
        *value_2 = my_increase_super_decimal(*value_2, difference);
    }
}

/*---------------------------------------------------------------------------
            my_INCREASE_SUPER_DECIMAL increase a number and scale 
            of super decimal
 ---------------------------------------------------------------------------*/
my_super_decimal my_increase_super_decimal(my_super_decimal value, scale difference) {
    my_super_decimal result = value;
    scale scale_value = my_get_scale_super(value);
    while (difference > 0) {
        result = my_mul_10_super(result);
        scale_value++;
        difference--;
    }
    my_set_scale_super(&result, scale_value);
    return result;
}

/*---------------------------------------------------------------------------
            my_MUL_10_SUPER multiplies super decimal by 10
 ---------------------------------------------------------------------------*/
my_super_decimal my_mul_10_super(my_super_decimal value) {
    my_super_decimal result;
    my_super_decimal_initialization(&result);
    result.bits[SUPER_SCALE] = value.bits[SUPER_SCALE];

    for (int index = 1; index <  3; index++) {
        value = my_shift_left_super(value, index);
        result = my_add_super_decimal(result, value);
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_SHIFT_LEFT_SUPER bitewise shift of super decimal 
            to the left by number of character
 ---------------------------------------------------------------------------*/
my_super_decimal my_shift_left_super(my_super_decimal value, int shift) {
    my_super_decimal result;
    my_super_decimal_initialization(&result);
    for (int index = 191; index >= shift; index--) {
        my_set_bit_super(&result, index, my_get_bit_super(value, index - shift));
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_SHIFT_RIGHT_SUPER bitewise shift of super decimal 
            to the right by number of character
 ---------------------------------------------------------------------------*/
my_super_decimal my_shift_right_super(my_super_decimal value, int shift) {
  my_super_decimal result;
  my_super_decimal_initialization(&result);
  for (int index = 0; index < 192 - shift; index++) {
    my_set_bit_super(&result, index, my_get_bit_super(value, index + shift));
  }
  return result;
}

/*---------------------------------------------------------------------------
            my_IS_EQUAL_SUPER one super decimal is equal to another
 ---------------------------------------------------------------------------*/
bool my_is_equal_super(my_super_decimal value_1, my_super_decimal value_2) {
    my_status_code status = my_TRUE;
    for (int index = LOW; index < SUPER_SCALE; index++) {
        if (value_1.bits[index] != value_2.bits[index]) {
            status = my_FALSE;
            break;
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_IS_GREATER_SUPER one super decimal is greater than the other
 ---------------------------------------------------------------------------*/
bool my_is_greater_super(my_super_decimal value_1, my_super_decimal value_2) {
    my_status_code status = my_FALSE;
    for (int index = HIGH_SUPER; index >= LOW; index--) {
        if (value_1.bits[index] > value_2.bits[index]) {
            status = my_TRUE;
            break;
        } else if (value_1.bits[index] < value_2.bits[index]) {
            break;
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_SUB_SUPER the operation of subtraction of 
            two super decimal
 ---------------------------------------------------------------------------*/
my_super_decimal my_sub_super(my_super_decimal value_1, my_super_decimal value_2) {
    my_super_decimal result;
    my_super_decimal_initialization(&result);
    int cloud = 0;
    for (int index = 0; index < 192; index++) {
        bit value_1_bit = my_get_bit_super(value_1, index);
        bit value_2_bit = my_get_bit_super(value_2, index);
        if (value_1_bit & value_2_bit) {
            if (cloud) {
                my_set_bit_super(&result, index, 1);
            } else {
                my_set_bit_super(&result, index, 0);
            }
        } else if (!(value_1_bit | value_2_bit)) {
            if (cloud) {
                my_set_bit_super(&result, index, 1);
            } else {
                my_set_bit_super(&result, index, 0);
            }
        } else if (value_1_bit > value_2_bit) {
            if (cloud) {
                my_set_bit_super(&result, index, 0);
                cloud = 0;
            } else {
                my_set_bit_super(&result, index, 1);
            }
        } else if (value_1_bit < value_2_bit) {
            if (cloud) {
                my_set_bit_super(&result, index, 0);
            } else {
                my_set_bit_super(&result, index, 1);
                cloud = 1;
            }
        }
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_MOD_DIV_10_SUPER get a remainder of super decimal 
            division by 10
 ---------------------------------------------------------------------------*/
int my_mod_div_10_super(my_super_decimal value) {
    int result = 0;
    for (int index = 191; index >= 0; index--) {
        result <<= 1;
        result |= my_get_bit_super(value, index);
        if (result >= 10) result -= 10;
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_DIV_10_SUPER dividing super decimal by 10
 ---------------------------------------------------------------------------*/
my_super_decimal my_div_10_super(my_super_decimal value) {
    my_super_decimal result, quotient;
    my_super_decimal_initialization(&result);
    my_super_decimal_initialization(&quotient);
    int divident = 0;
    int pos = 0;
    int status = 0;
    for (int index = 191; index >= 0; index--) {
        if (status) pos++;
        divident <<= 1;
        divident |= my_get_bit_super(value, index);
        if (divident >= 10) {
            my_set_bit_super(&quotient, pos, 1);
            divident -= 10;
            status = 1;
        }
    }
    for (int index = pos, index_2 = 0; index >= 0; index--, index_2++) {
        int bit = my_get_bit_super(quotient, index);
        my_set_bit_super(&result, index_2, bit);
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_MOD_DIV_2_SUPER get a remainder of super decimal 
            division by 2
 ---------------------------------------------------------------------------*/
my_super_decimal my_mod_div_2_super(my_super_decimal value_1, my_super_decimal value_2) {
    int shift = 0;
    while (!my_get_bit_super(value_2, 191 - shift)) {
        shift++;
    }
    for (int index = 0; !my_get_bit_super(value_1, 191 - index); index++) {
        shift--;
    }
    if (shift >= 0) {
    value_2 = my_shift_left_super(value_2, shift);
    while (shift >= 0) {
        if (my_is_greater_super(value_1, value_2) || my_is_equal_super(value_1, value_2)) {
            value_1 = my_sub_super(value_1, value_2);
        }
        value_2 = my_shift_right_super(value_2, 1);
        shift--;
    }
    }
    return value_1;
}

/*---------------------------------------------------------------------------
            my_IS_ZERO_SUPER check if super decimal is zero
 ---------------------------------------------------------------------------*/
bool my_is_zero_super(my_super_decimal value) {
    my_status_code status = my_TRUE;
    for (int index = HIGH_SUPER; index >= LOW; index--) {
        if (value.bits[index]) {
            status = my_FALSE;
            break;
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_DIV_SUPER the operation of division two super decimal numbers
 ---------------------------------------------------------------------------*/
my_super_decimal my_div_super(my_super_decimal value_1, my_super_decimal value_2) {
    my_super_decimal result;
    my_super_decimal_initialization(&result);
    int shift = 0;
    while (!my_get_bit_super(value_2, 191 - shift)) {
        shift++;
    }
    for (int index = 0; !my_get_bit_super(value_1, 191 - index); index++) {
        shift--;
    }
    if (shift >= 0) {
        value_2 = my_shift_left_super(value_2, shift);
        while (shift >= 0) {
            my_set_bit_super(&result, 0, (my_is_greater_super(value_1, value_2) ||
             my_is_equal_super(value_1, value_2)));
            if (my_get_bit_super(result, 0)) {
                value_1 = my_sub_super(value_1, value_2);
            }
            value_2 = my_shift_right_super(value_2, 1);
            if (shift) result = my_shift_left_super(result, 1);
            shift--;
        }
    }
    return result;
}

/*---------------------------------------------------------------------------
            my_MOD_SUPER the remainder of the division of 
            two super decimal numbers
 ---------------------------------------------------------------------------*/
my_super_decimal my_mod_super(my_super_decimal value_1, my_super_decimal value_2) {
    int shift = 0;
    while (!my_get_bit_super(value_2, 191 - shift)) {
        shift++;
    }
    for (int index = 0; !my_get_bit_super(value_1, 191 - index); index++) {
        shift--;
    }
    if (shift >= 0) {
        value_2 = my_shift_left_super(value_2, shift);
        while (shift >= 0) {
            if (my_is_greater_super(value_1, value_2) || my_is_equal_super(value_1, value_2)) {
                value_1 = my_sub_super(value_1, value_2);
            }
            value_2 = my_shift_right_super(value_2, 1);
            shift--;
        }
    }
    return value_1;
}
