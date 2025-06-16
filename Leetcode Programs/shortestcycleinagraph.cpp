class Solution {
public:
    int cycleLen = INT_MAX;
    vector<int> visited;
    void dfs(vector<vector<int>> &g, int node, int k){
        if(visited[node] != -1 && k > visited[node]){
            if(k - visited[node]  >= 3)
                cycleLen = min(cycleLen, k-visited[node]);
            return;
        }    
        visited[node] = k;
        for(int i=0; i<g[node].size(); i++){
            dfs(g, g[node][i], k+1);
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        visited = vector<int>(n, -1);
        for(int i=0; i<edges.size(); i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<n; i++){
            if(visited[i] == -1){
                dfs(g, i, 1);
            }
        }
        if(cycleLen == INT_MAX)
            return -1;
        return cycleLen;
    }
};
