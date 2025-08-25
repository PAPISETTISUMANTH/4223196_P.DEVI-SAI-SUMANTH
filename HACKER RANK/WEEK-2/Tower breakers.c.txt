#include <stdio.h>
int z(int m, int n) {
    if (n == 1 || m % 2 == 0) {
        return 2; 
    }
    return 1; 
}
int main() {
    int x; 
    scanf("%d", &x);
    while (x--) {
        int p, q; 
        int r, s; 
        scanf("%d %d", &p, &q);
        r = p + q;
        s = p * q;
        printf("%d\n", z(p, q));
    }
    return 0;
}
