#include <stdio.h>
#include <stdlib.h>

char *strtok(char *s, const char *sep) {
    printf("strtok banned\n");
    exit(1);
}
char *strtok_r(char *str, const char *sep, char **lasts) {
    printf("strtok_r banned\n");
    exit(1);
}

char *strsep(char **stringp, const char *delim) {
    printf("strsep banned\n");
    exit(1);
}
char *gettoken(char *str, const char *sep);
int main() {
    char buffer[4096];
    char *sep = " \t\n;,.?!";
    char *word;
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        fgets(buffer, 4095, stdin);
        for (word = gettoken(buffer, sep); word != NULL;
            word = gettoken(NULL, sep)) {
            printf("%s\n", word);
        }
    }
}/*
#include <string.h>
char list[4096] = {0};
int ptr = 0;
char *gettoken(char *str, const char *sep){
    if (str != NULL){
        strcpy(list, str);
    }
    printf("%s", list);
    char *token;
    int no_sep = 1;
    while (1){
        no_sep = 1;
        for (int i = 0; i < strlen(sep); i++){
            if (list[ptr] == sep[i]){
                no_sep = 0;
                break;
            }
        }
        if (no_sep){
            token = list+ptr;
            break;
        }
        ptr++;
    } 
    int endpoint;
    while (list[ptr] != '\0'){
        int end = 0;
        for (int i = 0; i < strlen(sep); i++){
            if (list[ptr] == sep[i]){
                end = 1;
                endpoint = ptr;
                break;
            }
        }
        if (end){
            break;
        }
        ptr++;
    }
    list[endpoint] = '\0';
    return token;
}
*/
#include <string.h>
static *former_str;
char *gettoken(char *str, const char *sep){
    char *token;
    if (str == NULL){
        str = former_str;
    }
    str += strspn (str, sep);
    if (*str == '\0')
    {   
        former_str = str;
        return NULL;
    }
    token = str;
    str = strpbrk (token, sep);
    if (str == NULL){
        former_str = __rawmemchr (token, '\0');
    }
    else{
        *str = '\0';
        former_str = str + 1;
    }
    return token;
}
