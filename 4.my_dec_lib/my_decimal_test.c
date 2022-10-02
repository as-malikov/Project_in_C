#include "my_decimal_test.h"

void compairs(my_decimal value_1, my_decimal value_2) {
    for (int index = LOW; index < SCALE; index++) {
        ck_assert_int_eq(value_1.bits[index], value_2.bits[index]);
    }
}

//  Arithmetic operators
START_TEST(my_add_test) {
    my_decimal result;
    my_status_code status = my_add(tc_add_number[_i].value_1,
                                     tc_add_number[_i].value_2, &result);
    compairs(tc_add_number[_i].result, result);
    ck_assert_int_eq(tc_add_number[_i].status, status);
}
END_TEST

START_TEST(my_sub_test) {
    my_decimal result;
    my_status_code status = my_sub(tc_sub_number[_i].value_1,
                                    tc_sub_number[_i].value_2, &result);
    compairs(tc_sub_number[_i].result, result);
    ck_assert_int_eq(tc_sub_number[_i].status, status);
}
END_TEST

START_TEST(my_mul_test) {
    my_decimal result;
    my_status_code status = my_mul(tc_mul_number[_i].value_1,
                                    tc_mul_number[_i].value_2, &result);
    compairs(tc_mul_number[_i].result, result);
    ck_assert_int_eq(tc_mul_number[_i].status, status);
}
END_TEST

START_TEST(my_div_test) {
    my_decimal result;
    my_status_code status = my_div(tc_div_number[_i].value_1,
                                    tc_div_number[_i].value_2, &result);
    compairs(tc_div_number[_i].result, result);
    ck_assert_int_eq(tc_div_number[_i].status, status);
}
END_TEST

START_TEST(my_mod_test) {
    my_decimal result;
    my_status_code status = my_mod(tc_mod_number[_i].value_1,
                                    tc_mod_number[_i].value_2, &result);
    compairs(tc_mod_number[_i].result, result);
    ck_assert_int_eq(tc_mod_number[_i].status, status);
}
END_TEST

//  Comparison operators
START_TEST(my_is_less_test) {
    my_status_code status = my_is_less(tc_is_less_number[_i].value_1,
                                        tc_is_less_number[_i].value_2);
    ck_assert_int_eq(tc_is_less_number[_i].status, status);
}
END_TEST

START_TEST(my_is_less_or_equal_test) {
    my_status_code status = my_is_less_or_equal(tc_is_less_or_equal_number[_i].value_1,
                                                 tc_is_less_or_equal_number[_i].value_2);
    ck_assert_int_eq(tc_is_less_or_equal_number[_i].status, status);
}
END_TEST

START_TEST(my_is_greater_test) {
    my_status_code status = my_is_greater(tc_is_greater_number[_i].value_1,
                                           tc_is_greater_number[_i].value_2);
    ck_assert_int_eq(tc_is_greater_number[_i].status, status);
}
END_TEST

START_TEST(my_is_greater_or_equal_test) {
    my_status_code status = my_is_greater_or_equal(tc_is_greater_or_equal_number[_i].value_1,
                                                    tc_is_greater_or_equal_number[_i].value_2);
    ck_assert_int_eq(tc_is_greater_or_equal_number[_i].status, status);
}
END_TEST

START_TEST(my_is_equal_test) {
    my_status_code status = my_is_equal(tc_is_equal_number[_i].value_1,
                                         tc_is_equal_number[_i].value_2);
    ck_assert_int_eq(tc_is_equal_number[_i].status, status);
}
END_TEST

START_TEST(my_is_not_equal_test) {
    my_status_code status = my_is_not_equal(tc_is_not_equal_number[_i].value_1,
                                             tc_is_not_equal_number[_i].value_2);
    ck_assert_int_eq(tc_is_not_equal_number[_i].status, status);
}
END_TEST

