#ifndef SRC_INCLUDE_H_
#define SRC_INCLUDE_H_

#define COLLUMS 80
#define ROWS 25
#define STDIN_FILENO 0
#define MAX_SAVE_FRAME 20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <termios.h>
#include <time.h>

int sumAround(int** field, int x, int y);
void mInput(int** field, int* end);
void mOutput(int** field);
void nextState(int** currentState, int** nextState, int* emptyFlag, int* freezeFlag);
void game(void);
void gameCycle(int** fieldCurrent, int** fieldNext, int* hashArr, int hashLen);
void swap(int*** a, int*** b);
void init(int*** fieldCurrent, int*** fieldNext, int* status, int** arr, int* len);
void getKey(int* flag);
int isPrime(int a);
int nextPrime(int a);
int getHash(int** field);
char* menu(int* flag);
int sameCheck(int* arr, int len);
int hashCheck(int** field, int* arr, int* len);
void fRead(int** field, int* flag);
void setup_terminal(void);
void reset_terminal(void);

#include "terminal.c"
#include "controller.c"
#include "view.c"
#include "model.c"
#endif  // SRC_INCLUDE_H_
