#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* isValid(char* input) {
    int charFreq[26] = {0};
    for (int i = 0; input[i]; i++) {
        charFreq[input[i] - 'a']++;
    }

    int freqList[26], freqCount = 0;
    for (int i = 0; i < 26; i++) {
        if (charFreq[i] > 0) freqList[freqCount++] = charFreq[i];
    }

    int minFreq = INT_MAX, maxFreq = INT_MIN;
    for (int i = 0; i < freqCount; i++) {
        if (freqList[i] < minFreq) minFreq = freqList[i];
        if (freqList[i] > maxFreq) maxFreq = freqList[i];
    }

    if (minFreq == maxFreq) return "YES";

    int minCount = 0, maxCount = 0;
    for (int i = 0; i < freqCount; i++) {
        if (freqList[i] == minFreq) minCount++;
        if (freqList[i] == maxFreq) maxCount++;
    }

    if ((minCount == freqCount - 1 && maxFreq - minFreq == 1) || 
        (maxCount == freqCount - 1 && minFreq == 1))
        return "YES";

    return "NO";
}

int main() {
    char str[100005];
    scanf("%s", str);

    printf("%s\n", isValid(str));
    return 0;
}
