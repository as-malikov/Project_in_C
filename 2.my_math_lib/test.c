#include <check.h>
#include <math.h>
#include "my_math.h"
#include <stdlib.h>
#include <stdio.h>

START_TEST(test_abs) {
    int test1num_def = -100;
    int test1num_my = -100;
    ck_assert_int_eq(labs(test1num_def), my_abs(test1num_my));
    int test2num_def = 450;
    int test2num_my = 450;
    ck_assert_int_eq(labs(test2num_def), my_abs(test2num_my));
    int test3num_def = 0;
    int test3num_my = 0;
    ck_assert_int_eq(labs(test3num_def), my_abs(test3num_my));
}
END_TEST

START_TEST(test_fabs) {
    double test1num_def = -134.12398484;
    double test1num_my = -134.12398484;
    ck_assert_ldouble_eq(fabsl(test1num_def), my_fabs(test1num_my));
    double test2num_def = 450.00000000;
    double test2num_my = 450.00000000;
    ck_assert_ldouble_eq(fabsl(test2num_def), my_fabs(test2num_my));
    double test3num_def = 0.0;
    double test3num_my = 0.0;
    ck_assert_ldouble_eq(fabsl(test3num_def), my_fabs(test3num_my));
    ck_assert_ldouble_nan(my_fabs(my_NAN * -1));
}
END_TEST

START_TEST(test_fmod) {
    double test1num = 9.2;
    double test1del = 2;
    ck_assert_ldouble_eq(fmodl(test1num, test1del), my_fmod(test1num, test1del));
    double test2num = -13.23;
    double test2del = 2.87;
    ck_assert_ldouble_eq_tol(fmodl(test2num, test2del), my_fmod(test2num, test2del), 1e-6);
    double test3num = 123.3124124;
    double test3del = 0;
    ck_assert_ldouble_nan(my_fmod(test3num, test3del));
    double test4num = 0;
    double test4del = 3.12355;
    ck_assert_ldouble_eq(fmod(test4num, test4del), my_fmod(test4num, test4del));
}
END_TEST

START_TEST(test_exp) {
    double test1num = 9.2;
    ck_assert_ldouble_eq_tol(expl(test1num), my_exp(test1num), 1e-6);
    double test2num = -13.23;
    ck_assert_ldouble_eq_tol(expl(test2num), my_exp(test2num), 1e-6);
    double test3num = 0;
    ck_assert_ldouble_eq_tol(expl(test3num), my_exp(test3num), 1e-6);
    ck_assert_int_eq(0, my_exp(-INFINITY));
    float test4num = 999999.9999;
    ck_assert_ldouble_infinite(my_exp(test4num));
}
END_TEST

START_TEST(test_ceil) {
    float test1num = 9.2;
    ck_assert_ldouble_eq(ceil(test1num), my_ceil(test1num));
    float test2num = -13.23;
    ck_assert_ldouble_eq(ceil(test2num), my_ceil(test2num));
    float test3num = 0.0;
    ck_assert_ldouble_eq(ceil(test3num), my_ceil(test3num));
    float test4num = 132.00001;
    ck_assert_ldouble_eq(ceil(test4num), my_ceil(test4num));
    float test5num = 0.000000000000000000001;
    ck_assert_ldouble_eq(ceil(test5num), my_ceil(test5num));
}
END_TEST

START_TEST(test_floor) {
    float test1num = 9.2;
    ck_assert_ldouble_eq(floor(test1num), my_floor(test1num));
    float test2num = -13.23;
    ck_assert_ldouble_eq(floor(test2num), my_floor(test2num));
    float test3num = 0.0;
    ck_assert_ldouble_eq(floor(test3num), my_floor(test3num));
    float test4num = 132.00001;
    ck_assert_ldouble_eq(floor(test4num), my_floor(test4num));
    float test5num = 0.000000000000000000001;
    ck_assert_ldouble_eq(floor(test5num), my_floor(test5num));
}
END_TEST

