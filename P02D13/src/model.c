void game() {
  int** fieldCurrent, ** fieldNext;
  int* arr;
  int len, flag;

  fieldCurrent = fieldNext = NULL;
  setup_terminal();
  init(&fieldCurrent, &fieldNext, &flag, &arr, &len);

  if (flag) {
    gameCycle(fieldCurrent, fieldNext, arr, len);
  }
  reset_terminal();
  free(arr);
}

void gameCycle(int** fieldCurrent, int** fieldNext, int* hashArr, int hashLen) {
  int freezeFlag, empltyFlag, keyFlag, sameFlag;

  keyFlag = 0, freezeFlag = 0, empltyFlag = 0, sameFlag = 0;

  mOutput(fieldCurrent);
  while (1) {
    getKey(&keyFlag);
    setup_terminal();
    printf("\033[0d\033[2J");
    reset_terminal();
    if (keyFlag == 1) {
      nextState(fieldCurrent, fieldNext, &freezeFlag, &empltyFlag);
      mOutput(fieldNext);
      sameFlag = hashCheck(fieldNext, hashArr, &hashLen);
      swap(&fieldCurrent, &fieldNext);
      printf("\n");
    } else {
      mOutput(fieldCurrent);
    }
    if (freezeFlag == 1 || empltyFlag == 1 || sameFlag == 1 || keyFlag == 2) break;
  }
  reset_terminal();
}
