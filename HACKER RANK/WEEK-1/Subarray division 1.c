#include <stdio.h>
int main() {
    int size;
    scanf("%d", &size);
    int bar[size];
    for (int a=0;a<size;a++) scanf("%d",&bar[a]);
    int day, month;
    scanf("%d%d",&day,&month);
    int count=0;
    for (int start=0;start<=size-month;start++) {
        int total=0;
        for (int step=0;step<month;step++) total+=bar[start+step];
        if (total==day)count++;
    }
    printf("%d\n", count);
    return 0;
}
