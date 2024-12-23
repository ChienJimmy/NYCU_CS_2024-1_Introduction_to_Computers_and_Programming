#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WAVEFORM_HEIGHT 68

typedef struct {
    char surname[256];
    char name[256];
    char rarity[4];
    char type[10];
    int vocal;
    int dance;
    int visual;
    int mental;
} Card;

int getRarityBase(const char *rarity) {
    if (strcmp(rarity, "R") == 0) return 13;
    if (strcmp(rarity, "SR") == 0) return 113;
    if (strcmp(rarity, "SSR") == 0) return 1103;
    return 0;
}

void trainProduce(Card *produce, Card *support) {
    int rarityBase = getRarityBase(support->rarity);
    produce->vocal += (int)pow(produce->vocal, support->vocal) % rarityBase;
    produce->dance += (int)pow(produce->dance, support->dance) % rarityBase;
    produce->visual += (int)pow(produce->visual, support->visual) % rarityBase;
    produce->mental += (int)pow(produce->mental, support->mental) % rarityBase;
}

void scheduleTraining(Card *produce) {
    const char *activities[5] = {"聲樂課程", "美容課程", "舞蹈課程", "廣播收錄", "雜誌拍攝"};
    int activityEffects[5][4] = {
        {10, 0, 0, 0},  // 聲樂課程
        {0, 10, 0, 0},  // 美容課程
        {0, 0, 10, 0},  // 舞蹈課程
        {3, 0, 0, 2},   // 廣播收錄
        {0, 3, 0, 2}    // 雜誌拍攝
    };

    int lastActivity = -1;
    for (int week = 0; week < 10; week++) {
        int bestActivity = -1;
        int bestMinValue = -1;

        for (int i = 0; i < 5; i++) {
            if (i == lastActivity) continue;

            int newValues[4] = {
                produce->vocal + activityEffects[i][0],
                produce->visual + activityEffects[i][1],
                produce->dance + activityEffects[i][2],
                produce->mental + activityEffects[i][3]
            };

            int minValue = newValues[0];
            for (int j = 1; j < 4; j++) {
                if (newValues[j] < minValue) {
                    minValue = newValues[j];
                }
            }

            if (minValue > bestMinValue || bestActivity == -1) {
                bestMinValue = minValue;
                bestActivity = i;
            }
        }

        produce->vocal += activityEffects[bestActivity][0];
        produce->visual += activityEffects[bestActivity][1];
        produce->dance += activityEffects[bestActivity][2];
        produce->mental += activityEffects[bestActivity][3];
        lastActivity = bestActivity;
    }
}

int main() {
    char domain[256];
    fgets(domain, sizeof(domain), stdin);
    domain[strcspn(domain, "\n")] = '\0';

    char line[1024];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';

        char url[512];
        Card card1, card2;
        int numCards = sscanf(line, "%511s \"%255[^\"] %255[^\"]\" %3s %9s %d %d %d %d \"%255[^\"] %255[^\"]\" %3s %9s %d %d %d %d",
                              url, card1.surname, card1.name, card1.rarity, card1.type,
                              &card1.vocal, &card1.dance, &card1.visual, &card1.mental,
                              card2.surname, card2.name, card2.rarity, card2.type,
                              &card2.vocal, &card2.dance, &card2.visual, &card2.mental);

        if (strncmp(url, "https://", 8) != 0 || strstr(url, domain) == NULL || strstr(url, "/produce") == NULL) {
            printf("Url error\n");
            continue;
        }

        if (numCards == 8) {
            printf("Card type error\n");
            continue;
        }

        if (numCards != 16) {
            printf("Card type error\n");
            continue;
        }

        if ((strcmp(card1.type, "Produce") == 0 && strcmp(card2.type, "Support") == 0) ||
            (strcmp(card1.type, "Support") == 0 && strcmp(card2.type, "Produce") == 0)) {
            Card *produce = strcmp(card1.type, "Produce") == 0 ? &card1 : &card2;
            Card *support = strcmp(card1.type, "Support") == 0 ? &card1 : &card2;

            trainProduce(produce, support);
            scheduleTraining(produce);

            printf("Vocal: %d\n", produce->vocal);
            printf("Visual: %d\n", produce->visual);
            printf("Dance: %d\n", produce->dance);
            printf("Mental: %d\n", produce->mental);
        } else {
            printf("Card type error\n");
        }
    }

    return 0;
}