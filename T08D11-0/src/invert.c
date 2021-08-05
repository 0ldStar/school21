#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int height);

int input(double ***matrix, int *height, int *width);
int inputMatrix(double **matrix, int height, int width);

double **alloc(int *flag, int height, int width);

void output(double **matrix, int height, int width);

int inverse(double **matrix, int size);
void memFree(double** matrix, int size);

// 3 3 1 0.5 1 4 1 2 3 2 2
int main() {
    int flag;
    double **matrix;
    int height, width;
    flag = input(&matrix, &height, &width);
    if (flag == 1) {
        flag = inverse(matrix, height);
        if (flag == 1) {
        output(matrix, height, width);
        memFree(matrix, height);
        }
    }
    if (flag == 0) {
        printf("n/a");
    }
    return 0;
}

int inputMatrix(double **matrix, int height, int width) {
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

double **alloc(int *flag, int height, int width) {
    double **matrix;
    matrix = (double **) malloc(height * sizeof(double *));
    if (!matrix) *flag = 0;
    if (*flag == 1) {
        for (int i = 0; i < height; i++) {
            matrix[i] = (double *) malloc(2 * width * sizeof(double));
            if (!matrix[i]) *flag = 0;
        }
    }
    return matrix;
}

int input(double ***matrix, int *height, int *width) {
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

void output(double **matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = width; j < 2* width; j++) {
            printf("%lf", matrix[i][j]);
            if (j != 2 * width - 1) printf(" ");
        }
        if (i != height - 1)printf("\n");
    }
}

int inverse(double **matrix, int size) {
    int i, j, k;
    double ratio;
    int flag = 1;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) {
                matrix[i][j + size] = 1;
            } else {
                matrix[i][j + size] = 0;
            }
        }
    }
    for (i = 0; i < size; i++) {
        if (matrix[i][i] == 0.0) {
            flag = 0;
            break;
        }
        for (j = 0; j < size; j++) {
            if (i != j) {
                ratio = matrix[j][i] / matrix[i][i];
                for (k = 0; k < 2 * size; k++) {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
            }
        }
    }
    if (flag == 1) {
    for (i = 0; i < size; i++) {
        for (j = size; j < 2 * size; j++) {
            matrix[i][j] = matrix[i][j] / matrix[i][i];
        }
    }}
    return flag;
}

void memFree(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
