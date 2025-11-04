class Solution {
public:
    const long long INF = 1e15;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        vector<long long> distDest(n, INF);
        using P = pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, dest});
        distDest[dest] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > distDest[u]) continue;
            for (auto [v, idx] : adj[u]) {
                int w = edges[idx][2];
                if (w == -1) continue; 
                if (distDest[v] > d + w) {
                    distDest[v] = d + w;
                    pq.push({distDest[v], v});
                }
            }
        }
        vector<long long> distSrc(n, INF);
        distSrc[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > distSrc[u]) continue;
            for (auto [v, idx] : adj[u]) {
                int &w = edges[idx][2];
                long long nd;
                if (w != -1) {
                    nd = d + w;
                } else {
                    long long need = target - d - distDest[v];
                    if (need > 0) {
                        w = (int)need;
                    } else {
                        w = 1;
                    }
                    nd = d + w;
                }
                if (nd < distSrc[v]) {
                    distSrc[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        if (distSrc[dest] != target) return {};
        for (auto &e : edges) if (e[2] == -1) e[2] = 1;
        return edges;
    }
};
