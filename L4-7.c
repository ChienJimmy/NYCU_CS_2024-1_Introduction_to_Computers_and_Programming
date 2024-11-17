#include<stdio.h>
int char_to_int(int input){
    if ('0' <= input && input <= '9'){
        return (input - '0');
    }
    else{
        return (input - 'a' + 10);
    }
}

int main () {
    int a, b, ip;
    for (int i = 0; i < 4; i++){
        a = char_to_int(getchar());
        b = char_to_int(getchar());
        ip = a * 16 + b;
        if (i != 3){
            printf("%d.", ip);
        }
        else{
            printf("%d", ip);
        }
    }

    return 0;
}
