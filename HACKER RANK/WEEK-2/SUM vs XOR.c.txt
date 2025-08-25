#include <stdio.h>

long calc(long num) {
    if (num == 0) return 1;
    long zeros = 0;
    while (num > 0) {
        if ((num & 1) == 0) zeros++;
        num >>= 1;
    }
    return 1L << zeros;
}

int main() {
    long val;
    scanf("%ld", &val);
    printf("%ld\n", calc(val));
    return 0;
}
