#include <stdio.h>

void minimumBribes(int q[], int n) {
    int bribes = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }
        int start = (q[i] - 2 > 0) ? q[i] - 2 : 0;
        for (int j = start; j < i; j++) {
            if (q[j] > q[i]) bribes++;
        }
    }
    printf("%d\n", bribes);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int q[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }

        minimumBribes(q, n);
    }

    return 0;
}
