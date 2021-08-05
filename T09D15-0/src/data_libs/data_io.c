#include "data_io.h"
#include <stdio.h>
int input(double* data, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (!scanf("%lf", &data[i])) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void output(double* data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) printf(" ");
    }
}
