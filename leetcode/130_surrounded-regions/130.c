#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(int *s, int x) {
    if (s[x] < 0) {
        return x;
    } else {
        return (s[x] = find(s, s[x]));
    }
}

void unionSets(int *s, int a, int b) {
    int root1 = find(s, a);
    int root2 = find(s, b);
    if (root1 == root2) return;
    if (s[root2] < s[root1]) {
        s[root1] = root2;
    } else {
        if (s[root1] == s[root2]) { --s[root1];
        }
        s[root2] = root1;
    }
}

void solve(char** board, int boardRowSize, int boardColSize) {
    int *s = (int *) malloc(sizeof(int) * boardRowSize * boardColSize);
    for (int i = 0; i < boardRowSize * boardColSize; i++) s[i] = -1;
    for (int row = 0; row < boardRowSize; row++) {
        for (int col = 0; col < boardColSize; col++) {
            if ('O' == board[row][col]) {
                if (row > 1 && 'O' == board[row-1][col]) 
                    unionSets(s, row*boardColSize+col, (row-1)*boardColSize+col);
                if (row < boardRowSize - 1 && 'O' == board[row+1][col]) 
                    unionSets(s, row*boardColSize+col, (row+1)*boardColSize+col);
                if (col > 1 && 'O' == board[row][col-1])
                    unionSets(s, row*boardColSize+col, row*boardColSize+col-1);
                if (col < boardColSize - 1 && 'O' == board[row][col+1])
                    unionSets(s, row*boardColSize+col, row*boardColSize+col+1);
            }   
        }
    }
    
    int *c = (int *) malloc(sizeof(int) * boardRowSize * boardColSize);
    for (int i = 0; i < boardRowSize * boardColSize; i++) c[i] = 0;
    for (int row = 0; row < boardRowSize; row++) {
        if ('O' == board[row][0]) {
            c[find(s, row*boardColSize)] = 1;
        }
        if ('O' == board[row][boardColSize-1]) {
            c[find(s, row*boardColSize+boardColSize-1)] = 1;
        }
    }
    for (int col = 0; col < boardColSize; col++) {
        if ('O' == board[0][col]) {
            c[find(s, col)] = 1;
        }
        if ('O' == board[boardRowSize-1][col]) {
            c[find(s, (boardRowSize-1)*boardColSize+col)] = 1;
        }
    }

    for (int row = 0; row < boardRowSize; row++) {
        for (int col = 0; col < boardColSize; col++) {
            if ('O' == board[row][col] && c[find(s, row*boardColSize+col)] != 1) {
                /* printf("board[%d][%d] ==> %c\n", row, col, board[row][col]); */
                board[row][col] = 'X';
            }
        }
    }
    
    free(s);
    free(c);
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

