#include<stdio.h>

int main () {
   	unsigned int n;
    scanf("%d", &n);
    long unsigned int prefix_sum = 0, input;
    for (int i = 0; i < n; i++){
        scanf("%ld", &input);
        prefix_sum += input;
        if (prefix_sum % input == 0){
            printf("%ld %ld\n", prefix_sum, input);
        }
    }
    return 0;
}