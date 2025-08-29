#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int index;
} Node;
int compareAsc(const void *a, const void *b) {
    return ((Node*)a)->value - ((Node*)b)->value;
}
int compareDesc(const void *a, const void *b) {
    return ((Node*)b)->value - ((Node*)a)->value;
}
int countPermutationCycles(int *arr, int n, int ascending) {
    Node *nodes = malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i].value = arr[i];
        nodes[i].index = i;
    }
    qsort(nodes, n, sizeof(Node), ascending ? compareAsc : compareDesc);
    char *visited = calloc(n, 1);
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || nodes[i].index == i) continue;
        int cycleSize = 0, j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = nodes[j].index;
            cycleSize++;
        }
        if (cycleSize > 1) swaps += cycleSize - 1;
    }
    free(nodes);
    free(visited);
    return swaps;
}
int minimumSwaps(int *arr, int n) {
    int ascSwaps = countPermutationCycles(arr, n, 1);
    int descSwaps = countPermutationCycles(arr, n, 0);
    return ascSwaps < descSwaps ? ascSwaps : descSwaps;
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", minimumSwaps(arr, n));
    free(arr);
    return 0;
}
