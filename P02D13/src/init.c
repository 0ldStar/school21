void init(int*** fieldCurrent, int*** fieldNext, int* flag, int** arr, int* len) {
    static int A[ROWS * COLLUMS] = { 0 };
    static int B[ROWS * COLLUMS] = { 0 };

    static int* rowStartA[ROWS];
    for (int i = 0; i < ROWS; i++) {
        rowStartA[i] = &A[i * COLLUMS];
    }
    *fieldCurrent = (int**)&rowStartA[0];

    static int* rowStartB[ROWS];
    for (int i = 0; i < ROWS; i++) {
        rowStartB[i] = &B[i * COLLUMS];
    }
    *fieldNext = (int**)&rowStartB[0];

    *flag = 1;
    *len = 1;

    fRead(*fieldCurrent, flag);

    *arr = (int*)malloc(sizeof(int));
    *arr[0] = getHash(*fieldCurrent);
}
