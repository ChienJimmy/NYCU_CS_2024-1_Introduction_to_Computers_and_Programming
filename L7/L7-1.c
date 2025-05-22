#include <stdio.h>

#define MAX_ITEMS 25
int count_original(int item, int recipes[MAX_ITEMS][MAX_ITEMS], int craft_count[MAX_ITEMS], int memo[MAX_ITEMS]) {
    if (memo[item] != -1) {
        return memo[item];
    }
    if (craft_count[item] == 0) {
        memo[item] = 1;
        return 1;
    }
    int total = 0;
    for (int i = 0; i < craft_count[item]; i++) {
        total += count_original(recipes[item][i], recipes, craft_count, memo);
    }
    memo[item] = total;
    return total;
}

int main() {
    int N;
    scanf("%d", &N);

    int recipes[MAX_ITEMS][MAX_ITEMS];
    int craft_count[MAX_ITEMS];
    int memo[MAX_ITEMS];
    for (int i = 0; i < N; i++) {
        memo[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &craft_count[i]);
        for (int j = 0; j < craft_count[i]; j++) {
            scanf("%d", &recipes[i][j]);
            recipes[i][j]--;
        }
    }
    int total_original_items = 0;
    for (int i = 0; i < N; i++) {
        total_original_items += count_original(i, recipes, craft_count, memo);
    }
    printf("%d\n", total_original_items);

    return 0;
}