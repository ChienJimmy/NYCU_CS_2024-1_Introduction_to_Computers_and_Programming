#include<stdio.h>
int trans(int ch){
    if (65 <= ch && ch <= 90){
        return ch-64;
    }
    else{
        return ch-96;
    }
}
int main () {
    int n;
    scanf("%d", &n);
    int new[20];
    int name[30][20];
    int info[30];
    int length;
    scanf("%d ", &length);
    for (int i = 0; i < length; i++){
        new[i] = trans(getchar());
    }
    for (int i = 0; i < n; i++){
        scanf("%d ", &info[i]);
        for (int j = 0; j < info[i]; j++){
            name[i][j] = trans(getchar());
        }
        for (int j = info[i]; j < length; j++){
            name[i][j] = 0;
        }
    }
    int seat = 1, forward;
    for (int i = 0; i < n; i++){
        forward = 0;
        for (int j = 0; j < length; j++){
            //printf("%d %d %d %d\n", i, j, new[j],name[i][j]);
            if (new[j] > name[i][j]){
                forward = 1;
                break;
            }
            if (new[j] < name[i][j]){
                forward = 0;
                //printf("S\n");
                break;
            }
        }
        if (forward == 1){
            seat += 1;
            //printf("seat\n");
        }
    }
    printf("%d", seat);
    return 0;
}