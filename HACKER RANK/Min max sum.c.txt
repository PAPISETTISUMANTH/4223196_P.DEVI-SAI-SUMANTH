#include <stdio.h>

void calculateMinMaxSum(int numbers[5]) {
    long totalSum= 0;
    int smallest= numbers[0];
    int largest= numbers[0];

    for (int i=0;i<5;i++) {
        totalSum += numbers[i];

        if (numbers[i]<smallest)
            smallest=numbers[i];
        if (numbers[i]>largest)
            largest=numbers[i];
    }

    long minSum = totalSum - largest;
    long maxSum = totalSum - smallest;

    printf("%ld %ld\n",minSum,maxSum);
}

int main() {
    int data[5];

    // Read 5 integers from user input
    for (int i = 0; i < 5; i++) {
        scanf("%d", &data[i]);
    }

    calculateMinMaxSum(data);

    return 0;
}
