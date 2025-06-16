class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        const int INF = 1e9;
        int n = cost.size();
        int dp[501];
        fill(dp, dp + 501, INF);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int c = cost[i], t = time[i];
            for (int j = n; j >= 0; --j) {
                int nj = min(n, j + t + 1);
                if (dp[j] + c < dp[nj]) dp[nj] = dp[j] + c;
            }
        }
        return dp[n];
    }
};
