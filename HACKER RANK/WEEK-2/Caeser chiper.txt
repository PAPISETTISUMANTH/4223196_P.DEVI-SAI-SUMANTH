#include <stdio.h>
#include <string.h>
#include <ctype.h>
void e(char a[], int b) {
    b = b % 26; 
    for (int c = 0; a[c] != '\0'; c++) {
        if (isalpha(a[c])) { 
            char d = isupper(a[c]) ? 'A' : 'a';
            a[c] = ((a[c] - d + b) % 26) + d;
        }
    }
}
int main() {
    int p, q;
    char r[1000];
    int s, t; 
    scanf("%d", &p); 
    scanf("%s", r);  
    scanf("%d", &q); 
    s = p + q; 
    t = p - q; 
    e(r, q);
    printf("%s\n", r);    
    return 0;
}
