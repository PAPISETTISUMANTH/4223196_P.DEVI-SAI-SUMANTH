#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *arr;
    int front, back;
} Deque;
Deque* createDeque(int n) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(n * sizeof(int));
    dq->front = 0;
    dq->back = -1;
    return dq;
}
void pushBack(Deque* dq, int val) {
    dq->back++;
    dq->arr[dq->back] = val;
}
void popFront(Deque* dq) {
    dq->front++;
}
void popBack(Deque* dq) {
    dq->back--;
}
int frontVal(Deque* dq) {
    return dq->arr[dq->front];
}
int backVal(Deque* dq) {
    return dq->arr[dq->back];
}
int isEmpty(Deque* dq) {
    return dq->front > dq->back;
}
void slidingMax(int nums[], int n, int k, int result[]) {
    Deque* dq = createDeque(n);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (!isEmpty(dq) && frontVal(dq) < i - k + 1) popFront(dq);
        while (!isEmpty(dq) && nums[backVal(dq)] < nums[i]) popBack(dq);
        pushBack(dq, i);
        if (i >= k - 1) result[idx++] = nums[frontVal(dq)];
    }
    free(dq->arr);
    free(dq);
}
void solve(int nums[], int n, int queries[], int qCount) {
    for (int i = 0; i < qCount; i++) {
        int k = queries[i];
        int total = n - k + 1;
        int *maxVals = (int*)malloc(total * sizeof(int));
        slidingMax(nums, n, k, maxVals);

        int minOfMax = maxVals[0];
        for (int j = 1; j < total; j++)
            if (maxVals[j] < minOfMax) minOfMax = maxVals[j];

        printf("%d\n", minOfMax);
        free(maxVals);
    }
}
int main() {
    int n, qCount;
    scanf("%d %d", &n, &qCount);
    int *nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    int *queries = (int*)malloc(qCount * sizeof(int));
    for (int i = 0; i < qCount; i++) scanf("%d", &queries[i]);
    solve(nums, n, queries, qCount);
    free(nums);
    free(queries);
    return 0;
}
