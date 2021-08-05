#include "parcer.h"
#include <stdlib.h>
#include <stdio.h>
/*
c - cos
s - sin
t - tg
g - ctg
q - sqrt
l - ln
*/

int input(char** strIn, int* len) {
    char* str, *tmp;
    int flag;

    *len = -1; flag = 1;
    tmp = (char*) malloc(200 * sizeof(char));
    if (tmp == NULL){
        flag = 0;
    } else {
        str = tmp;
    while (str[(*len)++] != '\n' && flag == 1) {
        str[*len] = getchar();
        if (valid(str[*len])) {
            flag = 0;
        }
    }
    str[--(*len)] = '\0';
    *strIn = str;
    }
    return flag;
}

int valid(char c) {
    return (c >= 40 && c <=57 || c >=97 && c<= 122 || c =='\n' || c == ' ') ? 0: 1;
}

void shift(char* str, int* len, int ind, int step) {
    for (int i = ind; i < *len - step; i++) {
        str[i] = str[i + step];
    }
    *len -= step;
}

int sinCheck(char* str, int* len, int ind) {
    int flag = 1;
    if (str[ind + 1] != 'i' || str[ind + 2] != 'n') {
        flag = 0;
    } else {
        shift(str, len, ind + 1, 2);
        str[ind] = 's';
    }
    return flag;
}

int cosCheck(char* str, int* len, int ind) {
    int flag = 1;
    if (str[ind + 1] != 'o' || str[ind + 2] != 's') {
        flag = 0;
    } else {
        shift(str, len, ind + 1, 2);
        str[ind] = 'c';
    }
    return flag;
}

int lnCheck(char* str, int* len, int ind) {
    int flag = 1;
    if (str[ind + 1] != 'n') {
        flag = 0;
    } else {
        shift(str, len, ind + 1, 1);
        str[ind] = 'l';
    }
    return flag;
}

int tgCheck(char* str, int* len, int ind) {
    int flag = 1;
    if (str[ind + 1] != 'g') {
        flag = 0;
    } else {
        shift(str, len, ind + 1, 1);
        str[ind] = 't';
    }
    return flag;
}

int ctgCheck(char* str, int* len, int ind) {
    int flag = 1;
    if (str[ind + 1] != 't' || str[ind + 2] != 'g') {
        flag = 0;
    } else {
        shift(str, len, ind + 1, 2);
        str[ind] = 'g';
    }
    return flag;
}

int sqrtCheck(char* str, int* len, int ind) {
    int flag = 1;
    if (str[ind + 1] != 'q' || str[ind + 2] != 'r' || str[ind + 3] != 't') {
        flag = 0;
    } else {
        shift(str, len, ind + 1, 3);
        str[ind] = 'q';
    }
    return flag;
}

int format(char* str, int* len) {
    int flag, operatorFlag, operandFlag, bracketCount1, bracketCount2;

    flag = 1, operatorFlag = 0, operandFlag = 0, bracketCount1 = 0, bracketCount2 = 0;
    for (int i = 0; i < *len && flag; i++) {
        flag = 0;
        if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '^') {
            if (str[i] != '-') {
                flag = (operatorFlag == 1) ? 0 : 1;
            } else {
                flag  = 1;
            }
            operandFlag = 0;
        }
        if (str[i] == 'x') {
            operandFlag = 1;
            operatorFlag = 0;
            flag += 1;
        }
        if (str[i] == '(') {
            bracketCount1++;
            flag += 1;
        }
        if (str[i] == ')') {
            bracketCount2++;
            flag += 1;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            operatorFlag = 0;
            operandFlag = 1;
            flag += 1;
        }
        if (str[i] == ' ') {
            flag += 1;
            shift(str, len, i, 1);
            i--;
        }
        if (str[i] == 's') {
            flag += sinCheck(str, len, i);
            flag += sqrtCheck(str, len, i);
            if (flag != 0) {
                operatorFlag = 1;
                flag = (operandFlag == 1) ? 0 : 1;
            }
            }
        if (str[i] == 'c') {
            flag += cosCheck(str, len, i);
            flag += ctgCheck(str, len, i);
            if (flag != 0) {
                operatorFlag = 1;
                flag = (operandFlag == 1) ? 0 : 1;
            }
            }
        if (str[i] == 'l') {
            flag += lnCheck(str, len, i);
            if (flag != 0) {
                operatorFlag = 1;
                flag = (operandFlag == 1) ? 0 : 1;
            }
            }
        if (str[i] == 't') {
            flag += tgCheck(str, len, i);
            if (flag != 0) {
                operatorFlag = 1;
                flag = (operandFlag == 1) ? 0 : 1;
            }
            }
    }
    str[*len] = '\0';
    if (bracketCount1 != bracketCount2 || operatorFlag == 1) flag = 0;
    return flag;
}
