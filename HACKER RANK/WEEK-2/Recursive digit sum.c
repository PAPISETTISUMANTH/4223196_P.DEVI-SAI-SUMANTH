#include <stdio.h>
#include <string.h>

long long sumOfDigits(char *digits) {
    long long s = 0;
    for (int i = 0; digits[i] != '\0'; i++) {
        s += (digits[i] - '0');
    }
    return s;
}

int superDigitCalc(long long num) {
    if (num < 10) {
        return (int)num;
    }
    long long next = 0;
    while (num > 0) {
        next += num % 10;
        num /= 10;
    }
    return superDigitCalc(next);
}

int main() {
    char input[100001];
    int k;
    scanf("%s %d", input, &k);

    long long base = sumOfDigits(input);
    long long expanded = base * k;
    int result = superDigitCalc(expanded);

    printf("%d\n", result);
    return 0;
}
