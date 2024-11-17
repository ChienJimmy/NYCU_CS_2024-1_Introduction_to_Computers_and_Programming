#include <stdio.h>
int winner(int player1, char guess1, int player2, char guess2, char judge){
    if ((guess1 == 'r' && guess2 == 's')||(guess1 == 's' && guess2 == 'p')||(guess1 == 'p' && guess2 == 'r')){
        return player1;
    }
    if ((guess1 == 's' && guess2 == 'r')||(guess1 == 'p' && guess2 == 's')||(guess1 == 'r' && guess2 == 'p')){
        return player2;
    }
    if (judge == 's'){
        return (player1 < player2) ? player1 : player2;
    }
    else{
        return (player1 > player2) ? player1 : player2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char guess[n+1];
    char judge[11];
    scanf("%s", guess);
    scanf("%s", judge);
    int players[n];
    for (int i = 0; i < n; i++) {
        players[i] = i + 1;
    }

    int current_round_players = n;
    int round = 0;
    while (current_round_players > 1) {
        int next_round_index = 0;
        for (int i = 0; i < current_round_players; i += 2) {
            int winner_player = winner(players[i], guess[players[i] - 1],
                                       players[i + 1], guess[players[i + 1] - 1],
                                       judge[round]);
            players[next_round_index++] = winner_player;
        }
        current_round_players /= 2;
        round++;
    }
    printf("%d\n", players[0]);
    return 0;
}
