#include <stdio.h>

#define MOD 1000000007

long long mod_pow(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        int height, width;
        scanf("%d %d", &height, &width);

        if (width == 0) {
            printf("0\n");
            continue;
        }

        long long row_ways[width + 1];
        row_ways[0] = 1;

        for (int i = 1; i <= width; i++) {
            row_ways[i] = 0;
            if (i >= 1) row_ways[i] = (row_ways[i] + row_ways[i - 1]) % MOD;
            if (i >= 2) row_ways[i] = (row_ways[i] + row_ways[i - 2]) % MOD;
            if (i >= 3) row_ways[i] = (row_ways[i] + row_ways[i - 3]) % MOD;
            if (i >= 4) row_ways[i] = (row_ways[i] + row_ways[i - 4]) % MOD;
        }

        long long total_ways[width + 1], solid_ways[width + 1];
        for (int i = 0; i <= width; i++) {
            total_ways[i] = mod_pow(row_ways[i], height);
        }

        solid_ways[0] = 0;
        solid_ways[1] = total_ways[1];

        for (int i = 2; i <= width; i++) {
            solid_ways[i] = total_ways[i];
            for (int j = 1; j < i; j++) {
                solid_ways[i] = (solid_ways[i] - (solid_ways[j] * total_ways[i - j]) % MOD + MOD) % MOD;
            }
        }

        printf("%lld\n", solid_ways[width]);
    }

    return 0;
}