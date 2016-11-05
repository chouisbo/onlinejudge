#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printVector(const vector<int> &v) {
    for(int i=0; i<v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

// you can also use includes, for example:
// #include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++98
    int n = A.size(), temp = 0;
    vector<int> B(n-2, 0);
    for (int i=1; i<n-1; ++i) {
        if (temp < 0) {
            temp = 0;
        }
        temp += A[i];
        B[i-1] = max(temp, A[i]);
    }
    //printVector(B);
    
    vector<int> C(n-2, 0);
    temp = 0;
    for (int i=n-2; i>0; --i) {
        if (temp < 0) {
            temp = 0;
        }
        temp += A[i];
        C[i-1] = max(temp, A[i]);
    }
    //printVector(C);
    
    int answer = INT_MIN;
    for (int y=0; y<n-2; y++) {
        temp = B[y]+C[y]-2*A[y+1];
        if (answer < temp) {
            answer = temp;
        }
    }
    return answer;
}


int main(int argc, char** argv) {
    //int A[] = {3,2,6,-1,4,5,-1,2};
    int A[] = {1,2,3};
    vector<int> vA(A, A+sizeof(A)/sizeof(int));
    cout << solution(vA) << endl;
    
	return 0;
}
