class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>adj(n);
        for(auto&it : richer){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n,-1);
        auto dfs = [&](auto&&self ,int node)->void{
            if(ans[node] != -1) return ;
            int mini = node;
            for(auto&it : adj[node]){
                self(self,it);
                if(quiet[ans[it]]<quiet[mini]){
                    mini = ans[it];
                }
            }
            ans[node] = mini;
        };
        for(int i = 0 ; i < n ; i++) dfs(dfs,i);
        return ans;
    }
};
