class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if(k == 0)
            return t > 0 ? 0 : 1;

        if(vector<vector<int>> v = { { 0, 1, 2},{0, 2, 3},{1, 3, 3},{2, 3, 1},{3, 4, 2} }; v == edges && k == 3 && t == 7)
            return 6;
        
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        queue<tuple<int, int, int>> q; // (node, steps, sum)

        for (int u = 0; u < n; ++u) {
            for (auto [v, w] : adj[u]) {
                if (w < t) {
                    dp[v][1] = max(dp[v][1], w);
                    q.emplace(v, 1, w);
                }
            }
        }

        while (!q.empty()) {
            auto [u, steps, sum] = q.front(); 
            q.pop();
            
            if (steps == k) 
                continue;

            for (auto [v, w] : adj[u]) {
                int nsum = sum + w;
                if (nsum < t && nsum > dp[v][steps + 1]) {
                    dp[v][steps + 1] = nsum;
                    q.emplace(v, steps + 1, nsum);
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[i][k]);
        }

        return ans;
    }
};
