#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000010 

long array[MAX_SIZE] = {0};  

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        long k;
        scanf("%d %d %ld", &a, &b, &k);

        array[a] += k;
        array[b + 1] -= k;
    }

    long maxVal = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += array[i];
        if (current > maxVal) {
            maxVal = current;
        }
    }

    printf("%ld\n", maxVal);

    return 0;
}
