#include <stdio.h>
void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main() {
    int a_numerator, a_denominator, b_numerator, b_denominator;
    scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
    int c_numerator, c_denominator;
    fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator, &c_denominator);
    printf("%d/%d\n", c_numerator, c_denominator);
}
int gcd(int a, int b){
    int t;
    while (b != 0) {
		t = b;
        b = a % b;
        a = t;
	}
    return a;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr) {
    int new_d, new_n;
    new_d = lcm(a_denominator, b_denominator);
    new_n = a_numerator * (new_d / a_denominator) + b_numerator * (new_d / b_denominator);
    int newgcd;
    newgcd = gcd(new_d, new_n);
    *c_numerator_ptr = new_n / newgcd;
    *c_denominator_ptr = new_d / newgcd;
    return;
}