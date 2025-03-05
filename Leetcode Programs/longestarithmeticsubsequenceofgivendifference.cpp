class Solution {
public:
    int longestSubsequence(vector<int>& num, int difference) {
        int n = num.size();
        if(n == 1)
            return 1;
        vector<int> dp(40001,0);
        int ans = 1;
        for(int i = 0; i < n; i++){
            int prev_val = num[i] - difference;
            dp[20000+num[i]] = dp[20000+prev_val]+1;
            ans = max(ans, dp[20000+num[i]]);
        }
        return ans;
    }
};
