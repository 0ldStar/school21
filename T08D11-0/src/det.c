#include <stdio.h>
#include <stdlib.h>

double det(double** matrix, int n);
int input(double*** matrix, int* n, int* m);
void output(double det);
double diagonalMultiplication(double** matrix, int SIZE);
int zeroesCheck(const double* range, int SIZE);
int power(int a, int b);
int sort(double** matrix, int SIZE);
double gaussianDeterminant(double** matrix, int SIZE);
int inputMatrix(double** matrix, int height, int width);
double** alloc(int* flag, int height, int width);
void memFree(double** matrix, int size);

int main() {
    int flag = 1;
    double** matrix;
    int height, width;
    double determ;
    flag = input(&matrix, &height, &width);
    if (flag == 1) {
        determ = det(matrix, height);
        output(determ);
        memFree(matrix, height);
    }
    if (flag == 0) {
        printf("n/a");
    }
    return 0;
}

int inputMatrix(double** matrix, int height, int width) {
    int flag = 1;
    for (int i = 0; i < height; i++) {
        if (flag == 0) break;
        for (int j = 0; j < width; j++) {
            if (!scanf("%lf", &matrix[i][j])) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

double** alloc(int* flag, int height, int width) {
    double** matrix;
    matrix = (double**)malloc(height * sizeof(double*));
    if (!matrix) *flag = 0;
    if (*flag == 1) {
        for (int i = 0; i < height; i++) {
            matrix[i] = (double*)malloc(width * sizeof(double));
            if (!matrix[i]) *flag = 0;
        }
    }
    return matrix;
}

int input(double*** matrix, int* height, int* width) {
    int flag = 1;
    if (!scanf("%d", width) || (*width < 1)) flag = 0;
    if (!scanf("%d", height) || (*height < 1)) flag = 0;
    if (*height != *width) flag = 0;
    if (flag == 1) {
        *matrix = alloc(&flag, *height, *width);
        if (flag == 1) {
            flag = inputMatrix(*matrix, *height, *width);
        }
    }
    return flag;
}
double det(double** matrix, int n) {
    int sign;
    sign = sort(matrix, n);
    return gaussianDeterminant(matrix, n) * (double)sign;
}
double diagonalMultiplication(double** matrix, int SIZE) {
    double rez = 1;
    for (int i = 0; i < SIZE; ++i) rez *= matrix[i][i];
    return rez;
}

int zeroesCheck(const double* range, int SIZE) {
    int count = 0, flag = 1;
    for (int i = 0; i < SIZE; ++i)
        if (range[i] == 0 && flag) {
            count++;
        } else {
            flag = 0;
        }
    return count;
}

int power(int a, int b) {
    int rez = 1;
    for (int i = 0; i < b; ++i) rez *= a;
    return rez;
}

int sort(double** matrix, int SIZE) {
    int i, j, count = 0;
    double* temp;
    for (i = 0; i < SIZE - 1; i++)
        for (j = 0; j < SIZE - i - 1; j++) {
            if (zeroesCheck(matrix[j], SIZE) > zeroesCheck(matrix[j + 1], SIZE)) {
                count++;
                temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
            }
        }
    return power(-1, count);
}

double gaussianDeterminant(double** matrix, int SIZE) {
    int size = SIZE;
    double first, factor;
    while (size > 1) {
        if (matrix[SIZE - size][SIZE - size] == 0) return 0;
        first = matrix[SIZE - size][SIZE - size];
        for (int i = SIZE - size + 1; i < SIZE; ++i) {
            factor = matrix[i][SIZE - size] / first;
            for (int j = SIZE - size; j < SIZE; ++j) {
                matrix[i][j] -= matrix[SIZE - size][j] * factor;
            }
        }
        size--;
    }
    return diagonalMultiplication(matrix, SIZE);
}

void output(double det) {
    printf("%lf", det);
}
void memFree(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
