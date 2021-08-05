#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileIO.h"
#include "clear_state.h"

int main() {
    clean();
    return 0;
}

void clean() {
    char* fileName;
    int flag;
    char c;

    flag = 1;
    fileName = (char*)malloc(100 * sizeof(char));
    fgets(fileName, 100, stdin);
    fileName[strlen(fileName) - 1] = '\0';
    int arr1[8], arr2[8];
    if (scanf("%2d%c%2d%c%4d", &arr1[0], &c, &arr1[1], &c, &arr1[2]) != 5) flag = 0;
    if (scanf("%2d%c%2d%c%4d", &arr2[0], &c, &arr2[1], &c, &arr2[2]) != 5) flag = 0;
    if (flag == 1) {
        flag = File_clear(fileName, arr1, arr2);
        if (flag == 1) File_read(fileName);
    }
    if (flag == 0) {
        printf("n/a");
    }
    free(fileName);
}
