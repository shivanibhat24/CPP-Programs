constexpr int N=1e5+1;
int Rt[N], Rk[N]; 
int freq[N];
class UnionFind {
public:
    UnionFind(int n){
        iota(Rt, Rt+n, 0);
        fill(Rk, Rk+n, 0);
    }
    int Find(int x) {
        // compress path
        return (x == Rt[x])?x:Rt[x]=Find(Rt[x]);
    }
    bool Union(int x, int y) {
        x=Find(x), y=Find(y);
        if (x==y) return 0;
        if (Rk[x]>Rk[y]) swap(x, y);
        Rt[x]=y;
        if (Rk[x]==Rk[y]) Rk[y]++;
        return 1;
    }
};

class Solution {
public:
    static int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int n=source.size();
        UnionFind G(n);        
        for(auto& sw : allowedSwaps)
            G.Union(sw[0], sw[1]);
        vector<vector<int>> components(n);
        for(int i=0; i<n; i++)
            components[G.Find(i)].push_back(i);
        int match=0;
        for(int i = 0;i<n; i++) {
            if (components[i].empty()) continue;
            for(int idx : components[i])
                freq[source[idx]]++;
            for(int idx : components[i]) {
                if (freq[target[idx]]>0) {
                    freq[target[idx]]--;
                    match++;
                }
            }
            for(int idx : components[i]) {
                freq[source[idx]]=0; 
            }
        }
        return n-match;
    }
};
