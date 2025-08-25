#include <stdio.h>
#include <stdlib.h>
int diagonalDifference(int size,int matrix[size][size]) {
    int sumMain=0;
    int sumAnti=0;
    for (int row =0;row<size;row++) {
        sumMain +=matrix[row][row];
        sumAnti +=matrix[row][size-row-1];
    }
    return abs(sumMain-sumAnti);
}
int main() {
    int dimension;
    scanf("%d",&dimension);
    int data[dimension][dimension];
    for (int r=0;r<dimension;r++) {
        for (int c = 0;c<dimension; c++) {
            scanf("%d",&data[r][c]);
        }
    }
    printf("%d\n", diagonalDifference(dimension, data));
    return 0;
}
