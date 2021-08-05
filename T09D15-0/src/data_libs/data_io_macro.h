#ifndef SRC_DATA_LIBS_DATA_IO_MACRO_H_
#define SRC_DATA_LIBS_DATA_IO_MACRO_H_
#include <stdio.h>

int inputInt(int* data, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (!scanf("%d", &data[i])) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int inputDouble(double* data, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (!scanf("%lf", &data[i])) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int inputChar(char* data, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (!scanf("%c", &data[i])) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int inputFloat(float* data, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (!scanf("%f", &data[i])) {
            flag = 0;
            break;
        }
    }
    return flag;
}
#define input(X, N)          \
    _Generic((X),       \
    int*: inputInt,       \
    char*: inputChar,     \
    float*: inputFloat,   \
    double*: inputDouble,   \
    default: inputDouble    \
)(X, N)

void outputInt(int* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", data[i]);
        if (i != n - 1) printf(" ");
    }
}
void outputDouble(double* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) printf(" ");
    }
}
void outputChar(char* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", data[i]);
        if (i != n - 1) printf(" ");
    }
}
void outputFloat(float* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f", data[i]);
        if (i != n - 1) printf(" ");
    }
}
#define output(X, N)          \
    _Generic((X),       \
    int*: outputInt,       \
    char*: outputChar,     \
    float*: outputFloat,   \
    double*: outputDouble,   \
    default: outputDouble    \
)(X, N)
#endif  // SRC_DATA_LIBS_DATA_IO_MACRO_H_
