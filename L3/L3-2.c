#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int main() {
	int cafe, amount;
    scanf("%d %d", &cafe, &amount);
    switch (cafe){
        case 1: printf("The total price is %d dollars!", (110 * amount)); break;
        case 2: printf("The total price is %d dollars!", (150 * amount)); break;
        case 3: printf("The total price is %d dollars!", (135 * amount)); break;
        case 4: printf("The total price is %d dollars!", (145 * amount)); break;
       	default : printf("Wait, what?");
    }
    return 0;
}