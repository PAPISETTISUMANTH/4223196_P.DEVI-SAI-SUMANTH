#include <stdio.h>
#include <stdlib.h>

int* climbingLeaderboard(int* ranked, int n, int* player, int m, int* result_count) {
    int* unique = (int*)malloc(n * sizeof(int));
    int uniqueCount = 0;

    unique[uniqueCount++] = ranked[0];
    for (int i = 1; i < n; i++) {
        if (ranked[i] != ranked[i - 1]) {
            unique[uniqueCount++] = ranked[i];
        }
    }

    int* result = (int*)malloc(m * sizeof(int));
    *result_count = m;

    int idx = uniqueCount - 1;

    for (int i = 0; i < m; i++) {
        while (idx >= 0 && player[i] >= unique[idx]) {
            idx--;
        }
        result[i] = idx + 2;
    }

    free(unique);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int* ranked = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }

    int m;
    scanf("%d", &m);
    int* player = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    int result_count;
    int* result = climbingLeaderboard(ranked, n, player, m, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    free(ranked);
    free(player);
    free(result);
    return 0;
}
