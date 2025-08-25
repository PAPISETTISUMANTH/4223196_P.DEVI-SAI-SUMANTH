#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000
int prime_check(int n) {
    if (n<2) return 0;
    if (n%2==0&&n!=2)return 0;
    for (int i=3;i*i<=n;i+=2) {
        if (n%i==0) return 0;
    }
    return 1;
}

void generate_primes(int arr[], int count) {
    int num=2,found=0;
    while (found<count) {
        if (prime_check(num)) {
            arr[found++]= num;
        }
        num++;
    }
}

int main() {
    int n,q;
    scanf("%d %d",&n,&q);

    int stack[MAX], primes[q];
    for (int i=0; i<n;i++) {
        scanf("%d",&stack[i]);
    }
    generate_primes(primes, q);
    for (int round=0; round<q;round++) {
        int divisible[MAX],remain[MAX];
        int div_top=0,rem_top=0;
        int p = primes[round];
        for (int i=n-1;i>=0;i--) {
            if (stack[i]%p==0) {
                divisible[div_top++]=stack[i];
            } else {
                remain[rem_top++]=stack[i];
            }
        }
        for (int i=div_top-1;i>=0;i--) {
            printf("%d\n",divisible[i]);
        }
        n = rem_top;
        for (int i=0;i<n;i++) {
            stack[i]=remain[i];
        }
    }
    for (int i=n-1;i>=0;i--) {
        printf("%d\n",stack[i]);
    }
    return 0;
}
