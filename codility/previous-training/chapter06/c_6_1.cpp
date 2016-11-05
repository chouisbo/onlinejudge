#include <cstdio>
#include <vector>

using namespace std;

int solution(const vector<int> &A) {
    // write your code in C++98
    if (A.empty()) {
        return -1;
    }
    int answer = 0, count = 1;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] == A[answer]) {
                ++count;
        }
        else if (--count == 0) {
            answer = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == A[answer]) {
            ++count;
        }
    }
    return ((count << 1) > A.size())?answer:(-1);
            
}

int main(int argc, const char *argv) {

    int A[] = {3, 4, 3, 2, 3, -1, 3, 3};
    vector<int> vA(A, A + sizeof(A)/sizeof(int) );
    printf("%d\n", solution);
    return 0;
}



