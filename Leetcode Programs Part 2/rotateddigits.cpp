class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(max(n + 1, 10), 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 0;
        dp[4] = 0;
        dp[5] = 2;
        dp[6] = 2;
        dp[7] = 0;
        dp[8] = 1;
        dp[9] = 2;
        int count = 0;
        for(int i = 0; i <= min(10, n); i++) {
            if(dp[i] == 2)
            count++;
        }
        for (int i = 10; i <= n; i++) {
            if (dp[i % 10] == 0 || dp[i / 10] == 0) {
                dp[i] = 0;
            } else if (dp[i % 10] == 1 && dp[i / 10] == 1) {
                dp[i] = 1;
            } else {
                dp[i] = 2;
                ++count;
            }
        }        
        return count;
    }
};
