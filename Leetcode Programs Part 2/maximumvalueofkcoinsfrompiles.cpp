class Solution {
private:
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, INT_MIN);
        dp[0] = 0;
        for(auto &p: piles) {
            int n = p.size();
            vector<int> prefixSum(min(n,k) + 1, 0);
            for(int i = 1; i < prefixSum.size(); i++) {
                prefixSum[i] = prefixSum[i - 1] + p[i - 1];
            }

            vector<int> tempDp = dp;

            for(int i = 0; i <= k; i++) {
                if (dp[i] < 0 and i != 0) continue;
                for(int j = 1; j < prefixSum.size() and k >= i + j; j++){
                    tempDp[i + j] = max(dp[i] + prefixSum[j], tempDp[i + j]);
                }
            }
            dp.swap(tempDp);
        }
        return dp[k];
    }
};
