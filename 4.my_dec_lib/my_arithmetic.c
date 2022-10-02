#include "my_decimal.h"

/*---------------------------------------------------------------------------
            my_ADD the operation of adding two decimal numbers
 ---------------------------------------------------------------------------*/
int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    my_status_code status = my_OK;
    my_super_decimal super_result;
    my_super_decimal_initialization(&super_result);
    if (result == NULL) {
        status = my_NAN;
    } else {
        bit sign_value_1 = my_get_sign(value_1);
        bit sign_value_2 = my_get_sign(value_2);
        my_super_decimal super_value_1 = my_from_decimal_to_super_decimal(value_1);
        my_super_decimal super_value_2 = my_from_decimal_to_super_decimal(value_2);
        my_equalize_scale(&super_value_1, &super_value_2);
        if (sign_value_1 == sign_value_2) {
            super_result = my_add_super_decimal(super_value_1, super_value_2);
            my_set_sign_super(&super_result, sign_value_1);
            my_set_scale_super(&super_result, my_get_scale_super(super_value_1));
        } else if (my_is_equal_super(super_value_1, super_value_2) == my_FALSE) {
            if (my_is_greater_super(super_value_1, super_value_2)) {
                super_result = my_sub_super(super_value_1, super_value_2);
                my_set_sign_super(&super_result, sign_value_1);
            } else {
                super_result = my_sub_super(super_value_2, super_value_1);
                my_set_sign_super(&super_result, sign_value_1);
            }
            my_set_scale_super(&super_result, my_get_scale_super(super_value_1));
        }
        *result = my_from_super_decimal_to_decimal(super_result, &status);
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_SUB the operation of subtraction two decimal numbers
 ---------------------------------------------------------------------------*/
int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    my_status_code status = my_OK;
    my_super_decimal super_result;
    my_super_decimal_initialization(&super_result);
    if (result == NULL) {
        status = my_NAN;
    } else {
        bit sign_value_1 = my_get_sign(value_1);
        bit sign_value_2 = my_get_sign(value_2);
        my_super_decimal super_value_1 = my_from_decimal_to_super_decimal(value_1);
        my_super_decimal super_value_2 = my_from_decimal_to_super_decimal(value_2);
        my_equalize_scale(&super_value_1, &super_value_2);
        if (sign_value_1 != sign_value_2) {
            super_result = my_add_super_decimal(super_value_1, super_value_2);
            my_set_sign_super(&super_result, sign_value_1);
            my_set_scale_super(&super_result, my_get_scale_super(super_value_1));
        } else if (my_is_equal_super(super_value_1, super_value_2) == my_FALSE) {
            if (my_is_greater_super(super_value_1, super_value_2)) {
                super_result = my_sub_super(super_value_1, super_value_2);
                my_set_sign_super(&super_result, sign_value_1);
            } else {
                super_result = my_sub_super(super_value_2, super_value_1);
                my_set_sign_super(&super_result, !sign_value_2);
            }
            my_set_scale_super(&super_result, my_get_scale_super(super_value_1));
        }
        *result = my_from_super_decimal_to_decimal(super_result, &status);
    }
    return status;
}


/*---------------------------------------------------------------------------
            my_MUL the operation of multiplication two decimal numbers
 ---------------------------------------------------------------------------*/
