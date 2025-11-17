class Solution {
public:
    void backtracking(std::vector<int> &values, int maxTime, std::vector<std::vector<std::pair<int, int>>> &graph,
                      std::vector<bool> &seen, std::vector<int> &dist, int node, int curTime, int curValue, int &maxQuality) {
        if (node == 0) {
            maxQuality = std::max(maxQuality, curValue);
        }
        for (const auto &[next, costTime] : graph[node]) {
            if (curTime + costTime + dist[next] > maxTime) continue;
            if (seen[next]) {
                backtracking(values, maxTime, graph, seen, dist, next, curTime + costTime, curValue, maxQuality);
            }
            else {
                seen[next] = true;
                backtracking(values, maxTime, graph, seen, dist, next, curTime + costTime, curValue + values[next], maxQuality);
                seen[next] = false;
            }
        }
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = static_cast<int>(values.size());
        using pii = std::pair<int, int>;
        std::vector<std::vector<pii>> graph(n);
        for (const auto &edge : edges) {
            int u = edge[0], v = edge[1], time = edge[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }
        std::vector<int> dist(n, INT_MAX);
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        pq.emplace(0, 0);
        dist[0] = 0;        
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (cost > dist[node]) continue;
            for (const auto &[next, nextTime] : graph[node]) {
                if (cost + nextTime < dist[next]) {
                    dist[next] = cost + nextTime;
                    pq.emplace(dist[next], next);
                }
            }
        }
        int maxQuality = 0;
        std::vector<bool> seen(n, false);
        seen[0] = true;
        backtracking(values, maxTime, graph, seen, dist, 0, 0, values[0], maxQuality);
        return maxQuality;
    }
};
