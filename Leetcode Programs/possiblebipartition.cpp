class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        size.resize(n + 1, 1);
    }
    int getParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = getParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = getParent(u);
        int ulp_v = getParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DSU ds(n * 2);
        for (auto& it : dislikes) {
            int u = it[0], v = it[1];
            if (ds.getParent(u) == ds.getParent(v)) return false;
            ds.unionBySize(u, v + n); 
            ds.unionBySize(v, u + n);  
        }
        return true;
    }
};
