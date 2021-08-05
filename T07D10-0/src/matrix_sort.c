#include <stdio.h>
#include <stdlib.h>

int input(int** matrix, int n, int m);
void output(int** matrix, int n, int m);
int menu(int mode);
int inputValue(int* height, int* width, int*** matrix);
int inputMatrix(int*** inMatrix, int width, int height);
void memFree(int** matrix, int width);
void sort(int*** matrix, int height, int width);
void swap(int** a, int** b);

int main() {
    int** matrix;
    int height, width;
    if (!inputValue(&height, &width, &matrix)) {
        printf("n/a");
        return 0;
    }
    sort(&matrix, height, width);
    output(matrix, height, width);
    memFree(matrix, height);
    return 0;
}

int inputValue(int* height, int* width, int*** matrix) {
    if (!scanf("%d", height) || (*height < 1)) return 0;
    if (!scanf("%d", width) || (*width < 1)) return 0;
    if (!inputMatrix(matrix, *height, *width)) return 0;
    return 1;
}

int alloc(int*** inMatrix, int height, int width) {
    int** matrix;
    if (!(matrix = (int**)malloc(height * sizeof(int*)))) return 0;
    for (int i = 0; i < height; i++) {
        if (!(matrix[i] = (int*)malloc(width * sizeof(int)))) return 0;
    }
    *inMatrix = matrix;
    return 1;
}

int inputMatrix(int*** inMatrix, int height, int width) {
    int** matrix;
    if (!alloc(&matrix, height, width)) return 0;
    input(matrix, height, width);
    *inMatrix = matrix;
    return 1;
}

int input(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!scanf("%d", &matrix[i][j])) return 0;
        }
    }
    return 1;
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

void memFree(int** matrix, int width) {
    for (int i = 0; i < width; i++) {
        free(matrix[i]);
    }
}


void swap(int** a, int** b) {
    int* tmp = *a;
    *a = *b;
    *b = tmp;
}

int sum(int* arr, int width) {
    int sum = 0;
    for (int i = 0; i < width; i++) {
        sum += arr[i];
    }
    return sum;
}

void sort(int*** inMatrix, int height, int width) {
    int** matrix = *inMatrix;
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            if (sum(matrix[j], width) > sum(matrix[j + 1], width))
                swap(&matrix[j], &matrix[j + 1]);
        }
    }
    inMatrix = &matrix;
}
