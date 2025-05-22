#include <stdio.h>

unsigned long construct(unsigned char parts[16]);

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));

    return 0;
}
unsigned long ChangeCharToLong(unsigned char ch){
    return ch;
}
unsigned long BitFill(unsigned long former, unsigned long fill){
    return former * 256 + fill; 
}
unsigned long construct(unsigned char parts[16]){
    unsigned long long l1 = 0;
    unsigned long long l2 = 0;
    for (int i = 0; i < 8; i++){
        l1 = BitFill(l1, ChangeCharToLong(parts[7 - i]));
    }
    for (int i = 0; i < 8; i++){
        l2 = BitFill(l2, ChangeCharToLong(parts[15 - i]));
    }
    return l1 ^ l2;
}