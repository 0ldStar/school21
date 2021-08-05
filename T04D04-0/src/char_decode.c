#include <stdio.h>
void code();
void hexCode();
void reverse();
void decode();

int main(int argc, char** argv) {
    if (argc != 2 || (int)argv[1][0] < 48 && (int)argv[1][0] > 49) {
        printf("n/a");
        return 1;
    }
    int mode;
    mode = argv[1][0] - '0';
    switch (mode) {
    case 0:
        code();
        break;
    case 1:
        decode();
        break;
    default:
        printf("n/a");
        break;
    }

    return 1;
}

void reverse(char str[], int* len) {
    char tmp[100];
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    *len = i;
    for (int i = 0; i < *len; i++) {
        tmp[*len - i - 1] = str[i];
    }
    for (int i = 0; i < *len; i++) {
        str[i] = tmp[i];
    }
    str[*len] = '\0';
}
void hexCode(int x, char strIn[], int* index) {
    char str[100];
    int i = 0, tmp = x, len = 0;
    do {
        if (tmp % 16 < 10) {
            str[i] = tmp % 16 + '0';
            i++;
        } else {
            str[i] = (char)(tmp % 16 + (int)'A' - 10);
            i++;
        }
        tmp /= 16;
    } while (tmp > 0);
    str[i] = '\0';
    reverse(str, &len);
    for (int j = 0; j < len; j++) {
        strIn[j + *index] = str[j];
    }
    (*index) += len;
    strIn[*index] = '\0';
}

void hexDecode(char c1, char c2, char strIn[], int* index) {
    int rez;
    if (c1 < '0' || c1 > '9') {
        rez = ((int)c1 - (int)'A' + 10) * 16;
    } else {
        rez = (c1 - '0') * 16;
    }
    if (c2 < '0' || c2 > '9') {
        rez += (int)c2 - (int)'A' + 10;
    } else {
        rez += (c2 - '0');
    }
    strIn[(*index)++] = (char)rez;
    strIn[(*index)++] = ' ';
    strIn[*index] = '\0';
}

void code() {
    char c, str[100];
    int index = 0;
    do {
        scanf("%c", &c);
        if (c == '\n') {
            if (index == 0) {
                printf("n/a");
                return;
            }
            str[index] = '\0';
            break;
        }
        if (c != ' ') {
            hexCode((int)c, str, &index);
        } else {
            str[index] = ' ';
            index++;
        }
    } while (c != '\n');
    printf("%s", str);
}

void decode() {
    char c1, c2, str[100];
    int iC1, iC2;
    int index = 0;
    do {
        if (scanf("%c", &c1) == 1 && scanf("%c", &c2) == 1) {
            iC1 = (int)c1;
            iC2 = (int)c2;
            if (!((iC1 >= 48 && iC1 <= 57) || (iC1 >= 65 && iC1 <= 70))) {
                printf("n/a");
                return;
            }
            if (!((iC2 >= 48 && iC2 <= 57) || (iC2 >= 65 && iC2 <= 70))) {
                printf("n/a");
                return;
            }
            hexDecode(c1, c2, str, &index);
            if (scanf("%c", &c1) != 1) {
                printf("n/a");
                return;
            }
            if (c1 != ' ') {
                if (c1 == '\n') {
                    str[index - 1] = '\0';
                    break;
                }
                printf("n/a");
                return;
            }
        } else {
            if (c1 == '\n') {
                if (index == 0) {
                    printf("n/a");
                    return;
                }
                break;
            }
            printf("n/a");
            return;
        }
    } while (c1 != '\n');
    printf("%s", str);
}
