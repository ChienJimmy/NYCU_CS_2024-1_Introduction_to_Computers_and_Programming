#include <stdio.h>
int upcipher(int charin, long shift){
    if (charin + shift >122){
        return (charin + shift - 26);
    }
    else if (charin + shift < 97){
        return (charin + shift + 26);
    }
    else{
        return (charin + shift);
    }
}
int downcipher(int charin, long shift){
    if (charin + shift > 90){
        return (charin + shift - 26);
    }
    else if (charin + shift < 65){
        return (charin + shift + 26);
    }
    else{
        return (charin + shift);
    }
}
int main () {
    int k, a;
    int a_or_d;
    char aord;
    scanf("%d", &k);
    k = k % 26;
    getchar();
    scanf("%c", &aord);
    if (aord == 'a'){
        a_or_d = 1;
    }
    else{
        a_or_d = -1;
    }
    getchar();
    while((a = getchar()) != '\n'){
        if (a <= 122 && a >= 97){
            putchar(upcipher(a, k));
            k += a_or_d; 
            k = k % 26;
        }
        else if (a <= 90 && a >= 65){
            putchar(downcipher(a, k));
            k += a_or_d; 
            k = k % 26;
        }
        else{
            putchar(a);
        }
    }
}