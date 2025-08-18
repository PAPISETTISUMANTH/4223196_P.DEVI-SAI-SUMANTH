#include <stdio.h>

int countSetBits(unsigned long long val) {
    int cnt = 0;
    while (val > 0) {
        val &= (val - 1);
        cnt++;
    }
    return cnt;
}

int main() {
    int tests;
    scanf("%d", &tests);

    while (tests--) {
        unsigned long long num;
        scanf("%llu", &num);

        unsigned long long decNum = num - 1;

        if (countSetBits(decNum) % 2 == 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }
    return 0;
}
