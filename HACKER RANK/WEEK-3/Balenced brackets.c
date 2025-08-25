#include<stdio.h>
#include<string.h>
#define L 1000
const char* check(char*s){
    int top=-1;char stk[L];int n=strlen(s);
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='('||c=='{'||c=='[')stk[++top]=c;
        else{if(top==-1)return"NO";char o=stk[top--];
        if((c==')'&&o!='(')||(c=='}'&&o!='{')||(c==']'&&o!='['))return"NO";}
    }
    return top==-1?"YES":"NO";
}
int main(){
    int t;scanf("%d",&t);
    while(t--){char s[L];scanf("%s",s);printf("%s\n",check(s));}
    return 0;
}
