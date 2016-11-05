#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rs;
        int mid = rowIndex/2;
        int r   = rowIndex & 0x1;
        for (int i=0; i<=mid; i++) {
            rs.push_back(combination(rowIndex, i));
        }
        if (0 == r) {
            for (int j=1; mid+j<=rowIndex; j++) {
                rs.push_back(rs[mid-j]);
            }
        }
        if (1 == r) {
            for (int j=1; mid+j<=rowIndex; j++) {
                rs.push_back(rs[mid+1-j]);
            }
        }
        return rs;
    }

    static int combination(int m, int n) {
        if (0 == n) return 1;
        if (1 == n) return m;
        if (n > (m-n)) return combination(m, m-n);
        long com = m;
        for (int i=1; i<n; i++) {
            com *= (m-i);
            com /= (i+1);
        }
        return com;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;
    vector<int> rs = s.getRow(4);
    for (vector<int>::const_iterator it = rs.begin();
            it != rs.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;

    return 0;
}

