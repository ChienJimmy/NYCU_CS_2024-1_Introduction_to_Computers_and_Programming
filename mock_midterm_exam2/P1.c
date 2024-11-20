#include <stdio.h>
#include <string.h>
void permutation(char *inputstr, int inputstr_len);
char input_chars[7] = {0};
int main(void){
    char tmp;
    scanf("%s", input_chars);
    
    int length = strlen(input_chars);
    for (int i = 0; i < strlen(input_chars) - 1; i++){
        for (int j = 0; j < strlen (input_chars) - i - 1; j++){
            if (input_chars[j] > input_chars[j+1]){
                tmp = input_chars[j];
                input_chars[j] = input_chars[j+1];
                input_chars[j+1] = tmp;
            }
        }
    }
    //input_chars[length-1] = '\0';
    //printf("inputsort:%s",input_chars);
    permutation(input_chars, strlen(input_chars));
    return 0;
}
char buffer[7] = {0};
void permutation(char *inputstr, int inputstr_len){
    //buffer[strlen(buffer)-1] = '\0';
    if (inputstr_len == 1){
        printf("%s", buffer);
        printf("%c\n", inputstr[0]);
        
        return;
    }
    
    //choose what character we should reserve and put at first
    for (int i = 0; i < inputstr_len; i++){ 
        char reserved_ch = inputstr[i];
        char remaining_str[7] = {0};
        int remaining_str_index = 0;
        
        // making a string excluded with reserved character
        for (int j = 0; j < inputstr_len; j++){
            
            if (inputstr[j] != reserved_ch){
                remaining_str[remaining_str_index] = inputstr[j];
                remaining_str_index ++;
                
            }
        }
        // add reserved character into buffer
        buffer[strlen(buffer)+1] = '\0';
        buffer[strlen(buffer)] = reserved_ch;
        
        //printf("layer:%d buffer:%s\n", inputstr_len, buffer);

        permutation(remaining_str, inputstr_len-1);
        // delete the last character in the buffer
        buffer[strlen(buffer)-1] = '\0';
    }

}