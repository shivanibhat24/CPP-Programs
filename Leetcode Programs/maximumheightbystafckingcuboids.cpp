class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
         for (auto& cub : cuboids) {
            sort(cub.begin(), cub.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2]){
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
        }
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){
            maxm=max(maxm,dp[i]);
        }
        return maxm;
    }
};
