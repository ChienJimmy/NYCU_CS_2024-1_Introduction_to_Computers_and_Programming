#include <stdio.h>
int lower(int ch){
    if (65 <= ch && ch <= 90){
        return ch + 32;
    }
}
int trans(int ch){
    if (97 <= ch && ch <= 102){
        return ch - 87;
    }
    else if (48 <= ch && ch <= 57)
    {
        return ch - 48;
    }
    
}
int main () {
    int a[10001];
    int i = 0, ch;
    while ((ch = getchar()) != '\n'){
        ch = lower(ch);
        ch = trans(ch);
        a[i] = ch;
        i++;
    }
    return 0;
}
