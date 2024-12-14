#include <stdio.h>
#include <stdlib.h>
struct Card{
    int suit;
    int rank;
};

struct Player{
    struct Card hand[5];
};

struct Player players[4];

void ReadCard(int player_num);
int ChangeSuit(char input);
int ChangeRank(char input);
void SortCard();
int JudgePoker(int player_num);

int main(void){
    for (int i = 0; i < 4; i++){
        ReadCard(i);
        /*for (int j = 0; j < 5; j++){
            printf("player%d card%d:%d %d\n", i, j, players[i].hand[j].suit, players[i].hand[j].rank);
        }*/
    }
    SortCard();
    /*for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            printf("player%d card%d:%d %d\n", i, j, players[i].hand[j].suit, players[i].hand[j].rank);
        }
    }*/
    int score[4] = {0}, score_sort[4] = {0};
    for (int i = 0; i < 4; i++){
        score[i] = JudgePoker(i);
        score_sort[i] = score[i];
        //printf("player%d's score: %d\n", i, score[i]);
    }
    // Sort by score to count their ranking
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3 - i; j++){
            if (score_sort[j] < score_sort[j+1]){
                int score_tmp = score_sort[j];
                score_sort[j] = score_sort[j+1];
                score_sort [j+1] = score_tmp;
            }
        }
    }
    // Print their rank based on `score_sort`
    const char player_name[4] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (score_sort[i] == score[j]){
                printf("%c ", player_name[j]);
            }
        }
    }
    return 0;
}

/*Transform rank into an interger.
2-9 ->  2-9
t   ->  10
j   ->  11
q   ->  12
k   ->  13
a   ->  14*/
int ChangeRank(char input){
    if (input <= '9' && input >= '2') return (input - '0');
    if (input == 't') return 10;
    if (input == 'j') return 11;
    if (input == 'q') return 12;
    if (input == 'k') return 13;
    if (input == 'a') return 14;
    return -1;
}

/*Transform suit into an interger.
c   ->  1
d   ->  2
h   ->  3
s   ->  4*/
int ChangeSuit(char input){
    if (input == 'c') return 1;
    if (input == 'd') return 2;
    if (input == 'h') return 3;
    if (input == 's') return 4;
    return -1;
}

/* Read the input and place the infomation in `players[player_num]` */
void ReadCard(int player_num){
    char suit, rank;
    for (int i = 0; i < 5; i++){
        scanf("%c%c", &rank, &suit);
        getchar();
        players[player_num].hand[i].suit = ChangeSuit(suit);
        players[player_num].hand[i].rank = ChangeRank(rank);
    }
}

/* Sort `Card` by the order from lowest to highest */
void SortCard(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4 - j; k++){
                if ((players[i].hand[k].rank * 10 + players[i].hand[k].suit) > (players[i].hand[k+1].rank * 10 + players[i].hand[k+1].suit)){
                    struct Card tmp = players[i].hand[k];
                    players[i].hand[k] = players[i].hand[k+1];
                    players[i].hand[k+1] = tmp;
                }
            }
        }
    }
}

