# include <stdio.h>
void ratate(){

}

int main () {
    unsigned int num16;
    scanf("%d", &num16);
    int ans[4][8];
    int temp[4][8];
    for (int i = 31; i >= 0; i--) {
        ans[(31-i)/8][(31-i)%8] = ((num16 >> i) & 1);
    }
    int d1, d2, d3, d4;
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

    for (int i = 0; i < 8; i++){
        temp[0][i] = (ans[(d1-1)][i] ^ ans[(d2-1)][i]);
    }
    for (int i = 0; i < 8; i++){
        temp[1][i] = (ans[(d2-1)][i] & ans[(d3-1)][i]);
    }
    for (int i = 0; i < 8; i++){
        temp[2][i] = (ans[(d3-1)][i] | ans[(d1-1)][i]);
    }
    for (int i = 0; i < 8; i++){
        temp[3][i] = (!ans[(d4-1)][i]);
    }


    int rotated[2][16];
    int dtotal = d1 + d2 + d3 + d4;
    for (int i = 0; i < 32; i++){
        int new = (i + dtotal)%32;
        rotated[new/16][new%16] = temp[i/8][i%8];
    }

    unsigned answer = 0;
    unsigned a = 1;
    for (int i = 15; i >= 0; i--){
        if (rotated[0][i] ^ rotated[1][i]){
            answer += a;
        }
        a *= 2;
    }
    printf("%u", answer);
}
