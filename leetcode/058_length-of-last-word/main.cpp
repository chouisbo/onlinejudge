#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
    	int len = 0;
    	if (s.size() > 0) {
    		const char STOPPER = ' ';
	    	string::reverse_iterator rit = s.rbegin();
	    	// trimming
			while (*rit == STOPPER && rit != s.rend()) rit++;
			while (*rit != STOPPER && rit != s.rend()) {
				len++; rit++;
			}
    	}
        return len;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.lengthOfLastWord("") << endl;
	cout << s.lengthOfLastWord("Hello World") << endl;
	cout << s.lengthOfLastWord("HelloWorld") << endl;
	cout << s.lengthOfLastWord("a ") << endl;
	return 0;
}