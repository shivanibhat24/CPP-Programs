class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int>dp(n,0),sum(n,0);
        int k=nums.size();
        for(int i=0;i<k;i++){
            sum[nums[i]]+=nums[i];
        }
        dp[0]=0;
        dp[1]=sum[1];
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+sum[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
