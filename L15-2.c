#include <stdio.h>
#include <stdlib.h>

// Enumrations
enum orb_type {
    O_UNSET = -1,
    O_RED = 17, O_BLUE = 1, O_GREEN = 6, O_YELLOW = 24,
    O_FLOAT = 5, O_CLONE = 2, O_EXPAND = 4, O_DYSON = 3
};

// Structure Declairation
struct node_t {
    struct node_t *next;
    enum orb_type orb;
};

struct head_t {
    struct node_t *head;
    int count;
    enum orb_type orb;
};

// Function Prototypes
struct head_t *alloc_list_heads(int size);              // Allocate memory for array of list heads
void init_head_arr(struct head_t *arr, int size);       // Initialize array of linked-lists
void print_magic_circle(struct head_t *arr, int size);  // Print the structure of magic circle
void insert_next(struct head_t *arr, int size, const char c);  // Insert the next orb onto the magic circle

// Main Function
int main() {
    int size;       // Size of center ring
    int count;      // Number of stem orbs will be put;

    // Allocate ring
    scanf("%d%d%*c", &size, &count);
    struct head_t *center_ring = alloc_list_heads(size);

    // Read and set ring
    init_head_arr(center_ring, size);

    // Place the orbs
    for (int i = 0; i < count; ++i) {
        insert_next(center_ring, size, getchar());
        //print_magic_circle(center_ring, size); // Debug
    }

    // Print magic circle configuration
    print_magic_circle(center_ring, size);
    return 0;
}

// Function Definitions
void print_magic_circle(struct head_t *arr, int size) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < size; ++i) {
        // Print center orb
        printf("CO_%c", arr[i].orb + 'A');

        // Print stem
        struct node_t *cur = arr[i].head;
        while (cur) {
            printf(" -> %c", 'A' + cur->orb);
            cur = cur->next;
        }
        if (i + 1 <= size) putchar('\n');
    }
    return;
}

// Allocate memory for array of list heads
struct head_t *alloc_list_heads(int size) {
    struct head_t *tmp = malloc(sizeof(struct head_t) * size); // Allocate memory for array of list heads
    return tmp;
}

// Read input and Initialize array of linked-lists
void init_head_arr(struct head_t *arr, int size) {
    for (int i = 0; i < size; i++) {
        char input; // 輸入的 Orb
        scanf("%c", &input); // 讀取輸入
        if (input == 'Y') { // 如果是 Yellow Orb
            arr[i].orb = 24; 
        }
        else if (input == 'R') { // 如果是 Red Orb
            arr[i].orb = 17;
        }
        else if (input == 'G') { // 如果是 Green Orb
            arr[i].orb = 6;
        }
        else { // 如果是 Blue Orb
            arr[i].orb = 1;
        }
    }
    getchar(); // 讀取換行符號
    return;
}
int FindCorbNum(struct head_t *arr, int size){ // 找出所有的 Clone Orb
    int count = 0;
    for (int i = 0; i < size; i++){ // 遍歷所有 Stem
        struct node_t *cur = arr[i].head;
        while (cur){ // 遍歷當前 Stem
            if (cur->orb == 2){ // 如果找到 Clone Orb
                count ++; // 增加計數
            }
            cur = cur->next; // 繼續檢查下一個節點
        }
    }
    return count;
}
int FindandClear(struct head_t *arr, int size, int dyson_target, int times){ // 找出所有的 Dyson Orb 並清除
    int count = 0;
    for (int i = 0; i < size; i++) { // 遍歷所有 Stem
        if (i == times) {
            continue;
        }
        struct node_t *cur = arr[i].head; // 當前 Stem 的頭節點
        struct node_t *prev = NULL; // 用來追蹤前一個節點

        while (cur) {  // 遍歷當前 Stem
            if (cur->orb == dyson_target) { // 如果找到目標
                if (prev) { // 如果前一個節點存在
                    prev->next = cur->next; // 跳過當前節點
                } else {
                    arr[i].head = cur->next; // 更新頭節點
                }
                struct node_t *to_free = cur; // 暫存當前節點
                cur = cur->next; // 移動到下一個節點
                free(to_free); // 釋放記憶體
                count++; // 增加移除計數
            } else {
                prev = cur; // 更新前一個節點
                cur = cur->next; // 繼續檢查下一個節點
            }
        }
    }
    return count; // 回傳移除的數量
}

