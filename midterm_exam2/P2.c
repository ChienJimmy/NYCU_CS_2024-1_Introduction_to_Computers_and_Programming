#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
int countdist(int x1, int x2, int y1, int y2){
    return (x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2);
}
int find_max_dot_value() {
    int total = 0, max = 0, biggest = 1000000000;
    for (int i = 0;i < 4; i++){
        max = 0;
        for (int j = 0; j < N; j++){
            if (dotset[j].value > max && dotset[j].value < biggest){
                max = dotset[j].value;
            }
        }
        total += max;
        biggest = max;
    }
    return total;
}
struct dot findnearestdot(struct dot self){
    int nearestdist = 1000000000, dist, dotinfo;
    for (int i = 0; i < N; i++){
        if (dotset[i].value == self.value){
            continue;
        }
        else{
            dist = countdist(self.x, self.y, dotset[i].x, dotset[i].y);
            if (dist < nearestdist){
                nearestdist = dist;
                dotinfo = i;
            }
        }
    }
    return dotset[dotinfo];
}

int find_min_distance() {
    int linked[8] = {0}, distance = 0;
    struct dot nearestdot;
    for (int i = 0;i < M; i++){
        nearestdot = findnearestdot(dotset[i]);
        distance += countdist(nearestdot.x, nearestdot.y, dotset[i].x, dotset[i].y);
    }
    return distance;
}