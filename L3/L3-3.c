#include<stdio.h>

int main () {
    int s = 2147483647, e = 1, input = 0;
    scanf("%d", &input);
    while (input >0 -1){
        if (input < s)
            s = input;
        else if (input > e)
            e = input;
        scanf("%d", &input);
    }
    printf("%d", (e-s));
    return 0;
}
