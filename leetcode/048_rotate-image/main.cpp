#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const size_t N = matrix.size();
        size_t n, x, y;
        for (size_t i=0; i<N/2; i++) {
            n = N-2*i;
            for (size_t k = 0; k < n-1; k++) {
                x = i+k; y = i;
                swap(matrix[x][y], matrix[N-y-1][x]);
                swap(matrix[N-y-1][x], matrix[N-x-1][N-y-1]);
                swap(matrix[N-x-1][N-y-1], matrix[y][N-x-1]);
            }
        }
    }
};

void printMatrix(const vector< vector<int> > & matrix) {
    for (auto &row : matrix) {
        for (auto &x : row) {
            printf("%3d, ", x);
        }
        cout << endl;
    }
}


int main(void) {

    // [[2,29,20,26,16,28],[12,27,9,25,13,21],[32,33,32,2,28,14],[13,14,32,27,22,26],[33,1,20,7,21,7],[4,24,1,6,32,34]]
    vector< vector<int> > matrix;
    matrix.push_back({2,29,20,26,16,28});
    matrix.push_back({12,27,9,25,13,21});
    matrix.push_back({32,33,32,2,28,14});
    matrix.push_back({13,14,32,27,22,26});
    matrix.push_back({33,1,20,7,21,7});
    matrix.push_back({4,24,1,6,32,34});

    printMatrix(matrix);
    Solution s;
    s.rotate(matrix);
    cout << "###############################" << endl;
    printMatrix(matrix);


    return 0;
}

