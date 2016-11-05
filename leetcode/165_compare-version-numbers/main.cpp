class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t p1 = 0, p2 = 0;
        int v1, v2;
        while (p1 < version1.length() && p2 < version2.length()) {
            v1 = nextVersionNum(version1, p1);
            v2 = nextVersionNum(version2, p2);
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
        }
        if (p1 == version1.length() && p2 == version2.length()) return 0;
        if (p2 == version2.length()) {
            while (p1 < version1.length()) {
                v1 = nextVersionNum(version1, p1);
                if (v1 != 0) return 1;
            }
            return 0;
        }
        if (p1 == version1.length()) {
            while (p2 < version2.length()) {
                v2 = nextVersionNum(version2, p2);
                if (v2 != 0) return -1;
            }
            return 0;
        }
    }

    static int nextVersionNum(const string &version, size_t &startPos) {
        // assumption startPos < version.length()
        size_t endPos = version.find('.', startPos);
        int val = -1;
        if (endPos != string::npos) {
            val = stoi(version.substr(startPos, endPos));
            startPos = endPos+1;
        } else {
            val = stoi(version.substr(startPos));
            startPos = version.length();    
        }
        return val;
        
    }
};
