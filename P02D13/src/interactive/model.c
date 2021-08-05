void game(void) {
  int** fieldCurrent, ** fieldNext;
  int* arr;
  int len, flag;

  fieldCurrent = fieldNext = NULL;
  setup_terminal();
  init(&fieldCurrent, &fieldNext, &flag, &arr, &len);
  reset_terminal();

  if (flag) {
    gameCycle(fieldCurrent, fieldNext, arr, len);
  }
  free(arr);
}

void gameCycle(int** fieldCurrent, int** fieldNext, int* hashArr, int hashLen) {
  int freezeFlag, empltyFlag, keyFlag, sameFlag, speed;
  speed = 1;
  keyFlag = 0, freezeFlag = 0, empltyFlag = 0, sameFlag = 0;
  clock_t time = clock();
  unsigned long step = 10000;
  mOutput(fieldCurrent);
  while (1) {
    setup_terminal();
    printf("\033[0d\033[2J");
    reset_terminal();
    getKey(&keyFlag);
    if (keyFlag != 0) {
      speed = keyFlag;
    }
    if ((clock() - time) >= step / speed) {
      time = clock();
      nextState(fieldCurrent, fieldNext, &freezeFlag, &empltyFlag);
      mOutput(fieldNext);
      sameFlag = hashCheck(fieldNext, hashArr, &hashLen);
      swap(&fieldCurrent, &fieldNext);
      printf("\n");
    }
    if (freezeFlag == 1 || empltyFlag == 1 || sameFlag == 1 || keyFlag == 10) break;
  }
}
