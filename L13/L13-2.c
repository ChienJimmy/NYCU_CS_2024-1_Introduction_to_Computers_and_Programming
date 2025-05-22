#include <stdio.h>
#include <stdlib.h>
struct Card {
    int num;
    struct Card *next;
};
void BulidCardlist(struct Card *firstcard, int n){
    struct Card *curr = firstcard;
    for (int i = 1; i <= n; i++){
        struct Card *newcard = malloc(sizeof(struct Card));
        curr->num = i;
        if (i == n){
            curr->next = NULL;
            break;
        }
        curr->next = newcard;
        curr = newcard;
    }
}
struct Card *DrawCard(struct Card *cardlist){
    int drawedcardnum;
    if (!cardlist){
        printf("NULL ptr\n");
        return NULL;
    }
    drawedcardnum = cardlist->num;
    printf("%d ",drawedcardnum);
    struct Card *topcard;
    topcard = cardlist->next;
    free(cardlist);
    if (!topcard) {
        return NULL;
    }
    struct Card *curr = topcard;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = topcard;
    topcard = topcard->next;
    curr->next->next = NULL;
    return topcard;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    struct Card *cardlist = malloc(sizeof(struct Card));
    BulidCardlist(cardlist, n);
    for (int i = 0; i < m; i++){
        cardlist = DrawCard(cardlist);
        if (!cardlist){
            break;
        }
    }
    return 0;
}

