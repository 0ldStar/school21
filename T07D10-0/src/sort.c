#include <stdio.h>
#include <stdlib.h>

int input(int** arr, int* length);
void sort(int* arr);
void swap(int* xp, int* yp);
void bubbleSort(int* arr, int length);
void output(int* arr, int length);

int main() {
    int* arr;
    int length, flag = 1;
    flag = input(&arr, &length);
    bubbleSort(arr, length);
    output(arr, length);
    free(arr);
    if (!flag) {
        printf("n/a");
    }
    return flag;
}

int input(int** buffer, int* length) {
    int flag = 1;
    if (scanf("%d", length) != 1 || *length < 0) {
        flag = 0;
    }
    *buffer = (int*)malloc(*length * sizeof(int));
    if (!buffer) {
        flag = 0;
    }
    if (flag == 1) {
        for (int* p = *buffer; p - *buffer < *length; p++) {
            scanf("%d", p);
        }
    }
    return flag;
}

void output(int* arr, int length) {
    for (int* p = arr; p - arr < length; p++) {
        printf("%d", *p);
        if (p - arr != length - 1) printf(" ");
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int* arr, int length) {
    for (int* p = arr; p - arr < length - 1; p++) {
        for (int* n = arr; n - arr + p < length + arr - 1; n++)
            if (*n > *(n + 1))
                swap(n, n + 1);
    }
}
