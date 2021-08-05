#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "state_sort.h"
#include "fileIO.h"

int main() {
    menu();
    return 0;
}

void menu() {
    char* fileName;
    int mode;
    int flag;

    flag = 1;
    fileName = (char*)malloc(100 * sizeof(char));
    fgets(fileName, 100, stdin);
    fileName[strlen(fileName) - 1] = '\0';
    scanf("%d", &mode);
    if (mode == 0) {
        File_read(fileName);
    } else if (mode == 1) {
        File_sort(fileName);
        File_read(fileName);
    } else if (mode == 2) {
        int inArr[8];
        for (int i = 0; i < 8 && flag; i++) {
            if (scanf("%d", &inArr[i]) != 1) flag = 0;
        }
        if (flag == 1) {
            File_endWrite(fileName, inArr);
            File_sort(fileName);
            File_read(fileName);
        }
    } else {
        flag = 0;
    }
    if (flag == 0) {
        printf("n/a");
    }
    free(fileName);
}
