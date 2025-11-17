class Solution {
public:
    using ll = long long;
    const ll INF = LLONG_MAX / 4;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n, 0);
        ll maxCost = 0;
        for (auto &e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, cost});
                indeg[v]++;
                maxCost = max(maxCost, (ll)cost);
            }
        }
        vector<int> topo;
        topo.reserve(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto &p : adj[u]) {
                int v = p.first;
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }
        auto can = [&](int X) {
            vector<ll> dist(n, INF);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == INF) continue;
                for (auto &p : adj[u]) {
                    int v = p.first, cost = p.second;
                    if (cost >= X) {
                        ll newCost = dist[u] + cost;
                        if (newCost < dist[v])
                            dist[v] = newCost;
                    }
                }
            }
            return dist[n-1] <= k;
        };
        int lo = 0, hi = maxCost, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
