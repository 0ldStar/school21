#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fileIO.h"
#include "fileArrWork.h"
#include "sort.h"

int File_read(char* fileName) {
    FILE* fp;
    int flag, inFlag;
    char* name;

    name = filePath(fileName);
    flag = 1; inFlag = 0;
    if ((fp = fopen(name, "rb")) == NULL) {
        flag = 0;
    }
    if (flag == 1) {
        int number;
        int i = 0;
        while (!feof(fp) && !ferror(fp)) {
            inFlag = 1;
            if (fread(&number, sizeof(int), 1, fp) == 1) {
                printf("%d", number);
                if (i % 8 != 7) printf(" ");
                if (i % 8 == 7) printf("\n");
                i++;
            }
        }
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
    fclose(fp);
    return flag;
}
int File_sort(char* fileName) {
    FILE* fp;
    int flag, inFlag;
    char* name;

    name = filePath(fileName);
    flag = 1; inFlag = 0;
    if ((fp = fopen(name, "r+b")) == NULL) {
        flag = 0;
    }
    if (flag == 1) {
        if (!feof(fp)) inFlag = 1;
        fseek(fp, 0L, SEEK_END);
        long sz = ftell(fp) / (8 * sizeof(int));
        heapSort(fp, sz);
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
    fclose(fp);
    return flag;
}

int File_endWrite(char* fileName, int* arr) {
    FILE* fp;
    int flag;
    char* name;

    name = filePath(fileName);
    flag = 1;
    if ((fp = fopen(name, "ab")) == NULL) {
        printf("n/a");
        flag = 0;
    }
    if (flag == 1) {
        for (int i = 0; i < 8; i++) {
            fwrite(&arr[i], sizeof(int), 1, fp);
        }
    }
    if (fp) fclose(fp);
    return flag;
}

int File_search(char* fileName, int* inArr, int* key) {
    FILE* fp;
    int flag, inFlag, findFlag;
    char* name;
    int arr[8];

    name = filePath(fileName);
    flag = 1; inFlag = 0; *key = -1;
    if ((fp = fopen(name, "rb")) == NULL) {
        flag = 0;
    }
    findFlag = 0;
    if (flag == 1) {
        while (!feof(fp) && !ferror(fp)) {
            inFlag = 1;
            if (fread(arr, sizeof(int), 8, fp) == 8) {
                if (check(inArr, arr) == 1) {
                    findFlag = 1;
                    *key = arr[7];
                }
            }
        }
    }
    if (inFlag == 0 || flag == 0 || findFlag == 0) {
        flag = 0;
    }
    fclose(fp);
    return flag;
}

int File_keyWrite(int key) {
    FILE* fp;
    int flag;

    flag = 1;
    if ((fp = fopen("../src/code.txt", "w+r")) == NULL) {
        printf("n/a");
        flag = 0;
    }
    if (flag == 1) {
        fprintf(fp, "%d", key);
    }
    if (fp) fclose(fp);
    return flag;
}
int check(int* a, int* b) {
    int flag;
    flag = 1;
    if (a[0] != b[2] || a[1] != b[1] || a[2] != b[0]) flag = 0;
    return flag;
}
char* filePath(char* fileName) {
    char path[] = "../";
    static char name[100];
    snprintf(name, strlen(path) + 1, "%s", path);
    strncat(name, fileName, strlen(fileName));
    return name;
}
int checkArr(int* a, int* b) {
    int flag;
    if (a[2] > b[0]) {
        flag = 1;
    } else if (a[2] == b[0]) {
        if (a[1] > b[1]) {
            flag = 1;
        } else if (a[1] == b[1]) {
            if (a[0] > b[2]) {
                flag = 1;
            } else if (a[0] == b[2]) {
                flag = 0;
            } else {
                flag = -1;
            }
        } else {
            flag = -1;
        }
    } else {
        flag = -1;
    }
    return flag;
}
int File_clear(char* fileName, int* arr1, int* arr2) {
    FILE* fp;
    int flag, inFlag, findFlag;
    char* name;

    name = filePath(fileName);
    flag = 1; inFlag = 0;
    if ((fp = fopen(name, "r+b")) == NULL) {
        flag = 0;
    }
    findFlag = 0;
    if (flag == 1) {
        int i = 0;
        fseek(fp, 0, SEEK_END);
        int sz = ftell(fp) / (8 * sizeof(int));
        fseek(fp, 0, SEEK_SET);
        while (!feof(fp) && !ferror(fp)) {
            int arr[8];
            if (fread(arr, sizeof(int), 8, fp) == 8) {
                if (checkArr(arr1, arr) <= 0 && checkArr(arr2, arr) >= 0) {
                    inFlag++;
                    shiftArr(fp, i, sz);
                    fseek(fp, i * 8 * sizeof(int), SEEK_SET);
                    sz--;
                    truncate(name, sz * 8 * sizeof(int));
                    i--;
                    findFlag = 1;
                }
                i++;
            }
        }
    }
    if (inFlag == 0 || flag == 0 || findFlag == 0) {
        flag = 0;
    }
    fclose(fp);
    return flag;
}

void shiftArr(FILE* fp, int ind, int len) {
    int arr[8];
    for (int i = ind; i < len - 1; i++) {
        for (int j = 0; j < 8; j++) {
            arr[j] = fRead(fp, (i + 1) * 8 + j);
        }
        fWrite(fp, i, arr);
    }
}
