class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        s = '#' + s; 
        int n = s.length() - 1;
        unordered_map<char, int> last;
        vector<int> dp1(n + 2, 0);
        vector<int> lastPos(26, -1);
        dp1[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp1[i] = (2 * dp1[i - 1]) % MOD;
            if (lastPos[s[i] - 'a'] != -1) {
                dp1[i] = (dp1[i] - dp1[lastPos[s[i] - 'a'] - 1] + MOD) % MOD;
            }
            lastPos[s[i] - 'a'] = i;
        }
        return (dp1[n] - 1 + MOD) % MOD;
    }
};
