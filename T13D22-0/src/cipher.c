#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "cipher.h"
#include "log_levels.h"
#include "logger.h"

int main() {
    menu();

    return 0;
}

void menu() {
    char* fileName, * str;
    int mode, flag, menuFlag, fileFlag;
    char* mesList[] = { "Read the file  ",
    "Cannot open file", "Add message in file:  ",
     "Ciphered file", "Close the file" };
    fileName = (char*)malloc(100 * sizeof(char));
    str = (char*)malloc(100 * sizeof(char));

    menuFlag = 1;
#ifdef LOG
    char message[200];
    FILE* fp;
    log_init("log.txt", &fp);
#endif  // LOG
    while (menuFlag) {
        int c;
        scanf("%d", &mode);
        if (mode == 1) {
            while ((c = getchar()) != '\n' && c != EOF) { }
            fgets(fileName, 100, stdin);
            fileName[strlen(fileName) - 1] = '\0';
            fileFlag = File_read(fileName);
#ifdef LOG
            snprintf(message, strlen(mesList[0]), "%s", mesList[0]);
            strncat(message, fileName, strlen(fileName));
            if (fileFlag == 1) addLog(message, info, fp);
            if (fileFlag == 0) addLog("Cannot open file", error, fp);

#endif  // LOG
        } else if (mode == 2) {
            while ((c = getchar()) != '\n' && c != EOF) {}
            fgets(str, 100, stdin);
            if (fileFlag == 1) {
                flag = File_write(fileName, str);
                File_read(fileName);
            } else {
                printf("n/a");
            }
#ifdef LOG
            snprintf(message, strlen(mesList[2]), "%s", mesList[2]);
            strncat(message, str, strlen(str));
            if (flag == 1) addLog(message, info, fp);
            if (flag == 0) addLog("Cannot open file", error, fp);
#endif  // LOG
        } else if (mode == 3) {
            while ((c = getchar()) != '\n' && c != EOF) {}
            fgets(str, 100, stdin);
            str[strlen(str) - 1] = '\0';
            flag = CaesarCipher(str);

#ifdef LOG
            if (flag == 1) addLog("Ciphered file", info, fp);
            if (flag == 0) addLog("Cannot open file", error, fp);
#endif  // LOG
        } else if (mode == -1) {
            menuFlag = 0;
        } else {
            printf("n/a");
            while ((c = getchar()) != '\n') { }
        }
    }
#ifdef LOG
    addLog("Close the file", info, fp);
    log_close(fp);
#endif  // LOG
    free(str);
    free(fileName);
}

int File_read(char* fileName) {
    FILE* fp;
    int flag, inFlag;
    char name[100];
    char path[] = "../";
    snprintf(name, strlen(path) + 1, "%s", path);
    strncat(name, fileName, strlen(fileName));
    flag = 1; inFlag = 0;
    if ((fp = fopen(name, "r+t")) == NULL) {
        flag = 0;
    }
    if (flag == 1) {
        char* str = NULL;
        size_t len = 0;
        while (getline(&str, &len, fp) != -1) {
            printf("%s", str);
            inFlag = 1;
        }
        if (str) free(str);
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
    fclose(fp);
    return flag;
}

int File_write(char* fileName, char* str) {
    FILE* fp;
    int flag;
    char name[100];
    char path[] = "../";
    snprintf(name, strlen(path) + 1, "%s", path);
    strncat(name, fileName, strlen(fileName));
    flag = 1;
    if ((fp = fopen(name, "a")) == NULL) {
        printf("n/a");
        flag = 0;
    }
    if (flag == 1) {
        fprintf(fp, "%s", str);
    }
    if (fp) fclose(fp);
    return flag;
}

int isCorH(char* str, char c) {
    int len = strlen(str);
    int status;
    status = 0;
    if (str[len - 1] == c) {
        if (str[len - 2] == '.') {
            status = 1;
        }
    }
    return status;
}

int CaesarCipher(char* dir) {
    DIR* pDir;
    int flag;
    char name[100];
    char path[] = "../";
    snprintf(name, strlen(path) + 1, "%s", path);
    strncat(name, dir, strlen(dir));
    flag = 1;
    pDir = opendir(name);
    if (pDir == NULL) {
        printf("n/a");
        flag = 0;
    }
    if (flag == 1) {
        struct dirent* pDirent;
        while ((pDirent = readdir(pDir)) != NULL) {
            char fileName[100];
            FILE* fp;
            snprintf(fileName, strlen(name) + 1, "%s", name);
            strncat(fileName, pDirent->d_name, strlen(pDirent->d_name));
            if (isCorH(pDirent->d_name, 'c')) {
                flag = 1;
                if ((fp = fopen(fileName, "r+t")) == NULL) {
                    printf("n/a");
                    flag = 0;
                }
                if (flag == 1) {
                    long pos = ftell(fp);
                    char buf[500];
                    while (fgets(buf, 500, fp) != NULL) {
                        for (int i = 0; i < 500 && buf[i] != '\0'; i++) {
                            if (buf[i] >= 'A' && buf[i] <= 'Z')
                                buf[i] = 64 + (buf[i] - 64 + 3) % 26;
                            if (buf[i] >= 'a' && buf[i] <= 'z')
                                buf[i] = 96 + (buf[i] - 96 + 3) % 26;
                        }
                        fseek(fp, pos, SEEK_SET);
                        fprintf(fp, "%s", buf);
                        fflush(fp);
                        pos = ftell(fp);
                    }
                    fclose(fp);
                }
            }
            if (isCorH(pDirent->d_name, 'h')) {
                fp = fopen(fileName, "w");
                fclose(fp);
            }
        }

        closedir(pDir);
    }
    return flag;
}
