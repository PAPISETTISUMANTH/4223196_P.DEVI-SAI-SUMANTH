#include <stdio.h>
unsigned int flippingBits(unsigned int value) {
    unsigned int flipped = 0;
    for (int bit=0;bit<32;bit++) {
        if ((value & (1U<<bit))==0) {
            flipped |=(1U<<bit);
        }
    }
    return flipped;
}
int main() {
    int queries;
    scanf("%d",&queries);

    while (queries--) {
        unsigned int inputNum;
        scanf("%u",&inputNum);
        printf("%u\n",flippingBits(inputNum));
    }

    return 0;
}
