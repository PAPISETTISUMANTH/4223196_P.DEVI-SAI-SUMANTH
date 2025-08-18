#include <stdio.h>
const char* isBalanced(int arr[], int n) {
    long long total = 0, leftSum = 0;    
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    for (int i = 0; i < n; i++) {
        long long rightSum = total - leftSum - arr[i];
        if (leftSum == rightSum) {
            return "YES";
        }
        leftSum += arr[i];
    }
    return "NO";
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int len;
        scanf("%d", &len);
        int data[len];
        for (int j = 0; j < len; j++) {
            scanf("%d", &data[j]);
        }
        printf("%s\n", isBalanced(data, len));
    }
    return 0;
}
