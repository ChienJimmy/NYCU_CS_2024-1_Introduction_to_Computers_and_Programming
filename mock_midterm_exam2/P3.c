#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 64
#define NAME_LENGTH 10

struct timestamp {
    int hour, minute;
};

struct message_info {
    struct timestamp time;
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
};

int cmp(const void *a, const void *b);
void sort_message(struct message_info *m, int *total);

int main(void) {
    struct message_info m[100];
    int total;
    scanf("%d", &total);
    for(int i = 0; i < total; i++) {
        scanf("%d:%d %s %[^\n]", &m[i].time.hour, &m[i].time.minute, m[i].name, m[i].message);
    }
    sort_message(m, &total);
    for(int i = 0; i < total; i++) {
        printf("%02d:%02d %s %s\n", m[i].time.hour, m[i].time.minute, m[i].name, m[i].message);
    }
    return 0;
}
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void sort_message(struct message_info *m, int *total) {
    // m is array of each message information wrapped in a struct
    // total is the number of total messages
    struct message_info tmp;
    for (int i = 0; i < *total - 1; i++){
        for (int j = 0; j < *total - i - 1; j++){
            int mjtime, mj1time;
            mjtime = m[j].time.hour * 60 + m[j].time.minute;
            mj1time = m[j+1].time.hour * 60 + m[j+1].time.minute;
            //printf("mj:%d mj1: %d j:%d cmp:%d\n",mjtime,mj1time,j,cmp(&mjtime, &mj1time));
            if(cmp(&mjtime, &mj1time) > 0){
                tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
                //printf("tmph:%d, tmpm:%d\n",tmp.time.hour, tmp.time.minute);
            }
        }
    }
}