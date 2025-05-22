#include <stdio.h>

int main(void){
    float x, ans;
    scanf("%f",&x);
    ans = 7 * x * x * x * x - 8 * x * x * x - x * x + 6 * x - 22;
    printf("%.1f",ans);
    return 0;
}
