#include <stdio.h>
#include "s21_string.h"

int main() {
    #ifdef Quest_1
        s21_strlen_test();
    #endif
    #ifdef Quest_2
        s21_strcmp_test();
    #endif
    #ifdef Quest_3
        s21_strcpy_test();
    #endif
    #ifdef Quest_4
        s21_strcat_test();
    #endif
    #ifdef Quest_5
        s21_strchr_test();
    #endif
    #ifdef Quest_6
        s21_strstr_test();
    #endif
    #ifdef Quest_7
        s21_strtok_test();
    #endif
    return 0;
}
