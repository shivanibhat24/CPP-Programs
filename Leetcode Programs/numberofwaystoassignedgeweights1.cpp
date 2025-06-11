class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxDepth = 0;
        function<void(int, int, int)> dfs = [&](int u, int p, int d) {
            maxDepth = max(maxDepth, d);
            for (int v : adj[u])
                if (v != p) dfs(v, u, d + 1);
        };
        dfs(1, 0, 0);
        --maxDepth;
        int mod = 1e9 + 7, res = 1;
        for (int i = 1; i <= maxDepth; ++i)
            res = (long long)res * 2 % mod;
        return res;
    }
};
