#include <stdio.h>

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int heights1[n1], heights2[n2], heights3[n3];
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < n1; i++) {
        scanf("%d", &heights1[i]);
        sum1 += heights1[i];
    }
    for (int i = 0; i < n2; i++) {
        scanf("%d", &heights2[i]);
        sum2 += heights2[i];
    }
    for (int i = 0; i < n3; i++) {
        scanf("%d", &heights3[i]);
        sum3 += heights3[i];
    }

    int i = 0, j = 0, k = 0;

    while (!(sum1 == sum2 && sum2 == sum3)) {
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= heights1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= heights2[j++];
        } else {
            sum3 -= heights3[k++];
        }
    }

    printf("%d\n", sum1);
    return 0;
}