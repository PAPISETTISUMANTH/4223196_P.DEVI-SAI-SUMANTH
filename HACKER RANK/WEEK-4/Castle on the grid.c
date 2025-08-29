#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 105
typedef struct Position {
    int row, col, dist;
} Position;
char board[MAX_SIZE][MAX_SIZE];
int explored[MAX_SIZE][MAX_SIZE];
int size;
Position bfsQueue[MAX_SIZE * MAX_SIZE];
int head = 0, tail = 0;
void push(Position p) {
    bfsQueue[tail++] = p;
}
Position pop() {
    return bfsQueue[head++];
}
int empty() {
    return head == tail;
}
int shortestPathMoves(char board[MAX_SIZE][MAX_SIZE], int rStart, int cStart, int rGoal, int cGoal, int size) {
    memset(explored, 0, sizeof(explored));
    head = tail = 0;

    Position start = {rStart, cStart, 0};
    push(start);
    explored[rStart][cStart] = 1;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    while (!empty()) {
        Position current = pop();
        if (current.row == rGoal && current.col == cGoal) {
            return current.dist;
        }

        for (int d = 0; d < 4; ++d) {
            int nr = current.row;
            int nc = current.col;

            while (1) {
                nr += dr[d];
                nc += dc[d];
                if (nr < 0 || nr >= size || nc < 0 || nc >= size || board[nr][nc] == 'X') {
                    break;
                }
                if (!explored[nr][nc]) {
                    explored[nr][nc] = 1;
                    Position nextPos = {nr, nc, current.dist + 1};
                    push(nextPos);
                }
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        scanf("%s", board[i]);
    }
    int startRow, startCol, goalRow, goalCol;
    scanf("%d %d %d %d", &startRow, &startCol, &goalRow, &goalCol);
    int moves = shortestPathMoves(board, startRow, startCol, goalRow, goalCol, size);
    printf("%d\n", moves);
    return 0;
}