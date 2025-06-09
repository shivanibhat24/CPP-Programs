class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1, 0);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        vector<int> comp(n+1, -1), color(n+1, -1);
        int cid = 0;
        vector<vector<int>> comps;
        queue<int> q;        
        for (int i = 1; i <= n; i++) {
            if (comp[i] != -1) continue;
            comp[i] = cid;
            color[i] = 0;
            q.push(i);
            vector<int> nodes = {i};            
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (comp[v] == -1) {
                        comp[v] = cid;
                        color[v] = color[u] ^ 1;
                        q.push(v);
                        nodes.push_back(v);
                    } else if (color[v] == color[u]) {
                        return -1; 
                    }
                }
            }
            comps.push_back(nodes);
            cid++;
        }
        int answer = 0;
        vector<int> dist(n+1);        
        for (auto &nodes : comps) {
            int sz = nodes.size();
            if (sz <= 3) {
                answer += sz;
                continue;
            }
            int minDeg = deg[nodes[0]];
            for (int u : nodes)
                if (deg[u] < minDeg) minDeg = deg[u];            
            vector<int> starts;
            for (int u : nodes)
                if (deg[u] == minDeg)
                    starts.push_back(u);
            int compBest = 0;
            for (int s : starts) {
                fill(dist.begin(), dist.end(), -1);
                dist[s] = 0;
                q.push(s);
                int maxd = 0;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : adj[u]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            maxd = max(maxd, dist[v]);
                            q.push(v);
                        }
                    }
                }
                vector<int> furthest;
                for (int u : nodes)
                    if (dist[u] == maxd)
                        furthest.push_back(u);
                for (int start2 : furthest) {
                    fill(dist.begin(), dist.end(), -1);
                    dist[start2] = 0;
                    q.push(start2);
                    int diam = 0;
                    while (!q.empty()) {
                        int u = q.front(); q.pop();
                        for (int v : adj[u]) {
                            if (dist[v] == -1) {
                                dist[v] = dist[u] + 1;
                                diam = max(diam, dist[v]);
                                q.push(v);
                            }
                        }
                    }
                    compBest = max(compBest, diam + 1);
                }
            }            
            answer += compBest;
        }        
        return answer;
    }
};
