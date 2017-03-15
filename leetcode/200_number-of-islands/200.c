#include <stdio.h>
#include <stdlib.h>

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

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int *s = (int *) malloc(sizeof(int) * gridRowSize * gridColSize);
    for (int i = 0; i < gridRowSize * gridColSize; i++) s[i] = -1;
    for (int row = 0; row < gridRowSize; row++) {
        for (int col = 0; col < gridColSize; col++) {
            if ('1' == grid[row][col]) {
                if (row > 1 && '1' == grid[row-1][col]) 
                    unionSets(s, row*gridColSize+col, (row-1)*gridColSize+col);
                if (row < gridRowSize - 1 && '1' == grid[row+1][col]) 
                    unionSets(s, row*gridColSize+col, (row+1)*gridColSize+col);
                if (col > 1 && '1' == grid[row][col-1])
                    unionSets(s, row*gridColSize+col, row*gridColSize+col-1);
                if (col < gridColSize - 1 && '1' == grid[row][col+1])
                    unionSets(s, row*gridColSize+col, row*gridColSize+col+1);
            }   
        }
    }
    
    int *c = (int *) malloc(sizeof(int) * gridRowSize * gridColSize);
    for (int i = 0; i < gridRowSize * gridColSize; i++) c[i] = 0;
    for (int row = 0; row < gridRowSize; row++) {
        for (int col = 0; col < gridColSize; col++) {
            if ('1' == grid[row][col]) {
                c[find(s, row*gridColSize+col)] = 1;
            }
        }
    }
    
    free(s);

    int count = 0;
    for (int i = 0; i < gridRowSize * gridColSize; i++) {
        if (c[i] > 0) count++;
    }

    free(c);

    return count;
}

void test_01() {
    char* grid[] = {
        "11110",
        "11010",
        "11000",
        "00000"
    };
    printf("%d\n", numIslands(grid, 4, 5));
}

void test_02() {
    char* grid[] = {
        "11000",
        "11000",
        "00100",
        "00011"
    };
    printf("%d\n", numIslands(grid, 4, 5));
}

void test_03() {
    char* grid[] = {"1","0","1","0","1","1"};
    printf("%d\n", numIslands(grid, 6, 1));
}

int main(void) {

    test_01();
    test_02();
    test_03();
    return 0;
}

