class Solution {
public:    
    int racecar(int target) {
        vector<int> dp(target+1,-1);
        return helper(target,dp);
    }
    int helper(int t,vector<int> &dp){
        if(dp[t]>0) return dp[t];
        int n = floor(log2(t))+1;
        if((1<<n)-1 == t)   dp[t]=n;
        else{
            dp[t] = n+1+helper((1<<n)-1-t, dp);
            for(int i=0;i<n-1;i++){
                dp[t]=min( dp[t], n-1+1+i+1+ helper(t- (1<<(n-1))-1 + (1<<i)+1 ,dp) );
            }
        }
        return dp[t];
    }
};
