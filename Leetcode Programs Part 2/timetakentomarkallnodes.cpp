class Solution {
public:
    #define vvi vector<vector<int>>
    int dp[100002];
    void dfs(int node,int parent,vvi& adj){
        if(adj[node].size() == 1 && parent != -1){
            dp[node] = 0;
            return;
        }
        
        for(int x : adj[node]){
            if(x == parent) continue;
            dfs(x,node,adj);
            dp[node] = max(dp[node],dp[x] + ((x%2) ? 1 : 2 ));
        }
    }

    void dfs2(int node,int par,vvi& adj,int to_p,vector<int>& ans){
        if(adj[node].size() == 1 && par != -1){
            ans[node] = to_p;
            return;
        }

        int c1 = -1;
        int c2 = -1;

        ans[node] = max(to_p,dp[node]);

        for(int x : adj[node]){
            if(x == par) continue;
            if( c1 == -1 || dp[x] + 1 + !(x%2) >= dp[c1]  + 1 + !(c1%2)){
                c2 = c1;
                c1 = x;
            }
            else if(c2 == -1 || dp[x]  + 1 + !(x%2) >= dp[c2]  + 1 + !(c2%2)){
                c2 = x;
            }
        }

        if(c1 == -1){
            return;
        }

        if(c2 == -1){
            for(int x : adj[node]){
                if(x == par) continue;
                dfs2(x,node,adj,to_p + ((node%2) ? 1 : 2 ),ans);
            }
            return;
        }

        for(int x : adj[node]){
            if(x == par) continue;
            if(x == c1) dfs2(x,node,adj,max(dp[c2] + ((c2%2) ? 1 : 2 ) , to_p) + ((node%2) ? 1 : 2 ),ans);
            else{
                dfs2(x,node,adj,max(dp[c1] + ((c1%2) ? 1 : 2 ) ,to_p) + ((node%2) ? 1 : 2 ),ans);
            }
        }
        
    }

    vector<int> timeTaken(vector<vector<int>>& edges) {
        vector<int> ans(edges.size() + 1);
        vvi adj(edges.size() + 1);

        for(auto& e : edges ){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0,-1,adj);
        dfs2(0,-1,adj,0,ans);

        return ans;
        
    }
};
