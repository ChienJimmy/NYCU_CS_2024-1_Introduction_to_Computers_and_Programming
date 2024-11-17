#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}
int CheckDigits(char ch){
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z')){
        return 1;
    }
    if (ch == '.' || ch == ',' || ch == '!' || ch == '?'){
        return 2;
    }
    return 0;
}
void recovery(char *homework) {
    for (int i = 0; i < strlen(homework); i++){
        if (homework[i] == '\n'){
            homework[i] = '\0';
            break;
        }
    }
    char *token;
    token = strtok(homework, " ");
    int check, reserve;
    char storage[4097];
    while( token != NULL ) {
        reserve = 1;
        //printf("%s\n", token);
        for (int i = 0;; i++){
            if (token[i] == '\0'){
                break;
            }
            if (i >= 21){
                reserve = 0;
                break;
            }
            check = CheckDigits(token[i]);
           	if (i == 0 && check == 2){
                reserve = 0;
            }
            //printf("check: %d\n", check);
            if (check == 0){
                reserve = 0;
                break;
            }
            if (check == 2){
                if (token[i+1] != '\0'){
                    reserve = 0;
                    break;
                }
            }
        }
        //printf("%s %d\n",token, reserve);
        if (reserve){
            //printf("reserve: %s\n",token);
            strcat(storage, token);
            strcat(storage, " ");
        }
        token = strtok(NULL, " ");
    }
    storage[strlen(storage) - 1] = '\0';
    strcpy(homework, storage);
}