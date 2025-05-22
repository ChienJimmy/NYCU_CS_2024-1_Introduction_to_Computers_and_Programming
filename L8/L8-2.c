#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
	if (k == 0)
    {
        *f2k = 0;
        *f2k1 = 1;
        return;
    }

    uint64_t fk, fk1;
    fib_fast_doubling(k / 2, &fk, &fk1);

    uint64_t c = fk * (2 * fk1 - fk);
    uint64_t d = fk * fk + fk1 * fk1;

    if (k % 2 == 0)
    {
        *f2k = c;
        *f2k1 = d;
    }
    else
    {
        *f2k = c + d;
        *f2k1 = c + 2 * d;
    }
}