struct TrieNode {
    TrieNode* child[2];
    int cnt;
    TrieNode() {
        child[0] = child[1] = nullptr;
        cnt = 0;
    }
};
TrieNode* Trieroot;
const int MX = 19;
void insert(int val, int ct) {
    TrieNode* root = Trieroot;
    for (int d = MX; d >= 0; d--) {
        int bit = (val >> d) & 1;
        if (!root->child[bit]) {
            root->child[bit] = new TrieNode();
        }
        root = root->child[bit];
        root->cnt += ct;
    }
}
int maxxor(int val) {
    TrieNode* root = Trieroot;
    int ans = 0;
    for (int d = MX; d >= 0; d--) {
        int bit = (val >> d) & 1;
        if (root->child[1 - bit] && root->child[1 - bit]->cnt > 0) {
            ans |= (1 << d);
            root = root->child[1 - bit];
        } else {
            root = root->child[bit];
        }
    }
    return ans;
}
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj,
             vector<vector<pair<int, int>>>& qu, vector<int>& ans) {
        insert(u, +1);
        for (auto it : qu[u]) {
            int val = it.first, ind = it.second;
            ans[ind] = maxxor(val);
        }
        for (auto v : adj[u]) {
            dfs(v, adj, qu, ans);
        }
        insert(u, -1);
    }
    vector<int> maxGeneticDifference(vector<int>& par,
                                     vector<vector<int>>& que) {
        int n = par.size(), m = que.size();
        vector<vector<int>> adj(n);
        int root = -1;
        for (int u = 0; u < n; u++) {
            int pa = par[u];
            if (pa == -1) {
                root = u;
                continue;
            } else {
                adj[pa].push_back(u);
            }
        }
        vector<int> ans(m);
        vector<vector<pair<int, int>>> qu(n);
        for (int i = 0; i < m; i++) {
            int u = que[i][0], val = que[i][1];
            qu[u].push_back({val, i});
        }
        Trieroot = new TrieNode();
        dfs(root, adj, qu, ans);
        return ans;
    }
};
