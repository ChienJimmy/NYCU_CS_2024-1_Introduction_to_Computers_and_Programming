#include<stdio.h>

int main () {
    int option, layer;
    scanf("%d %d", &option, &layer);
    switch (option){
    	case 1:
    		for (int i = layer; i > 0; i--){
    			for (int j = 0; j < i; j++){
        			printf("*");
        		}
        		printf("\n");
    		}
    		break;
    	case 2:
    		for (int i = 1; i <= layer; i++){
    			for (int j = 0; j < i; j++){
        			printf("*");
        		}
        		printf("\n");
    		}
    		break;
    	case 3:
            for (int i = layer; i > 0; i--){
                for (int j = 0; j < (layer - i); j++){
                    printf(" ");
                }
    			for (int j = 0; j < i; j++){
        			printf("*");
        		}
        		printf("\n");
    		}
    		break;
        case 4:
            for (int i = 1; i <= layer; i++){
                for (int j = 0; j < (layer - i); j++){
                    printf(" ");
                }
    			for (int j = 0; j < i; j++){
        			printf("*");
        		}
        		printf("\n");
    		}
    		break;
    }
    return 0;
}
