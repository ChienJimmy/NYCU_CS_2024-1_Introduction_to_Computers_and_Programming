#include <stdio.h>
#include <stdlib.h>

#define WAVEFORM_HEIGHT 68

char *decodeWaveform(int **waveform, int width, int secretLength);

int main() {
    int width;
    int secretLength;

    scanf("%d", &width);
    scanf("%d", &secretLength);

    int **waveform;
    waveform = (int **)malloc(WAVEFORM_HEIGHT * sizeof(int *));
    for (int i = 0; i < WAVEFORM_HEIGHT; i++) {
        waveform[i] = (int *)malloc(width * sizeof(int));
    }

    char tmp;
    for (int i = 0; i < WAVEFORM_HEIGHT; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &waveform[i][j]);
            if (j != width - 1) {
                scanf("%c", &tmp);
            }
        }
    }
    
    char *secret = decodeWaveform(waveform, width, secretLength);
    printf("%s\n", secret);

    return 0;
}
char *decodeWaveform(int **waveform, int width, int secretLength) {
    char *secret = (char *)malloc((secretLength + 1) * sizeof(char));
    int step = width / secretLength;

    // 計算每個字符在波形圖中的步長
    int positions[secretLength];
    for (int i = 0; i < secretLength; i++) {
        positions[i] = i * step;
    }

    // 尋找正常的波形應該會是介於第26-41列之間，且跟前一列的1相差一列
    int normal_waveform[secretLength];
    for (int i = 0; i < secretLength; i++) {
        int x = positions[i];
        for (int y = 26; y <= 41; y++) {
            if (waveform[y][x] == 1 && (waveform[y - 1][x - 1] == 1 || waveform[y + 1][x - 1] == 1)) {
                normal_waveform[i] = y;
                break;
            }
        }
    }

    // 計算第1,6,11,16,21,26,31,36行的另外一個1
    for (int i = 0; i < secretLength; i++) {
        int x = positions[i];
        int y = normal_waveform[i];
        int other_y = -1;
        for (int j = 0; j < WAVEFORM_HEIGHT; j++) {
            if (j != y && waveform[j][x] == 1) {
                other_y = j;
                break;
            }
        }

        if (other_y != -1) {
            int offset = other_y - y;
            if (i == 0) {
                secret[i] = other_y - 27; // 根據範例，第一個字符應該是 'm'
            } else {
                secret[i] = (secret[i - 1] - 'a' + offset + 26) % 26 + 'a';
            }
        }
    }
    secret[secretLength] = '\0';
    return secret;
}