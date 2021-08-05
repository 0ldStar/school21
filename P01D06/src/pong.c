// Copyright 2021 Rpoutine Gconn Blucila
#include <stdio.h>
#define WIDTH 81
#define HIGHT 26
#define PADDLE1_X 7  //Значение 1 ракетки по х
#define PADDLE2_X WIDTH - 7
#define BALLSTARTX 40  //Начальная позичия мяча по х
#define BALLSTARTY 13
#define BALLSTARTMOVE 0             //  Начальное движение мяча
void graph();                       //  Функция отрисовки поля со всеми включениями
void ballCalc();                    //  Функция полета мяча
void paddleCal(char, int*, int*);  //  Функция движения ракеток
int main() {
    char command;                                      //  Значение того, что было нажато на клавиатуре
    int paddle1_y = 13, paddle2_y = 13;                //  Начальное положение ракеток по у
    int ballX = BALLSTARTX, ballY = BALLSTARTY;        //  Начальное положение мяча
    int move = BALLSTARTMOVE;                          //  Начальное накправление мяча
    int scoreF = 0, scoreS = 0, goalFlag = 0, winFlag;
//  Начальные значения счета, указатель забит ли мяч и кому , указатель окончания игры
    printf("PRESS ENTER TO START");
    while (1) {
        if (goalFlag == 1) {                 //  Если забит мяч превому
            goalFlag = 0;  //  Изменяет значение опять на не гол
            ballX = 8;    //  Вывод положения мяча после гола по х
            ballY = paddle1_y;
            move = 0;  //  Назначаем новый способ движения
        }
        if (goalFlag == 2) {
            goalFlag = 0;
            ballX = 73;
            ballY = paddle2_y;
            move = 3;
        }
        if (scanf("%c", &command) == 1 || command != '\n') {
            //Если нажали какой-нибудь символ или нет переноса строки
            graph(&ballX, &ballY, &paddle1_y,
                &paddle2_y, scoreF, scoreS, winFlag);  // Отрисовывает поле
            if ((command == 'A') || (command == 'Z') ||
                (command == 'K') || (command == 'M') || (command == ' ')) {
                    //Проверка будет ли двигаться ракетка
                ballCalc(&ballX, &ballY, &move, paddle1_y,
                    paddle2_y, &scoreF, &scoreS, &goalFlag);  // Изменяет положение мяча
                paddleCal(command, &paddle1_y, &paddle2_y);       // Изменяет положение ракетки
            }
        }
        if (scoreF == 21) {                //Проверяем значение счета
            winFlag = 1;  // Окончена игра для 1
        }
        if (scoreS == 21) {
            winFlag = 2;
        }
        if (winFlag == 1 || winFlag == 2) {  // Проверка окончена ли игра
            graph(&ballX, &ballY, &paddle1_y,
                &paddle2_y, scoreF, scoreS, winFlag);
            break;
        }
    }
}

/*
* Mode to move a ball
0 - Right Up
1 - Right Down
2 - Left Donw
3 - Left Up
*/

