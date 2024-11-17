#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
    char line[BUFFER_LEN];
    char buffer[LINE_LEN][BUFFER_LEN];
    char *arr[LINE_LEN];

    int count = 0;
    while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
        arr[count] = buffer[count];
        strncpy(buffer[count++], line, BUFFER_LEN - 1);
    }
    convert(arr, count);
    for (int i = 0; i < count; i++) {
        printf("%s", arr[i]);
    }
}
void print_t9(char *output, char c) {
    // Mapping of characters to their corresponding T9 key and key press count
    const char *t9_map[] = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    for (int i = 0; i < 8; i++) {
        const char *letters = t9_map[i];
        for (int j = 0; letters[j] != '\0'; j++) {
            if (letters[j] == c) {
                char buffer[10];
                sprintf(buffer, "(%d)%d", i + 2, j + 1);
                strcat(output, buffer);
                return;
            }
        }
    }
}

void convert(char *arr[], int count) {
    for (int i = 0; i < count; i++) {
        char result[BUFFER_LEN] = ""; // Temporary buffer to store the converted line
        int len = strlen(arr[i]);

        for (int j = 0; j < len; j++) {
            if (arr[i][j] == '\n') {
                strcat(result, "\n");
            } else if (arr[i][j] == ' ') {
                strcat(result, " ");
            } else {
                print_t9(result, arr[i][j]);
            }
        }

        // Copy the result back to arr[i]
        strcpy(arr[i], result);
    }
}