#include "my_decimal.h"

/*---------------------------------------------------------------------------
            my_IS_LESS one number is smaller than the other
 ---------------------------------------------------------------------------*/
int my_is_less(my_decimal value_1, my_decimal value_2) {
    my_status_code status = my_FALSE;
    bit sign_1 = my_get_sign(value_1);
    bit sign_2 = my_get_sign(value_2);
    if (my_is_zero(value_1)) {
        sign_1 = my_plus;
    }
    if (my_is_zero(value_2)) {
        sign_2 = my_plus;
    }
    if (sign_1 == sign_2) {
        my_super_decimal super_value_1 = my_from_decimal_to_super_decimal(value_1);
        my_super_decimal super_value_2 = my_from_decimal_to_super_decimal(value_2);
        my_equalize_scale(&super_value_1, &super_value_2);
        for (int index = HIGH_SUPER; index >= LOW; index--) {
            if (super_value_1.bits[index] > super_value_2.bits[index]) {
                if (sign_1) {
                    status = my_TRUE;
                }
                break;
            } else if (super_value_1.bits[index] < super_value_2.bits[index]) {
                if (!sign_1) {
                    status = my_TRUE;
                }
                break;
            }
        }
    } else if (sign_1) {
        status = my_TRUE;
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_IS_LESS_OR_EQUAL one number is less than or equal
            to another
 ---------------------------------------------------------------------------*/
int my_is_less_or_equal(my_decimal value_1, my_decimal value_2) {
    my_status_code status = my_FALSE;
    if (my_is_less(value_1, value_2) || my_is_equal(value_1, value_2)) {
        status = my_TRUE;
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_IS_GREATER one number is greater than the other
 ---------------------------------------------------------------------------*/
int my_is_greater(my_decimal value_1, my_decimal value_2) {
    my_status_code status = my_FALSE;
    bit sign_1 = my_get_sign(value_1);
    bit sign_2 = my_get_sign(value_2);
    if (my_is_zero(value_1)) {
        sign_1 = my_plus;
    }
    if (my_is_zero(value_2)) {
        sign_2 = my_plus;
    }
    if (sign_1 == sign_2) {
        my_super_decimal super_value_1 = my_from_decimal_to_super_decimal(value_1);
        my_super_decimal super_value_2 = my_from_decimal_to_super_decimal(value_2);
        my_equalize_scale(&super_value_1, &super_value_2);
        for (int index = HIGH_SUPER; index >= LOW; index--) {
            if (super_value_1.bits[index] > super_value_2.bits[index]) {
                if (!sign_1) {
                    status = my_TRUE;
                }
                break;
            } else if (super_value_1.bits[index] < super_value_2.bits[index]) {
                if (sign_1) {
                    status = my_TRUE;
                }
                break;
            }
        }
    } else if (sign_2) {
        status = my_TRUE;
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_IS_GREATER_OR_EQUAL one number is greater than or equal
            to another
 ---------------------------------------------------------------------------*/
int my_is_greater_or_equal(my_decimal value_1, my_decimal value_2) {
    my_status_code status = my_FALSE;
    if (my_is_greater(value_1, value_2) || my_is_equal(value_1, value_2)) {
        status = my_TRUE;
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_IS_EQUAL one number is equal to another
 ---------------------------------------------------------------------------*/
int my_is_equal(my_decimal value_1, my_decimal value_2) {
    my_status_code status = my_FALSE;
    if (my_is_zero(value_1) && my_is_zero(value_2)) {
        status = my_TRUE;
    } else if (my_get_sign(value_1) == my_get_sign(value_2)) {
        my_super_decimal value_1_super = my_from_decimal_to_super_decimal(value_1);
        my_super_decimal value_2_super = my_from_decimal_to_super_decimal(value_2);
        my_equalize_scale(&value_1_super, &value_2_super);
        status = my_TRUE;
        for (int index = HIGH_SUPER; index >= LOW; index--) {
            if (value_1_super.bits[index] != value_2_super.bits[index]) {
                status = my_FALSE;
                break;
            }
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_NOT_EQUAL one number is not equal to another
 ---------------------------------------------------------------------------*/
int my_is_not_equal(my_decimal value_1, my_decimal value_2) {
    my_status_code status = my_TRUE;
    if (my_is_equal(value_1, value_2)) {
        status = my_FALSE;
    }
    return status;
}
