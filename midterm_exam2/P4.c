#include <stdio.h>
int main(){
    int beverage[30];
    for (int i = 0; i < 30; i++){
        beverage[i] = 10;
    }
    int customer;
    int beverage_kind, num;
    scanf("%d", &customer);
    for (int i = 0; i < customer; i++){
        scanf("%d %d", &beverage_kind, &num);
        if (beverage[beverage_kind - 1] < num){
            beverage[beverage_kind - 1] = 0;
        }
        else {
            beverage[beverage_kind - 1] -= num;
        }
    }
    int profit = 0, sell_num, price;
    for (int i = 0; i < 30; i++){
        price = 10 * (i / 10 + 1);
        sell_num = 10 - beverage[i];
        profit += (sell_num * price);
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 10; j++){
            printf("%d", beverage[i*10+j]);
            if (j == 9){
                printf("\n");
            }
            else{
                printf(" ");
            }
        }
    }
    printf("Earned: $%d", profit);
    return 0;
}