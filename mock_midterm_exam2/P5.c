#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"
};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}
int FindIndex(char *str, char *target){
    int len = strlen(target);
    for (int i = 0; str[i] != '\0'; i++){
        int  correct = 1;
        for (int j = 0; j < len; j++){
            if (str[i+j] != target[j]){
                correct = 0;
                break;
            }
        }
        if (correct == 1){
            return i;
        }
    }
    return -1;
}
void recovering_order(char *order, char **result) {
    *result = malloc(sizeof(char) * 10000);
    char store[10000];
    char *token;
    token = strtok(order, ":");
    while (token != NULL){
        int lowest_index = 50, index, info[120] = {0};
        for (int i = 0; i < 120; i++){
            index = FindIndex(names[i], token);
            info[i] = index;
            if (index >= 0 && index < lowest_index){
                lowest_index = index;
            }
        }

        char *lowest_str = "zzzzzzzzzzzzzz";
        for (int i = 0; i < 120; i++){
            if (info[i] == lowest_index){
                if (strlen(lowest_str) > strlen(names[i])){
                    lowest_str = names[i];
                    continue;
                }
                if ((strlen(lowest_str) == strlen(names[i])) && (strcmp(lowest_str, names[i]) > 0)){
                    lowest_str = names[i];
                }
            }
        }
        
        strcat(store, lowest_str); 
        strcat(store, "+"); // problem
        token = strtok(NULL, ":");
    }
    strcat(store, "\0");
    int last = strlen(store) - 1;
    
    store[last] = '\0'; 
    strcpy(*result, store);
    
    return;
}