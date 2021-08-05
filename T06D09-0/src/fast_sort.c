#include <stdio.h>
#define N 10

int input(int* arr);
void sort(int* arr);
void swap(int* xp, int* yp);
void bubbleSort(int* arr);
void output(int* arr);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void heapify(int* arr, int n, int i);
void heapSort(int* arr, int n);
void copy(int* arr1, int* arr2);

int main() {
    int flag = 1;
    int arr1[N], arr2[N];
    flag = input(arr1);
    if (flag == 1) {
        copy(arr1, arr2);
        quickSort(arr1, 0, N - 1);
        output(arr1);
        printf("\n");
        heapSort(arr2, N);
        output(arr2);
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

void copy(int* arr1, int* arr2) {
    for (int* p = arr1; p - arr1 < N; p++) {
        *(p + (arr2 - arr1)) = *p;
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int low, int high) {
    int step = *(arr + high);
    int i = (low - 1);
    for (int* p = arr + low; p - arr <= high - 1; p++) {
        if (*p < step) {
            i++;
            swap(arr + i, p);
        }
    }
    swap(arr + i + 1, arr + high);
    return (i + 1);
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int* arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && *(arr + l) > *(arr + largest))
        largest = l;

    if (r < n && *(arr + r) > *(arr + largest))
        largest = r;

    if (largest != i) {
        swap(arr + i, arr + largest);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr, arr + i);
        heapify(arr, i, 0);
    }
}
