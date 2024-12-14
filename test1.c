#include <stdio.h>
#include <stdlib.h>

// Enumrations
enum orb_type {
    O_UNSET = -1,
    O_RED = 17, O_BLUE = 1, O_GREEN = 6, O_YELLOW = 24,
    O_FLOAT = 5, O_CLONE = 2, O_EXPAND = 4, O_DYSON = 3
};

// Node structure
struct node_t {
    struct node_t *next;
    enum orb_type orb;
};

// List head structure
struct head_t {
    struct node_t *head;
    int count;
    enum orb_type orb;
};

// Function prototypes
struct head_t *alloc_list_heads(int size);
void init_head_arr(struct head_t *arr, int size);
void print_magic_circle(struct head_t *arr, int size);
void insert_next(struct head_t *arr, int size, const char c);
int FindandClear(struct head_t *arr, int size, int dyson_target, int times);

// Main function
int main() {
    int size, count;

    // Allocate ring
    scanf("%d%d%*c", &size, &count);
    struct head_t *center_ring = alloc_list_heads(size);

    // Initialize ring
    init_head_arr(center_ring, size);

    // Insert orbs
    for (int i = 0; i < count; ++i) {
        insert_next(center_ring, size, getchar());
    }

    // Print magic circle configuration
    print_magic_circle(center_ring, size);
    return 0;
}

// Allocate array of list heads
struct head_t *alloc_list_heads(int size) {
    struct head_t *arr = (struct head_t *)malloc(size * sizeof(struct head_t));
    for (int i = 0; i < size; ++i) {
        arr[i].head = NULL;
        arr[i].count = 0;
        arr[i].orb = O_UNSET;
    }
    return arr;
}

// Initialize list heads with their respective colors
void init_head_arr(struct head_t *arr, int size) {
    char orbs[] = {'R', 'G', 'B'};
    for (int i = 0; i < size; ++i) {
        arr[i].orb = (enum orb_type)orbs[i % 3];
    }
}

// Print the current state of the magic circle
void print_magic_circle(struct head_t *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("CO_%c ->", "RGB"[i % 3]);
        struct node_t *current = arr[i].head;
        while (current) {
            printf(" %c ->", current->orb);
            current = current->next;
        }
        printf(" END\n");
    }
}

// Insert next orb into the magic circle
void insert_next(struct head_t *arr, int size, const char c) {
    struct node_t *new_node = (struct node_t *)malloc(sizeof(struct node_t));
    new_node->orb = c;
    new_node->next = NULL;

    int times = 0;  // Times determine which head to modify

    switch (c) {
    case 'R': case 'G': case 'B': case 'Y':
        // Normal orbs are added to the tail
        if (arr[times].head == NULL) {
            arr[times].head = new_node;
        } else {
            struct node_t *current = arr[times].head;
            while (current->next) current = current->next;
            current->next = new_node;
        }
        break;

    case 'F':
        // Floating orbs are added to the head
        new_node->next = arr[times].head;
        arr[times].head = new_node;
        break;

    case 'C':
        // Clone all orbs from the current list to the left neighbor
        {
            int prev = (times - 1 + size) % size;
            struct node_t *current = arr[times].head;
            struct node_t **target = &arr[prev].head;
            while (*target) target = &((*target)->next);  // Find the end of the target list
            while (current) {
                struct node_t *cloned_node = (struct node_t *)malloc(sizeof(struct node_t));
                cloned_node->orb = current->orb;
                cloned_node->next = NULL;
                *target = cloned_node;
                target = &((*target)->next);
                current = current->next;
            }
        }
        break;

    case 'D':
        // Dyson absorbs matching orbs from all other lists
        {
            struct node_t **target = &arr[times].head;
            while (*target) target = &((*target)->next);  // Find the end of the current list
            for (int i = 0; i < size; ++i) {
                if (i == times) continue;  // Skip the current list
                struct node_t **current = &arr[i].head;
                while (*current) {
                    if ((*current)->orb == c) {
                        struct node_t *absorbed_node = *current;
                        *current = (*current)->next;  // Remove node from the original list
                        absorbed_node->next = NULL;   // Detach node
                        *target = absorbed_node;      // Add node to the current list
                        target = &((*target)->next);
                    } else {
                        current = &((*current)->next);
                    }
                }
            }
        }
        break;

    case 'E':
        // Expand adds a new orb to the end of all lists
        for (int i = 0; i < size; ++i) {
            struct node_t **target = &arr[i].head;
            while (*target) target = &((*target)->next);  // Find the end of the current list
            struct node_t *new_expansion = (struct node_t *)malloc(sizeof(struct node_t));
            new_expansion->orb = c;
            new_expansion->next = NULL;
            *target = new_expansion;
        }
        break;
    }
}