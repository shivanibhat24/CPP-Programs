class Solution {
public:
    const int mod = 1000000007;

    long long count(long long len) {
        return len * (len + 1) / 2;
    }

    int numSub(string s) {
        long long len = 0, ans = 0;
        for (char c : s) {
            if (c == '1') len++;
            else {
                ans = (ans + count(len)) % mod;
                len = 0;
            }
        }
        if (len) ans = (ans + count(len)) % mod;
        return ans % mod;
    }
};
