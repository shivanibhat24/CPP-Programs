class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=1+dp[i-1][j-1]+dp[i-1][j];
            }
            if(dp[i][k]>=n) return i;
        }
        return -1;
    }
};
