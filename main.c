#include <stdio.h>
#include <stdbool.h>

#define SIZE 8
#define MOVES 8

typedef int Board[SIZE][SIZE];

const int dx[MOVES] = {2,1,-1,-2,-2,-1,1,2};
const int dy[MOVES] = {1,2,2,1,-1,-2,-2,-1};

bool ok(int x, int y, Board board) {
return (x >=0 && x < SIZE && y >=0 && y < SIZE && board[y][x] ==0);
}

int tour(int sx, int sy) {
Board board = {0};
int x = sx, y = sy, c = 1; 
board[y][x] = c; 

while(1) {
int moved = 0; 

for (int i = 0; 
i < MOVES; i++) {
int nx = x + dx[i], ny = y + dy[i];
if (ok(nx, ny, board)) {
x = nx; y = ny; board[y][x] = c++; moved = 1; 

break; 
}}

if (!moved) break; 
}

return c;
}

int main (void) {
    printf("Greedy Knight's Tour (%dx%d)\n\n", SIZE, SIZE);
    for (int y = 0; y < SIZE; y++) {
    for (int x = 0; x < SIZE; x++)
    printf("%3d", tour(x,y)); 
    printf("\n");
    }
return 0; 
}