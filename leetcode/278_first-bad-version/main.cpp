
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 0) return 0;
        if (n == 1) return isBadVersion(n) ? 1 : 0;
        int low = 1, high = n, mid;
        int bad = 0;
        while (low <= high) {
            mid = (high - low)/2 + low;
            if (isBadVersion(mid)) {
                bad  = mid;
                high = mid -1;
            } else {
                low  = mid+1;
            }
        }
        return bad;
    }
};
