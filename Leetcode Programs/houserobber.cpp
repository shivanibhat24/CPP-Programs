class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101];

        dp[0] = nums[0];
        if (nums.size() != 1) dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};