//  Convertors
START_TEST(my_from_int_to_decimal_test) {
    my_decimal result;
    my_status_code status = my_from_int_to_decimal(tc_int_decimal[_i].int_value, &result);
    compairs(tc_int_decimal[_i].decimal_value, result);
    ck_assert_int_eq(status, tc_int_decimal[_i].status);
}
END_TEST

START_TEST(my_from_float_to_decimal_test) {
    my_decimal result;
    my_status_code status = my_from_float_to_decimal(tc_float_decimal[_i].float_value, &result);
    compairs(tc_float_decimal[_i].decimal_value, result);
    ck_assert_int_eq(tc_float_decimal[_i].status, status);
}
END_TEST

START_TEST(my_from_decimal_to_int_test) {
    int origin = tc_int_decimal[_i].int_value;
    int result = 0;
    my_status_code status = my_from_decimal_to_int(tc_int_decimal[_i].decimal_value, &result);
    ck_assert_int_eq(status, tc_int_decimal[_i].status);
    ck_assert_int_eq(origin, result);
}
END_TEST

START_TEST(my_from_decimal_to_float_test) {
    float result;
    my_status_code status = my_from_decimal_to_float(tc_float_decimal[_i].decimal_value, &result);
    ck_assert_int_eq(tc_float_decimal[_i].float_value, result);
    ck_assert_int_eq(tc_float_decimal[_i].status, status);
}
END_TEST

//  Another functions
START_TEST(my_floor_test) {
    my_decimal result;
    my_status_code status = my_floor(tc_floor_number[_i].value, &result);
    compairs(tc_floor_number[_i].result, result);
    ck_assert_int_eq(tc_floor_number[_i].status, status);
}
END_TEST

START_TEST(my_round_test) {
    my_decimal result;
    my_status_code status = my_round(tc_round_number[_i].value, &result);
    compairs(tc_round_number[_i].result, result);
    ck_assert_int_eq(tc_round_number[_i].status, status);
}
END_TEST

START_TEST(my_truncate_test) {
    my_decimal result;
    my_status_code status = my_truncate(tc_truncate_number[_i].value, &result);
    compairs(tc_truncate_number[_i].result, result);
    ck_assert_int_eq(tc_truncate_number[_i].status, status);
}
END_TEST

