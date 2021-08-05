#include <stdio.h>
#include <stdlib.h>

#define WIDTHMAX 100
#define HEIGHTMAX 100

void output(int** matrix, int height, int width);
void memFree(int mode, int** matrix, int height);
int** doubleAlloc(int* flag, int height, int width);
int** dynAlloc(int* flag, int height, int width);
int** dynLinAlloc(int* flag, int height, int width);
int** statAlloc(int* flag, int height, int width);
int input(int** matrix, int height, int width);
int menu(int mode, int*** matrix, int height, int width);
int inputValue(int* mode, int* height, int* width);
void transform(int* buf, int** matr, int n, int m);

int main() {
    int** matrix = NULL;
    int mode, height, width, flag = 1;
    flag = inputValue(&mode, &height, &width);
    if (flag == 1) {
        flag = menu(mode, &matrix, height, width);
    }
    if (flag == 1) {
        output(matrix, height, width);
        memFree(mode, matrix, height);
    }
    if (!flag) {
        printf("n/a");
    }
    return flag;
}

int inputValue(int* mode, int* height, int* width) {
    int flag = 1;
    if (!scanf("%d", mode) || (*mode < 1) || (*mode > 4)) flag = 0;
    if (!scanf("%d", width) || (*width < 1)) flag = 0;
    if (!scanf("%d", height) || (*height < 1)) flag = 0;
    return flag;
}

int menu(int mode, int*** matrix, int height, int width) {
    int flag = 1;
    switch (mode) {
    case 1:
        *matrix = statAlloc(&flag, height, width);
        break;
    case 2:
        *matrix = doubleAlloc(&flag, height, width);
        break;
    case 3:
        *matrix = dynAlloc(&flag, height, width);
        break;
    case 4:
        *matrix = dynLinAlloc(&flag, height, width);
        break;
    default:
        flag = 0;
        break;
    }
    if (flag == 1) {
        flag = input(*matrix, height, width);
    }
    return flag;
}

void transform(int* buf, int** matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

int** statAlloc(int* flag, int height, int width) {
    int picture_data[HEIGHTMAX][WIDTHMAX];
    static int* picture[HEIGHTMAX];
    if (height > HEIGHTMAX || width > WIDTHMAX) *flag = 0;
    if (*flag == 1) {
        transform((int*)picture_data, picture, HEIGHTMAX, WIDTHMAX);
    }
    return picture;
}

int** doubleAlloc(int* flag, int height, int width) {
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

int** dynAlloc(int* flag, int height, int width) {
    int** matrix;
    int* arr;
    matrix = (int**)malloc(height * sizeof(int*));
    if (!matrix) *flag = 0;
    if (*flag == 1) {
        arr = (int*)malloc(height * width * sizeof(int));
        if (!arr) *flag = 0;
        if (*flag == 1) {
            for (int i = 0; i < height; i++) {
                matrix[i] = &arr[i * width];
            }
        }
    }
    return matrix;
}
int** dynLinAlloc(int* flag, int height, int width) {
    int len;
    int* ptr, ** arr;

    len = sizeof(int*) * height + sizeof(int) * width * height;
    arr = (int**)malloc(len);
    if (!arr) *flag = 0;

    if (*flag == 1) {
        ptr = (int*)(arr + height);
        for (int i = 0; i < height; i++)
            arr[i] = (ptr + width * i);
    }
    return arr;
}

int input(int** matrix, int height, int width) {
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
void output(int** matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", matrix[i][j]);
            if (j != width - 1) printf(" ");
        }
        if (i != height - 1)printf("\n");
    }
}

void memFree(int mode, int** matrix, int height) {
    switch (mode) {
    case 1:
        break;
    case 2:
        for (int i = 0; i < height; i++) {
            free(matrix[i]);
        }
        break;
    case 3:
        free(matrix);
        break;
    case 4:
        free(matrix);
        break;
    default:
        break;
    }
}
