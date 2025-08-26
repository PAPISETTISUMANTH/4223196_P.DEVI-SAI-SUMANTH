#include <stdio.h>
#include <limits.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxContiguousSum(int nums[], int length) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    int has_positive = 0;
    int max_element = INT_MIN;

    for (int i = 0; i < length; i++) {
        current_sum += nums[i];
        if (nums[i] >= 0) {
            has_positive = 1;
        }
        max_element = max(max_element, nums[i]);

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    return has_positive ? max_sum : max_element;
}
int maxNonContiguousSum(int nums[], int length) {
    int sum_positive = 0;
    int has_positive = 0;
    int max_element = INT_MIN;

    for (int i = 0; i < length; i++) {
        if (nums[i] > 0) {
            sum_positive += nums[i];
            has_positive = 1;
        }
        max_element = max(max_element, nums[i]);
    }

    return has_positive ? sum_positive : max_element;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        int size;
        scanf("%d", &size);

        int array[size];
        for (int i = 0; i < size; i++) {
            scanf("%d", &array[i]);
        }

        int max_subarray = maxContiguousSum(array, size);
        int max_subsequence = maxNonContiguousSum(array, size);

        printf("%d %d\n", max_subarray, max_subsequence);
    }

    return 0;
}