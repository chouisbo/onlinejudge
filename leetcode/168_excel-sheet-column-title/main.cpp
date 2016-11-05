class Solution {
public:
    string convertToTitle(int n) {
        string rs = "";
        int q, r;
        while (n > 0) {
            q = n / 26;
            r = n - 26*q;
            if (0 == r) {
                q--;
                rs.push_back('Z');
            } else {
                rs.push_back('A'+r-1);
            }
            n = q;
        }
        // reverse rs;
        for (int i=0, j=rs.length()-1; i<j; i++, j--) {
            rs[i] = rs[i] ^ rs[j];
            rs[j] = rs[i] ^ rs[j];
            rs[i] = rs[i] ^ rs[j];
        }
        return rs;
    }
};