void ballCalc(int* x, int* y, int* move, int paddle1_y,
    int paddle2_y, int* scoreF, int* scoreS, int* goalFlag) {
    if (*x == PADDLE1_X && (*y < paddle1_y - 1 || *y > paddle1_y + 1)) {
        // Проверяем не попал ли мяч на линию ракетки по х и не попал на ракетку
        (*scoreS)++;   // Увеличиваем счет второго
        *goalFlag = 1;  // Указываем, что гол забит первому
    }
    if (*x == PADDLE2_X && (*y < paddle2_y - 1 || *y > paddle2_y + 1)) {
        (*scoreF)++;
        *goalFlag = 2;
    }
    switch (*move) {  // Обработка отражения
    case 0:
        if (*x == 80 || *x == PADDLE2_X && *y >= paddle2_y - 1
            && *y <= paddle2_y + 1) {
        // Проверка врезается в правый край поля или в ракетку 2
            *move = 3;  // Меняет направление: влево вверх
        }
        if (*y == 1) {              // Проверка врезался ли в потолок
            *move = 1;  //  Меняет направление: вправо вниз
        }
        break;
    case 1:
        if (*x == 80 || *x == PADDLE2_X && *y >= paddle2_y - 1
        // Проверка врезается в правый край или в ракетку 2
            && *y <= paddle2_y + 1) {
            *move = 2;
        }
        if (*y == 25) {  // Проверка врезается ли в пол
            *move = 0;
        }
        break;
    case 2:
        if (*x == 1 || *x == PADDLE1_X && *y >= paddle1_y - 1
        // Проверка врезается в левый край или в ракетку 1
            && *y <= paddle1_y + 1) {
            *move = 1;
        }
        if (*y == 25) {  // Проверка врезается ли в пол
            *move = 3;
        }
        break;
    case 3:
        if (*x == 1 || *x == PADDLE1_X && *y >= paddle1_y - 1 && *y <= paddle1_y + 1) {
            *move = 0;
        }
        if (*y == 1) {
            *move = 2;
        }
        break;
    default:   // Выхот при ошибке
        break;
    }
    switch (*move) {  // Описание полета мяча
    case 0:
        (*x)++;  // Мяч вправо вниз
        (*y)--;
        break;
    case 1:
        (*x)++;
        (*y)++;
        break;
    case 2:
        (*x)--;
        (*y)++;
        break;
    case 3:
        (*x)--;
        (*y)--;
        break;
    default:
        break;
    }
}
void paddleCal(char mode, int* paddle1_y, int* paddle2_y) {  // Движение ракеток
    if (mode == 'Z') {  // Будет ли двигаться вниз 1 ракетка
        if (*paddle1_y + 2 < HIGHT) {                    // Сможет ли двигаться
            *paddle1_y += 1;  // Меняем положение центра ракетки по у
        }
    } else if (mode == 'A') {
        if (*paddle1_y - 2 > 0) {
            *paddle1_y -= 1;
        }
    } else if (mode == 'M') {
        if (*paddle2_y + 2 < HIGHT) {
            *paddle2_y += 1;
        }
    } else if (mode == 'K') {
        if (*paddle2_y - 2 > 0) {
            *paddle2_y -= 1;
        }
    }
}
void graph(int* ballX, int* ballY, int* paddle1_y,
    int* paddle2_y, int scoreF, int scoreS, int winFlag) {
    char str[] = "WINNER";
    int i = 0;  // Счетчик для вывода букв
    for (int y = 0; y < 27; y++) {
        for (int x = 0; x < 82; x++) {
            if (x == 0 || x == 81 || y == 0 || y == 26) {  // Отрисовка рамки
                printf("#");
            } else if (x == *ballX && y == *ballY) {
                printf("*");
            } else if (((y == *paddle1_y - 1) || (y == *paddle1_y) ||
             (y == *paddle1_y + 1)) && (x == PADDLE1_X)) {
                printf("|");
            } else if (((y == *paddle2_y - 1) || (y == *paddle2_y) ||
                (y == *paddle2_y + 1)) &&
                (x == PADDLE2_X)) {
                printf("|");
            } else if (x == 40 && y != 0 && y != 26) {  // Отрисовка сетки
                printf("[");
            } else if (x == 41 && y != 0 && y != 26) {
                printf("]");
            } else if ((scoreF > 9) && ((x == 37) && (y == 2) ||
                ((x == 38) && (y == 2)))) {  // Отрисовка счета
                if (x == 37) {
                    printf("%d", scoreF / 10);
                } else {
                    printf("%d", scoreF % 10);
                }
            } else if ((scoreF < 10) && (x == 38) && (y == 2)) {
                printf("%d", scoreF);
            } else if ((scoreS > 9) && ((x == 43) && (y == 2) ||
                ((x == 44) && (y == 2)))) {
                if (x == 43) {
                    printf("%d", scoreS / 10);
                } else {
                    printf("%d", scoreS % 10);
                }
            } else if ((scoreS < 10) && (x == 43) && (y == 2)) {
                printf("%d", scoreS);
            } else if ((winFlag == 1) && (x == 17 + i)  // Проверка окончания игры и отрисовка поздравления
                && (y == 12) && (i < 6)) {
                printf("%c", str[i]);
                i++;
            } else if ((winFlag == 2) && (x == 57 + i) && (y == 12) && (i < 6)) {
                printf("%c", str[i]);
                i++;
            } else {  // В других ситуациях пробел
                printf(" ");
            }
        }
        printf("\n");
    }
}
