class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void UnionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mpp;
        int n = accounts.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++) {
                auto it = mpp.find(accounts[i][j]);
                if (it == mpp.end())
                    mpp[accounts[i][j]] = i;
                else
                    ds.UnionBySize(i,mpp[accounts[i][j]]);
            }
        }
        vector<vector<string>> club(n);
        for(auto it:mpp){
            int indx = ds.findUPar(it.second);
            club[indx].push_back(it.first);
        }
        for(int i=0;i<n;i++)
            sort(club[i].begin(),club[i].end());
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(club[i].size()>=1){
                vector<string> lvl;
                lvl.push_back(accounts[i][0]);
                for(int j=0;j<club[i].size();j++) lvl.push_back(club[i][j]);
                ans.push_back(lvl);
            }
        }
        return ans;
    }
};
