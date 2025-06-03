class Solution {
public:
    int numPermsDISequence(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'I') {
                int sum = 0;
                for (int j = 0; j <= n - i; ++j) {
                    sum = (sum + dp[i - 1][j]) % MOD;
                    dp[i][j] = sum;
                }
            } else {
                int sum = 0;
                for (int j = n - i; j >= 0; --j) {
                    sum = (sum + dp[i - 1][j + 1]) % MOD;
                    dp[i][j] = sum;
                }
            }
        }
        int result = 0;
        for (int j = 0; j <= n; ++j) {
            result = (result + dp[n][j]) % MOD;
        }
        return result;
    }
};
