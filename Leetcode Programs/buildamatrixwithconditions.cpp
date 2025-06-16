class Solution {
private:
    vector<int> topoSort(int k, vector<vector<int>>& edges) {
        vector<int> indegree(k + 1, 0);
        vector<vector<int>> adj(k + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        vector<int> order;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (order.size() != k) return {};
        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k, rowConditions);
        if (rowOrder.size() != k) return {};
        vector<int> colOrder = topoSort(k, colConditions);
        if (colOrder.size() != k) return {};
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<int> colIndex(k+1);
        for (int i = 0; i < k; ++i) {
            colIndex[colOrder[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            res[i][colIndex[rowOrder[i]]] = rowOrder[i];
        }
        return res;
    }
};
