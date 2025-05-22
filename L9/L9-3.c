#include <stdio.h>
#define ARR_MAX 1000
void sort_section(int *ptr, int *qtr);
int main() {
    int N, a, b;
    scanf("%d%d%d", &N, &a, &b);
    int arr[ARR_MAX] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }
    sort_section(&arr[a], &arr[b]);
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
}

void sort_section(int *ptr, int *qtr) {
    int *tmp_ptr;
    if (ptr > qtr){
        tmp_ptr = ptr;
        ptr = qtr;
        qtr = tmp_ptr;
    }
    int tmp_num;
    int *i, *j;
    for (i = ptr; i < qtr; i++) {
        for (j = ptr; j < qtr - (i - ptr); j++) {
            if (*j > *(j + 1)) {
                tmp_num = *j;
                *j = *(j + 1);
                *(j + 1) = tmp_num;
            }
        }
        for (j = ptr; j <= qtr; j++) {
            printf("%d ", *j);
        }
        printf("\n");
    }
}