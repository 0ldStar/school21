#include <stdio.h>
#include <stdlib.h>

int input(int** matrix, int n, int m);
void output(int** matrix, int n, int m);
int sum(int height1, int width1, int** matrix1, int height2, int width2, int** matrix2, int*** rez);
int mul(int height1, int width1, int** matrix1, int height2, int width2, int** matrix2, int*** rez);
void trans(int height, int width, int** matrix, int*** rez);
int menu(int mode);
int inputValue(int* height, int* width, int*** matrix);
int inputMatrix(int*** inMatrix, int width, int height);
void memFree(int** matrix, int width);

int main() {
    int flag = 1;
    int mode;
    if (!scanf("%d", &mode) || (mode < 1) || (mode > 3)) {
        flag = 0;
    }
    if (flag == 1) flag = menu(mode);
    return flag;
}

int inputValue(int* height, int* width, int*** matrix) {
    int flag = 1;
    if (!scanf("%d", height) || (*height < 1)) flag = 0;
    if (!scanf("%d", width) || (*width < 1)) flag = 0;
    flag = inputMatrix(matrix, *height, *width);
    return flag;
}

int menu(int mode) {
    int flag = 1;
    int width1, height1, width2, height2;
    int** matrix1, ** matrix2, ** rez;
    switch (mode) {
    case 1:
        flag = inputValue(&height1, &width1, &matrix1);
        flag = inputValue(&height2, &width2, &matrix2);
        if (flag == 1) {
            flag = sum(height1, width1, matrix1, height2, width2, matrix2, &rez);
            if (flag == 1) {
                memFree(matrix1, height1);
                memFree(matrix2, height2);
                output(rez, height1, width1);
                memFree(rez, height1);
            }
        }
        break;
    case 2:
        flag = inputValue(&height1, &width1, &matrix1);
        flag = inputValue(&height2, &width2, &matrix2);
        if (flag == 1) {
            flag = mul(height1, width1, matrix1, height2, width2, matrix2, &rez);
            if (flag == 1) {
                memFree(matrix1, height1);
                memFree(matrix2, height2);
                output(rez, height1, width2);
                memFree(rez, height1);
            }
        }
        break;
    case 3:
        flag = inputValue(&height1, &width1, &matrix1);
        if (flag == 1) {
            trans(height1, width1, matrix1, &rez);
            memFree(matrix1, height1);
            output(rez, width1, height1);
            memFree(rez, width1);
        }
        break;
    default:
        flag = 0;
        break;
    }

    return flag;
}

int alloc(int*** inMatrix, int height, int width) {
    int flag = 1;
    int** matrix;
    matrix = (int**)malloc(height * sizeof(int*));
    if (!matrix) flag = 0;
    if (flag == 1) {
        for (int i = 0; i < height; i++) {
            matrix[i] = (int*)malloc(width * sizeof(int));
            if (!matrix[i]) {
                flag = 0;
                break;
            }
        }
        *inMatrix = matrix;
    }
    return flag;
}

int inputMatrix(int*** inMatrix, int height, int width) {
    int flag = 1;
    int** matrix;
    flag = alloc(&matrix, height, width);
    if (flag == 1) {
        flag = input(matrix, height, width);
        *inMatrix = matrix;
    }
    return flag;
}

int input(int** matrix, int n, int m) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (flag == 0) break;
        for (int j = 0; j < m; j++) {
            if (!scanf("%d", &matrix[i][j])) {
                flag = 0;
                break;
            }
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

void memFree(int** matrix, int height) {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }
}

int sum(int height1, int width1, int** matrix1, int height2, int width2, int** matrix2, int*** rez) {
    int flag = 1;
    if (width1 != width2 || height1 != height2) flag = 0;
    if (flag == 1) {
        flag = alloc(rez, width1, height1);
        if (flag == 1) {
            int** rezM = *rez;
            for (int i = 0; i < height1; i++) {
                for (int j = 0; j < width1; j++) {
                    rezM[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
        }
    }
    return flag;
}

int mul(int height1, int width1, int** matrix1, int height2, int width2, int** matrix2, int*** rez) {
    int flag = 1;
    if (width1 != height2) flag = 0;
    if (flag == 1) {
        flag = alloc(rez, height1, width2);
        if (flag == 1) {
            int** rezM = *rez;
            for (int i = 0; i < height1; i++) {
                for (int j = 0; j < width2; j++) {
                    rezM[i][j] = 0;
                    for (int k = 0; k < width1; k++)
                        rezM[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
    return flag;
}

void trans(int height, int width, int** matrix, int*** rez) {
    int i, j;
    alloc(rez, width, height);
    int** rezM = *rez;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            rezM[i][j] = matrix[j][i];
        }
    }
}
