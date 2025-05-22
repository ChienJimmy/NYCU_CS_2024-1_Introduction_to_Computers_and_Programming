#include<stdio.h>

int main () {
    int x, y;
    scanf("%d %d", &x, &y);
    float h, w;
    h = x/ 100.0;
    w = y;
    printf("%.6f",(w/(h*h)));
    return 0;
}
