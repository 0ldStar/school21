#include <stdio.h>
#include <stdlib.h>

int sle(double **matrix, int n, int m, double *roots);
void output_roots(double *roots, int n);
void det(double** matrix, int n, int m);
int input(double*** matrix, int* n, int* m);
double diagonalMultiplication(double** matrix, int SIZE);
int zeroesCheck(const double* range, int SIZE);
int power(int a, int b);
void sort(double** matrix, int height, int width);
void gaussianDeterminant(double** matrix, int height, int width);
int inputMatrix(double** matrix, int height, int width);
double** alloc(int* flag, int height, int width);

void output(double **matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%lf", matrix[i][j]);
            if (j !=  width - 1) printf(" ");
        }
        if (i != height - 1)printf("\n");
    }
}

// 3 4 1 1 1 2 4 5 3 7 2 7 7 9
int main() {
    int flag = 1;
    double** matrix;
    int height, width;
    flag = input(&matrix, &height, &width);
    if (flag == 1) {
        det(matrix, height, width);
        output(matrix, height, width);
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
    if (!scanf("%d", height) || (*height < 1)) flag = 0;
    if (!scanf("%d", width) || (*width < 1)) flag = 0;
    if (flag == 1) {
        *matrix = alloc(&flag, *height, *width);
        if (flag == 1) {
            flag = inputMatrix(*matrix, *height, *width);
        }
    }
    return flag;
}
void det(double** matrix, int height, int width) {
    sort(matrix, height, width);
    gaussianDeterminant(matrix, height, width);
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

void sort(double** matrix, int height, int width) {
    int i, j;
    double* temp;
    for (i = 0; i < height - 1; i++)
        for (j = 0; j < width - i - 1; j++) {
            if (zeroesCheck(matrix[j], width) > zeroesCheck(matrix[j + 1], width)) {
                temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
            }
        }
}

void gaussianDeterminant(double** matrix, int height, int width) {
    int size = height;
    double first, factor;
    while (size > 1) {
        first = matrix[height - size][height - size];
        for (int i = height - size + 1; i < height; ++i) {
            factor = matrix[i][height - size] / first;
            for (int j = width - size; j < width; ++j) {
                matrix[i][j] -= matrix[height - size][j] * factor;
            }
        }
        size--;
    }
}


