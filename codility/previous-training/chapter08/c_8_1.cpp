#include <iostream>
#include <cmath>

using namespace std;

// you can also use includes, for example:
// #include <algorithm>
int solution(int N) {
    // write your code in C++98
    int q=0, p=0;
    for (p=sqrt(N); p>=1; p--) {
        q = N / p;
        if (p*q == N) {
            break;
        }
    }
    return 2*(p+q);
}


int main(int argc, char** argv) {
    cout << solution(30) << endl;
	return 0;
}
