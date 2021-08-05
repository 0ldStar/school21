#include <stdio.h>
#define N 10

int input(int* arr);
void sort(int* arr);
void swap(int* xp, int* yp);
void bubbleSort(int* arr);
void output(int* arr);

int main() {
    int flag = 1;
    int arr[N];
    flag = input(arr);
    if (flag == 1) {
        bubbleSort(arr);
        output(arr);
    }
    if (flag == 0) {
        printf("n/a");
    }
    return flag;
}

int input(int* arr) {
    int flag = 1;
    for (int* p = arr; p - arr < N; p++) {
        if (scanf("%d", p) != 1) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void output(int* arr) {
    for (int* p = arr; p - arr < N; p++) {
        printf("%d", *p);
        if (p - arr != N - 1) printf(" ");
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int* arr) {
    for (int* p = arr; p - arr < N - 1; p++) {
        for (int* n = arr; n - arr + p < N + arr - 1; n++)
            if (*n > *(n + 1))
                swap(n, n + 1);
    }
}
