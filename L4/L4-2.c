#include<stdio.h>

int main () {
    long double p = 1.00L;
    double p_word;
    for (int i = 0; i < 5; i++){
        scanf("%lf", &p_word);
        p *= p_word;
    }
    printf("%.15Lf", p);

    return 0;
}