START_TEST(test_pow) {
    double test1num1 = 5.3;
    double test1num2 = 2.4;
    ck_assert_ldouble_eq_tol(powl(test1num1, test1num2), my_pow(test1num1, test1num2), 1e-6);
    double test2num1 = -5;
    double test2num2 = 4;
    ck_assert_ldouble_eq_tol(powl(test2num1, test2num2), my_pow(test2num1, test2num2), 1e-6);
    double test3num1 = 0;
    double test3num2 = 0;
    ck_assert_ldouble_eq_tol(powl(test3num1, test3num2), my_pow(test3num1, test3num2), 1e-6);
    double test4num1 = 5;
    double test4num2 = -4;
    ck_assert_ldouble_eq_tol(powl(test4num1, test4num2), my_pow(test4num1, test4num2), 1e-6);
    double test5num1 = -5.5;
    double test5num2 = -2.4;
    ck_assert_ldouble_nan(my_pow(test5num1, test5num2));
    double test6num1 = 123;
    double test6num2 = my_INFINITY * -1;
    ck_assert_ldouble_eq_tol(my_pow(test6num1, test6num2), powl(test6num1, test6num2), 1e-6);
}
END_TEST

START_TEST(test_sqrt) {
    ck_assert_double_nan(my_sqrt(-100));
    ck_assert_ldouble_eq_tol(my_sqrt(450), sqrt(450), 1e-6);
    ck_assert_ldouble_eq_tol(my_sqrt(0), sqrt(0), 1e-6);
    ck_assert_ldouble_eq_tol(my_sqrt(0.999999), sqrt(0.999999), 1e-6);
    ck_assert_ldouble_eq_tol(my_sqrt(9999999999.999999), sqrt(9999999999.999999), 1e-7);
    ck_assert_ldouble_infinite(my_sqrt(my_INFINITY));
    ck_assert_double_nan(my_sqrt(my_INFINITY * -1) * -1);
    ck_assert_double_nan(my_sqrt(my_NAN * -1) * -1);
}
END_TEST

START_TEST(test_sin) {
    long double test1num = -100;;
    ck_assert_ldouble_eq_tol(my_sin(test1num), sinl(test1num), 1e-6);
    long double test2num = 450;
    ck_assert_ldouble_eq_tol(my_sin(test2num), sinl(test2num), 1e-6);
    long double test3num = 0;
    ck_assert_ldouble_eq_tol(my_sin(test3num), sinl(test3num), 1e-6);
    long double test5num = my_INFINITY;
    ck_assert_ldouble_nan(my_sin(test5num) * -1);
    long double test6num = my_INFINITY * -1;
    ck_assert_ldouble_nan(my_sin(test6num) * -1);
    long double test7num = my_NAN;
    ck_assert_ldouble_nan(my_sin(test7num) * -1);
    long double test8num = my_NAN * -1;
    ck_assert_ldouble_nan(my_sin(test8num));
    long double test9num = -9999999999.999999;
    ck_assert_ldouble_eq_tol(my_sin(test9num), sinl(test9num), 1e-6);
    long double test10num = 9999999999.999999;
    ck_assert_ldouble_eq_tol(my_sin(test10num), sinl(test10num), 1e-6);
    long double test11num = 0.999999;
    ck_assert_ldouble_eq_tol(my_sin(test11num), sinl(test11num), 1e-6);
}
END_TEST

START_TEST(test_tan) {
    long double test1num = -100;
    ck_assert_ldouble_eq_tol(my_tan(test1num), tanl(test1num), 1e-6);
    long double test2num = 450;
    ck_assert_ldouble_eq_tol(my_tan(test2num), tanl(test2num), 1e-6);
    long double test3num = 0;
    ck_assert_ldouble_eq_tol(my_tan(test3num), tanl(test3num), 1e-6);
    long double test4num = my_INFINITY;
    ck_assert_ldouble_nan(my_tan(test4num));
    long double test5num = my_INFINITY * -1;
    ck_assert_ldouble_nan(my_tan(test5num));
    long double test6num = my_NAN;
    ck_assert_ldouble_nan(my_tan(test6num));
    long double test7num = my_NAN * -1;
    ck_assert_ldouble_nan(my_tan(test7num));
    long double test8num = -999999999.999999;
    ck_assert_ldouble_eq_tol(my_tan(test8num), tanl(test8num), 1e-6);
    long double test9num = 999999999.999999;
    ck_assert_ldouble_eq_tol(my_tan(test9num), tanl(test9num), 1e-6);
    long double test10num = 0.999999;
    ck_assert_ldouble_eq_tol(my_tan(test10num), tanl(test10num), 1e-6);
}
END_TEST

