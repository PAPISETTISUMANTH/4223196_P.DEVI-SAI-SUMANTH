#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int **arr = (int **)malloc(n * sizeof(int *));
    int *sizes = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = NULL;
    int lastAnswer = 0;
    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;
        if (type == 1) {
            arr[idx] = realloc(arr[idx], (sizes[idx] + 1) * sizeof(int));
            arr[idx][sizes[idx]++] = y;
        } else {
            lastAnswer = arr[idx][y % sizes[idx]];
            printf("%d\n", lastAnswer);
        }
    }
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    free(sizes);
    return 0;
}
