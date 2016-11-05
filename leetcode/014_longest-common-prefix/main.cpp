#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string sb("");

    	if (strs.size() <= 0) {
    		return sb;
    	}

    	// find the lowest length string
    	int min_len = INT_MAX;
    	for (vector<string>::iterator it = strs.begin();
    		 it != strs.end(); ++it) {
    		if (it->length() < min_len) {
    			min_len = it->length();
    		}
    	}
    	if (min_len <= 0) {
    		return sb;
    	}
    	
    	bool bEnd = false;
    	for (int i=0; i<min_len; i++) {
    		const char ch = strs[0][i];
    		for (vector<string>::iterator it = strs.begin();
    		 	 it != strs.end(); ++it) {
    			if (it->at(i) != ch) {
    				bEnd = true;
    				break;
    			}
    		}
    		if (bEnd) {
    			return sb;
    		} else {
    			sb.push_back(ch);
    		}
    	}
    }
};


int main(int argc, char const *argv[])
{
	std::vector<string> v;
	// v.push_back("");
	v.push_back("happy");
	v.push_back("happyWorld");
	v.push_back("hapHanness");
	Solution s;
	cout << s.longestCommonPrefix(v) << endl; 
	return 0;
}