START_TEST(test_log) {
    ck_assert_double_nan(my_log(-100));
    ck_assert_ldouble_eq_tol(my_log(450), log(450), 1e-6);
    ck_assert_ldouble_infinite(my_log(0) * -1);
    ck_assert_ldouble_eq_tol(my_log(0.999999), log(0.999999), 1e-6);
    ck_assert_ldouble_eq_tol(my_log(9999999999.999999), log(9999999999.999999), 1e-7);
    ck_assert_ldouble_infinite(my_log(my_INFINITY));
    ck_assert_double_nan(my_log(my_INFINITY * -1) * -1);
    ck_assert_double_nan(my_log(my_NAN * -1) * -1);
}
END_TEST

START_TEST(test_cos) {
    long double test1num = -1/0.0;
    ck_assert_ldouble_nan(my_cos(test1num)* (-1));
    long double test2num = 999;
    ck_assert_ldouble_eq_tol(my_cos(test2num), cosl(test2num), 1e-6);
    long double test3num = -7;
    ck_assert_ldouble_eq_tol(my_cos(test3num), cosl(test3num), 1e-6);
    long double test4num = -4;
    ck_assert_ldouble_eq_tol(my_cos(test4num), cosl(test4num), 1e-6);
    long double test5num = (-1) * my_PI;
    ck_assert_ldouble_eq_tol(my_cos(test5num), cosl(test5num), 1e-6);
    long double test6num = 0;
    ck_assert_ldouble_eq_tol(my_cos(test6num), cosl(test6num), 1e-6);
    long double test7num = my_PI;
    ck_assert_ldouble_eq_tol(my_cos(test7num), cosl(test7num), 1e-6);
    long double test8num = 4;
    ck_assert_ldouble_eq_tol(my_cos(test8num), cosl(test8num), 1e-6);
    long double test9num = 7;
    ck_assert_ldouble_eq_tol(my_cos(test9num), cosl(test9num), 1e-6);
    long double test10num = 999;
    ck_assert_ldouble_eq_tol(my_cos(test10num), cosl(test10num), 1e-6);
    long double test11num = my_NAN;
    ck_assert_ldouble_nan(my_cos(test11num)* (-1));
    long double test12num = my_NAN;
    ck_assert_ldouble_nan(my_cos(test12num));
    long double test13num = (-1) * my_NAN;
    ck_assert_ldouble_nan(my_cos(test13num) * (-1));;
}
END_TEST

START_TEST(test_acos) {
    long double test1num = -1/0.0;
    ck_assert_ldouble_nan(my_acos(test1num));
    long double test2num = -999;
    ck_assert_ldouble_nan(my_acos(test2num));
    long double test3num = -1;
    ck_assert_ldouble_eq_tol(my_acos(test3num), acosl(test3num), 1e-6);
    long double test4num = -0.7;
    ck_assert_ldouble_eq_tol(my_acos(test4num), acosl(test4num), 1e-6);
    long double test5num = -0.2;
    ck_assert_ldouble_eq_tol(my_acos(test5num), acosl(test5num), 1e-6);
    long double test6num = 0;
    ck_assert_ldouble_eq_tol(my_acos(test6num), acosl(test6num), 1e-6);
    long double test7num = 0.2;
    ck_assert_ldouble_eq_tol(my_acos(test7num), acosl(test7num), 1e-6);
    long double test8num = 0.2;
    ck_assert_ldouble_eq_tol(my_acos(test8num), acosl(test8num), 1e-6);
    long double test9num = 0.7;
    ck_assert_ldouble_eq_tol(my_acos(test9num), acosl(test9num), 1e-6);
    long double test10num = 1;
    ck_assert_ldouble_eq_tol(my_acos(test10num), acosl(test10num), 1e-6);
    long double test11num = 1/0.0;
    ck_assert_ldouble_nan(my_acos(test11num));
    long double test12num = my_NAN;
    ck_assert_ldouble_nan(my_acos(test12num));
    long double test13num = (-1) * my_NAN;
    ck_assert_ldouble_nan(my_acos(test13num) * (-1));;
}
END_TEST

