#include <stdio.h>
#include "s21_string.h"

void processor(char* str, int n);

int main(int argc, char** argv) {
    int flag, n;
    char str[100];

    flag = 1;

    if (argc != 2 || (argv[1][0] != '-' || argv[1][1] != 'w')) {
        flag = 0;
    }
    if (flag == 1) {
        if (scanf("%d", &n) != 1 || n < 2) flag = 0;
        if (flag == 1) {
            scanf("%c", &str[0]);
            for (int i = 0; i < 100; i++) {
                scanf("%c", &str[i]);
                if (str[i] == '\n') {
                    str[i] = '\0';
                    break;
                }
            }
            if (flag == 1) {
                processor(str, n);
            }
        }
    }
    if (flag == 0) {
        printf("n/a");
    }
    return flag;
}

void processor(char* str, int n) {
    char* pch = s21_strtok(str, " ,.");
    int curentIn, wordIn, len, flag;
    char buf[100] = "";
    curentIn = 0; wordIn = 0; flag = 1;
    while (pch != NULL) {
        len = s21_strlen(pch);
        if (curentIn + len < n) {
            if (flag == 1) {
                if (curentIn != 0) {
                    buf[curentIn++] = ' ';
                    buf[curentIn] = '\0';
                }
                s21_strcat(buf, pch);
            } else {
                s21_strcpy(buf, pch);
                flag = 1;
            }
            curentIn += len;
            flag = 1;
        } else {
            if (len < n) {
                if (flag == 1) printf("%s\n", buf);
                s21_strcpy(buf, pch);
                curentIn = len;
                flag = 1;
            } else {
                if (flag == 1 && curentIn != 0) buf[curentIn++] = ' ';
                for (int i = curentIn; i < n - 1; i++) {
                    buf[i] = pch[wordIn++];
                }
                buf[n -1] = '-';
                buf[n] = '\0';
                curentIn = 0;
                printf("%s\n", buf);
                flag = 0;
                for (int i = wordIn, j = 0; i < len; i++) {
                    pch[j++] = pch[i];
                }
                pch[len - wordIn] = '\0';
                wordIn = 0;
                curentIn = 0;
            }
        }
        if (flag == 1) {
            pch = s21_strtok(NULL, " ,.");
        }
    }
    printf("%s", buf);
}
