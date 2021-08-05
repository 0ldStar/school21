#include "hashGen.c"
#include "init.c"

void nextState(int** currentState, int** nextState, int* freezeFlag, int* emptyFlag) {
    int sumValue = 0;

    sumValue = 0, * freezeFlag = 1, * emptyFlag = 1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLLUMS; j++) {
            sumValue = sumAround(currentState, i, j);
            if (currentState[i][j]) {
                if (sumValue > 3) {
                    nextState[i][j] = 0;
                } else if (sumValue < 2) {
                    nextState[i][j] = 0;
                } else {
                    *emptyFlag = 0;
                    nextState[i][j] = currentState[i][j];
                }
            } else {
                if (sumValue == 3) {
                    *emptyFlag = 0;
                    nextState[i][j] = 1;
                } else {
                    nextState[i][j] = currentState[i][j];
                }
            }
            if (nextState[i][j] != currentState[i][j]) *freezeFlag = 0;
        }
    }
}

int sumAround(int** fiedld, int y, int x) {
    int sum, leftBorder, rightBorder, upBorder, downBorder, kX, kY;
    sum = 0;

    upBorder = y + 1;
    leftBorder = x - 1;
    downBorder = y - 1;
    rightBorder = x + 1;

    for (int i = downBorder; i <= upBorder; i++) {
        for (int j = leftBorder; j <= rightBorder; j++) {
            kX = j;
            kY = i;
            if (i == -1) kY = ROWS - 1;
            if (i == ROWS) kY = 0;
            if (j == -1) kX = COLLUMS - 1;
            if (j == COLLUMS) kX = 0;
            if (x == j && y == i) continue;
            sum += fiedld[kY][kX];
        }
    }
    return sum;
}

void swap(int*** a, int*** b) {
    int** tmp = *a;
    *a = *b;
    *b = tmp;
}

void getKey(int* flag) {
    char key;

    if (scanf("%c", &key) == 1) {
        if (key == ' ') {
            *flag = 1;
        } else if (key == 'Q' || key == 'q') {
            *flag = 2;
        } else {
            *flag = 0;
        }
    } else {
        *flag = 0;
    }
}