START_TEST(test_asin) {
    long double test1num = -1/0.0;
    ck_assert_ldouble_nan(my_asin(test1num));
    long double test2num = -999;
    ck_assert_ldouble_nan(my_asin(test2num));
    long double test3num = -1;
    ck_assert_ldouble_eq_tol(my_asin(test3num), asinl(test3num), 1e-6);
    long double test4num = -0.7;
    ck_assert_ldouble_eq_tol(my_asin(test4num), asinl(test4num), 1e-6);
    long double test5num = -0.2;
    ck_assert_ldouble_eq_tol(my_asin(test5num), asinl(test5num), 1e-6);
    long double test6num = 0;
    ck_assert_ldouble_eq_tol(my_asin(test6num), asinl(test6num), 1e-6);
    long double test7num = 0.2;
    ck_assert_ldouble_eq_tol(my_asin(test7num), asinl(test7num), 1e-6);
    long double test8num = 0.2;
    ck_assert_ldouble_eq_tol(my_asin(test8num), asinl(test8num), 1e-6);
    long double test9num = 0.7;
    ck_assert_ldouble_eq_tol(my_asin(test9num), asinl(test9num), 1e-6);
    long double test10num = 1;
    ck_assert_ldouble_eq_tol(my_asin(test10num), asinl(test10num), 1e-6);
    long double test11num = 1/0.0;
    ck_assert_ldouble_nan(my_asin(test11num));
    long double test12num = my_NAN;
    ck_assert_ldouble_nan(my_asin(test12num));
    long double test13num = (-1) * my_NAN;
    ck_assert_ldouble_nan(my_asin(test13num) * (-1));;
}
END_TEST

START_TEST(test_atan) {
    long double test1num = -1/0.0;
    ck_assert_ldouble_eq_tol(my_atan(test1num), atanl(test1num), 1e-6);
    long double test2num = -999;
    ck_assert_ldouble_eq_tol(my_atan(test2num), atanl(test2num), 1e-6);
    long double test3num = -1;
    ck_assert_ldouble_eq_tol(my_atan(test3num), atanl(test3num), 1e-6);
    long double test4num = -0.7;
    ck_assert_ldouble_eq_tol(my_atan(test4num), atanl(test4num), 1e-6);
    long double test5num = -0.2;
    ck_assert_ldouble_eq_tol(my_atan(test5num), atanl(test5num), 1e-6);
    long double test6num = 0;
    ck_assert_ldouble_eq_tol(my_atan(test6num), atanl(test6num), 1e-6);
    long double test7num = 0.2;
    ck_assert_ldouble_eq_tol(my_atan(test7num), atanl(test7num), 1e-6);
    long double test8num = 0.2;
    ck_assert_ldouble_eq_tol(my_atan(test8num), atanl(test8num), 1e-6);
    long double test9num = 0.7;
    ck_assert_ldouble_eq_tol(my_atan(test9num), atanl(test9num), 1e-6);
    long double test10num = 1;
    ck_assert_ldouble_eq_tol(my_atan(test10num), atanl(test10num), 1e-6);
    long double test11num = 1/0.0;
    ck_assert_ldouble_eq_tol(my_atan(test11num), atanl(test11num), 1e-6);
    long double test12num = my_NAN;
    ck_assert_ldouble_nan(my_atan(test12num));
    long double test13num = (-1) * my_NAN;
    ck_assert_ldouble_nan(my_atan(test13num) * (-1));;
}
END_TEST

Suite *math_test_suite(void) {
    Suite *suite = suite_create("Test of math");
    TCase  *tcase_core = tcase_create("Core of math");
    tcase_add_test(tcase_core, test_abs);
    tcase_add_test(tcase_core, test_fabs);
    tcase_add_test(tcase_core, test_fmod);
    tcase_add_test(tcase_core, test_exp);
    tcase_add_test(tcase_core, test_ceil);
    tcase_add_test(tcase_core, test_floor);
    tcase_add_test(tcase_core, test_pow);
    tcase_add_test(tcase_core, test_sqrt);
    tcase_add_test(tcase_core, test_sin);
    tcase_add_test(tcase_core, test_tan);
    tcase_add_test(tcase_core, test_log);
    suite_add_tcase(suite, tcase_core);
    tcase_add_test(tcase_core, test_cos);
    tcase_add_test(tcase_core, test_asin);
    tcase_add_test(tcase_core, test_atan);
    tcase_add_test(tcase_core, test_acos);
    return suite;
}

int main(void) {
    Suite *suite = math_test_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_VERBOSE);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return failed_count !=0 ? 1 : 0;
}
