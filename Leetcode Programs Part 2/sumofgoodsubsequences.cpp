const int N=1e5+9;
const int mod=1e9+7;
#define ll long long
class Solution {
public:
    ll add(ll x,ll y){
        return (x+y)%mod;
    }
    int sumOfGoodSubsequences(vector<int>& a) {
        int n=a.size();
        int K=0;
        ll ans = 0;
        for(auto i:a) K=max(i,K);
        vector<ll> sum(K+2,0),cnt(K+2,0);
        for(int i=0;i<n;i++){
            ll v = a[i];
            sum[v]=add(sum[v], v);
            ans=add(ans,v);
            ll add_on = add((v?cnt[v-1]:0),cnt[v+1]);
            sum[v]=add(sum[v],add_on*v);
            if(v){
                sum[v]=add(sum[v],sum[v-1]);
                  ans=add(ans,sum[v-1]);
            }
            sum[v]=add(sum[v],sum[v+1]);
            ans=add(ans,sum[v+1]);
            
            ans=add(ans,add_on*v);
            cnt[v]=add(cnt[v],1+add_on);
        }
        return ans;
    }
};
