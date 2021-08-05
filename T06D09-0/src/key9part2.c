#include <stdio.h>

#define LEN 100

void sum(int* buff1, int len1, int* buff2, int len2, int* result, int* rezlen);
int sub(int* buff1, int len1, int* buff2, int len2, int* result, int* rezlen);
int input(int* num, int* len);
void output(int* num, int len);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:ƒ
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
  int flag = 1;
  int num1[LEN], num2[LEN], rez[LEN], len1, len2, rezlen;
  flag = input(num1, &len1);
  if (flag == 1) {
    flag = input(num2, &len2);
    if (flag == 1) {
      sum(num1, len1, num2, len2, rez, &rezlen);
      output(rez, rezlen);
      printf("\n");
      flag = sub(num1, len1, num2, len2, rez, &rezlen);
      if (flag == 1) {
      output(rez, rezlen);
      }
    }
  }
  if (flag == 0) {
    printf("n/a");
  }
  return flag;
}

int input(int* num, int* len) {
  int flag = 1;
  char c = ' ';
  int a;
  *len = -1;
  while (1) {
    if (flag == 0) break;
    scanf("%c", &c);
    if (c == '\n') break;
    if (c == ' ') continue;
    a = c - '0';
    if (a < 0 || a > 9) flag = 0;
    (*len)++;
    if (*len >= LEN) flag = 0;
    num[*len] = a;
  }
  return flag;
}

void output(int* num, int len) {
  int flag = 1, outlfag = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == 0 && flag == 1) {
      continue;
    }
    if (num[i] != 0) flag = 0;
    printf("%d", num[i]);
      outlfag = 1;
    if (i != 0) printf(" ");
  }
    if (outlfag == 0){
        printf("0");
    }
}

void sum(int* buff1, int len1, int* buff2, int len2, int* result, int* rezlen) {
  int flag = 0;
  *rezlen = 0;
  int i, j;
  for (i = len1, j = len2; i >= 0 && j >= 0; i--, j--) {
    if (flag == 0) result[*rezlen] = buff1[i] + buff2[j];
    if (flag == 1) {
      flag = 0;
      result[*rezlen] += buff1[i] + buff2[j];
    }
    if (result[*rezlen] > 9) {
      flag = 1;
      result[*rezlen + 1] = result[*rezlen] / 10;
      result[*rezlen] %= 10;
    }
    (*rezlen)++;
  }
  if (i < 0) {
    for (int k = j; k >= 0; k--) {
      result[(*rezlen)++] = buff2[k];
    }
  }
  if (j < 0) {
    for (int k = i; k >= 0; k--) {
      result[(*rezlen)++] = buff1[k];
    }
  }
}

int sub(int* buff1, int len1, int* buff2, int len2, int* result, int* rezlen) {
  int flag = 0, outflag = 1;
  *rezlen = 0;
  int i, j;

  for (i = len1, j = len2; i >= 0 && j >= 0; i--, j--) {
    if (outflag == 0)break;
    if (flag == 0) result[*rezlen] = buff1[i] - buff2[j];
    if (flag == 1) {
      flag = 0;
      result[*rezlen] += buff1[i] - buff2[j];
    }
    if (result[*rezlen] < 0) {
      if (*rezlen >= len1) outflag = 0;
      flag = 1;
      result[*rezlen + 1] = -1;
      result[*rezlen] += 10;
    }
    (*rezlen)++;
  }

  if (i < 0 && i != j) outflag = 0;
  if (j < 0 && outflag == 1) {
    for (int k = i; k >= 0; k--) {
      if (flag == 0) result[(*rezlen)++] = buff1[k];
      if (flag == 1) {
        flag = 0;
        result[(*rezlen)++] += buff1[k];
      }
    }
  }
  return outflag;
}
