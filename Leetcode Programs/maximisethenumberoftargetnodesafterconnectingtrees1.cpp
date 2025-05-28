class Solution {
public:
    void build_graph(vector<vector<int>>& g, vector<vector<int>>& edges) {
        for(const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int dfs(int u, int p, vector<vector<int>>& g, int k) {
        if(k < 0)
            return 0;  
        int nodes = 1;
        for(int& v : g[u]) {
            if(v == p)
                continue;
            nodes += dfs(v, u, g, k - 1);
        }
        return nodes;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        vector<int> reach_g1(n), reach_g2(m), res(n);
        build_graph(g1, edges1);
        build_graph(g2, edges2);
        for(int i = 0; i < n; ++i)
            reach_g1[i] = dfs(i, -1, g1, k);
        for(int i = 0; i < m; ++i)
            reach_g2[i] = dfs(i, -1, g2, k - 1);        
        int max_reach = *max_element(begin(reach_g2), end(reach_g2));
        for(int i = 0; i < n; ++i)
            res[i] = reach_g1[i] + max_reach;
            
        return res;
    }
};
