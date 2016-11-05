#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int SIDE_LEN = 9;
        const int SQUARE_SIDE_LEN = 3;

        bitset<10> bs;
        // check each row
        for (int i=0; i<SIDE_LEN; i++) {
            bs.reset();
            for (int j=0; j<SIDE_LEN; j++) {
                if (board[i][j] == '.') continue;
                if (bs[board[i][j]-'0']) {
                    return false;
                } else {
                    bs.flip(board[i][j]-'0');
                }
            }
        }
        
        // check each column
        for (int i=0; i<SIDE_LEN; i++) {
            bs.reset();
            for (int j=0; j<SIDE_LEN; j++) {
                if (board[j][i] == '.') continue;
                if (bs[board[j][i]-'0']) {
                    return false;
                } else {
                    bs.flip(board[j][i]-'0');
                }
            }
        }

        // check each square
        for (int i=0; i<SIDE_LEN; i += SQUARE_SIDE_LEN) {
            for (int j=0; j<SIDE_LEN; j += SQUARE_SIDE_LEN) {
                bs.reset();
                for (int k=0; k<SQUARE_SIDE_LEN; k++) {
                    for (int m=0; m<SQUARE_SIDE_LEN; m++) {
                        if (board[i+k][j+m] == '.') continue;
                        if (bs[board[i+k][j+m]-'0']) {
                            return false;
                        } else {
                            bs.flip(board[i+k][j+m]-'0');
                        }
                    }
                }
            }
        }

        return true;        
    }
};
