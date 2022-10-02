#include "my_decimal.h"

/*---------------------------------------------------------------------------
            my_FROM_INT_TO_DECIMAL conversion from int to decimal
 ---------------------------------------------------------------------------*/
int my_from_int_to_decimal(int src, my_decimal *dst) {
    my_status_code status = my_SUCCESS;
    if (dst != NULL) {
        my_decimal_initialization(dst);
        if (src < 0) {
            my_set_sign(dst, my_minus);
            src = -src;
        }
        dst->bits[LOW] = src;
    } else {
        status = my_CONVERTING_ERROR;
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_FROM_DECIMAL_TO_INT conversion from decimal to int
 ---------------------------------------------------------------------------*/
int my_from_decimal_to_int(my_decimal src, int *dst) {
    my_status_code status = my_SUCCESS;
    if (dst == NULL) {
        status = my_CONVERTING_ERROR;
    } else {
        my_decimal result;
        my_truncate(src, &result);
        if (result.bits[MID] == 0 && result.bits[HIGH] == 0 && (result.bits[LOW] < (1u << 31))) {
            *dst = (int) result.bits[LOW];
            if (my_get_sign(src)) *dst = -(*dst);
        } else {
            status = my_CONVERTING_ERROR;
        }
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_FROM_FLOAT_TO_DECIMAL conversion from float to decimal
 ---------------------------------------------------------------------------*/
int my_from_float_to_decimal(float src, my_decimal *dst) {
    my_status_code status = my_SUCCESS;
    if (dst == NULL || isnan(src)) status = my_CONVERTING_ERROR;
    my_decimal_initialization(dst);
    int exp = my_get_float_scale(src);
    bit sign = my_get_bit_float(src, 31);
    if (exp > 95) {
        status = my_CONVERTING_ERROR;
    } else if (exp > -95) {
        if (sign) src *= -1;
        bit float_bits = *((bit *)&src);
        int mask = 0x400000;
        double binar = pow(2, exp);
        for (int index = exp - 1; mask; mask >>= 1, index--) {
            if (float_bits & mask) binar += pow(2, index);
        }
        int scale = 0;
        while (src < 1) {
            src *= 10;
            scale++;
        }
        while (src > 10) {
            src /= 10;
            scale--;
        }
        binar *= pow(10, 8 + scale);
        if (scale > 0) {
            while (binar < 10000000) {
                binar *= 10;
            }
        }
        long int res = round(binar);
        int cloud = 0;
        while (res >= 10000000) {
            cloud = res % 10;
            res /= 10;
        }
        while (scale > 22) {
            cloud = res % 10;
            res /= 10;
            scale--;
        }
        if (cloud > 4) res++;
        while (res % 10 == 0) {
            res /= 10;
            scale--;
        }
        my_from_int_to_decimal((int)res, dst);
        while (scale < -6) {
            *dst = my_mul_10(*dst);
            scale++;
        }
        my_set_sign(dst, sign);
        my_set_scale(dst, scale + 6);
    }
    return status;
}

/*---------------------------------------------------------------------------
            my_FROM_DECIMAL_TO_FLOAT conversion from decimal to float
 ---------------------------------------------------------------------------*/
int my_from_decimal_to_float(my_decimal src, float *dst) {
    my_status_code status = my_SUCCESS;
    if (dst == NULL) {
        status = my_CONVERTING_ERROR;
    } else {
        scale exp = my_get_scale(src);
        double tmp = 0.0;
        for (int i = 0; i < 96; i++) {
            if (my_get_bit(src, i)) {
                tmp += pow(2, i);
            }
        }
        while (exp) {
            tmp /= 10.0;
            exp--;
        }
        *dst = (float) tmp;
        if (my_get_sign(src)) *dst = -(*dst);
    }
    return status;
}
