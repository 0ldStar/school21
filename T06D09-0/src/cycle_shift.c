#include <stdio.h>
#define NMAX 10

int input(int* arr, int* lenght, int* c);
void output(int* a, int lenght);
void cycle(int* arr, int lenght, int c);
void swap(int* a, int* b);

int main() {
    int flag = 1;
    int lenght, arr[NMAX], c;
    flag = input(arr, &lenght, &c);
    if (flag == 1) {
        cycle(arr, lenght, c);
        output(arr, lenght);
    }
    if (flag == 0) {
        printf("n/a");
    }
    return flag;
}

int input(int* arr, int* lenght, int* c) {
    int flag = 1;
    if (scanf("%d", lenght) != 1 || *lenght > NMAX || *lenght <= 0) {
        flag = 0;
    }
    if (flag == 1) {
        for (int* p = arr; p - arr < *lenght; p++) {
            if (flag == 0)break;
            if (scanf("%d", p) != 1) flag = 0;
        }
        if (flag == 1) {
            if (scanf("%d", c) != 1) {
                flag = 0;
            }
        }
    }
    return flag;
}

void output(int* arr, int lenght) {
    for (int* p = arr; p - arr < lenght; p++) {
        printf("%d", *p);
        if (p - arr != lenght - 1) printf(" ");
    }
}
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void cycle(int* arr, int lenght, int c) {
    int tmp[NMAX], index;
    for (int* p = arr; p - arr < lenght; p++) {
        *(p + (tmp - arr)) = *p;
    }
    if (c > lenght) c = c % lenght;
    if (c < 0) c = lenght + c;
    int tmpLen = 0;
    for (int i = 0; i < lenght; i++) {
        index = (i + c) % lenght;
        *(tmp + tmpLen) = *(arr + index);
        tmpLen++;
    }
    for (int* p = tmp; p - tmp < tmpLen; p++) {
        *(p + (arr - tmp)) = *p;
    }
}
