#ifndef SRC_MY_DECIMAL_H_
#define SRC_MY_DECIMAL_H_

#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE_DECIMAL 4
#define SIZE_SUPER_DECIMAL 7

#define LOW 0
#define MID 1
#define HIGH 2
#define LOW_SUPER 3
#define MID_SUPER 4
#define HIGH_SUPER 5
#define SCALE 3
#define SUPER_SCALE 6
#define my_MAX_SCALE 28

//  data type for use bit and scale
typedef unsigned int bit;
typedef unsigned int scale;
typedef int bool;

typedef enum {
    my_OK = 0,
    my_INFINITY = 1,
    my_NEGATIVE_INFINITY = 2,
    my_NAN = 3,
    my_CONVERTING_ERROR = 1,
    my_CALCULATION_ERROR = 1,
    my_SUCCESS = 0,
    my_TRUE = 1,
    my_FALSE = 0,
} my_status_code;

typedef enum {
    my_plus = 0,
    my_minus = 1
} my_sign;

typedef struct {
    unsigned int bits[SIZE_DECIMAL];
} my_decimal;

typedef struct {
    unsigned int bits[SIZE_SUPER_DECIMAL];
} my_super_decimal;

//  Arithmetic operators
int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_mod(my_decimal value_1, my_decimal value_2, my_decimal *result);
//  0 - OK, 1 - INF, 2 - NEG_INF, 3 - DIV BY ZERO

//  Comparison operators
int my_is_less(my_decimal value_1, my_decimal value_2);
int my_is_less_or_equal(my_decimal value_1, my_decimal value_2);
int my_is_greater(my_decimal value_1, my_decimal value_2);
int my_is_greater_or_equal(my_decimal value_1, my_decimal value_2);
int my_is_equal(my_decimal value_1, my_decimal value_2);
int my_is_not_equal(my_decimal value_1, my_decimal value_2);
//  1 - TRUE, 0 - FALSE

//  Convertors
int my_from_int_to_decimal(int src, my_decimal *dst);  //  From int
int my_from_float_to_decimal(float src, my_decimal *dst);  //  From float
int my_from_decimal_to_int(my_decimal src, int *dst);  //  To int
int my_from_decimal_to_float(my_decimal src, float *dst);  //  To float
//  0 - SUCCESS, 1 - CONVERTING ERROR

//  Another functions
int my_floor(my_decimal value, my_decimal *result);
int my_round(my_decimal value, my_decimal *result);
int my_truncate(my_decimal value, my_decimal *result);
int my_negate(my_decimal number, my_decimal *result);
//  0 - OK, 1 - CALCULATION ERROR

// Common functions

//  my_decimal function
void my_decimal_initialization(my_decimal *number);
my_decimal my_from_super_decimal_to_decimal(my_super_decimal value, my_status_code *status);
void my_set_sign(my_decimal *value, bit sign);
bit my_get_sign(my_decimal value);
my_decimal my_shift_left(my_decimal value, int shift);
my_decimal my_shift_right(my_decimal value, int shift);
void my_set_scale(my_decimal *value, scale scale_value);
scale my_get_scale(my_decimal value);
void my_set_bit(my_decimal *value, int index, bit value_bit);
bit my_get_bit(my_decimal value, int index);
my_decimal my_div_10(my_decimal value);
int my_mod_div_10(my_decimal value);
bool my_is_zero(my_decimal value);
int my_get_float_scale(float src);
bit my_get_bit_float(float source, int index);
my_decimal my_mul_10(my_decimal value);

//  my_super_decimal function
void my_super_decimal_initialization(my_super_decimal *number);
my_super_decimal my_from_decimal_to_super_decimal(my_decimal value);
my_super_decimal my_add_super_decimal(my_super_decimal value_1, my_super_decimal value_2);
void my_set_scale_super(my_super_decimal *value, scale scale_value);
scale my_get_scale_super(my_super_decimal value);
void my_set_sign_super(my_super_decimal *value, bit sign);
bit my_get_sign_super(my_super_decimal value);
void my_set_bit_super(my_super_decimal *value, int index, bit value_bit);
bit my_get_bit_super(my_super_decimal value, int index);
bool my_check_entry_super(my_super_decimal value);
void my_equalize_scale(my_super_decimal *value_1, my_super_decimal *value_2);
my_super_decimal my_increase_super_decimal(my_super_decimal value, scale difference);
my_super_decimal my_mul_10_super(my_super_decimal result);
my_super_decimal my_shift_left_super(my_super_decimal value, int shift);
my_super_decimal my_shift_right_super(my_super_decimal value, int shift);
bool my_is_equal_super(my_super_decimal value_1, my_super_decimal value_2);
bool my_is_greater_super(my_super_decimal value_1, my_super_decimal value_2);
my_super_decimal my_sub_super(my_super_decimal value_1, my_super_decimal value_2);
int my_mod_div_10_super(my_super_decimal value);
my_super_decimal my_div_10_super(my_super_decimal value);
my_super_decimal my_mod_div_2_super(my_super_decimal value_1, my_super_decimal value_2);
bool my_is_zero_super(my_super_decimal value);
my_super_decimal my_div_super(my_super_decimal value_1, my_super_decimal value_2);
my_super_decimal my_mod_super(my_super_decimal value_1, my_super_decimal value_2);

#endif  //  SRC_MY_DECIMAL_H_
