#include "s21_string.h"
#include <stdio.h>

void s21_strlen_test() {
    printf("TESTING STRLEN MODULE\n");
    s21_strlen("School 21") == 9 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strlen("\0") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strlen("") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcmp_test() {
    printf("TESTING STRCMP MODULE\n");
    s21_strcmp("School 21", "School 42") < 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strcmp("", "ABC") < 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strcmp("ABC", "ABC") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcpy_test() {
    printf("TESTING STRCPY MODULE\n");
    char str1[] = "SCHOOL21";
    char str2[] = "21";
    char str3[] = "ABC";
    s21_strcpy(str1, str2);
    s21_strcmp(str1, str2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strcpy(str2, str1);
    s21_strcmp(str2, str1) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strcpy(str1, str3);
    s21_strcmp(str1, str3) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strcat_test() {
    printf("TESTING STRCAT MODULE\n");
    char str[80];
    char str1[] = "SCHOOL21";
    char str2[] = "21";
    char str3[] = "ABC";
    s21_strcpy(str, str1);
    s21_strcat(str, str2);
    s21_strcmp(str, "SCHOOL2121") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strcat(str, str3);
    s21_strcmp(str, "SCHOOL2121ABC") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    s21_strcat(str, str2);
    s21_strcmp(str, "SCHOOL2121ABC21") == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strchr_test() {
    printf("TESTING STRCHR MODULE\n");
    char* p;
    char str[] = "School 21";
    p = s21_strchr(str, 'o');
    *p == 'o' ? printf("SUCCESS\n") : printf("FAIL\n");
    p = s21_strchr(str, 'c');
    *p == 'c' ? printf("SUCCESS\n") : printf("FAIL\n");
    p = s21_strchr(str, 'A');
    p == NULL ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strstr_test() {
    printf("TESTING STRSTR MODULE\n");
    char str1[] = "School 21";
    char str2[] = "chool 21";
    char str3[] = "42";
    char* pointer;
    pointer = s21_strstr(str1, str2);
    s21_strcmp(pointer, str2) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
    pointer = s21_strstr(str1, str3);
    pointer == NULL ? printf("SUCCESS\n") : printf("FAIL\n");
    pointer = s21_strstr(str2, str3);
    pointer == NULL ? printf("SUCCESS\n") : printf("FAIL\n");
}

void s21_strtok_test() {
    printf("TESTING STRTOK MODULE\n");
    char str1[] = "This is not bug, this ficha.";
    char* pch = s21_strtok(str1, " ,.");
    char* str2[] = {"This", "is", "not", "bug", "this", "ficha"};
    int i = 0;
    while (pch != NULL) {
        s21_strcmp(pch, str2[i]) == 0 ? printf("SUCCESS\n") : printf("FAIL\n");
        pch = s21_strtok(NULL, " ,.");
        i++;
    }
}