// Insert the next orb onto the magic circle
void insert_next(struct head_t *arr, int size, const char c) {
    static int times = 0; // 決定要修改哪個 Stem
    static int count_c = 0; // 計算 Clone Orb 的數量
    struct node_t *insert = malloc(sizeof(struct node_t)); // 新增一個節點
    if (c == 'R' || c == 'Y' || c == 'G' || c == 'B') { // 如果是普通 Orb
        if (arr[(times)].head == NULL) { // 如果 Stem 是空的
            arr[(times)].head = insert; // 新增節點
            arr[(times)].head->orb = (c - 'A'); // 設定 Orb 的值
            arr[(times)].head->next = NULL; // 設定下一個節點為空
        }
        else { // 如果 Stem 不是空的
            struct node_t *cur = arr[(times)].head; // 當前 Stem 的頭節點
            while (cur->next) { // 找到 Stem 的尾節點
                cur = cur->next;
            }
            if (cur->orb == 5) { // 如果尾節點是 Floating Orb
                insert->next = arr[(times)].head; // 新節點指向 Stem 的頭節點
                insert->orb = (c - 'A'); // 設定 Orb 的值
                arr[(times)].head = insert; // 更新 Stem 的頭節點
            }
            else { // 如果尾節點不是 Floating Orb
                cur->next = insert; // 新節點接在尾節點後面
                cur->next->orb = (c - 'A'); // 設定 Orb 的值
                cur->next->next = NULL; // 設定下一個節點為空
            }
        }
    }
    if (c == 'C') { // 如果是 Clone Orb
        if (!arr[(times)].head) { // 如果 Stem 是空的
            arr[(times)].head = insert; // 新增節點
            arr[(times)].head->orb = 2; // 設定 Orb 的值
        }
        else { // 如果 Stem 不是空的
            struct node_t *cur = arr[(times)].head; // 當前 Stem 的頭節點
            while (cur->next) { // 找到 Stem 的尾節點
                cur = cur->next; 
            }
            struct node_t *insert = malloc(sizeof(struct node_t)); // 新增一個節點
            if (cur->orb == 5) { // 如果尾節點是 Floating Orb
                insert->next = arr[(times)].head; // 新節點指向 Stem 的頭節點
                insert->orb = 2; // 設定 Orb 的值
                arr[(times)].head = insert; // 更新 Stem 的頭節點
            }
            else {
                cur->next = insert; // 新節點接在尾節點後面
                cur->next->orb = 2; // 設定 Orb 的值
                cur->next->next = NULL; // 設定下一個節點為空
            }
        }
        // TODO: Clone
        count_c = FindCorbNum(arr, size); // 找出所有Clone Orb的數量
        int target; // 目標 Stem
        if (times >= count_c) { // 如果 Clone Orb 的數量小於目前節點的數字
            target = times - count_c; // 目標 Stem 是目前節點的數字減去 Clone Orb 的數量
        }
        else {
            target = (((times - count_c) % size) + size) % size; // 目標 Stem 是目前節點的數字減去 Clone Orb 的數量加上總共的 Stem 數量
        }
        struct node_t *cur = arr[(times)].head; // 當前 Stem 的頭節點
        struct node_t *target_cur = arr[(target)].head; // 目標 Stem 的頭節點
        // 先處理 head 節點的部分
        if (!target_cur) { // 如果目標 Stem 的指標是空的
            struct node_t *newnode = malloc(sizeof(struct node_t)); // 新增一個節點
            newnode->next = NULL; // 設定下一個節點為空
            newnode->orb = cur->orb; // 設定 Orb 的值
            arr[(target)].head = newnode; // 更新目標 Stem 的頭節點
            target_cur = arr[(target)].head; // 目標 Stem 的頭節點
        }
        else { // 如果目標 Stem 不是空的
            target_cur->orb = cur->orb; // 設定 Orb 的值
        }
        // 再處理剩下 Stem 的部分
        while (cur->next) { // 遍歷當前 Stem
            if (target_cur->next == NULL) { // 如果目標 Stem 的下一個節點是空的
                struct node_t *newnode = malloc(sizeof(struct node_t)); // 新增一個節點
                newnode->next = NULL; // 設定下一個節點為空
                newnode->orb = cur->next->orb; // 設定 Orb 的值
                target_cur->next = newnode; // 更新目標 Stem 的下一個節點
            }
            else { // 如果目標 Stem 的下一個節點不是空的
                struct node_t *existnode = target_cur->next; // 暫存目標 Stem 的下一個節點
                existnode->orb = cur->next->orb; // 設定 Orb 的值
                target_cur->next = existnode; // 更新目標 Stem 的下一個節點
            }
            cur = cur->next; // 繼續檢查原始 Stem 的下一個節點
            target_cur = target_cur->next; // 繼續檢查被複製 Stem 的下一個節點
        }
        if (target_cur) target_cur->next = NULL; // 設定目標 Stem 的尾節點為空
    }
    if (c == 'D') { // 如果是 Dyson Orb
        if (!arr[(times)].head) { // 如果 Stem 是空的
            arr[(times)].head = insert; // 新增節點
            arr[(times)].head->orb = 3; // 設定 Orb 的值
        }
        else { // 如果 Stem 不是空的
            struct node_t *cur = arr[(times)].head; // 當前 Stem 的頭節點
            while (cur->next) { // 找到 Stem 的尾節點
                cur = cur->next;
            }
            struct node_t *insert = malloc(sizeof(struct node_t)); // 新增一個節點
            if (cur->orb == 5) { // 如果尾節點是 Floating Orb
                insert->next = arr[(times)].head;
                insert->orb = 3;
                arr[(times)].head = insert;
            }
            else { // 如果尾節點不是 Floating Orb
                cur->next = insert;
                cur->next->orb = 3;
                cur->next->next = NULL;
            }
        }
        // TODO: Dyson
        int dyson_orb = arr[times].orb; // 設定 Dyson Orb 的值
        int orbnum = FindandClear(arr, size, dyson_orb, times); // 找出所有的 Dyson Orb 並清除
        //printf("orbnum:%d\n", orbnum);
        // 將 orbnum 個 Dyson Orb 加入 Stem
        for (int i = 0; i < orbnum; i++) { // 重複 orbnum 次
            struct node_t *cur = arr[(times)].head; // 當前 Stem 的頭節點
            while (cur->next) { // 找到 Stem 的尾節點
                cur = cur->next; 
            }
            struct node_t *insert = malloc(sizeof(struct node_t)); // 新增一個節點
            if (cur->orb == 5) { // 如果尾節點是 Floating Orb
                insert->next = arr[(times)].head; 
                insert->orb = dyson_orb;
                arr[(times)].head = insert;
            }
            else { // 如果尾節點不是 Floating Orb
                cur->next = insert;
                cur->next->orb = dyson_orb;
                cur->next->next = NULL;
            }
        }
    }
    if (c == 'E') { // 如果是 Expand Orb
        if (!arr[(times)].head) { // 如果 Stem 是空的
            arr[(times)].head = insert;
            arr[(times)].head->orb = 4;
        }
        else { // 如果 Stem 不是空的
            struct node_t *cur = arr[(times)].head;
            while (cur->next) { // 找到 Stem 的尾節點
                cur = cur->next;
            }
            if (cur->orb == 5) { // 如果尾節點是 Floating Orb
                insert->next = arr[(times)].head;
                insert->orb = 4;
                arr[(times)].head = insert;
            }
            else { // 如果尾節點不是 Floating Orb
                cur->next = insert;
                cur->next->orb = 4;
                cur->next->next = NULL;
            }
        }
        // TODO: Expand
        int expander = arr[times].orb; // 設定 Expand Orb 的值
        for (int i = 0; i < size; i++) { // 遍歷所有 Stem
            struct node_t *insert = malloc(sizeof(struct node_t)); // 新增一個節點
            if (!arr[i].head) { // 如果 Stem 是空的
                arr[i].head = insert;
                arr[i].head->orb = expander;
            }
            else { // 如果 Stem 不是空的
                struct node_t *cur = arr[i].head; // 當前 Stem 的頭節點
                while (cur->next) { // 找到 Stem 的尾節點
                    cur = cur->next;
                }
                struct node_t *insert = malloc(sizeof(struct node_t)); // 新增一個節點
                if (cur->orb == 5) { // 如果尾節點是 Floating Orb
                insert->next = arr[i].head;
                insert->orb = expander;
                arr[i].head = insert;
                }
                else { // 如果尾節點不是 Floating Orb
                    cur->next = insert;
                    cur->next->orb = expander;
                    cur->next->next = NULL;
                }
            }
        }
    }
    if (c == 'F') { // 如果是 Floating Orb
        if (!arr[(times)].head) { // 如果 Stem 是空的
            arr[(times)].head = insert;
            arr[(times)].head->orb = 5;
        }
        else { // 如果 Stem 不是空的
            struct node_t *cur = arr[(times)].head; // 當前 Stem 的頭節點
            while (cur->next) { // 找到 Stem 的尾節點
                cur = cur->next;
            }
            struct node_t *insert = malloc(sizeof(struct node_t)); // 新增一個節點
            if (cur->orb != 5){ // 如果尾節點不是 Floating Orb
                cur->next = insert;
                cur->next->orb = 5;
                cur->next->next = NULL;
            }
        }   
    }

    times ++; // 更新 Stem 的數字
    if (times == size) { // 如果 Stem 的數字等於總共的 Stem 數量
        times = 0; // 重置 Stem 的數字
    }
    return;
}
