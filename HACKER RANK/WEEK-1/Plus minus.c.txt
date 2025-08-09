#include <stdio.h>

void plusMinus(int arr[], int n) {
    int positive = 0, negative = 0, zero = 0;

    for(int i=0;i<n;i++) {
        if(arr[i] >0)
            positive++;
        else if(arr[i]<0)
            negative++;
        else
            zero++;
    }

    // Convert to float to get decimal output
    printf("%.6f\n",(float)positive / n);
    printf("%.6f\n",(float)negative / n);
    printf("%.6f\n",(float)zero / n);
}

int main() {
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    plusMinus(arr, n);

    return 0;
}
