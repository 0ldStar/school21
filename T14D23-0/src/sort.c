#include <stdio.h>
#include "sort.h"
#include "fileArrWork.h"

void heapify(FILE* fp, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && (arrCmp(fp, l, largest) == 1))
        largest = l;

    if (r < n && (arrCmp(fp, r, largest) == 1))
        largest = r;

    if (largest != i) {
        swap(fp, i, largest);

        heapify(fp, n, largest);
    }
}

void heapSort(FILE* fp, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(fp, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(fp, 0, i);
        heapify(fp, i, 0);
    }
}
