#ifndef SRC_CIPHER_H_
#define SRC_CIPHER_H_

void menu();
int File_read(char *fileName);
int File_write(char* fileName, char* str);
int CaesarCipher(char* dir);
int isCorH(char* str, char c);

#endif  // SRC_CIPHER_H_
