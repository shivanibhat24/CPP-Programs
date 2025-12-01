class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, bad = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(isBadVersion(mid)) {
                bad = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return bad;
    }
};
