class Solution {
public:
    vector<int> parent;
    vector<int> sizee;
    vector<unordered_set<int> > ban;
    void make_set(int n) {
        parent.resize(n);
        sizee.resize(n);
        ban.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizee[i] = 1;
        }
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void merge_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return;
        if (sizee[u] < sizee[v]) swap(u, v);

        for (int cur : ban[v]) {
            cur = find_set(cur);
            if (cur == u) continue;
            ban[u].insert(cur);
            ban[cur].erase(v);
            ban[cur].insert(u);
        }

        parent[v] = u;
        sizee[u] += sizee[v];
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        make_set(n);
        for (auto res : restrictions) {
            int u = res[0];
            int v = res[1];
            ban[u].insert(v);
            ban[v].insert(u);
        }
        vector<bool> ans;
        for(auto req : requests) {
            int u = req[0];
            int v = req[1];
            u = find_set(u);
            v = find_set(v);
            if (u == v) {
                ans.push_back(true);
                merge_set(u, v);
            }
            else {
                if (ban[u].count(v) || ban[v].count(u)) {
                    ans.push_back(false);
                }
                else {
                    ans.push_back(true);
                    merge_set(u, v);
                }
            }
        }
        return ans;
    }
};
