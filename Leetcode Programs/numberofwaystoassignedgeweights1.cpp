typedef long long ll;
vector<ll> v[100002];
ll depth;
ll mod=1e9+7;
void fun(ll node, ll height){
    depth=max(depth,height);
    for(auto child: v[node]){
        fun(child,height+1);
    }
}
ll power(ll base, ll exponent){
    ll ans=1;
    while(exponent){
        if(exponent&1){
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        exponent/=2;
    }
    return ans%mod;
}
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        ll n=edges.size()+1,i,j,k;
        depth=0;
        for(i=1;i<=n;i++){
            v[i].clear();
        }
        for(i=0;i<n-1;i++){
            v[edges[i][0]].push_back(edges[i][1]);
        }
        fun(1,0);
        return power(2,depth-1);
    }
};
