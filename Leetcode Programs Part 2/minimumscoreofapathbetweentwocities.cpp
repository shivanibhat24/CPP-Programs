class Solution {
public:
    void dfs(unordered_map<int,vector<pair<int,int>>>& adj, int u,vector<bool>&visited, int &mind){
        // if(visited[u])return ;

        visited[u]=true;

        for(auto &p: adj[u]){
            int v=p.first;
            int d=p.second;
            mind=min(mind,d);

            if(!visited[v]){
                dfs(adj,v,visited,mind);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec:roads){
            int u=vec[0];
            int v=vec[1];
            int dist=vec[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        vector<bool>visited(n,false);
        int mind=INT_MAX;
        dfs(adj,1,visited,mind);
        return mind;
    }
};
