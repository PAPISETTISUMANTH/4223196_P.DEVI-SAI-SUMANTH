#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}
int main() {
    int t; 
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char g[101][101];
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
            qsort(g[i], n, sizeof(char), cmp); // sort each row
        }
        int ok = 1;
        for (int c = 0; c < n && ok; c++) {
            for (int r = 1; r < n; r++) {
                if (g[r][c] < g[r-1][c]) { 
                    ok = 0; 
                    break; 
                }
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
