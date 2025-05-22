#include <stdio.h>
void intervalcount(int score[], int len, int b, int a){
    int low = 0, middle = 0, high = 0;
    for (int i = 0; i < len; i++){
        if (score[i] < b){
            low += 1;
        }
        else if (score[i] < a){
            middle += 1;
        }
        else{
            high += 1;
        }
    }
    printf("%d %d %d\n", low, middle, high);
}

int main() {
    int n, score[1024]={}, t, a, b;
    scanf("%d", &n);
    score[n] = -1;
    for (int i = 0; i < n; i++){
        scanf("%d", &score[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d %d", &b, &a);
        intervalcount(score, n, b, a);
    }
    return 0;
}