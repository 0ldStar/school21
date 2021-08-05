#include <stdio.h>
#include <stdlib.h>
// 3 3 1 2 3 4 5 6 7 8 9
// 4 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
/*
 1 6 7
 2 5 8
 3 4 9
 */
void sort_vertical(int* arr, int height, int width, int*** result_matrix);

/*
 1 2 3
 6 5 4
 7 8 9
 */
void sort_horizontal(int* arr, int height, int width, int** result);

/*
 7 8 9
 6 1 2
 5 4 3
 */
void sort_spiral(int* arr, int height, int width, int** result_matrix);

int input(int*** matrix, int* n, int* m);
void output(int** matrix, int n, int m);
int** alloc(int* flag, int height, int width);
int inputMatrix(int** matrix, int height, int width);
void swap(int* a, int* b);
void bubbleSort(int* arr, int length);
void arrCreate(int** matrix, int heigth, int width, int** arr);

int main() {
    int** matrix, ** result, * arr;
    int n, m;

    input(&matrix, &n, &m);
    output(matrix, n, m);
    arrCreate(matrix, n, m, &arr);
    printf("\n\n");
    sort_vertical(arr, n, m, &result);
    output(result, n, m);
    printf("\n\n");
    sort_horizontal(arr, n, m, result);
    output(result, n, m);
    printf("\n\n");
    sort_spiral(arr, n, m, result);
    output(result, n, m);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(arr);
    return 0;
}

int inputMatrix(int** matrix, int height, int width) {
    int flag = 1;
    for (int i = 0; i < height; i++) {
        if (flag == 0) break;
        for (int j = 0; j < width; j++) {
            if (!scanf("%d", &matrix[i][j])) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int** alloc(int* flag, int height, int width) {
    int** matrix;
    matrix = (int**)malloc(height * sizeof(int*));
    if (!matrix) *flag = 0;
    if (*flag == 1) {
        for (int i = 0; i < height; i++) {
            matrix[i] = (int*)malloc(width * sizeof(int));
            if (!matrix[i]) *flag = 0;
        }
    }
    return matrix;
}
int input(int*** matrix, int* height, int* width) {
    int flag = 1;
    if (!scanf("%d", width) || (*width < 1)) flag = 0;
    if (!scanf("%d", height) || (*height < 1)) flag = 0;
    if (flag == 1) {
        *matrix = alloc(&flag, *height, *width);
        if (flag == 1) {
            flag = inputMatrix(*matrix, *height, *width);
        }
    }
    return flag;
}
void output(int** matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", matrix[i][j]);
            if (j != width - 1) printf(" ");
        }
        if (i != height - 1)printf("\n");
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int* arr, int length) {
    int i, j;
    for (i = 0; i < length - 1; i++)
        for (j = 0; j < length - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void arrCreate(int** matrix, int heigth, int width, int** inArr) {
    int len = 0;
    int* arr = (int*)malloc(heigth * width * sizeof(int));
    for (int i = 0; i < heigth; i++)
        for (int j = 0; j < width; j++)
            arr[len++] = matrix[i][j];
    bubbleSort(arr, len);
    *inArr = arr;
}

void sort_vertical(int* arr, int height, int width, int*** result_matrix) {
    int flag = 1;
    int** result = alloc(&flag, height, width);
    if (flag == 1) {
    int k = 0;
    for (int i = 0; i < width; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < height; j++)
                result[j][i] = arr[k++];
        } else {
            for (int j = height - 1; j >= 0; j--)
                result[j][i] = arr[k++];
        }
    }
    *result_matrix = result;
    }
}

void sort_horizontal(int* arr, int height, int width, int** result) {
    int k = 0;
    for (int i = 0; i < height; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < width; j++)
                result[i][j] = arr[k++];
        } else {
            for (int j = width - 1; j >= 0; j--)
                result[i][j] = arr[k++];
        }
    }
}

void sort_spiral(int* arr, int height, int width, int** result) {
    int K = 0;
    int i, j, k, l;
    int centre_x = (width - 1) / 2;
    int centre_y = (height - 1) / 2;
    for (i = centre_x; i < width; i++) {
        result[centre_y][i] = arr[K++];
    }
    for (j = centre_y; j >= 0; j--) {
        result[j][i] = arr[K++];
    }
    for (k = i - 1; k >= 0; k--) {
        result[j + 1][k] = arr[K++];
    }
    for (l = j + 1; l < height; l++) {
        result[l][k + 1] = arr[K++];
    }
}
