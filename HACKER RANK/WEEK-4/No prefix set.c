#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define K 26

typedef struct N { struct N* c[K]; bool end; } N;

N* mk(){ return (N*)calloc(1,sizeof(N)); }

bool ins(N* r, const char* s){
    N* p = r;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - 'a';
        if (!p->c[x]) p->c[x] = mk();
        p = p->c[x];
        if (p->end && s[i+1]) return false;  
    }
    if (p->end) return false;                 
    for (int i = 0; i < K; i++)               
        if (p->c[i]) return false;
    p->end = true;
    return true;
}

int main(){
    int n; if (scanf("%d",&n)!=1) return 0;
    N* root = mk();
    char w[100005];
    for (int i = 0; i < n; i++) {
        scanf("%s", w);
        if (!ins(root, w)) { printf("BAD SET\n%s\n", w); return 0; }
    }
    printf("GOOD SET\n");
    return 0;
}
