
long long dp[505][1<<10];
long long fl[505];
class Solution {
    long long mod = 1e9 + 7, limit = 1<<10;
    vector<vector<pair<int,int>>> bits;
    bool on(int b, int x) {
        return (b>>x) & 1;
    }
public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        memset(dp,-1,sizeof dp);
        memset(fl,0,sizeof fl);
        long long n = vals.size(), res = 0;
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) adj[par[i]].push_back(i);
        vector<int> ord;
        queue<int> q;
        q.push(0); ord.push_back(0);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(auto& v : adj[u]) {
                ord.push_back(v);
                q.push(v);
            }
        }
        while(ord.size()) {
            int u = ord.back(); ord.pop_back();
            long long bit = 0, ok = true, val = vals[u];
            dp[u][0] = 0;
            while(vals[u] and ok) {
                if(on(bit, vals[u] % 10)) ok = false;
                else {
                    bit |= 1<<(vals[u] % 10);
                    vals[u] /= 10;
                }
            }
            if(ok) dp[u][bit] = max(dp[u][bit], val), fl[u] |= bit;
            if(fl[u]) {
                for(auto& v : adj[u]) {
                    for(int mask = fl[v]; mask; mask = (mask - 1) & fl[v]) dp[u][mask] = max(dp[u][mask], dp[v][mask]);
                }
                int mask = 0;
                long long best = 0;
                do {
                    if(dp[u][mask] != -1) {
                        int inv = fl[u] ^ mask;
                        for(int sub = inv; ; sub = (sub - 1) & inv) {
                            if(dp[u][sub] == -1) continue;
                            dp[u][mask | sub] = max(dp[u][mask | sub], dp[u][mask] + dp[u][sub]);
                            if(!sub) break;
                        }
                        best = max(best, dp[u][mask]);
                    }
                    mask = (mask - fl[u]) & fl[u];
                }while(mask);
                res = (res + best) % mod;
            }
            if(par[u] != -1) fl[par[u]] |= fl[u];
        }
        return res;
    }
};
