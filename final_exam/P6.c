#include <stdio.h>
#include <stdlib.h>

// 函數：計算最大正方形面積
int findMaxSquareArea(int *heights, int n) {
    int max_square = 0;

    for (int i = 0; i < n; i++) {
        int min_height = heights[i];

        for (int j = i; j < n; j++) {
            min_height = (min_height < heights[j]) ? min_height : heights[j];

            int side_length = j - i + 1; // 寬度
            if (side_length > min_height) {
                side_length = min_height; // 高度限制正方形邊長
            }

            int square_area = side_length * side_length;
            if (square_area > max_square) {
                max_square = square_area;
            }
        }
    }

    return max_square;
}

int main() {
    int n;
    scanf("%d", &n);

    int *heights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int max_square = findMaxSquareArea(heights, n);
    printf("max_square:%d\n", max_square);

    free(heights);
    return 0;
}