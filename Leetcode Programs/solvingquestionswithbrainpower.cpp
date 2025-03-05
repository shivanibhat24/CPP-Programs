class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1);
        for (int i = n-1; i >= 0; i--) {
            int p = questions[i][0], j = questions[i][1];
            int ne = min(n, i+j+1);
            dp[i] = max(dp[i+1], p+dp[ne]);
        }
        return dp[0];
    }
};