int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    my_status_code status = my_OK;
    my_decimal_initialization(result);
    my_super_decimal super_result;
    my_super_decimal_initialization(&super_result);
    if (result == NULL) {
        status = my_NAN;
    } else {
        bit sign = my_get_sign(value_1) ^ my_get_sign(value_2);
        my_super_decimal value = my_from_decimal_to_super_decimal(value_1);
        if (my_is_zero(value_1) || my_is_zero(value_2)) {
            if (my_is_zero(value_1)) {
                my_set_scale(result, my_get_scale(value_1));
            } else {
                my_set_scale(result, my_get_scale(value_2));
            }
            my_set_sign(result, sign);
        } else {
            scale Scale = my_get_scale(value_1) + my_get_scale(value_2);
            while (my_is_zero(value_2) == my_FALSE) {
                my_set_scale(&value_2, 0);
                if (my_get_bit(value_2, 0)) {
                    super_result = my_add_super_decimal(super_result, value);
                }
                value = my_shift_left_super(value, 1);
                value_2 = my_shift_right(value_2, 1);
            }
            my_set_sign_super(&super_result, sign);
            my_set_scale_super(&super_result, Scale);
            *result = my_from_super_decimal_to_decimal(super_result, &status);
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_DIV the operation of division two decimal numbers
 ---------------------------------------------------------------------------*/
int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    my_status_code status = my_OK;
    my_decimal_initialization(result);
    my_decimal neg_value_2;
    my_negate(value_2, &neg_value_2);
    bit sign = my_get_sign(value_1) ^ my_get_sign(value_2);
    my_decimal one = {{1, 0, 0, 0}};
    if (my_is_zero(value_2)) {
        if (my_is_zero(value_1)) {
            status = my_NAN;
        } else {
            if (sign) {
                status = my_NEGATIVE_INFINITY;
            } else {
                status = my_INFINITY;
            }
        }
    } else if (my_is_zero(value_1)) {
        if (!my_is_zero(value_2)) {
            if (sign) {
                my_set_sign(result, my_minus);
            } else {
                my_set_sign(result, my_plus);
            }
            my_set_scale(result, my_get_scale(value_1));
        }
    } else if (my_is_equal(value_2, one) || my_is_equal(neg_value_2, one)) {
        *result = value_1;
        my_set_sign(result, sign);
    } else if (my_is_equal(value_1, value_2) || my_is_equal(value_1, neg_value_2)) {
        *result = one;
        my_set_sign(result, sign);
    } else {
        my_super_decimal super_value_1 = my_from_decimal_to_super_decimal(value_1);
        my_super_decimal super_value_2 = my_from_decimal_to_super_decimal(value_2);
        my_equalize_scale(&super_value_1, &super_value_2);
        my_super_decimal super_result = my_div_super(super_value_1, super_value_2);
        super_value_1 = my_mod_super(super_value_1, super_value_2);
        scale cloud_scale = 0;
        my_super_decimal ten = {{10, 0, 0, 0, 0, 0, 0}};
        while (my_is_greater_super(super_result, ten) || my_is_equal_super(super_result, ten)) {
            ten = my_mul_10_super(ten);
            cloud_scale++;
        }
        scale super_result_scale = 0;
        while (super_result_scale + cloud_scale < 29 && !my_is_zero_super(super_value_1)) {
            super_value_1 = my_mul_10_super(super_value_1);
            super_result = my_mul_10_super(super_result);
            super_result = my_add_super_decimal(super_result, my_div_super(super_value_1, super_value_2));
            super_value_1 = my_mod_super(super_value_1, super_value_2);
            super_result_scale++;
        }
        my_set_sign_super(&super_result, sign);
        my_set_scale_super(&super_result, super_result_scale);
        *result = my_from_super_decimal_to_decimal(super_result, &status);
        if (!my_mod_div_10(*result) && super_result_scale) {
            super_result_scale = my_get_scale(*result);
            while (!my_mod_div_10(*result)) {
                *result = my_div_10(*result);
                super_result_scale--;
            }
            my_set_scale(result, super_result_scale);
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_MOD the remainder of the division of two decimal numbers
 ---------------------------------------------------------------------------*/
int my_mod(my_decimal value_1, my_decimal value_2, my_decimal *result) {
    my_status_code status = my_OK;
    bit sign = my_get_sign(value_1);
    if (result == NULL) {
        status = my_NAN;
    } else {
        scale result_scale;
        my_decimal_initialization(result);
        if (my_get_scale(value_1) >= my_get_scale(value_2)) {
            result_scale = my_get_scale(value_1);
        } else {
            result_scale =  my_get_scale(value_2);
        }
        my_decimal neg_val;
        my_negate(value_2, &neg_val);
        if (my_is_equal(value_1, value_2) || my_is_equal(value_1, neg_val)) {
            my_set_sign(result, sign);
        } else if (!my_is_zero(value_2)) {
            my_set_sign(&value_1, my_plus);
            my_set_sign(&value_2, my_plus);
            if (my_is_greater(value_1, value_2)) {
                my_super_decimal super_value_1 = my_from_decimal_to_super_decimal(value_1);
                my_super_decimal super_value_2 = my_from_decimal_to_super_decimal(value_2);
                my_equalize_scale(&super_value_1, &super_value_2);
                super_value_1 = my_mod_div_2_super(super_value_1, super_value_2);
                *result = my_from_super_decimal_to_decimal(super_value_1, &status);
                my_set_scale(result, result_scale);
            } else {
                *result = value_1;
            }
            my_set_sign(result, sign);
        } else {
            status = my_NAN;
        }
    }
    return status;
}
