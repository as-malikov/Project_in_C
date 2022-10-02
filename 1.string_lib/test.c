#include <string.h>
#include <stdio.h>
#include <check.h>
#include "my_string.h"

START_TEST(test_my_memchr) {
    char test1Standart[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test1my[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    ck_assert_str_eq(memchr(test1Standart, 'E', 10), my_memchr(test1my, 'E', 10));

    char test2Standart[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test2my[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    ck_assert_msg(memchr(test2Standart, '1', 10) == my_memchr(test2my, '1', 10), "Return not NULL");

    char test3Standart[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test3my[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    ck_assert_msg(memchr(test3Standart, 'C', 3) == my_memchr(test3my, 'C', 3), "Return not NULL");
}
END_TEST

START_TEST(test_my_memcmp) {
    char test1Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test1Dest[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    ck_assert_msg(memcmp(test1Str, test1Dest, 15) == 0 && \
    my_memcmp(test1Str, test1Dest, 15) == 0, "The value is not zero.");

    char test2Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test2Dest[40] = "VERTEROTPUSTI";
    ck_assert_int_eq(memcmp(test2Str, test2Dest, 15), my_memcmp(test2Str, test2Dest, 15));

    char test3Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test3Dest[40] = "verterotpusti";
    ck_assert_msg(memcmp(test3Str, test3Dest, 15) <= 0 && \
    my_memcmp(test3Str, test3Dest, 15) <= 0, "Non-negative number");

    char test4Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test4Dest[40] = "DARKPLACECREWTHEBESTTEAM";
    ck_assert_msg(memcmp(test4Str, test4Dest, 40) >= 0 \
    && my_memcmp(test4Str, test4Dest, 40) >= 0, "Not a positive number");
}
END_TEST

START_TEST(test_my_memcpy) {
    char test1Def[80], test1my[80], test1Text[] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    memcpy(test1Def, test1Text, 7);
    my_memcpy(test1my, test1Text, 7);
    ck_assert_str_eq(test1Def, test1my);

    char test2Def[] = "randomnozapolnennayastroka";
    char test2my[] = "randomnozapolnennayastroka";
    char test2Text[] = "DARKPLACECREWTHEBESTTEAM";
    memcpy(test2Def, test2Text, 10);
    my_memcpy(test2my, test2Text, 10);
    ck_assert_str_eq(test2Def, test2my);
}
END_TEST

START_TEST(test_my_memmove) {
    char test1Def[] = "abcd";
    char test1my[] = "abcd";
    char sources1[] = "****";
    ck_assert_str_eq(memmove(test1Def, sources1, 4), my_memmove(test1my, sources1, 4));

    char test2Def[] = "DARKPLACE";
    char test2my[] = "DARKPLACE";
    char sources2[] = "******";
    ck_assert_str_eq(memmove(test2Def, sources2, 6), "******ACE");
    ck_assert_str_eq(my_memmove(test2my, sources2, 6), "******ACE");

    char test3Def[] = "DARKPLACE";
    char test3my[] = "DARKPLACE";
    ck_assert_str_eq(memmove(&test3Def[4], &test3Def[3], 3), my_memmove(&test3my[4], &test3my[3], 3));

    char test4Def[] = "DARK";
    char test4my[] = "DARK";
    char sources3[] = "DARKER";
    ck_assert_str_eq(memmove(test4Def, sources3, 4), my_memmove(test4my, sources3, 4));
}
END_TEST

START_TEST(test_my_memset) {
    unsigned char test1Src1[15] = "DARKPLACE";
    unsigned char test1Src2[15] = "DARKPLACE";
    ck_assert_str_eq(memset(test1Src1, 'V', 10), my_memset(test1Src2, 'V', 10));

    unsigned char test2Src1[25] = "DARKPLACECREWTHEBESTTEAM";
    unsigned char test2Src2[25] = "DARKPLACECREWTHEBESTTEAM";
    ck_assert_str_eq(memset(test2Src1, 'V', 20), my_memset(test2Src2, 'V', 20));
}
END_TEST

START_TEST(test_my_strlen) {
    char test1[11] = "DARKPLACE";
    ck_assert_int_eq(strlen(test1), my_strlen(test1));

    char test2[12] = "";
    ck_assert_int_eq(strlen(test2), my_strlen(test2));

    char test3[12] = "\n";
    ck_assert_int_eq(strlen(test3), my_strlen(test3));
}
END_TEST

START_TEST(test_my_strcat) {
    char sources1[1024] = "DARKPLACECREWTHEBESTTEAM";
    char test1Dst1[1024] = "DARKPLACECREWTHEBES12345";
    char test1Dst2[1024] = "DARKPLACECREWTHEBES12345";
    strcat(test1Dst1, sources1);
    my_strcat(test1Dst2, sources1);
    ck_assert_str_eq(test1Dst1, test1Dst2);

    char sources2[1024] = "DARKPLACECREWTHEBES12345";
    char test2Dst1[1024] = "";
    char test2Dst2[1024] = "";
    strcat(test2Dst1, sources2);
    my_strcat(test2Dst2, sources2);
    ck_assert_str_eq(test2Dst1, test2Dst2);

    char souces3[1024] = "";
    char test3Dst1[1024] = "DARKPLACECREWTHEBES12345";
    char test3Dst2[1024] = "DARKPLACECREWTHEBES12345";
    strcat(test3Dst1, souces3);
    my_strcat(test3Dst2, souces3);
    ck_assert_str_eq(test3Dst1, test3Dst2);
}
END_TEST

START_TEST(test_my_strncat) {
    char test1Src1Def[10] = "BEST";
    char test1App1Def[10] = "DARKPLA";
    char test1Src1my[10] = "BEST";
    char test1Appmy[10] = "DARKPLA";
    strncat(test1Src1Def, test1App1Def, 4);
    my_strncat(test1Src1my, test1Appmy, 4);
    ck_assert_str_eq(test1Src1Def, test1Src1my);

    char test2Src1Def[15] = "BEST";
    char test2App1Def[15] = "DARKPLA";
    char test2Src1my[15] = "BEST";
    char test2Appmy[15] = "DARKPLA";
    strncat(test2Src1Def, test2App1Def, 7);
    my_strncat(test2Src1my, test2Appmy, 7);
    ck_assert_str_eq(test2Src1Def, test2Src1my);
}
END_TEST

START_TEST(test_my_strcmp) {
    char test1Str1[10]="DARK";
    char test1Str2[10]="DARK";
    ck_assert_int_eq(strcmp(test1Str1, test1Str2), my_strcmp(test1Str1, test1Str2));

    char test2Str1[10]="DARK";
    char test2Str2[10]="PLACE";
    ck_assert_int_eq(strcmp(test2Str1, test2Str2), my_strcmp(test2Str1, test2Str2));
    char test3Str1[10]="DARKPlAC";
    char test3Str2[10]="DARKPlAC";
    ck_assert_int_eq(strcmp(test3Str1, test3Str2), my_strcmp(test3Str1, test3Str2));
}
END_TEST

START_TEST(test_my_strcspn) {
    char test1Str[13] = "DARKPLACE";
    char test1Sym[10] = "RKPL";
    ck_assert_int_eq(strcspn(test1Str, test1Sym), my_strcspn(test1Str, test1Sym));

    char test2Str[13] = "DARKPLACE";
    char test2Sym[10] = "BFGJ";
    ck_assert_int_eq(strcspn(test2Str, test2Sym), my_strcspn(test2Str, test2Sym));

    char test3Str[13] = "DARKPLACE";
    char test3Sym[10] = "DARKPLACE";
    ck_assert_int_eq(strcspn(test3Str, test3Sym), my_strcspn(test3Str, test3Sym));

    char test4Str[13] = "DARKPLACE";
    char test4Sym[10] = "";
    ck_assert_int_eq(strcspn(test4Str, test4Sym), my_strcspn(test4Str, test4Sym));

    char test5Str[13] = "";
    char test5Sym[10] = "DARKPLACE";
    ck_assert_int_eq(strcspn(test5Str, test5Sym), my_strcspn(test5Str, test5Sym));

    char test6Str[13] = "";
    char test6Sym[10] = "";
    ck_assert_int_eq(strcspn(test6Str, test6Sym), my_strcspn(test6Str, test6Sym));
}
END_TEST

START_TEST(test_my_strpbrk) {
    char string[100] = "DARK1 PLACE2 CREW3 THE4 BEST5 TEAM6 FOREVER\n";
    char *test1Result = NULL;
    char *test1Result1 = NULL;;
    test1Result = strpbrk(string, "0123456");
    test1Result1 = my_strpbrk(string, "0123456");
    ck_assert_str_eq(test1Result, test1Result1);

    test1Result = strpbrk(test1Result, "0123456");
    test1Result1 = my_strpbrk(test1Result1, "0123456");
    ck_assert_str_eq(test1Result, test1Result1);

    test1Result = strpbrk(test1Result, "0123456");
    test1Result1 = my_strpbrk(test1Result1, "0123456");
    ck_assert_str_eq(test1Result, test1Result1);

    test1Result = strpbrk(test1Result, "7");
    test1Result1 = my_strpbrk(test1Result1, "7");
    ck_assert_msg(test1Result == NULL && test1Result1 == NULL, "Return not NULL");
}
END_TEST

START_TEST(test_my_strspn) {
    char string[] = "DARKPLACECREWTHEBESTTEAM";
    ck_assert_int_eq(strspn(string, "PLACE"), my_strspn(string, "PLACE"));
    ck_assert_int_eq(strspn(string, "TTEA"), my_strspn(string, "TTEA"));
    ck_assert_int_eq(strspn(string, "VERTER"), my_strspn(string, "VERTER"));
}
END_TEST

START_TEST(test_my_strchr) {
    char test1Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    int test1Ch = 'W';
    char *test1Def = NULL;
    char *test1my = NULL;
    test1Def = strchr(test1Str, test1Ch);
    test1my = my_strchr(test1Str, test1Ch);
    ck_assert_str_eq(test1Def, test1my);

    char test2Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    int test2Ch = 'J';
    char *test2Def = NULL;
    char *test2my = NULL;
    test2Def = strchr(test2Str, test2Ch);
    test2my = my_strchr(test2Str, test2Ch);
    ck_assert(test2Def == test2my);
}
END_TEST

START_TEST(test_my_strcpy) {
    char test1Src[1024] = "DARKPLACECREWTHE\0BESTTEAMFOREVER";
    char test1Def[1024] = "";
    char test1my[1024] = "";
    ck_assert_str_eq(strcpy(test1Def, test1Src), my_strcpy(test1my, test1Src));

    char test2Src[1024] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test2Def[1024] = "";
    char testmy[1024] = "";
    ck_assert_str_eq(strcpy(test2Def, test2Src), my_strcpy(testmy, test2Src));

    char test3Src[1024] = "\0DARKPLACECREWTHEBESTTEAMFOREVER";
    char test3Def[1024] = "";
    char test3my[1024] = "";
    ck_assert_str_eq(strcpy(test3Def, test3Src), my_strcpy(test3my, test3Src));
}
END_TEST

START_TEST(test_my_strncpy) {
    char sources[] = "DARKPLACECREWTH\0EBESTTEAMFOREVER";
    char test1Def[] = "VERTEROTPUTI";
    char test1my[] = "VERTEROTPUTI";
    char test2Def[] = "VERTEROTPUTI";
    char test2my[] = "VERTEROTPUTI";
    strncpy(test1Def, sources, 5);
    my_strncpy(test1my, sources, 5);
    ck_assert_str_eq(test1Def, test1my);
    ck_assert_str_eq(strncpy(test2Def, sources, 10), my_strncpy(test2my, sources, 10));
}
END_TEST

START_TEST(test_my_strstr) {
    char test1Str1[] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test1Str2[] = "BEST";
    char *result1Def = strstr(test1Str1, test1Str2);
    char *result1my = my_strstr(test1Str1, test1Str2);
    ck_assert_str_eq(result1Def, result1my);
    char test2Str1[] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test2Str2[] = "VERTER";
    char *result2Def = strstr(test2Str1, test2Str2);
    char *result2my = my_strstr(test2Str1, test2Str2);
    ck_assert_msg(result2Def == result2my, "Return not NULL");
}
END_TEST

START_TEST(test_my_strrchr) {
    char test1Str[] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    int test1Ch = 'M';
    char *result1Def = NULL;
    char *result1my = NULL;
    result1Def = strrchr(test1Str, test1Ch);
    result1my = my_strrchr(test1Str, test1Ch);
    ck_assert_str_eq(result1Def, result1my);

    char test2Str[] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    int test2Ch = 'U';
    char *result2Def = NULL;
    char *result2my = NULL;
    result2Def = strrchr(test2Str, test2Ch);
    result2my = my_strrchr(test2Str, test2Ch);
    ck_assert(result2Def == result2my);
}
END_TEST

START_TEST(test_my_strncmp) {
    char test1Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test1Str2[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    ck_assert_int_eq(strncmp(test1Str, test1Str2, 5), my_strncmp(test1Str, test1Str2, 5));

    char test2Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test2Str2[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    ck_assert_int_eq(strncmp(test2Str, test2Str2, 15), my_strncmp(test2Str, test2Str2, 15));

    char test3Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVERVERTER";
    char test3Str1[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    ck_assert_int_eq(strncmp(test3Str, test3Str1, 25), my_strncmp(test3Str, test3Str1, 25));

    char test4Str[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
    char test4Str1[40] = "DARKPLACECREWTHEBESTTEAMFOREVERVERTER";
    ck_assert_int_eq(strncmp(test4Str, test4Str1, 25), my_strncmp(test4Str, test4Str1, 25));
}
END_TEST

START_TEST(test_my_strtok) {
    char test1Def[] = "DARK.PLACE.CREW.THE.BEST.TEAM.FOREVER";
    char test1my[] = "DARK.PLACE.CREW.THE.BEST.TEAM.FOREVER";
    char sep1[] = ".";
    char *result1Def = NULL;
    char *result1my = NULL;
    result1Def = strtok(test1Def, sep1);
    result1my = my_strtok(test1my, sep1);
    ck_assert(result1Def != NULL && result1my != NULL);
    while (result1Def != NULL && result1my != NULL) {
        ck_assert_str_eq(result1Def, result1my);
        result1Def = strtok(NULL, sep1);
        result1my = my_strtok(NULL, sep1);
    }

    char *test2def = NULL;
    char *test2my = NULL;
    char sep2[] = ".";
    char *result2Def = NULL;
    char *result2my = NULL;
    result2Def = strtok(test2def, sep2);
    result2my = my_strtok(test2my, sep2);
    ck_assert(result2Def == NULL && result2my == NULL);

    char test3Def[] = "DARK.PLACE.CREW.THE.BEST.TEAM.FOREVER";
    char test3my[] = "DARK.PLACE.CREW.THE.BEST.TEAM.FOREVER";
    char sep3[] = "";
    char *result3Def = NULL;
    char *result3my = NULL;
    result3Def = strtok(test3Def, sep3);
    result3my = my_strtok(test3my, sep3);
    ck_assert(result3Def != NULL && result3my != NULL);
    while (result3Def != NULL && result3my != NULL) {
        ck_assert_str_eq(result3Def, result3my);
        result3Def = strtok(NULL, sep3);
        result3my = my_strtok(NULL, sep3);
    }

    char test4Def[] = "";
    char test4my[] = "";
    char sep4[] = ".";
    char *result4Def = NULL;
    char *result4my = NULL;
    result4Def = strtok(test4Def, sep4);
    result4my = my_strtok(test4my, sep4);
    ck_assert_msg(result4Def == NULL && result4my == NULL, "Return not NULL");
}
END_TEST

START_TEST(test_my_strerror) {
    for (int errorNum = 0; errorNum <= 135; errorNum++) {
        char *test1Str1 = NULL;
        test1Str1 = strerror(errorNum);
        char *test1Str2 = NULL;
        test1Str2 = my_strerror(errorNum);
        ck_assert_str_eq(test1Str1, test1Str2);
    }
    char *test2Str1 = strerror(-145);
    char *test2Str2 = my_strerror(-145);
    ck_assert_str_eq(test2Str1, test2Str2);
}
END_TEST

START_TEST(test_my_sprintf) {
    char test1[] = "DARK";
    char result1Def[1024] = "";
    char result1my[1024] = "";
    int res1Def = sprintf(result1Def, "%%%s%.2s%-10s", test1, test1, test1);
    int res1my = my_sprintf(result1my, "%%%s%.2s%-10s", test1, test1, test1);
    ck_assert_str_eq(result1Def, result1my);
    ck_assert_int_eq(res1Def, res1my);
    char test2[] = "DARKPLACE";
    char result2Def[1024] = "";
    char result2my[1024] = "";
    float test2Float = 1.9999999;
    int res2Def = sprintf(result2Def, "%s%3s% f%+d", test2, test2, test2Float, 0);
    int res2my = my_sprintf(result2my, "%s%3s% f%+d", test2, test2, test2Float, 0);
    ck_assert_str_eq(result2Def, result2my);
    ck_assert_int_eq(res2Def, res2my);
    char result3Def[1024] = "";
    char result3my[1024] = "";
    unsigned int test3U = 429496729;
    unsigned long int test3UL = 12314124124112;
    int res3Def = sprintf(result3Def, "%u%3lu%ld", test3U, test3UL, 9999999999);
    int res3my = my_sprintf(result3my, "%u%3lu%ld", test3U, test3UL, 9999999999);
    ck_assert_str_eq(result3Def, result3my);
    ck_assert_int_eq(res3Def, res3my);
    char result4Def[1024] = "";
    char result4my[1024] = "";
    int res4Def = sprintf(result4Def, "%-.5d%.7d%.4f", 150, 1231, 65.000000);
    int res4my = my_sprintf(result4my, "%-.5d%.7d%.4f", 150, 1231, 65.000000);
    ck_assert_str_eq(result4Def, result4my);
    ck_assert_int_eq(res4Def, res4my);
    char result5Def[1024] = "";
    char result5my[1024] = "";
    char test5[] = "DARK";
    int res5Def = sprintf(result5Def, "%5s%c%.7f", test5, 'V', 112.1234);
    int res5my = my_sprintf(result5my, "%5s%c%.7f", test5, 'V', 112.1234);
    ck_assert_str_eq(result5Def, result5my);
    ck_assert_int_eq(res5Def, res5my);
}
END_TEST

START_TEST(test_my_to_upper) {
    char *test1 = NULL;
    char test1Sources[40] = "darkplacecrewthebestteamforever";
    test1 = my_to_upper(test1Sources);
    ck_assert_str_eq(test1, "DARKPLACECREWTHEBESTTEAMFOREVER");
    free(test1);
    char *test2 = NULL;
    char test2Sources[30] = "+++darkPLACE**123";
    test2 = my_to_upper(test2Sources);
    ck_assert_str_eq(test2, "+++DARKPLACE**123");
    free(test2);
}
END_TEST

START_TEST(test_my_to_lower) {
        char *test1 = NULL;
        char test1Sources[40] = "DARKPLACECREWTHEBESTTEAMFOREVER";
        test1 = my_to_lower(test1Sources);
        ck_assert_str_eq(test1, "darkplacecrewthebestteamforever");
        free(test1);
        char *test2 = NULL;
        char test2Sources[30] = "+++darkPLACE**123";
        test2 = my_to_lower(test2Sources);
        ck_assert_str_eq(test2, "+++darkplace**123");
        free(test2);
    }
END_TEST

START_TEST(test_my_insert) {
        char *test1 = NULL;
        char test1Sources[40] = "DARKFOREVER";
        char test1Str[40] = "PLACECREWTHEBESTTEAM";
        test1 = my_insert(test1Str, test1Sources, 4);
        ck_assert_str_eq(test1, "PLACDARKFOREVERECREWTHEBESTTEAM");
        free(test1);
        char *test2 = NULL;
        char test2Sources[30] = "+++darkPLACE**123";
        char test2Str[30] = " ";
        test2 = my_insert(test2Sources, test2Str, 7);
        ck_assert_str_eq(test2, "+++dark PLACE**123");
        free(test2);
    }
END_TEST

START_TEST(test_my_trim) {
        char *test1 = NULL;
        char test1Sources[40] = "DARKPLACECREWTHEBESTDARK";
        char test1Trim[40] = "DARK";
        test1 = my_trim(test1Sources, test1Trim);
        ck_assert_str_eq(test1, "PLACECREWTHEBEST");
        free(test1);
        char *test2 = NULL;
        char test2Sources[30] = "+++darkPLACE**123";
        char test2Trim[30] = "+";
        test2 = my_trim(test2Sources, test2Trim);
        ck_assert_str_eq(test2, "darkPLACE**123");
        free(test2);
        char *test3 = NULL;
        char test3Sources[50] = "                 darkPLACE            ";
        char test3Trim[30] = " ";
        test3 = my_trim(test3Sources, test3Trim);
        ck_assert_str_eq(test3, "darkPLACE");
        free(test3);
    }
END_TEST

Suite *example_suite_create(void) {
    Suite *suite = suite_create("Test of my_string");
    TCase *tcase_core = tcase_create("Core of my_string");
    tcase_add_test(tcase_core, test_my_memchr);
    tcase_add_test(tcase_core, test_my_memcmp);
    tcase_add_test(tcase_core, test_my_memcpy);
    tcase_add_test(tcase_core, test_my_memmove);
    tcase_add_test(tcase_core, test_my_memset);
    tcase_add_test(tcase_core, test_my_strlen);
    tcase_add_test(tcase_core, test_my_strcat);
    tcase_add_test(tcase_core, test_my_strncat);
    tcase_add_test(tcase_core, test_my_strcmp);
    tcase_add_test(tcase_core, test_my_strcspn);
    tcase_add_test(tcase_core, test_my_strpbrk);
    tcase_add_test(tcase_core, test_my_strspn);
    tcase_add_test(tcase_core, test_my_strchr);
    tcase_add_test(tcase_core, test_my_strcpy);
    tcase_add_test(tcase_core, test_my_strncpy);
    tcase_add_test(tcase_core, test_my_strstr);
    tcase_add_test(tcase_core, test_my_strrchr);
    tcase_add_test(tcase_core, test_my_strncmp);
    tcase_add_test(tcase_core, test_my_strtok);
    tcase_add_test(tcase_core, test_my_strerror);
    tcase_add_test(tcase_core, test_my_sprintf);
    tcase_add_test(tcase_core, test_my_to_upper);
    tcase_add_test(tcase_core, test_my_to_lower);
    tcase_add_test(tcase_core, test_my_insert);
    tcase_add_test(tcase_core, test_my_trim);
    suite_add_tcase(suite, tcase_core);
    return suite;
}

int main(void) {
    Suite *suite = example_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return failed_count != 0 ? 1 : 0;
}
