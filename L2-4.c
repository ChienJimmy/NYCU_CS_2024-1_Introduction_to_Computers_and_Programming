#include<stdio.h>
# define root3 1.7320508f
int main () {
    float A, a;
    scanf("%f", &a);
    A = root3 * a * a / 4.0;
    printf("%.3f",A);
    return 0;
}
