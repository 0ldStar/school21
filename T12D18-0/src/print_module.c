#include <stdio.h>
#include <time.h>
#include <string.h>
#include "print_module.h"

char print_char(char ch)
{
    return putchar(ch);
}
void print_log(char (*print) (char), char* message) {
    time_t now = time(NULL);
    struct tm* tm_struct = localtime(&now);
    int len;
    len = strlen(Log_prefix);
    for (int i = 0; i < len; i++) {
        print_char(Log_prefix[i]);
    }
    numprint(print, tm_struct->tm_hour);
    print(':');
    numprint(print, tm_struct->tm_min);
    print(':');
    numprint(print, tm_struct->tm_sec);
    print(' ');
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        print_char(message[i]);
    }


}

void numprint(char(*print)(char), int num) {
    if (num < 10) {
        print('0');
        print(num + '0');
    } else {
        print(num / 10 + '0');
        print(num % 10 + '0');
    }
}