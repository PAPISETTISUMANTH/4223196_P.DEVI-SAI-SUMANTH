#include <stdio.h>
#include <stdlib.h>
int heap[100000], size = 0;
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
void up(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
void down(int i) {
    int l = 2*i+1, r = 2*i+2, s = i;
    if (l < size && heap[l] < heap[s]) s = l;
    if (r < size && heap[r] < heap[s]) s = r;
    if (s != i) { swap(&heap[i], &heap[s]); down(s); }
}
void insert(int x) { heap[size] = x; up(size++); }
void del(int x) {
    for (int i = 0; i < size; i++) if (heap[i] == x) {
        heap[i] = heap[--size];
        down(i); up(i);
        break;
    }
}
int main() {
    int q, t, x;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &t);
        if (t == 1) { scanf("%d", &x); insert(x); }
        else if (t == 2) { scanf("%d", &x); del(x); }
        else printf("%d\n", heap[0]);
    }
    return 0;
}
