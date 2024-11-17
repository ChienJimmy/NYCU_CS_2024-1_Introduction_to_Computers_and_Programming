#include <stdio.h>

int main () {
    int dra = 100, hu = 100;
    int d1, d2, d3, d4, d5, d6;
    while (dra > 0 && hu > 0){
        scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
        if ((d1 + d2 + d3)%2){
            if ((d4 < d5) && (d5 < d6)){
                dra -=25;
            }
            else if (((d4 % 2) == (d5 % 2)) || ((d6 % 2) == (d5 % 2))){
                dra -=5;
            }
        }
        else{
            if (((d4 - d5) > d6) || ((d5 - d4) > d6)){
                hu -= 15;
            }
            else if ((d4 + d5) != d6){
                hu -= 5;
            }
        }
    }
    if (hu > 0)
        printf("Player wins");
    else
        printf("Dragon wins");
    return 0;
}
