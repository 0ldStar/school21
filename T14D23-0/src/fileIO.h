#ifndef SRC_FILEIO_H_
#define SRC_FILEIO_H_

int File_read(char* fileName);
int File_endWrite(char* fileName, int* arr);
int File_sort(char* fileName);
int File_search(char* fileName, int* arr, int* key);
char* filePath(char* fileName);
int check(int* a, int* b);
int checkArr(int* a, int* b);
int File_keyWrite(int key);
int File_clear(char* fileName, int* arr1, int* arr2);
void shiftArr(FILE* fp, int ind, int len);

#endif  // SRC_FILEIO_H_
