#include <stdio.h>

int main() {
    int a, b, c, d, e, f;

    // Original code with common subexpression
    a = 2 * 3;
    b = 2 * 3 + 1;
    c = 2 * 3 - 1;

    // Optimized code without common subexpression
    d = 2 * 3;
    e = d + 1;
    f = d - 1;

    printf("Original code results: a = %d, b = %d, c = %d\n", a, b, c);
    printf("Optimized code results: e = %d, f = %d\n", e, f);

    return 0;
}


