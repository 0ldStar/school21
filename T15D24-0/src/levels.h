#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_

typedef struct level {
    int memLvl;
    int memCount;
    int secFlag;
} level;

int levelsRead(FILE* fp);
void levelsPrint(level* one);
void levelsWrite(FILE* db, int ind, level* one);
level* levelsSelect(FILE* fp, int id);
int levelsInsert(FILE *db, level *entity);
int levelsUpdate(FILE* fp, int id, level* entity);
int levelsDelete(FILE* fp, int id, char* fileName);
void levelsShift(FILE* fp, int ind, int len);

#endif  // SRC_LEVELS_H_
