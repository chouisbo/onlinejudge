#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define QUEUE_CAPACITY 40000
int queue[QUEUE_CAPACITY][2];
int q_head = 0;
int q_tail = 0;

void enqueue(int queue[QUEUE_CAPACITY][2], int row, int col) {
    queue[q_tail][0] = row;
    queue[q_tail][1] = col;            
    q_tail++;
    if (q_tail >= QUEUE_CAPACITY) {
        q_tail -= QUEUE_CAPACITY;    
    }
}

void dequeue(int queue[QUEUE_CAPACITY][2], int *row, int *col) {
    *row = queue[q_head][0];
    *col = queue[q_head][1];
    q_head++;
    if (q_head >= QUEUE_CAPACITY) {
        q_head -= QUEUE_CAPACITY;    
    }
}

void solve(char** board, int boardRowSize, int boardColSize) {

    for (int row = 0; row < boardRowSize; row++) {
        if ('O' == board[row][0]) {
            enqueue(queue, row, 0);
        }
        if ('O' == board[row][boardColSize-1]) {
            enqueue(queue, row, boardColSize-1);
        }
    }
    for (int col = 0; col < boardColSize; col++) {
        if ('O' == board[0][col]) {
            enqueue(queue, 0, col);
        }
        if ('O' == board[boardRowSize-1][col]) {
            enqueue(queue, boardRowSize-1, col);
        }
    }

    int row, col;
    while (q_head != q_tail) {
        dequeue(queue, &row, &col);
        if (board[row][col] != 'O') continue;
        
        board[row][col] = 'D';
        if (row > 1 && 'O' == board[row-1][col]) {
            enqueue(queue, row-1, col);
        }
        if (row < boardRowSize-1 && 'O' == board[row+1][col]) {
            enqueue(queue, row+1, col);
        }
        if (col > 1 && 'O' == board[row][col-1]) {
            enqueue(queue, row, col-1);
        }
        if (col < boardColSize-1 && 'O' == board[row][col+1]) {
            enqueue(queue, row, col+1);
        }
    }
    
    for (int row = 0; row < boardRowSize; row++) {
        for (int col = 0; col < boardColSize; col++) {
            if ('O' == board[row][col]) {
                board[row][col] = 'X';
            }
            if ('D' == board[row][col]) {
                board[row][col] = 'O';            
            }
        }
    }

}

void printBoard(char **board, int boardRowSize, int boardColSize) {
    for (int row = 0; row < boardRowSize; row++) {
        for (int col = 0; col < boardColSize; col++) {
            printf("%c, ", board[row][col]);
        }
        printf("\n");
    }
}

void test_01() {
    char **board = (char **)malloc(sizeof(char *) * 4);
    for (int i=0; i<4; i++) {
        board[i] = (char *)malloc(sizeof(char) * 4);
    }
    memcpy(board[0], "XXXX", 4);
    memcpy(board[1], "XOOX", 4);
    memcpy(board[2], "XXOX", 4);
    memcpy(board[3], "XOXX", 4);
    solve(board, 4, 4);
    printBoard(board, 4, 4);

    for (int i=0; i<4; i++) {
        free(board[i]);
    }
    free(board);
}


int main(void) {

    test_01();
    return 0;
}

