#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapifyDown(int heap[], int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}
void heapifyUp(int heap[], int idx) {
    int parent = (idx - 1) / 2;
    if (idx > 0 && heap[idx] < heap[parent]) {
        swap(&heap[idx], &heap[parent]);
        heapifyUp(heap, parent);
    }
}
int popMin(int heap[], int *size) {
    if (*size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}
void pushHeap(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}
int minOperations(int threshold, int arr[], int n) {
    int heap[n], size = 0;

    for (int i = 0; i < n; i++) {
        pushHeap(heap, &size, arr[i]);
    }
    int steps = 0;
    while (size > 1 && heap[0] < threshold) {
        int first = popMin(heap, &size);
        int second = popMin(heap, &size);

        int combined = first + 2 * second;
        pushHeap(heap, &size, combined);
        steps++;
    }
    if (size > 0 && heap[0] >= threshold)
        return steps;
    return -1;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int values[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    int result = minOperations(k, values, n);
    printf("%d\n", result);
    return 0;
}
