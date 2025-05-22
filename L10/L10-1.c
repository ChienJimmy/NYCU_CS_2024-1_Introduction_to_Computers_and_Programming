#include <stdio.h>
#include <string.h>
int ReadCommand(){
    char command[1000];
    int a, i = 0;
    while (1){
        a = getchar();
        if (a == '\n'){
            command[i] = '\0';
            //printf("%s", command);
            if (strcmp(command, "PATA PATA PATA PON") == 0){
                return 11;
            }    
            if (strcmp(command, "PON PON PATA PON") == 0){
                return 12;
            }
            if (strcmp(command, "CHAKA CHAKA PATA PON") == 0){
                return 13;
            }
            else return 10;
        }
        if (a == ',' || a == '.'){
            command[i] = '\0';
            //printf("%s", command);
            if (strcmp(command, "PATA PATA PATA PON") == 0){
                return 1;
            }    
            if (strcmp(command, "PON PON PATA PON") == 0){
                return 2;
            }
            if (strcmp(command, "CHAKA CHAKA PATA PON") == 0){
                return 3;
            }
            else return 0;
        }
        else{
            command[i] = (char)a;
        }
        i++;
    }
}
int main(){
    int distance, hp, num_command = 0, command_type, num_legal_command = 0;
    scanf("%d %d", &distance, &hp);
    getchar();
    int endloop = 0;
    while (!endloop){
        int defence =  0;
        command_type = ReadCommand();
        if (command_type >= 10){
            command_type -= 10;
            endloop = 1;
        }
        if (command_type == 1){
            num_command ++;
            num_legal_command ++;
            distance --;
            if (distance == 0){
                printf("NO %d", hp);
                return 0;
            }
        }
        else if (command_type == 2){
            num_command ++;
            num_legal_command ++;
            if (distance <=3){
                hp --;
            }
            if (hp == 0){
                printf("YES %d", num_legal_command);
                return 0;
            }
        }
        else if (command_type == 3){
            num_command ++;
            num_legal_command ++;
            distance ++;
            defence = 1;
        }
        else{
            num_command ++;
        }
        //printf("\tcommand:%d %d \tdistance:%d \thp:%d\n", command_type, num_command, distance, hp);
        if (num_command == 10){
            if (defence){
                num_command = 0;
            }
            else{
                printf("NO %d", hp);
                return 0;
            }
        }
    }
    printf("NO %d", hp);
    return 0;
}