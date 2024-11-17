#include <stdio.h>
int access(){
    int ch, store= 0;
    while (1){    
        if (ch != ' '){
            store = store * 10 + ch;
        }
        else{
            return store;
        }
    }
}
int trans(int ch){
    return ch - 48;
}
int main(){
    int n;
    scanf("%d", &n);
    int info[101][101];
    int store;
    int ch;
    int j;
    int index[101][101];
    for (int i = 0; i < n; i++){
        j = 0;
        while ((ch = getchar())!= '\n'){    
            if (ch != ' '){
                ch = trans(ch);
                store = store * 10 + ch;
            }
            else{
                info[i][j] = store;
                j++;
            }
        }
        for (int k = j; k <= 101; k++){
            info[i][k] = 0;
        }
    }
    for (int i = 0; i < 101; i++){
        for (int j = 0; i < 101; j++)
        {
            index[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; i < 101; j++)
        {
            if (info[i][j] == 0){
                break;
            }
            else{
                index[info[i][0]][info[i][j]] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ->",i);
        for (int j = 0; i < n; j++)
        {
            if (info[i][j] == 1){
                printf(" %d", j);
            }
        }
        printf("\n");
    }
    return 0;
}