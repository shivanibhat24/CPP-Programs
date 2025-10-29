class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            adj[u].push_back({v, cnt});
            adj[v].push_back({u, cnt});
        }
        vector<int> dist(n, -1);
        priority_queue<pair<int,int>> pq;
        pq.push({maxMoves, 0});
        dist[0] = maxMoves;
        while (!pq.empty()) {
            auto [moves, u] = pq.top(); pq.pop();
            if (moves < dist[u]) continue;
            for (auto [v, cost] : adj[u]) {
                int remain = moves - cost - 1;
                if (remain > dist[v]) {
                    dist[v] = remain;
                    pq.push({remain, v});
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] >= 0) ans++;
        }
        for (auto &e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            long long a = max(0, dist[u]);
            long long b = max(0, dist[v]);
            ans += min((long long)cnt, a + b);
        }
        return ans;
    }
};
