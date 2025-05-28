class Solution {
public:
    const int MOD = 1e9 + 7;
    int checkRecord(int n) {
        long dp[2][3] = {1, 0, 0};
        long total = 0;
        vector<long> dpNoA(n + 1);
        dpNoA[0] = 1;
        for (int i = 1; i <= n; i++) {
            long next[3] = {0, 0, 0};
            for (int j = 0; j < 3; ++j)
                next[0] = (next[0] + dp[0][j]) % MOD;
            next[1] = dp[0][0];
            next[2] = dp[0][1];
            dp[0][0] = next[0];
            dp[0][1] = next[1];
            dp[0][2] = next[2];
            dpNoA[i] = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;
        }
        total = dpNoA[n];
        for (int i = 0; i < n; ++i) {
            long left = dpNoA[i];
            long right = dpNoA[n - i - 1];
            total = (total + (left * right) % MOD) % MOD;
        }
        return total;
    }
};
