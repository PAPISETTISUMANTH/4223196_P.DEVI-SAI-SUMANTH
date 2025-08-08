#include <stdio.h>
#include <string.h>
int main() {
    int a,q;
    scanf("%d",&a);
    char s[1000][21]; 
    for (int i =0;i<a;i++) {
        scanf("%s",s[i]);
    }
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        char query[21];
        scanf("%s",query);
        int count=0;
        for (int j=0;j<a;j++) {
            if (strcmp(s[j],query)==0) {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
