const int mxN = 1e5 + 5;
int nxt[mxN];
int Find(int u){
    if(u == nxt[u])
        return u;
    return nxt[u] = Find(nxt[u]);
}
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        for(int i = 0; i < n + 5; ++i)
            nxt[i] = i;
        for(int i: banned)
            nxt[i] = i + 2;
        vector<int> res(n, -1);
        res[p] = 0;
        queue<int> q;
        q.push(p);
        nxt[p] = p + 2;
        while(q.size()){
            int u = q.front(); q.pop();
            int l = max(0, u - min(k - 1, (u - k / 2) * 2 + (k % 2 == 0)));
            int r = min(n - 1, u + min(k - 1, (n - 1 - k / 2 - u) * 2 + (k % 2 == 0)));
            for(int i = Find(l); i <= r; i = Find(i)){
                res[i] = res[u] + 1;
                q.push(i);
                nxt[i] = i + 2; 
            }
        }
        return res;
    }
};
