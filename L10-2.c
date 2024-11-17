# include <stdio.h>
# include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main()
{
    char password1[SIZE];
    char password2[SIZE];
    
    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);
    
    // Check Password
    // First: Check length
    if(length(password1, password2) == 1) {
        printf("Length does not match the requirements");
    }
    else {
        // Second: Check for consistency
        if(compare(password1, password2) == 1) {
            printf("Not the same password");
        }
        else {
            // Third: Check for compliance
            if(content(password1) == 1) {
                printf("Do not satisfy the conditions");
            }
            else {
                printf("Everything is good");
            }
        }
    }

    return 0;
}
int length(char pwd1[], char pwd2[]) {
    if (strlen(pwd1) <6 || strlen(pwd1) >16){
        return 1;
    }
    if (strlen(pwd2) <6 || strlen(pwd2) >16){
        return 1;
    }
    return 0;
}

int compare(char pwd1[], char pwd2[]) {
    if (strcmp(pwd1,pwd2) != 0){
        return 1;
    }
    return 0;
}

int content(char pwd1[]) {
    int upper = 0, lower = 0, number = 0;
    int i = 0;
    while (pwd1[i] != '\0'){
        if (pwd1[i] >= 'a' && pwd1[i] <= 'z'){
            lower = 1;
        }
        if (pwd1[i] >= 'A' && pwd1[i] <= 'Z'){
            upper = 1;
        }
        if (pwd1[i] >= '0' && pwd1[i] <= '9'){
            number = 1;
        }
        if ((upper + lower + number) == 3){
            return 0;
        }
        i++;
    }
    return 1;
}