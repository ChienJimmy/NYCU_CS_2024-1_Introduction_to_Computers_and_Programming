#include<stdio.h>
# define w 0.9f
# define u 0.1f
# define b -51
# define U -0.98f
# define B 153
int main () {
    float x, h = 0, y;
    scanf("%f",&x);
    for (int i = 0; i < 5; i++){
        h = ((w * x) + (u * h) + b);
        y = (U * h + B);
        printf("%.1f ",y);
        x = y;
    }
    return 0;
}
