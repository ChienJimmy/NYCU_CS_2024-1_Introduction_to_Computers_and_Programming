#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define mxN 10005
#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b

struct dot{
    int x;
    int y;
    int value;
} dotset[mxN];

int N, M;

int distance(struct dot a, struct dot b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
int find_max_dot_value();
int find_min_distance();


int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i<N; i++){
        scanf("%d %d %d", &(&dotset[i])->x, &(&dotset[i])->y, &(&dotset[i])->value);
    }
    int max_dot_value = find_max_dot_value();
    int min_distance = find_min_distance();
    printf("%d %d", max_dot_value, min_distance);
}
