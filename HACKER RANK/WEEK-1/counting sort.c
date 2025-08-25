#include <stdio.h>
void countingSort(int length, int numbers[]) {
    int countArr[100] = {0};
    for (int idx=0;idx<length;idx++) {
        countArr[numbers[idx]]++;
    }
    for (int pos = 0; pos < 100; pos++) {
        printf("%d ", countArr[pos]);
    }
}
int main() {
    int total;
    scanf("%d",&total);
    int data[total];
    for (int k = 0; k < total; k++) {
        scanf("%d", &data[k]);
    }
    countingSort(total, data);
    return 0;
}
