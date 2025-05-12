class Solution {
public:
    int memo[13][5000];
    int shortestPathLength(vector<vector<int>>& graph) {
        memset(memo, 0, sizeof(memo));
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < graph.size(); ++i) q.push({i, 1 << i});
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [node, mask] = q.front(); q.pop();
                if (mask == (1 << graph.size()) - 1) return ans;
                for (int nei : graph[node]) {
                    int nmask = mask | (1 << nei);
                    if (memo[nei][nmask]) continue;
                    q.push({nei, nmask});
                    memo[nei][nmask] = 1;
                }
            }
            ++ans;
        }
        return -1;
    }
};
