class Solution {
public:
    int dp[101][101][21] = {};
    int mx = 1e6 + 1;    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res = dfs(houses, cost, m, n, target, 0, 0);
        return res == mx ? -1 : res;
    }    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int& m, int& n, int t, int i, int p) {
        if(i == m || t < 0 || m - i < t)
            return (t == 0 && i == m) ? 0 : mx;
        if(dp[i][t][p] == 0) {
            if(houses[i] == 0) {
                int ans = mx;
                for(int c = 1; c <= n; ++c) {
                    ans = min(dfs(houses, cost, m, n, t - (c != p), i + 1, c) + cost[i][c-1], ans);
                }
                dp[i][t][p] = ans;
            }
            else
                dp[i][t][p] = dfs(houses, cost, m, n, t - (houses[i] != p), i + 1, houses[i]);
        }
        return dp[i][t][p];
    }
};
