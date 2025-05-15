class Solution {
public:
    bool solve(int n, int cnt, vector<int>& dp){
        if(n == 0){
            return (n % 2);
        }
        if(dp[n] != -1)
            return dp[n];        
        for (int i = 1; i*i <= n; i++) {
            if(i*i > n)
                break;
            if (!solve(n - i*i, cnt + 1, dp)) {
                dp[n] = 1; 
                return true;
            }
        }
        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1); 
        return solve(n, 0, dp);
    }
};
