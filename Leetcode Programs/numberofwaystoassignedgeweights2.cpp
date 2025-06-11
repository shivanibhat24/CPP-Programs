using LL = long long;
constexpr int NN = 1.1e5;
constexpr int MM = 18;
constexpr int MOD = 1e9+7;
int e_to[NN*2], e_next[NN*2], n_e[NN], n_h[NN];
int dp[NN][MM+1];
bool inited = false;
LL dp_query_D[NN]={0};
void init(){
    if(!inited){
        inited = true;
        dp_query_D[1] = 1;
        for(int D=2; D<NN; ++D){
            dp_query_D[D] = dp_query_D[D-1]*2%MOD;
        }
    }
}
inline void add_edge(int u, int v, int e){
    e_to[e] = v;
    e_next[e] = n_e[u];
    n_e[u] = e;
}
void dfs(int ni, int fi, int h){
    n_h[ni] = h;
    dp[ni][0] = fi;
    for(int e=n_e[ni]; e!=-1; e=e_next[e]){
        int nj = e_to[e];
        if(nj==fi) continue;
        dfs(nj, ni, h+1);
    }
}
void make_dp(int N){
    for(int d=1; d<=MM; ++d){
        for(int i=0; i<=N; ++i){
            dp[i][d] = dp[dp[i][d-1]][d-1];
        }
    }
}
int query(int u, int v){
    if(n_h[u]<n_h[v]) swap(u,v);
    for(int i=0, dh=n_h[u]-n_h[v]; (1<<i)<=dh; ++i){
        if(dh&(1<<i)){
            u = dp[u][i];
        }
    }
    for(int i=MM; i>=0 and u!=v; --i){
        if(dp[u][i]!=dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    if(u!=v) u = dp[u][0];
    return u;
}
class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        init();
        memset(n_e, -1, sizeof(int)*(n+1));
        for(int e=0; e<n-1; ++e){
            int u = edges[e][0]-1, v = edges[e][1]-1;
            add_edge(u, v, e<<1);
            add_edge(v, u, e<<1^1);
        }
        dfs(0, 0, 0);
        make_dp(n);
        vector<int> ans;
        for(auto &q:queries){
            int u = q[0]-1, v = q[1]-1, w = query(u, v);
            ans.push_back(dp_query_D[n_h[u]+n_h[v]-2*n_h[w]]); 
        }
        return ans;
    }
};
