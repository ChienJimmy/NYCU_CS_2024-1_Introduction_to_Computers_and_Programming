#include <stdio.h>

int main(void){
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a, b, x, y, z;
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12);
    a = a2 + a4 + a6 + a8 + a10 + a12;
    b = a1 + a3 + a5 + a7 + a9 + a11;
    x = a * 3 + b;
    y = x - 1;
    z = y % 10;
    int ans = 9 - z;
    printf("%d", ans);
    return 0;
}
