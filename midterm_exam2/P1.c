#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}
int ch_to_int(char ch){
    return (ch - '0');
}
char int_to_char(int i){
    return '0' + i;
}
void add(char a[], char b[], char res[]){
    unsigned long a_size = strlen(a);
    unsigned long b_size = strlen(b);
    unsigned long res_size;
    if (a_size > b_size){
        res_size = a_size + 1;
    }
    else {
        res_size = b_size + 1;
    }
    int add_next = 0;
    res[0] = '0';
    for (int i = 1; i < res_size; i++){
        int ach, bch, resch;
        if ((a_size - i > 100)){
            ach = 0;
        } 
        else{
            ach = ch_to_int(a[a_size - i]);
        }
        if ((b_size - i > 1000)){
            bch = 0;
        } 
        else{
            bch = ch_to_int(b[b_size - i]);
        }
        if((ach + bch + add_next) >= 10){
            resch = ach + bch + add_next - 10;
            add_next = 1;
        }
        else{
            resch = ach + bch+ add_next;
            add_next = 0;
        }
        res[res_size - i] = int_to_char(resch);
    }
    res[res_size] = '\0';
    
    if (res[0] == '0'){
        for (int i = 1; i < res_size; i++){
            res[i-1] = res[i];
        }
        res[res_size-1] = '\0';
    }
    
}
