/*------------------------------------
 Здравствуй, человек!
 Чтобы получить ключ
 поработай с комментариями.
 -------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int* buffer, int* length);
void output(int* buffer, int length);
int sum_numbers(int* buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers, int* outLenght);

/*------------------------------------
 Функция получает массив данных
 через stdin.
 Выдает в stdout особсую сумму
 и сформированных массив
 специальных элементов
 (выбранных с помощью найденной суммы):
 это и будет частью ключа
 -------------------------------------*/

int main() {
    int flag = 1;
    int inLenght, inArr[NMAX], outLenght, outArr[NMAX], sum;
    flag = input(inArr, &inLenght);
    if (flag == 1) {
        sum = sum_numbers(inArr, inLenght);
        flag = find_numbers(inArr, inLenght, sum, outArr, &outLenght);
        if (flag == 1) {
            printf("%d\n", sum);
            output(outArr, outLenght);
        }
    }
    if (flag == 0) {
        printf("n/a");
    }
    return flag;
}

int input(int* buffer, int* length) {
    int flag = 1;
    if (scanf("%d", length) != 1 || *length > NMAX || *length <= 0) {
        flag = 0;
    }
    if (flag == 1) {
        for (int* p = buffer; p - buffer < *length; p++) {
            scanf("%d", p);
        }
    }
    return flag;
}
/*------------------------------------
 Функция должна находить
 сумму четных элементов
 с 0-й позиции.
 -------------------------------------*/
int sum_numbers(int* buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

void output(int* arr, int lenght) {
    for (int* p = arr; p - arr < lenght; p++) {
        printf("%d", *p);
        if (p - arr != lenght - 1) printf(" ");
    }
}

/*------------------------------------
 Функция должна находить
 все элементы, на которые нацело
 делится переданное число и
 записывает их в выходной массив.
 -------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers, int* outLength) {
    *outLength = 0;
    int flag = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            flag = 1;
            numbers[(*outLength)++] = buffer[i];
        }
    }
    return flag;
}
