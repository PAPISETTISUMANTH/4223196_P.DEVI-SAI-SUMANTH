#include <stdio.h>
int countSockPairs(int totalSocks, int sockColors[]) {
    int totalPairs = 0;
    int freq[101] = {0}; 
    for (int idx = 0; idx < totalSocks; idx++) {
        freq[sockColors[idx]]++;
    }
    for (int c = 0; c <= 100; c++) {
        totalPairs += freq[c] / 2;
    }   
    return totalPairs;
}
int main() {
    int numSocks;
    scanf("%d", &numSocks);
    int colors[numSocks];    
    for (int i = 0; i < numSocks; i++) {
        scanf("%d", &colors[i]);
    }
    
    printf("%d\n", countSockPairs(numSocks, colors));
    return 0;
}
