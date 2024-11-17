#include <stdio.h>

#define LIM_ULL 18446744073709551615ULL
#define NUMBER_1 0x38E38E38E38E3800LLU
#define NUMBER_2 0x2AAAAAAAAAAAAAAALLU
#define NUMBER_3 0x1C71C71C71C71C71LLU
#define MOD 0x7CE66C50E2840000LLU
int main() {
    int d1, d2, d3;
    unsigned long long add_value;
    scanf("%d %d %d", &d1, &d2, &d3);

    unsigned long long result = 0;
    while (d1 > 2) {
        d1 -= 2;
        add_value = 2 * NUMBER_1;
        result += add_value;
        if (result >= MOD) {
            result %= MOD;
        }
    }
    add_value = d1 * NUMBER_1;
   	result += add_value;
    if (result >= MOD) {
        result %= MOD;
    }
	while (d2 > 3) {
        d2 -= 3;
        add_value = 3 * NUMBER_2;
        result += add_value;
        if (result >= MOD) {
            result %= MOD;
        }
    }
    add_value = d2 * NUMBER_2;
   	result += add_value;
    if (result >= MOD) {
        result %= MOD;
    }
    while (d3 > 4) {
        d3 -= 4;
        add_value = 4 * NUMBER_3;
        result += add_value;
        if (result >= MOD) {
            result %= MOD;
        }
    }
    add_value = d3 * NUMBER_3;
   	result += add_value;
    if (result >= MOD) {
        result %= MOD;
    }
    printf("%llu\n", result);

    return 0;
}