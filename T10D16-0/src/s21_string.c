#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int s21_strcmp(const char* str1, const char* str2) {
    int i = 0, status = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && status == 0) {
        if ((int)str1[i] < (int)str2[i]) {
            status = -1;
        }
        if ((int)str1[i] > (int)str2[i]) {
            status = 1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        status = 0;
    } else if (str1[i] == '\0' && str2[i] != '\0') {
        status = -1;
    } else if (str1[i] != '\0' && str2[i] == '\0') {
        status = 1;
    }
    return status;
}

void s21_strcpy(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void s21_strcat(char* destination, const char* source) {
    int len, i = 0;
    len = s21_strlen(destination);
    while (source[i] != '\0') {
        destination[len + i] = source[i];
        i++;
    }
    destination[len + i] = '\0';
}

char* s21_strchr(char* source, int chCode) {
    int i = 0;
    char* point = NULL;
    while (source[i] != '\0' && point == NULL) {
        if (source[i] == (char)chCode) point = source + i;
        i++;
    }
    return point;
}

char* s21_strstr(char* haystack, char* need) {
    int i = 0, j, flag, len;
    char* point = NULL, *buf = NULL;
    len = s21_strlen(haystack);
    while (haystack[i] != '\0') {
        flag = 1;
        j = 0;
        while (need[j] != '\0') {
            if (i + j >= len) break;
            if (haystack[i+j] == need[j] && flag == 1) {
                buf = haystack + i + j;
                flag = 2;
            } else if (flag == 2) {
                flag = 2;
            } else {
                flag = 0;
            }
        j++;
        }
        if (flag == 2) {
            point = buf;
            break;
        }
        i++;
    }
    return point;
}
int* create_delim_dict(char* delim) {
    int *d = (int*)malloc(10 *sizeof(int));
    int i;
    for (i = 0; i < s21_strlen(delim); i++) {
        d[delim[i]] = 1;
    }
    return d;
}

char* s21_strtok(char* str, char* delim) {
    static char *last, *strToFree;
    int *deliDict = create_delim_dict(delim);
    if (!deliDict) {
        return NULL;
    }
    if (str) {
        last = (char*)malloc(s21_strlen(str)+1);
        if (!last) {
            free(deliDict);
        }
        strToFree = last;
        s21_strcpy(last, str);
    }
    while (deliDict[*last] && *last != '\0') {
        last++;
    }
    str = last;
    if (*last == '\0') {
        free(deliDict);
        free(strToFree);
        return NULL;
    }
    while (*last != '\0' && !deliDict[*last]) {
        last++;
    }
    *last = '\0';
    last++;

    free(deliDict);
    return str;
}
