
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string patternMap[26] = {""};

        vector<string> vecWords = strSplit(str, " ");
    
        if (pattern.length() != vecWords.size()) { return false; }
    
        set<string> mappedWordSet;
    
        for (size_t i=0; i<pattern.length(); ++i) {
            if (patternMap[pattern.at(i)-'a'] != "") {
                if (patternMap[pattern.at(i)-'a'] != vecWords.at(i)) {
                    return false;
                }
            } else {
                if (mappedWordSet.find(vecWords.at(i)) != mappedWordSet.end()) {
                    return false;
                }
                patternMap[pattern.at(i)-'a'] = vecWords.at(i);
                mappedWordSet.insert(vecWords.at(i));
            }
        }
    
        return true;
    }

private:
    static vector<string> strSplit(const string &text, string separator) {
        vector<string> rsVec;

        string::size_type p_start = 0, p_end;
        while ((p_end = text.find(separator, p_start)) != string::npos) {
            if (p_end > p_start) {
                rsVec.push_back(text.substr(p_start, p_end - p_start));
            }
            p_start = p_end + separator.length();
        }
        if (p_start < text.length()) {
            rsVec.push_back(text.substr(p_start));
        }

        return rsVec;
    }

};