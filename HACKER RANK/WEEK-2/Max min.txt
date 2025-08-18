#include <stdio.h>
#include <stdlib.h>
int sortAsc(const void *p, const void *q) {
    return (*(int *)p - *(int *)q);
}
int minUnfairness(int size, int *values, int count) {
    qsort(values, count, sizeof(int), sortAsc);
    int best = 1e9;
    for (int i = 0; i + size - 1 < count; i++) {
        int diff = values[i + size - 1] - values[i];
        if (diff < best) {
            best = diff;
        }
    }
    return best;
}
int main() {
    int count, size;
    scanf("%d %d", &count, &size);
    int *values = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        scanf("%d", &values[i]);
    }
    printf("%d\n", minUnfairness(size, values, count));
    free(values);
    return 0;
}
