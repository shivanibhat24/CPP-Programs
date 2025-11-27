class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long prefix=0;
        int n=nums.size();
        vector<long long>bestMin(k, LLONG_MAX);
        bestMin[0]=0;
        long long ans=LLONG_MIN;
        for(int i=1; i<=n; i++){
            prefix+=nums[i-1];
            int mod=i%k;
            if(bestMin[mod]!=LLONG_MAX){
                ans=max(ans,prefix-bestMin[mod]);
            }
            bestMin[mod]=min(bestMin[mod],prefix);
        }
        return ans;        
    }
};
