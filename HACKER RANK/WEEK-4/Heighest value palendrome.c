#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* highestValuePalindrome(char* s, int n, int k) {
    int left = 0, right = n - 1;
    int *changed = calloc(n, sizeof(int));
    while (left < right) {
        if (s[left] != s[right]) {
            if (s[left] > s[right]) {
                s[right] = s[left];
            } else {
                s[left] = s[right];
            }
            changed[left] = changed[right] = 1;
            k--;
        }
        left++;
        right--;
    }
    if (k < 0) {
        free(changed);
        return "-1";
    }
    left = 0; right = n - 1;
    while (left <= right && k > 0) {
        if (left == right) {
            if (k > 0 && s[left] != '9') {
                s[left] = '9';
                k--;
            }
        } else {
            if (s[left] != '9') {
                if (changed[left] || changed[right]) {
                    if (k >= 1) {
                        s[left] = s[right] = '9';
                        k--;
                    }
                } else if (k >= 2) {
                    s[left] = s[right] = '9';
                    k -= 2;
                }
            }
        }
        left++;
        right--;
    }
    free(changed);
    return s;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char *s = (char*)malloc((n + 1) * sizeof(char));
    scanf("%s", s);
    char* result = highestValuePalindrome(s, n, k);
    printf("%s\n", result);
    if (strcmp(result, "-1") != 0) free(result);
    return 0;
}
