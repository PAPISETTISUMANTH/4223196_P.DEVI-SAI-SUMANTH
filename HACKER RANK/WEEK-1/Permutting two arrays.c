#include <stdio.h>
#include <stdlib.h>
int cmpA(const void*a, const void*b){ return*(int*)a-*(int*)b;}
int cmpB(const void*a, const void*b){ return*(int*)b-*(int*)a;}
int main() {
    int q,n,k;
    scanf("%d",&q);
    while(q--) {
        scanf("%d %d",&n,&k);
        int A[n],B[n];
        for(int i=0;i<n;i++) scanf("%d",&A[i]);
        for(int i=0;i<n;i++) scanf("%d",&B[i]);
        qsort(A,n,sizeof(int),cmpA);
        qsort(B,n,sizeof(int),cmpB);
        int ok=1;
        for(int i=0;i<n;i++) if(A[i]+B[i]<k){ ok=0; break; }
        printf(ok?"YES\n":"NO\n");
    }
}
