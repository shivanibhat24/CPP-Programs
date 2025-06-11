class Solution {
public:
    static constexpr int BMAX = 200;       
    static constexpr int NEG_INF = -1000000;
    int n, budget;
    vector<int> present, future;
    vector<vector<int>> adj;
    pair<array<int,BMAX+1>, array<int,BMAX+1>>
    dfs(int u, int p) {
        array<int,BMAX+1> child0, child1;
        child0.fill(NEG_INF);
        child1.fill(NEG_INF);
        child0[0] = child1[0] = 0;
        for (int v : adj[u]) if (v != p) {
            auto [dp0_v, dp1_v] = dfs(v, u);
            array<int,BMAX+1> nxt0, nxt1;
            nxt0.fill(NEG_INF);
            nxt1.fill(NEG_INF);
            for (int c0 = 0; c0 <= budget; ++c0) {
                if (child0[c0] < 0) continue;
                for (int c1 = 0; c0 + c1 <= budget; ++c1) {
                    if (dp0_v[c1] < 0) continue;
                    nxt0[c0 + c1] = max(nxt0[c0 + c1],
                                        child0[c0] + dp0_v[c1]);
                }
            }
            for (int c0 = 0; c0 <= budget; ++c0) {
                if (child1[c0] < 0) continue;
                for (int c1 = 0; c0 + c1 <= budget; ++c1) {
                    if (dp1_v[c1] < 0) continue;
                    nxt1[c0 + c1] = max(nxt1[c0 + c1],
                                        child1[c0] + dp1_v[c1]);
                }
            }
            child0 = nxt0;
            child1 = nxt1;
        }
        array<int,BMAX+1> dp0_u = child0;
        array<int,BMAX+1> dp1_u = child0;
        {
            int price  = present[u];
            int profit = future[u] - price;
            for (int c = 0; c + price <= budget; ++c) {
                if (child1[c] < 0) continue;
                dp0_u[c + price] = max(dp0_u[c + price],
                                       child1[c] + profit);
            }
        }
        {
            int price  = present[u] / 2;
            int profit = future[u] - price;
            for (int c = 0; c + price <= budget; ++c) {
                if (child1[c] < 0) continue;
                dp1_u[c + price] = max(dp1_u[c + price], child1[c] + profit);
            }
        }
        return {dp0_u, dp1_u};
    }
    int maxProfit(int _n,vector<int>& _present,
                  vector<int>& _future,
                  vector<vector<int>>& hierarchy,
                  int _budget) {
        n       = _n;
        present = _present;
        future  = _future;
        budget  = min(_budget, BMAX);
        adj.assign(n, {});
        for (auto &e : hierarchy) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto [dp0_root, dp1_root] = dfs(0, -1);
        int ans = 0;
        for (int c = 0; c <= budget; ++c)
            ans = max(ans, dp0_root[c]);
        return ans;
    }
};
