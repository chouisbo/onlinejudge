#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word2.length(), n = word1.length();
        vector<size_t> prev(n+1), current(n+1, 0);
        iota(prev.begin(), prev.end(), 0);
        for (size_t i=1; i<m+1; i++) {
            current[0] = i;
            for (size_t j=1; j<n+1; j++) {
                if (word2[i-1] == word1[j-1]) {
                    current[j] = prev[j-1]; 
                } else {
                    current[j] = min(min(prev[j-1]+1, prev[j]+1), current[j-1]+1);
                }
            }
            swap_ranges(prev.begin(), prev.end(), current.begin());
        }
        return (int) prev[n];
    }
private:
    void printVec(const vector<size_t> &vec) {
        for (auto &x : vec) {
            printf("%d, ", (int) x);
        }
        printf("\n");
    }
};

void calcEditDistance(string word1, string word2) {
    Solution s;
    printf("The Edit Distance between \"%s\" and \"%s\" is %d.", 
        word1.c_str(), word2.c_str(), s.minDistance(word1, word2));
}

int main(void) {
    calcEditDistance("kitten", "sitting");
    return 0;
}

