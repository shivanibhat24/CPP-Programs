class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        int dp[n + 1][minProfit + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; 
        const int MOD = 1e9 + 7;
        for(int i = 0; i < m; i++){
            int g = group[i];
            int p = profit[i];
            for(int j = n; j>= g; j--){
                for(int k = minProfit; k >= 0; k--){
                    dp[j][k] = (dp[j][k] + dp[j-g][max(k-p, 0)]) % MOD;
                }
            }
        }
        int res = 0; 
        for(int i = 0; i<= n; i++){
            res = (res + dp[i][minProfit]) % MOD;
        }
        return res;
    }
};
