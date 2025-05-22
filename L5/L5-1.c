#include <stdio.h>
int PlusOrMinus(int plus_or_minus, int target){
    if (plus_or_minus == 0){
        if (target == 0){
            return 9;
        }
        return target - 1;
    }
    else{
        if (target == 9){
            return 0;
        }
        return target + 1;
    }
}

int main(){
    int arr[6] = {0,0,0,0,0,0};
    int d1, d2;
    for (int i=0; i < 75; i++){
        scanf("%d %d", &d1, &d2);
        arr[d1-1] = PlusOrMinus(d2 % 2,arr[d1-1]);
    }
    for (int i=0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}