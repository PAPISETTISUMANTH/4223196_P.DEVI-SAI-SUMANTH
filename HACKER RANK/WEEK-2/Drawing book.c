#include <stdio.h>
int f(int x, int y) {
    int a = y / 2;         
    int b = (x / 2) - (y / 2);
    int c = (a < b) ? a : b;   
    return c;
}
int main() {
    int p, q;
    scanf("%d %d", &p, &q);
    int r = f(p, q);
    printf("%d\n", r);
    return 0;
}
