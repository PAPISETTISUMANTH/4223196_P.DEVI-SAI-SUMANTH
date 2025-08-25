#include <stdio.h>
int s1[100000], s2[100000],t1=-1,t2=-1;
int main() {
    int q,type,x;
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&type);
        if (type==1) { 
            scanf("%d",&x);
            s1[++t1]=x; 
        } 
        else if (type==2) {
            if (t2==-1)while (t1!=-1)s2[++t2]=s1[t1--];
            if (t2!=-1)t2--;
        } 
        else {
            if (t2==-1)while(t1!=-1) s2[++t2]=s1[t1--];
            if (t2!=-1)printf("%d\n", s2[t2]);
        }
    }
    return 0;
}
