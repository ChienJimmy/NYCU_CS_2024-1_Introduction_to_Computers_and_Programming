#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t * const queue, int value, int weight);
node_t *dequeue(prio_queue_t * const queue);
void print_nodes(const prio_queue_t * const queue);

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		}
		else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
        }
		print_nodes(&queue);
	}
	return 0;
}

void print_nodes(const prio_queue_t *const queue) {
	if (!queue->head) {
		printf("EMPTY\n");
		return;
	}
	for (node_t *node = queue->head; node; node = node->next) {
		printf(" -> %d", node->value);
    }
	printf("\n");
    return;
}
void enqueue(prio_queue_t *const queue, int value, int weight) {
    node_t *target = malloc(sizeof(node_t));
    if (!queue->head){
        queue->head = target;
        target->value = value;
        target->weight = weight;
        target->next = NULL;
        return;
    }
    node_t *curr = queue->head;
    if (weight < curr->weight){
        queue->head = target;
        target->value = value;
        target->weight = weight;
        target->next = curr;
        return;
    }
    while (curr->next!= NULL && curr->next->weight <= weight){
        curr = curr->next;
    }
    target->value = value;
    target->weight = weight;
    target->next = curr->next;
    curr->next = target;
    return;
}

node_t *dequeue(prio_queue_t *const queue) {
    if (queue->head){
        node_t *head = queue->head;
        queue->head = head->next;
        return head;
    }
    else{
        return NULL;
    }
}