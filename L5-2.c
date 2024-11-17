# include <stdio.h>

int main () {
    int arr[8][8];
    int target;
    int situation[8][8] = {0};
    int lines = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 64; i++){
        scanf("%d", &target);
        for (int j = 0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                if (arr[j][k] == target){
                    situation[j][k] = 1;
                }
            }
        }
    }
    int allok;
    for (int i = 0; i < 8; i++){
        allok = 1;
        for (int j = 0; j < 8; j++){
            if (situation[i][j] == 0){
                allok = 0;
            }
        }
        if (allok){
            lines += 1;
        }
    }
    for (int i = 0; i < 8; i++){
        allok = 1;
        for (int j = 0; j < 8; j++){
            if (situation[j][i] == 0){
                allok = 0;
            }
        }
        if (allok == 1){
            lines += 1;
        }
    }
    allok = 1;
    for (int i = 0; i < 8; i++){
        if (situation[i][i] == 0){
            allok = 0;
        }
    }
    if (allok == 1){
        lines += 1;
    }
    allok = 1;
    for (int i = 0; i < 8; i++){
        if (situation[i][7-i] == 0){
            allok = 0;
        }
    }
    if (allok == 1){
        lines += 1;
    }
    printf("%d",lines);
    return 0;
}
