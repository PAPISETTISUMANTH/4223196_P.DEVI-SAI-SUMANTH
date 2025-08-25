#include<stdio.h>
void solve(int t,int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==t){
                printf("%d %d\n",i+1,j+1);
                return;
            }
        }
    }
}
int main(){
    int c;scanf("%d",&c);
    while(c--){
        int t,n;scanf("%d%d",&t,&n);
        int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
        solve(t,a,n);
    }
    return 0;
}
