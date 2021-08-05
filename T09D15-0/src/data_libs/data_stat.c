#include "data_stat.h"
#include <math.h>

double max(double* data, int n) {
    double max = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max) max = data[i];
    }
    return max;
}

double min(double* data, int n) {
    double min = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min) min = data[i];
    }
    return min;
}

double mean(double* data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / (double)n;
}

double variance(double* data, int n) {
    double sum = 0;
    double meanValue = mean(data, n);
    for (int i = 0; i < n; i++) {
        sum += pow((data[i] - meanValue), 2);
    }
    return sum / (double)n;
}

void swap(double* a, double* b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(double* data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1])
                swap(&data[j], &data[j + 1]);
        }
    }
}
