void mOutput(int** field) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLLUMS; j++) {
      if (field[i][j]) {
        printf("W");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void fRead(int** field, int* flag) {
  char *str;
  FILE* fp;

  str = menu(flag);

  if (*flag == 1) {
    if ((fp = fopen(str, "r")) == NULL) {
      printf("Can't open file '%s'\n", str);
      *flag = 0;
    } else {
      *flag = 1;
      for (int i = 0; i < ROWS; i++) {
        if (*flag == 0) break;
        for (int j = 0; j < COLLUMS; j++) {
          if ((fscanf(fp, "%d", &field[i][j]) != 1) ||
            (field[i][j] != 1 && field[i][j] != 0)) {
            *flag = 0;
            break;
          }
        }
      }
      fclose(fp);
    }
  }
}

char* menu(int* flag) {
  static char str[50];
  int menuExit, desition;

  menuExit = 1;
  str[0] = '-';

  while (menuExit) {
    setup_terminal();
    printf("\033[0d\033[2J");

    printf("===========================================\n"
            "|| Please define initial state:         ||\n"
            "|| ( 1 ) - 5_pentomino                  ||\n"
            "|| ( 2 ) - glider_80_25                 ||\n"
            "|| ( 3 ) - glider_gun                   ||\n"
            "|| ( 4 ) - queen_bee_loop               ||\n"
            "|| ( 5 ) - random                       ||\n"
            "|| ( 6 ) - clock                        ||\n"
            "|| ( 0 ) - for exit                     ||\n"
            "|| Press key 1 .. 6 to start            ||\n"
            "||         or 0 for exit                ||\n"
            "||    and then press any button         ||\n"
            "||       in game Q key for exit         ||\n"
            "==========================================\n");

    scanf("%d", &desition);
    reset_terminal();

    switch (desition) {
    case 1:
    snprintf(str, sizeof(str), "data/5_pentomino.txt");
      break;
    case 2:
    snprintf(str, sizeof(str),  "data/glider_80_25.txt");
      break;
    case 3:
    snprintf(str, sizeof(str), "data/glider_gun.txt");
      break;
    case 4:
    snprintf(str, sizeof(str), "data/queen_bee_loop.txt");
      break;
    case 5:
    snprintf(str, sizeof(str), "data/random.txt");
      break;
    case 6:
    snprintf(str, sizeof(str), "data/clock.txt");
      break;
    case 0:
      *flag = 0;
      break;
    default:
      break;
    }
    if (str[0] != '-' || *flag ==0) menuExit = 0;
  }
  return str;
}
