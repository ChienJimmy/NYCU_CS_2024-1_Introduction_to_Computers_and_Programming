#include <stdio.h>
int BitChange(int inputInt) {
    float floatRepresentation;
    unsigned int bitRepresentation;
    floatRepresentation = (float)inputInt;
    bitRepresentation = *(unsigned int*)&floatRepresentation;
    return bitRepresentation;
}

void PrintBitChange(int inputInt){
    for (int i = 31; i >= 0; i--) {
        unsigned int mask = 1u << i;
        printf("%d", (inputInt & mask) ? 1 : 0);
        if (i % 8 == 0) {
            if (i == 0){
                printf("\n");
            }
            else{
                printf(" ");
            }
        }
    }
    
}
int main (){
    int a, b, ans;
    unsigned ach, bch, ansch;
    scanf("%d %d", &a, &b);
    printf("   ");
    ach = BitChange(a);
    bch = BitChange(b);
    PrintBitChange(ach);
    printf("+) ");
    PrintBitChange(bch);
    printf("---------------------------------------\n   ");
    ansch = ach + bch;
    PrintBitChange(ansch);
    int ansint;
    if (ansch > 2147483647){
        ansch = 2147483648 - (ansch - 2147483648);
        printf("%d + %d = -%u", a, b, ansch);
    }
    else{
        printf("%d + %d = %u", a, b, ansch);
    }
}