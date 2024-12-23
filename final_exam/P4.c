#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PLAYERS 100
#define MAX_CARDS 100

typedef struct {
    char name[51];
    char cards[MAX_CARDS][51];
    int cardCount;
} Player;

Player players[MAX_PLAYERS];
int playerCount = 0;

// 查找玩家索引
int findPlayerIndex(const char *name) {
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, name) == 0)
            return i;
    }
    return -1;
}

// 查找玩家卡片索引
int findCardIndex(int playerIndex, const char *cardName) {
    for (int i = 0; i < players[playerIndex].cardCount; i++) {
        if (strcmp(players[playerIndex].cards[i], cardName) == 0)
            return i;
    }
    return -1;
}

// 新增卡片
void addCard(const char *playerName, const char *cardName) {
    int playerIndex = findPlayerIndex(playerName);
    if (playerIndex == -1) return;

    if (findCardIndex(playerIndex, cardName) != -1) {
        printf("ALREADY EXISTS IN %s\n", playerName);
        return;
    }

    strcpy(players[playerIndex].cards[players[playerIndex].cardCount++], cardName);
    printf("ADDED %s TO %s\n", cardName, playerName);

    if (players[playerIndex].cardCount == 100) {
        printf("%s WINS THE GAME!\n", playerName);
        exit(0);
    }
}

// 移除卡片
void gainCard(const char *playerName, const char *cardName) {
    int playerIndex = findPlayerIndex(playerName);
    if (playerIndex == -1) return;

    int cardIndex = findCardIndex(playerIndex, cardName);
    if (cardIndex == -1) {
        printf("NOT FOUND IN %s\n", playerName);
        return;
    }

    for (int i = cardIndex; i < players[playerIndex].cardCount - 1; i++) {
        strcpy(players[playerIndex].cards[i], players[playerIndex].cards[i + 1]);
    }
    players[playerIndex].cardCount--;
    printf("REMOVED %s FROM %s\n", cardName, playerName);
}

// 查詢卡片
void queryCard(const char *playerName, const char *cardName) {
    int playerIndex = findPlayerIndex(playerName);
    if (playerIndex == -1) return;

    if (findCardIndex(playerIndex, cardName) != -1) {
        printf("%s HAS %s\n", playerName, cardName);
    } else {
        printf("%s DOES NOT HAVE %s\n", playerName, cardName);
    }
}

// 計算卡片總數
void countCards(const char *playerName) {
    int playerIndex = findPlayerIndex(playerName);
    if (playerIndex == -1) return;

    printf("%s TOTAL %d\n", playerName, players[playerIndex].cardCount);
}

// 交易卡片
void tradeCard(const char *player1, const char *player2, const char *cardName) {
    int index1 = findPlayerIndex(player1);
    int index2 = findPlayerIndex(player2);

    if (findCardIndex(index1, cardName) == -1) {
        printf("%s DOES NOT HAVE %s\n", player1, cardName);
    }

    if (findCardIndex(index2, cardName) != -1) {
        printf("%s ALREADY HAS %s\n", player2, cardName);
    }
    if (findCardIndex(index1, cardName) == -1 || findCardIndex(index2, cardName) != -1) return;
    gainCard(player1, cardName);
    addCard(player2, cardName);

    printf("TRADE SUCCESS %s FROM %s TO %s\n", cardName, player1, player2);
    if (players[index2].cardCount == 100) {
        printf("%d WINS THE GAME!\n", index2);
        exit(0);
    }
}

int main() {
    int n;
    char command[10], player1[51], player2[51], cardName[51];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", players[i].name);
        players[i].cardCount = 0;
    }
    playerCount = n;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "END") == 0) break;

        if (strcmp(command, "ADD") == 0) {
            scanf("%s %s", player1, cardName);
            addCard(player1, cardName);
        } else if (strcmp(command, "GAIN") == 0) {
            scanf("%s %s", player1, cardName);
            gainCard(player1, cardName);
        } else if (strcmp(command, "QUERY") == 0) {
            scanf("%s %s", player1, cardName);
            queryCard(player1, cardName);
        } else if (strcmp(command, "COUNT") == 0) {
            scanf("%s", player1);
            countCards(player1);
        } else if (strcmp(command, "TRADE") == 0) {
            scanf("%s %s %s", player1, player2, cardName);
            tradeCard(player1, player2, cardName);
        }
    }

    return 0;
}