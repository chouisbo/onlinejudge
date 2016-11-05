#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	if (1 == numRows) {
    		return s;
    	}

    	string sb("");

    	if (2 == numRows) {
    		for (int i=0; i<s.length(); i+=2) {
    			sb.push_back(s[i]);
    		}
    		for (int i=1; i<s.length(); i+=2) {
    			sb.push_back(s[i]);
    		}
    	} else {
	        for (int i=1; i<=numRows; i++) {
				appendLevel(sb, s, i, numRows);
			}
		}
		return sb;
    }

private:
	void appendLevel(string &sb, const string &s, int level, const int MaxLevel) {
		int p        = level - 1;
		if (p >= s.length()) {
			return;
		}
		sb.push_back(s[p]);

		bool du_flag = true;
		int delta    = 0;
		while (true) {
			if (du_flag) {
				// delta = down_next(level, MaxLevel);
				delta = (level >= MaxLevel) ? 0 : (1+(MaxLevel-level+1-2)*2 + 1);
			} else {
				// delta = up_next(level, MaxLevel);
				delta = (level <= 1) ? 0 : (1+(level-2)*2 + 1);
			}
			du_flag = !du_flag;
			if (delta > 0) {
				p += delta;
				if (p >= s.length()) { return; }
				sb.push_back(s[p]);
			}
		}

	}

	// int down_next(int level, const int MaxLevel) {
	// 	if (level >= MaxLevel) {
	// 		return 0;
	// 	}
	// 	return 1+(MaxLevel-level+1-2)*2 + 1;
	// }

	// int up_next(int level, const int MaxLevel) {
	// 	if (level <= 1) {
	// 		return 0;
	// 	}
	// 	return 1+(level-2)*2 + 1;
	// }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 1) << endl;
	cout << s.convert("PAYPALISHIRING", 2) << endl;
	cout << s.convert("PAYPALISHIRING", 3) << endl;
	cout << s.convert("PAYPALISHIRING", 4) << endl;
	cout << s.convert("PAYPALISHIRING", 5) << endl;
	cout << s.convert("PAYPALISHIRING", 6) << endl;

	cout << "*" << s.convert("A", 3) << "*" << endl;
	
	return 0;
}