START_TEST(my_negate_test) {
    my_decimal result;
    my_status_code status = my_negate(tc_negate_number[_i].value, &result);
    compairs(tc_negate_number[_i].result, result);
    ck_assert_int_eq(tc_negate_number[_i].status, status);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("my_decimal");
    SRunner *sr = srunner_create(s1);
    int nf;
    TCase *tc1_1 = tcase_create("my_add");
    tcase_add_loop_test(tc1_1, my_add_test, 0,
        sizeof(tc_add_number) / sizeof(tc_add_number[0]));
    suite_add_tcase(s1, tc1_1);
    TCase *tc2_1 = tcase_create("my_sub");
    tcase_add_loop_test(tc2_1, my_sub_test, 0,
        sizeof(tc_sub_number) / sizeof(tc_sub_number[0]));
    suite_add_tcase(s1, tc2_1);
    TCase *tc3_1 = tcase_create("my_mul");
    tcase_add_loop_test(tc3_1, my_mul_test, 0,
        sizeof(tc_mul_number) / sizeof(tc_mul_number[0]));
    suite_add_tcase(s1, tc3_1);
    TCase *tc4_1 = tcase_create("my_div");
    tcase_add_loop_test(tc4_1, my_div_test, 0,
                       sizeof(tc_div_number) / sizeof(tc_div_number[0]));
    suite_add_tcase(s1, tc4_1);
    TCase *tc5_1 = tcase_create("my_mod");
    tcase_add_loop_test(tc5_1, my_mod_test, 0,
       sizeof(tc_mod_number) / sizeof(tc_mod_number[0]));
    suite_add_tcase(s1, tc5_1);
    TCase *tc6_1 = tcase_create("my_is_less");
    tcase_add_loop_test(tc6_1, my_is_less_test, 0,
       sizeof(tc_is_less_number) / sizeof(tc_is_less_number[0]));
    suite_add_tcase(s1, tc6_1);
    TCase *tc7_1 = tcase_create("my_is_less_or_equal");
    tcase_add_loop_test(tc7_1, my_is_less_or_equal_test, 0,
       sizeof(tc_is_less_or_equal_number) / sizeof(tc_is_less_or_equal_number[0]));
    suite_add_tcase(s1, tc7_1);
    TCase *tc8_1 = tcase_create("my_is_greater");
    tcase_add_loop_test(tc8_1, my_is_greater_test, 0,
       sizeof(tc_is_greater_number) / sizeof(tc_is_greater_number[0]));
    suite_add_tcase(s1, tc8_1);
    TCase *tc9_1 = tcase_create("my_is_greater_or_equal");
    tcase_add_loop_test(tc9_1, my_is_greater_or_equal_test, 0,
       sizeof(tc_is_greater_or_equal_number) / sizeof(tc_is_greater_or_equal_number[0]));
    suite_add_tcase(s1, tc9_1);
    TCase *tc10_1 = tcase_create("my_is_equal");
    tcase_add_loop_test(tc10_1, my_is_equal_test, 0,
       sizeof(tc_is_equal_number) / sizeof(tc_is_equal_number[0]));
    suite_add_tcase(s1, tc10_1);
    TCase *tc11_1 = tcase_create("my_is_not_equal");
    tcase_add_loop_test(tc11_1, my_is_not_equal_test, 0,
       sizeof(tc_is_not_equal_number) / sizeof(tc_is_not_equal_number[0]));
    suite_add_tcase(s1, tc11_1);
    TCase *tc12_1 = tcase_create("my_from_int_to_decimal");
    tcase_add_loop_test(tc12_1, my_from_int_to_decimal_test, 0,
                        (sizeof(tc_int_decimal) / sizeof(tc_int_decimal[0])) - 1);
    suite_add_tcase(s1, tc12_1);
    TCase *tc13_1 = tcase_create("my_from_decimal_to_int");
    tcase_add_loop_test(tc13_1, my_from_decimal_to_int_test, 0,
        sizeof(tc_int_decimal) / sizeof(tc_int_decimal[0]));
    suite_add_tcase(s1, tc13_1);
    TCase *tc14_1 = tcase_create("my_from_float_to_decimal");
    tcase_add_loop_test(tc14_1, my_from_float_to_decimal_test, 0,
                        sizeof(tc_float_decimal) / sizeof(tc_float_decimal[0]));
    suite_add_tcase(s1, tc14_1);
    TCase *tc15_1 = tcase_create("my_from_decimal_to_float");
    tcase_add_loop_test(tc15_1, my_from_decimal_to_float_test, 0,
                        (sizeof(tc_float_decimal) / sizeof(tc_float_decimal[0])) - 5);
    suite_add_tcase(s1, tc15_1);
    TCase *tc16_1 = tcase_create("my_floor");
    tcase_add_loop_test(tc16_1, my_floor_test, 0,
        sizeof(tc_floor_number) / sizeof(tc_floor_number[0]));
    suite_add_tcase(s1, tc16_1);
    TCase *tc17_1 = tcase_create("my_round");
    tcase_add_loop_test(tc17_1, my_round_test, 0,
        sizeof(tc_round_number) / sizeof(tc_round_number[0]));
    suite_add_tcase(s1, tc17_1);
    TCase *tc18_1 = tcase_create("my_truncate");
    tcase_add_loop_test(tc18_1, my_truncate_test, 0,
        sizeof(tc_truncate_number) / sizeof(tc_truncate_number[0]));
    suite_add_tcase(s1, tc18_1);
    TCase *tc19_1 = tcase_create("my_negate");
    tcase_add_loop_test(tc19_1, my_negate_test, 0,
        sizeof(tc_negate_number) / sizeof(tc_negate_number[0]));
    suite_add_tcase(s1, tc19_1);
    srunner_run_all(sr, CK_VERBOSE);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);
    return nf == 0 ? 0 : 1;
}
