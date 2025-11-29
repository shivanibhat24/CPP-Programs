class Solution {
public:
    #define ll long long
    const ll INF = 1e18;
    
    int i, j;
    
    vector<ll> dijkstra(int n, int src, vector<vector<pair<int, ll>>>& adj) {
        vector<ll> d(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, src}); 
        d[src] = 0;
        
        while (!pq.empty()) {
            auto [w, u] = pq.top(); 
            pq.pop();
            if (d[u] < w) continue;
            
            for (auto [v, wt] : adj[u]) {
                if (d[v] > (w + wt)) {
                    d[v] = (w + wt); 
                    pq.push({w + wt, v});
                }
            }
        }
        return d;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        // Build adjacency list for forward graph and reverse graph
        vector<vector<pair<int, ll>>> adj(n), radj(n);
        
        for (i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            radj[v].push_back({u, w});
        }
        
        // Calculate shortest distances from src1 to all nodes
        vector<ll> d1 = dijkstra(n, src1, adj);
        // Calculate shortest distances from src2 to all nodes  
        vector<ll> d2 = dijkstra(n, src2, adj);
        // Calculate shortest distances from all nodes to dest (using reverse graph)
        vector<ll> dd = dijkstra(n, dest, radj);
        
        ll ans = INF;
        // Try each node as intermediate meeting point
        for (int m = 0; m < n; m++) {
            if (d1[m] == INF || d2[m] == INF || dd[m] == INF) continue;
            ans = min(ans, (d1[m] + d2[m] + dd[m]));
        }
        
        return ans == INF ? -1 : ans;
    }
};
