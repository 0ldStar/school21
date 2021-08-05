#ifndef SRC_STATUS_EVENTS_H_
#define SRC_STATUS_EVENTS_H_

typedef struct status {
    int eventId;
    int moduleId;
    int newStatus;
    char date[11];
    char time[9];
} status;

int statusRead(FILE* fp);
void statusPrint(status* one);
void statusWrite(FILE* db, int ind, status* one);
status* statusSelect(FILE* fp, int id);
int statusInsert(FILE *db, status *entity);
int statusUpdate(FILE* fp, int id, status* entity);
int statusDelete(FILE* fp, int id, char* fileName);
void statusShift(FILE* fp, int ind, int len);
#endif  // SRC_STATUS_EVENTS_H_
