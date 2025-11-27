class Solution {
public:
    long long MOD = 1000'000'007;
    int numberOfPaths(vector<vector<int>>& a, int k) {
        int n=a.size(); int m = a[0].size();
        long long dp[n][m][k];
        for(int r=0;r<k;r++){
            dp[n-1][m-1][r] = 0;
        }
        dp[n-1][m-1][a[n-1][m-1]%k]=1;
        for(int j=m-2;j>=0;j--){
            int x = a[n-1][j]%k;
            for(int r=0;r<k;r++)
            dp[n-1][j][r] = dp[n-1][j+1][ r>=x ? r-x : k+r-x]; 
        }
        for(int i=n-2;i>=0;i--){
            int x = a[i][m-1]%k;
            for(int r=0;r<k;r++){
                dp[i][m-1][r]=dp[i+1][m-1][ r>=x ? r-x : k+r-x];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int x = a[i][j]%k;                
                for(int r=0;r<k;r++){
                    int y = r>=x ? r-x : k+r-x;
                    dp[i][j][r] = dp[i+1][j][y]+dp[i][j+1][y];
                    dp[i][j][r]%=MOD;
                }
            }
        }
        return dp[0][0][0];        
    }
};
