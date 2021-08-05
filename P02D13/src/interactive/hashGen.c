int hashCheck(int** field, int* arr, int* len) {
    int flag;

    flag = 0;
    if (!arr) flag = 1;
    if (flag == 0) {
        arr[*len] = getHash(field);
        flag = sameCheck(arr, *len);
        (*len)++;
        if (*len == MAX_SAVE_FRAME) *len = 0;
    }
    return flag;
}

int sameCheck(int* arr, int len) {
    int flag;

    flag = 0;

    for (int i = 0; i < len ; i++) {
        for (int j = 0; j < len; j++) {
        if (arr[i] == arr[j] && i != j) {
            flag = 1;
            break;
        }
        }
    }
    return flag;
}

int getHash(int** fiedld) {
    int sumI, hash, startNumber;

    hash = 0;
    startNumber = 17;

    for (int i = 0; i < ROWS; i++) {
        sumI = 0;
        startNumber = nextPrime(startNumber);
        for (int j = 0; j < COLLUMS; j++) {
            sumI = fiedld[i][j] + sumI * i;
        }
        hash += sumI * startNumber;
    }
    for (int j = 0; j < COLLUMS; j++) {
        sumI = 0;
        startNumber = nextPrime(startNumber);
        for (int i = 0; i < ROWS; i++) {
            sumI = fiedld[i][j] + sumI * j;
        }
        hash += sumI * startNumber;
    }
    return hash;
}

int isPrime(int a) {
    int i, j, k;

    for (i = 2; i <= (int)pow(a, 0.5) + 1; i = i + 1) {
        for (j = 2; j <= (int)pow(a, 0.5) + 1; j = j + 1) {
            k = i * j;
            if (k == a) {
                return 0;
            }
        }
    }
    return 1;
}

int nextPrime(int a) {
    a = a + 1;

    if (isPrime(a)) {
        return (a);
    } else {
        return nextPrime(a);
    }
    return 0;
}