/*JudgePoker use input of player number to judge the player's cards and return a score of his/her cards.
Before judge, the card must be sorted from lowest to highest by rank first and if rank is same then by suit.*/
int JudgePoker(int player_num){
// Check straight flush
    int cont = 0;
    struct Player player = players[player_num];
    for (int i = 1; i < 5; i++){
        if ((player.hand[0].rank + i != player.hand[i].rank) || (player.hand[0].suit != player.hand[i].suit)){
            cont = 1;
            break;
        }
    }
    if (!cont){
        return 10000 + 10 * player.hand[4].rank + player.hand[4].suit;
    }

// Check four-of-a-kind
    cont = 0;
    int fir_r = 0, sec_r = 0;
    int fir_r_num = 0, sec_r_num = 0;
    for (int i = 0; i < 5; i++){
        if (player.hand[i].rank != fir_r){
            if (fir_r == 0){
                fir_r = player.hand[i].rank;
                fir_r_num = 1;
            }
            else if (sec_r == 0){
                sec_r = player.hand[i].rank;
                sec_r_num = 1;
            }
            else if (player.hand[i].rank == sec_r){
                sec_r_num ++;
            }
            else { // This case means the player has more than 2 different ranks, hence four_of_a_kind must impossible
                cont = 1;
                break;
            }
        }
        else{
            fir_r_num ++;
        }
    }
    //printf("cont:%d first rank num:%d second rank num:%d", cont, fir_r_num, sec_r_num);
    if (cont == 0 && (fir_r_num == 4 || sec_r_num == 4)){
        if (fir_r_num == 4){
            return 9000 + 10 * fir_r;
        } 
        return 9000 + 10 * sec_r;
    }

// Check full_house
    cont = 0;
    fir_r = 0;
    sec_r = 0;
    fir_r_num = 0;
    sec_r_num = 0;
    for (int i = 0; i < 5; i++){
        if (player.hand[i].rank != fir_r){
            if (fir_r == 0){
                fir_r = player.hand[i].rank;
                fir_r_num = 1;
            }
            else if (sec_r == 0){
                sec_r = player.hand[i].rank;
                sec_r_num = 1;
            }
            else if (player.hand[i].rank == sec_r){
                sec_r_num ++;
            }
            else { // This case means the player has more than 2 different ranks, hence four_of_a_kind must impossible
                cont = 1;
                break;
            }
        }
        else{
            fir_r_num ++;
        }
    }
    if (cont == 0 && (fir_r_num == 3 || sec_r_num == 3)){
        if (fir_r_num == 3){
            return 8000 + 10 * fir_r;
        } 
        return 8000 + 10 * sec_r;
    }
    
// Check flush
    cont = 0;
    for (int i = 1; i < 5; i++){
        if (player.hand[0].suit != player.hand[i].suit){
            cont = 1;
            break;
        }
    }
    if (!cont){
        return 7000 + 10 * player.hand[4].rank + player.hand[4].suit;
    }

// Check straight
    cont = 0;
    for (int i = 1; i < 5; i++){
        if (player.hand[0].rank + i != player.hand[i].rank){
            cont = 1;
            break;
        }
    }
    if (!cont){
        return 6000 + 10 * player.hand[4].rank + player.hand[4].suit;
    }

// Check three-of-a-kind
    int rank_list[13] = {0};
    for (int i = 0; i < 5; i++){
        rank_list[(player.hand[i].rank) - 2]++; // the range of rank is 2-14 so it has to be subtracted by 2
    }
    // if there exists rank_list[i] == 3 then it must be three-of-a-kind because full-house has been judged 
    for (int i = 0; i < 13; i++){
        if (rank_list[i] == 3){
            return 5000 + 10 * (i + 2); // add 2 because we have subtracted 2 when handling data
        }
    }

// Check two pairs
    // Using the former rank_list to judge
    int return_rank = 0, return_suit = 0, pairs_count = 0;
    // Check whether the player has two pairs
    for (int i = 12; i >= 0; i--){
        if (rank_list[i] == 2){
            pairs_count ++;
        }
    }
    if (pairs_count == 2){
        for (int i = 12; i >= 0; i--){
            if (rank_list[i] == 2){
                return_rank = i+2; // add 2 because we have subtracted 2 when handling data
                break;
            }
        }
        
        // Solve a problem for the different player which has same rank pairs, for example: 8h 8s jh jd 4c and jc js 5h 5c 3d
        for (int i = 0; i < 5; i++){
            if (player.hand[i].rank == return_rank && player.hand[i].suit > return_suit){
                return_suit = player.hand[i].suit;
            }
        }
        return 4000 + 10 * return_rank + return_suit; 
    }

// Check pair
    // Similar to Check two pairs
    pairs_count = 0;
    for (int i = 12; i >= 0; i--){
        if (rank_list[i] == 2){
            pairs_count ++;
        }
    }
    if (pairs_count == 1){
        for (int i = 0; i < 13; i++){
            if (rank_list[i] == 2){
                return_rank = i+2; // add 2 because we have subtracted 2 when handling data
                break;
            }
        }
        
        // Solve a problem for the different player which has same rank pairs, for example: 8h 8s jh jd 4c and jc js 5h 5c 3d
        for (int i = 0; i < 5; i++){
            if (player.hand[i].rank == return_rank && player.hand[i].suit > return_suit){
                return_suit = player.hand[i].suit;
            }
        }
        return 3000 + 10 * return_rank + return_suit; 
    }

// Check the other card
    int score = 0, cardscore;
    for (int i = 0; i < 5; i++){
        cardscore = 10 * player.hand[i].rank + player.hand[i].suit;
        if (cardscore > score){
            score = cardscore;
        }
    }
    if (score){
        return score;
    }

// End the Judge
    return 0;
}