# include <stdio.h>
typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28
int main () {
    int s = INIT_STRENGTH, o = INIT_OBEDIENCE;
    int input;
    int command = 0;
    while ((input = getchar())!='\n'){
        if (input == 'e'){
            s += STRENGTH_EAT;
            o -= OBEDIENCE_EAT;
        }
        else{
            s -= STRENGTH_TRAIN;
            o += OBEDIENCE_TRAIN;
        }
        if (o >= LEARN_OBEDIENCE && s <= LEARN_STRENGTH){
            o = INIT_OBEDIENCE;
            command += 1;
        }
    }
    if (command >= 5){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
