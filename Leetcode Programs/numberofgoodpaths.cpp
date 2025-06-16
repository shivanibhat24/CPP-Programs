class DSU {
    vector<int> parent, count, vals;
public:
    DSU(int n, vector<int>& vals) : vals(vals), parent(n), count(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    int unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return 0;
        }
        if (vals[pu] < vals[pv]) {
            parent[pu] = pv;
        } else if (vals[pu] > vals[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            int result = count[pu] * count[pv];
            count[pu] += count[pv];
            return result;
        }
        return 0;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DSU dsu(n, vals);
        sort(edges.begin(), edges.end(), [&](auto& a, auto& b) {
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
        });
        int res = n; 
        for (auto& edge : edges) {
            res += dsu.unionNodes(edge[0], edge[1]);
        }
        return res;
    }
};
