#include<stdio.h>


int main () {
    int n = 0;
    int a;
    scanf("%d", &n);
    a = getchar();
    int cap = 1;
    for (int i = 0; i < n; i++){
        cap = 1;
        while (1==1){
            a = getchar();
            if (a == ','){
                cap = 1;
                printf("\n");
                break;
            }
            if (a == '.'){
                cap = 1;
                printf("\n");
                break;
            }
            if (a == ';'){
                cap = 1;
                printf("\n");
                break;
            }
            if (a == ' '){
                cap = 1;
                printf(" ");
                continue;
            }
            if (cap == 1){
                cap = 0;
                if ('a' <= a && a <= 'z'){
                    a = a - 'a' + 'A';
                }
            }
            else{
                if ('A' <= a && a <= 'Z'){
                    a = a - 'A' + 'a';
                }
            }
            putchar(a);
        }
    }
    return 0;
}
