class Solution {
    private:
    int solve(vector<int> &nums, vector<int> &dp, int target){
        int n = nums.size();
        if(target==0) return 1;
        if(dp[target] != -1) return dp[target];
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=target){
                cnt += solve(nums,dp,target-nums[i]);
            }
        }
        return dp[target] = cnt;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                if(nums[j]<=i){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return (int)dp[target];
    }
};
