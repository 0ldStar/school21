#include <stdio.h>
#include "fileArrWork.h"

int fRead(FILE* fp, int ind) {
    int num;
    fseek(fp, ind * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, fp);
    return num;
}
void fWrite(FILE* fp, int ind, int* arr) {
    fseek(fp, ind * 8 * sizeof(int), SEEK_SET);
    fwrite(arr, sizeof(int), 8, fp);
}

int arrCmp(FILE* fp, int i, int j) {
    int flag;

    flag = 0;
    for (int k = 0; k < 8 && flag == 0; k++) {
        int a = fRead(fp, i * 8 + k);
        int b = fRead(fp, j * 8 + k);
        if (a > b) {
            flag = 1;
        } else if (a < b) {
            flag = -1;
        }
    }
    return flag;
}

void swap(FILE* fp, int i, int j) {
    int tmp1[8];
    int tmp2[8];
    for (int k = 0; k < 8; k++) {
        tmp1[k] = fRead(fp, i * 8 + k);
        tmp2[k] = fRead(fp, j * 8 + k);
    }
    fWrite(fp, i, tmp2);
    fWrite(fp, j, tmp1);
}
