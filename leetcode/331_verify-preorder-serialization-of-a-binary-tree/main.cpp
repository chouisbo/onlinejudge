
/**
Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
**/

#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:

    static vector<string> splitStrToVec(const string &str, const string sep) {
        vector<string> rs;
        string text(str); text.append(sep);
        size_t s = 0, p, lenSep = sep.length();
        while ((p = text.find(sep, s)) != string::npos) {
            rs.push_back(str.substr(s, p-s));
            s = p + lenSep;
        }
        return rs;
    }

    bool isValidSerialization(string preorder) {
        size_t s = 0, p;
        preorder.append(",");
        stack<string> st;
        string token;
        st.push("$");
        while ((p = preorder.find(",", s)) != string::npos) {
            token = preorder.substr(s, p-s);
            s = p + 1;
            if (token != "#") {
                st.push(token);
            } else {
                if (st.empty()) return false;
                else if (st.top() == "$") {
                    st.pop(); break;
                } else st.pop();
            }
        }
        if (s < preorder.length() || ! st.empty()) return false;
        else return true;
    }
};

int main(void) {

    Solution s;

    string text("9,3,4,#,#,1,#,#,2,#,6,#,#");
    for (auto &x : s.splitStrToVec(text, ",")) {
        cout << x << "; ";
    }
    cout << endl;

/**
"9,3,4,#,#,1,#,#,2,#,6,#,#"
"1,#"
"9,#,#,1"
"#,#"
"#,7,6,9,#,#,#"

expected

true
false
false
false
false
**/

    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("1,#") << endl;
    cout << s.isValidSerialization("9,#,#,1") << endl;
    cout << s.isValidSerialization("#,#") << endl;
    cout << s.isValidSerialization("#,7,6,9,#,#,#") << endl;

    return 0;

}
